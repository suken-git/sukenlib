# sukenlib
C++(Dxlib)の数研ライブラリです
http://sukenlibrary.webcrow.jp/sukenlib_reference/index.html

## 環境構築
1. Visual Studio 2010以降のVisual Studio（C++パッケージ込）が必要なのでインストールする。（時間がかかります）
2. DxLibのダウンロードページからVisualC++用のDxLibをダウンロード
http://dxlib.o.oo7.jp/dxdload.html
3. ダウンロードしたexeファイルを実行すると自動でダウンロードしたフォルダ内に「DxLib_VC」フォルダが作成され、そのフォルダの中にDxLibを展開されます。
4. 先ほど作られたフォルダの中にある「プロジェクトに追加すべきファイル_VC用」をコピーしてCドライブ直下に貼り付けます。これで環境構築は終了です。

## SukenLibを使う
1. このページの右上の方にある緑の「clone or download」ボタンを押し、更に「Download ZIP」を選択。これでSukenLibがダウンロードされます。（他の選択肢が分かる人はそれでも可）
2. SukenLibがダウンロードできたら適当なところに解凍する。
3. 「Scripts」フォルダの中の「Suken.sln」を開きます。（コンパイラのアップグレードを聞かれたら「OK」をクリックしてください）
4. ソリューションエクスプローラーの「ソースファイル/Main.cpp」に自分の好きな処理を追加してください。
Awake()は実行時のはじめに一度だけ実行され、GameLoopEnter()は毎フレームSukenLibのシステム処理・描画の前、GameLoopExit()は後に実行されます。

## 参考
- SukenLibリファレンス（未完成）
- http://sukenlibrary.webcrow.jp/sukenlib_reference/index.html
- Dxlibリファレンス
- http://dxlib.o.oo7.jp/dxfunc.html
