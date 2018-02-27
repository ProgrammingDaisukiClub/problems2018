# Problems2018
Problems for Waseda CS orientation 2018

# Past Problems

* [2017](https://github.com/AI-comp/Problems2017)
* [2016](https://github.com/AI-comp/Orientation2016Problems) - 2015,2014と問題の重複あり．
* [2015](https://github.com/AI-comp/Orientation2015Problems)
* [2014](https://github.com/AI-comp/Orientation2014Problems) - [順位表](https://drive.google.com/file/d/0BzlMTVLOBnPmN25pWFBYbXN5STA/view?usp=sharing)

## How to Solve and Test Problems

1. [rime](https://github.com/icpc-jag/rime)をインストール
```
pip install git+https://github.com/icpc-jag/rime
```

2. 解く問題のディレクトリ名を確かめ，以下を実行．この際，``solution_name``は既存のものと被らなければ自由に設定可能．
```
rime add <problem_dir_name> solution <solution_name>
```

3. 既定のエディタで`SOLUTION`ファイルが開く．このファイルが解法の設定ファイル．今から作る解法のファイル名やコンパイルオプション等を設定する．（分からない場合は問題`a+b`に複数の言語での設定があるので参考にしてください．）

4. `<problem_dir_name>/<solution_name>` ディレクトリ内に解答を作成．

5. `rime test -j N` コマンドでジャッジを実行．（`N`は並列ジョブ数．）
プロジェクトのルートで実行すれば，全問題に対するジャッジが走る．問題のディレクトリ内で実行すれば，その問題だけのジャッジが走る．解法のディレクトリ内で実行すれば，その解法だけのジャッジが走る．

他にもrimeの機能はあるので，詳しく知りたい場合はこちら： https://rime.readthedocs.io/ja/latest/
