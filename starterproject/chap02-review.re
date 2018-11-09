= Re:VIEWサンプル

//lead{
章の概要説明は、このように「//lead{ ... //}」で囲みます。
海外の本によくある、ほかの本からの引用を冒頭に置く場合も、これを使うといいでしょう。
//}


== フォーマット

詳しくは
https://github.com/kmuto/review/blob/master/doc/format.ja.md
を参照してください。


=== コメント

行コメントは「#@#」です。ただし行頭でしか使えません。
#@# たとえばこの行は行コメントになるので、PDFには現れません。

範囲コメント（HTMLの「<!-- -->」やCSSの「/* */」に相当するもの）はありません。


==={chapsec} 章と節

章（チャプター）は「= 」で始め、節（セクション）は「== 」で始め、小節（サブセクション）は「=== 」で始めます。ただしRe:VIEWでは、章（チャプター）ごとにファイルを分割することに注意してください。1つのファイルに複数の「= 」を含めることもできますが、お勧めしません。

節（セクション）や小節（サブセクション）に「=={chapsec} 」のようなラベルをつけると、他の場所から「@<hd>{chapsec}」のように参照できます。ラベルをつけない場合は、「@<hd>{フォーマット|コメント}」のように節タイトルや小節タイトルをつなげて階層を明示します。

章（チャプター）を参照する場合は、ラベルではなくファイル名を使います@<fn>{xt9q}。たとえばファイル名が「chap01-intro.re」なら、その章は「@<chapref>{chap01-intro}」や「@<chap>{chap01-intro}」で参照できます。
//footnote[xt9q][これが、1つのファイルに複数の章（チャプター）を含めるのを勧めない理由です。]


=== 箇条書き

 * 「* 」で始めると番号なし箇条書き
 * 行頭に半角空白が必要なことに注意
 ** 入れ子は「** 」や「*** 」にする（インデントはしない）

 1.「1. 」「2. 」…で始めると番号つき箇条書き
 2. 行頭に半角空白が必要なことに注意
 3. 「* 」と違って、入れ子にできないことに注意（え〜！）
 4. 「a. 」「b. 」…で始めても、アルファベットにならないことに注意（え〜！）

間違えやすいので繰り返しますが、@<strong>{行頭に半角空白が必要}です。

* 行頭の半角空白がないと、このように箇条書きにはなりません。


=== 定義リスト



=== コード

コードは「//list[ID][説明][言語名]{」と「//}」で囲みます（[説明]と[言語名]は省略可能）。コードには「リストX.X」のような番号がつき、たとえば「@<list>{fibo}」のように参照できます。

//list[fibo][フィボナッチ数列][ruby]{
def fib(n)
  return n <= 1 ? n : fib(n-1) + fib(n-2)
end
//}

番号をつける必要がない場合は「//emlist[説明][言語名]{」と「//}」で囲みます（[説明]と[言語名]は省略可能）。コードに「リスト1.2」のような番号をつけたくない場合に使います。

//emlist{
## フィボナッチ数列
def fib(n)
  return n <= 1 ? n : fib(n-1) + fib(n-2)
end
//}

行番号をつけるには、「//list」や「//emlist」のかわりに「//listnum」や「//emlistnum」を使います。

//listnum[fibo2][フィボナッチ数列][ruby]{
def fib(n)
  return n <= 1 ? n : fib(n-1) + fib(n-2)
end
//}

//emlistnum{
## フィボナッチ数列
def fib(n)
  return n <= 1 ? n : fib(n-1) + fib(n-2)
end
//}

なお、コードの[説明]は省略するけど[言語名]は指定したい場合は、「//emlist[言語名]」ではなく「//emlist[][言語名]」と書きます。このとき、Re:VIEWのバグにより本文とコードとの間に余計な空行が入ってしまいますが、starterではLaTeXマクロを上書きしてこの症状を回避しています。


=== 画像

「images」ディレクトリに置いた画像ファイル（PNG、JPG、GIF）を、本文に取りこめます。そのためには「//image[ファイル名][説明文字列][倍率]」と書きます。ファイル名には拡張子をつけません。また[説明文字列]と[倍率]は省略できます。

次の例では、倍率を指定せずに画像を取りこんでいます。今回は本文の幅より画像の幅のほうが大きいので、本文の幅にあうように画像が縮小されています。

//image[example2][サンプル画像（倍率指定なし）]

次の例では、倍率として「0.5」を指定しています。この場合、画像の幅は本文の幅の半分になります。もとの画像の幅の半分ではないことに注意してください。

//image[example3][サンプル画像（倍率0.5倍）][scale=0.5]

同じ章（チャプター）の画像を参照するには、たとえば「@<img>{example2}」とします。他の章の画像を参照するには、章IDを使ってたとえば「@<img>{chap01-intro|example1}」とします。

章（チャプター）ごとに画像フォルダを分けられます。それには「images/chap01-intro」「images/chap02-review」のようにサブフォルダを作り、そこに画像を格納します。Re:VIEWはコンパイル時に、まず章ごとのサブフォルダ内で画像を検索し、なければimagesフォルダを検索します。

印刷用には、高解像度の画像を用意したほうがいいでしょう。詳しくは「ワンストップ！技術同人誌を書こう」第8章を参照してください。


=== 文字装飾

(TODO)


=== 脚注

(TODO)


=== コラム

(TODO)


=== 表

(TODO)


=== リンク

(TODO)


=== 引用

(TODO)


=== インデント、改行、改ページ

(TODO)


=== Rawデータ

(TODO)


=== 独自命令

Re:VIEWでは、ファイル「review-ext.rb」を用意すると、独自の命令を用意できます。命令には、「//list{...}」のようなブロック命令と、「@<code>{...}」のようなインライン命令の2種類があります。今回はすでにreview-ext.rbが用意されているので、参考にしてください。使用例は次の通り。

改ページ（インライン命令）：
@<clearpage>{}

右寄せ：
//textright{
aaa

bbb

ccc
//}

中央揃え：
//textcenter{
xxx

yyy

zzz
//}
