# Description

もふふ大学のカトー先生は講義でペアプログラミングを教えています。
これは受講者を2人1組にして一緒にプログラミングさせるものであり、学科の中でも群を抜く人気科目です。
カトー先生の唯一の悩みはペアを作れずに余ってしまう学生がいることでした。

講義は全部で$N$回行われます。
この講義は非常に人気なので、$i$回目の受講者数は$i - 1$回目の受講者数から$A_i$人増加しています。
$i - 1$回目までの受講者が$i$回目にいなくなることはありません。
なお、$0$日目の受講者数は$0$人であると見なせます。

つまり、$i$回目の講義の受講者数は$A_1 + A_2 + \ldots + A_i$です。

$N$回の講義それぞれについて、その回の受講者をできるだけ多くの2人組にしたとき、余ってしまう受講者の人数を求めてください。

# Constraints

* $1 \leq N \leq 10^3$
* $0 \leq A_i \leq 10^3$ $(1 \leq i \leq N)$
* 入力中のすべての値は整数である。

# Input
1つの入力ファイルは複数のテストケースからなる。

入力ファイルの最初の1行目にはテストケースの個数$T$が記される $(1 \leq T \leq 100)$。

2行目以降には、$T$個のテストケースが記述されており、各テストケースは次の形式で表される。

```
$N$
$A_1$ $A_2$ $\ldots$ $A_N$
```

# Output
各テストケースに対して、各講義で余る受講者の人数を1行ずつ出力せよ。

# Sample Input

```
2
3
5 2 9
5
0 0 0 0 0
```

# Sample Output

```
1
1
0
0
0
0
0
0
```

入力例は$2$個のテストケースからなります。

$1$個目のテストケースでは、講義は$3$回行われます。
$1$回目の受講者数は$5$人なので、2人組を作ると$1$人余ります。
$2$回目には$2$人増加して合計$7$人になるので、また$1$人余ります。
$3$回目には合計$16$人になるので余りは$0$人になります。

$2$個目のテストケースでは、講義は$5$回行われます。
このように、受講者数が増加しない場合もあります。