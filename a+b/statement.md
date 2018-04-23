# Description

2つの整数 $A, B$ の和を求めよ。

なお、この問題は入出力の練習のために用意されている。
問題の末尾にサンプルプログラムなどが示されているので、参考にせよ。

# Constraints

* $A, B$ は整数
* $-5000 \leq A, B \leq 5000$

# Input
1つの入力ファイルは複数のテストケースからなる。

入力ファイルの最初の1行目にはテストケースの個数 $T$ が記される $(1 \leq T \leq 50)$ 。

2行目以降には、$T$ 個のテストケースが記述されており、各テストケースは次の形式で表される。

```
$A$ $B$
```

# Output
各テストケースに対して、$A+B$ を1行ずつ出力せよ。

# Sample Input
```
3
1 2
-4 2
-100 100
```

# Sample Output
```
3
-2
0
```

# Sample Programs

## C

```
#include &lt;stdio.h&gt;

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0){
        int a, b;
        scanf("%d %d", &a, &b);
        int answer = 0; // EDIT HERE
        printf("%d\n", answer);
    }
    return 0;
}
```

## Java

```
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0; i < n; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(0); // EDIT HERE
        }
        sc.close();
    }
}
```

# Answer Book

## C

* コンパイル・実行 (C)

```
gcc main.c
./a.out
```

コンパイルでは必要に応じて、``-O2``や``-Wall``などのコンパイルオプションを使用するとよいかもしれない。

* ファイルから入力する

```
./a.out < in.txt
```

* ファイルへ出力する

```
./a.out > out.txt
```

* ファイル入出力を同時に行う

```
./a.out < in.txt > out.txt
```

## Java

* コンパイル・実行

```
javac Main.java
java Main
```

* ファイルから入力する

```
java Main < in.txt
```

* ファイルへ出力する

```
java Main > out.txt
```

* ファイル入出力を同時に行う

```
java Main < in.txt > out.txt
```

## C++ / Python / Ruby / 他

上記を参考に、自分で調べてください。
