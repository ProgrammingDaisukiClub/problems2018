#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

def solve():
    know = set()
    for _ in range(int(input())):
        know.add(input())

    seen = set()
    for _ in range(int(input())):
        s = input()

        ans = 'siranai'
        if s in know:
            if s in seen:
                ans = 'moumita'
            else:
                ans = 'kawaii'

        seen.add(s)
        print(ans)

def main():
    for _ in range(int(input())):
        solve()

if __name__ == '__main__':
    main()
