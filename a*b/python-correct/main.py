#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

def solve():
    a,b = map(int,input().split())
    return a * b

def main():
    cases = int(input())
    for _ in range(cases):
        print(solve())

if __name__ == '__main__':
    main()
