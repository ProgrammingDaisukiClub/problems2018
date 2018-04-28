#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

def solve():
    kill = list(map(int,input().split()))
    kill.sort()

    n = len(kill)
    alive = [1]*n

    for i in range(n):
        rem = kill[i]
        for j in range(i):
            if rem == 0:
                break

            if alive[j]:
                alive[j] = 0
                rem -= 1

        assert rem == 0

    print(sum(alive))

def main():
    for _ in range(int(input())):
        solve()

if __name__ == '__main__':
    main()
