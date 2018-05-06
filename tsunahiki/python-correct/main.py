#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

def solve():
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))

    # binary search
    ok, ng = 0, n+1
    while ng-ok > 1:
        m = (ok+ng)//2

        valid = True
        for i in range(m):
            if b[i] >= a[n-m+i]:
                valid = False

        if valid:
            ok = m
        else:
            ng = m

    print(ok)

def main():
    for _ in range(int(input())):
        solve()

if __name__ == '__main__':
    main()
