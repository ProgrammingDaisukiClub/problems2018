# Description

P子さんは動物を $N$ 種類知っています。
P子さんが知っている $i$ 番目の種類の名前は $s_i$です。

P子さんは動物園に来ました。園内を回って、順番に $M$ 匹の動物を見ました。$i$ 番目に見た動物の種類の名前は $t_i$です。

各動物 $t_i$ に対して、P子さんが

* その動物を知っており、初めて見た時には `kawaii`
* その動物を知っているが、既に1回以上見ている時には `moumita`
* その動物を知らない時は `siranai`

と言うことが分かっているので、P子さんが、何と言ったかを再現せよ(**スペルに注意**)。
ただし、動物園で知らない動物を見たとしても、P子さんの知っている動物の種類が増えないことに注意せよ。仮に知らない動物を見たとして、それ以降もう一度同じ動物を見たとしてもP子さんは `siranai` と答える(Sampleも参照)。

# Constraints

* $1 \leq N \leq 100$
* $1 \leq M \leq 100$
* $s_i , t_i$ は英小文字のみで構成され、20文字以下
* 知っている動物 $N$ 種類の名前はすべて異なる ( $s_i \neq s_j, i \neq j$ )
* テストケース数 $T$ について、Smallは $T=10$、Largeは$T=50$

# Input
1つの入力ファイルは複数のテストケースからなる。

入力ファイルの最初の1行目にはテストケースの個数 $T$ が記される $(1 \leq T \leq 50)$。

2行目以降には、$T$ 個のテストケースが記述されており、各テストケースは次の形式で表される。

```
$N$
$s_1$
$\vdots$
$s_N$
$M$
$t_1$
$\vdots$
$t_M$
```

# Output
各テストケースに対して、出力は $M$行からなる。
$i$ 行目に $t_i$ を見た時のP子さんの発言を1行ずつ出力せよ。


# Sample Input
```
3
6
panda
koala
tasmaniantiger
wombat
wallaby
tasmaniandevil
10
panda
koala
panda
koala
tasmaniantiger
wombat
dingo
wallaby
wombat
tasmaniandevil
2
cat
dog
3
cat
cat
cat
1
angel
4
human
human
human
human
```

# Sample Output
```
kawaii
kawaii
moumita
moumita
kawaii
kawaii
siranai
kawaii
moumita
kawaii
kawaii
moumita
moumita
siranai
siranai
siranai
siranai
```

2ケース目で、P子さんはcatを知っているので、初めて見た時には `kawaii` と発言するが、2回目以降は `moumita` と発言する。

3ケース目で、P子さんはangelしか知らないので、humanを何度見ても `siranai` と発言する。このように、動物園で見た動物が新たに知っている動物にならないことに注意せよ。
