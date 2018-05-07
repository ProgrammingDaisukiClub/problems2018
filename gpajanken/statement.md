# Description
GPA JANKENとは
「じゃんけんをして、じゃんけんの結果に関わらずGPAが高い方が問答無用で勝ち」
というルールのゲームです。
GPAが同じ場合引き分けになります。
（ここでいうGPAとはGanbari Point Accumulateの略で、0から4のいずれかの整数です。）

カトー君とサトー君がGPA JANKENをしました。
カトー君のGPAは$A$、サトー君のGPAは$B$です。
カトー君が勝った場合`KATO`、サトー君が勝った場合`SATO`、引き分けの場合`DRAW`と出力してください。

# Constraints
 - $0 \leq A \leq 4$
 - $0 \leq B \leq 4$
 - $A$ $B$は整数

# Input
1つの入力ファイルは複数のテストケースからなる。

入力ファイルの最初の1行目にはテストケースの個数 $T$ が記される $(1 \leq T \leq 100)$。

2行目以降には、$T$個のテストケースが記述されており、各テストケースは次の形式で表される。

```
$A$ $B$
```

# Output
各テストケースに対して、GPA JANKENの結果を1行ずつ出力せよ。

# Sample Input
```
3
2 3
4 3
0 0
```

# Sample Output
```
SATO
KATO
DRAW
```
