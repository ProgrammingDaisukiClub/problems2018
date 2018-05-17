#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

import yaml
import sys
import json
import os

usage = """
Problem data json file generator from rime for WPCS2

usage:
$ ./jsoner.py [config yaml file]

Note that you need to run `rime test` before executing this script
"""


def exit_with_usage(error = None) :
    print(usage)
    if error is not None :
        print('\nError: ' + error)
    exit(-1)


def open_and_read_file(file_name) :
    if not os.path.isfile(file_name) :
        exit_with_usage("file " + file_name + " dose not exist!")
    with open(file_name, "r", encoding="utf-8") as f:
        return f.read()


def sanitize_title(title) :
    if title.startswith('X: ') :
        return title[3:]
    elif title.startswith('X:') :
        return title[2:]
    elif title.startswith('X') :
        return title[1:]
    return title


if __name__ == '__main__' :
    argvs = sys.argv

    if len(argvs) != 2 :
        exit_with_usage()

    infile_name = argvs[1]
    data = yaml.load(open_and_read_file(infile_name))

    for problem in data['problems'] :
        dir_name = problem['dir_name']

        # check rime-out exists
        if not os.path.isdir(dir_name + "/rime-out") :
            exit_with_usage(dir_name + "/rime-out directory does not exits ")

        # read problem title
        def _problem(title=None, **ignore) :
            problem['title'] = sanitize_title(title)
        def _atcoder_config(**ignore) :
            return
        exports = {'problem': _problem, 'atcoder_config': _atcoder_config}
        exec(open_and_read_file(dir_name + "/PROBLEM"), exports, {})

        # statement
        problem['statement'] = open_and_read_file(dir_name + "/statement.md")

        # dataset
        for data_set in problem['data_sets'] :
            test_dir =  dir_name + "/rime-out/tests/" + data_set['label'].lower()
            data_set['input'] = open_and_read_file(test_dir + ".in")
            data_set['output'] = open_and_read_file(test_dir + ".diff")

        del problem['dir_name']

        # output to std
        data_set_str = ["{} ({})".format(s['label'], s['score']) for s in problem['data_sets']]
        print(problem['title'] + " : " + ", ".join(data_set_str))

    # TODO not endwith .yml
    outfile_name = infile_name.replace(".yml", ".json")

    with open(outfile_name, "w", encoding="utf-8") as f :
        json.dump(data, f, ensure_ascii=False, sort_keys=True)

    print("\nSuccessfully output to " + outfile_name)
