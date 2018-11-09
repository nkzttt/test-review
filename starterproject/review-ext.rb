# -*- coding: utf-8 -*-

##
## Re:VIEWを拡張し、インライン命令とブロック命令を追加する
##


module ReVIEW

  ## インライン命令「@<clearpage>{}」を宣言
  Compiler.definline :clearpage         ## 改ページ

  ## ブロック命令「//textleft{ ... //}」等を宣言
  ## （ここでは第2引数が「0」なので、引数なしのブロック命令になる。
  ##   もし第2引数が「1..3」なら、//listのように必須引数が1つで
  ##   非必須引数が2という意味になる。）
  Compiler.defblock :textleft, 0        ## 左寄せ
  Compiler.defblock :textright, 0       ## 右寄せ
  Compiler.defblock :textcenter, 0      ## 中央揃え


  ## LaTeX用の定義
  class LATEXBuilder

    ## 改ページ
    def inline_clearpage(str)
      '\clearpage'
    end

    ## 左寄せ
    def textleft(lines)
      puts '\begin{flushleft}'
      puts lines
      puts '\end{flushleft}'
    end

    ## 右寄せ
    def textright(lines)
      puts '\begin{flushright}'
      puts lines
      puts '\end{flushright}'
    end

    ## 中央揃え
    def textcenter(lines)
      puts '\begin{center}'
      puts lines
      puts '\end{center}'
    end

  end


  ## HTML（ePub）用の定義
  class HTMLBuilder

    ## 改ページはHTMLにはない
    def inline_clearpage(str)
      puts '<p></p>'
      puts '<p></p>'
    end

    ## 左寄せ
    def textleft(lines)
      puts '<div style="text-align:left">'
      puts lines
      puts '</div>'
    end

    ## 右寄せ
    def textright(lines)
      puts '<div style="text-align:right">'
      puts lines
      puts '</div>'
    end

    ## 中央揃え
    def textcenter(lines)
      puts '<div style="text-align:center">'
      puts lines
      puts '</div>'
    end

  end


end
