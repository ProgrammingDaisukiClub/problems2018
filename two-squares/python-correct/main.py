#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

import numpy as np
import itertools

# 距離の2乗
def dist_sq(vec):
    return vec[0]**2 + vec[1]**2

# 与えられた4点が正方形かをチェック
# 正方形なら面積、そうでなければ-1を返す
def square_area(pts):
    a = pts[0]
    for idx in list(itertools.permutations([1,2,3])):
        b,c,d =  [pts[idx[i]] for i in range(3)]

        # 辺の向きを表すベクトル
        vb,vc = b-a,c-a

        # 辺abと辺acは直角
        if np.dot(vb,vc) != 0:
            continue

        # 辺abと辺acの長さは等しい
        if dist_sq(vb) != dist_sq(vc):
            continue

        # adが対角線になる
        if np.any(b + vc - d != 0):
            continue

        return dist_sq(vb)

    return -1

def solve():
    l = list(map(int,input().split()))

    point = []
    for i in range(8):
        point.append(np.array([l[2*i], l[2*i+1]]))

    for idx in list(itertools.combinations(range(8),4)):
        s1,s2 = [],[]
        for i in range(8):
            if i in idx:
                s1.append(point[i])
            else:
                s2.append(point[i])

        S1,S2 = square_area(s1),square_area(s2)

        # 答えが見つかったので終了
        if S1 > 0 and S2 > 0:
            print(min(S1,S2), max(S1,S2))
            return

    assert(False)

def main():
    for _ in range(int(input())):
        solve()

if __name__ == '__main__':
    main()
