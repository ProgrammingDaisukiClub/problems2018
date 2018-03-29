# Problems2018
Problems for Waseda CS orientation 2018

問題案はissueへ！

# Past Problems

* [2017](https://github.com/AI-comp/Problems2017)
* [2016](https://github.com/AI-comp/Orientation2016Problems) - 2015,2014と問題の重複あり．
* [2015](https://github.com/AI-comp/Orientation2015Problems)
* [2014](https://github.com/AI-comp/Orientation2014Problems) - [順位表](https://drive.google.com/file/d/0BzlMTVLOBnPmN25pWFBYbXN5STA/view?usp=sharing)


# Guide for Problem Writers

サンプル問題である `a+b` に，一通り必要な物が揃っているので，これを参考にしてください．

## 準備

* [rime](https://github.com/icpc-jag/rime) インストール

## 新規問題追加

1. 問題ディレクトリの作成（プロジェクトトップで以下実行）．

```
rime add . problem <problem_name>
```

2. その問題の設定ファイル `PROBLEM` が `<problem_name>/` に作成され，エディタで開くので，適当に必要そうなところを編集する．（AtCoder用の項目とかもあるので分からなければ飛ばす）

3. 問題文ファイル `statement.md` を作成して，書く．

4. 必要に応じてwriter解（次の「解の追加」も参照），input generator, input validatorを作る．`PROBLEM` ファイルの `reference_solution` にはwriter解を指定する．

## 解の追加とテスト

1. 解く問題のディレクトリ名を確かめ，以下を実行．この際，``solution_name``は既存のものと被らなければ自由に設定可能．
```
rime add <problem_dir_name> solution <solution_name>
```

2. その解法の設定ファイル `SOLUTION` が `<problem_name>/<<problem_dir_name>` に作成され，エディタで開く．今から作る解法のファイル名やコンパイルオプション等を設定する．（分からない場合は問題`a+b`に複数の言語での設定があるので参考にしてください．）

3. `<problem_dir_name>/<solution_name>` ディレクトリ内に先ほどのファイル名で解答を作成．

4. `rime test -j N` コマンドでジャッジを実行．（`N`は並列ジョブ数．）
プロジェクトのルートで実行すれば，全問題に対するジャッジが走る．問題のディレクトリ内で実行すれば，その問題だけのジャッジが走る．解法のディレクトリ内で実行すれば，その解法だけのジャッジが走る．

> 今回は，`<problem_dir_name>/tests` に全部のテストケースを入れるようにしている．そのディレクトリ内の `*.in` ファイルは入力ファイルとして扱われる．それに対し，同一ファイル名の `*.diff` があれば，それが期待される出力である．`*.diff` ファイルが存在しない場合，`PROBLEM` ファイルの `reference_solution` で指定されたwriter解の出力が，その入力に対する出力ファイルとみなされる．

## Generator, validator作成

* Generatorとは
  * 入力ファイルを生成するプログラム．
* Validatorとは
  * 生成された入力ファイルが，制約を守って正しいフォーマットであることを検証するプログラム．
* outputJudgeとは
  * 完全一致以外が許される出力をチェックし，出力されたものがACか否かをジャッジするプログラム．オリエンでは出力の完全一致のみACとしているので今回は使わない．

説明が面倒なので `a+b` をサンプルに作成してください．

これらの作成に，[testlib](https://github.com/MikeMirzayanov/testlib)（[codeforces上での説明](http://codeforces.com/testlib)）を使おう．（このレポジトリの `/common/testlib.h` が該当ファイルです）

今回，問題の制約で指定する定数群は `constraints.h` に記載し，各generatorやvalidarorが参照するようにしましょう．

他にもrimeの機能はあるので，詳しく知りたい場合はこちら： https://rime.readthedocs.io/ja/latest/ （ただし，リンク先はver.1について述べているけど，rimeは最新はver.2）
