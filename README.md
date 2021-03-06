# 入門Puppet

antipopがPuppet勉強のためにがんばって調べながら書く『入門Puppet(仮)の』epub/mobi本執筆用リポジトリです。このリポジトリが見える方々は、レビューや助言、執筆参加よろしくおねがいいたします(^o^)/

「naoyaさんのChef本の構成をパクって章立てします」とかいってたけど、だいぶ違うものになった。

## 目次

  1.  はじめに
  2.  なぜPuppetが必要なのか？
  3.  本書の方針
  4.  Vagrantで開発環境を用意する
  5.  Hello, Puppet!
  6.  nginxのmanifestを書く
  7.  パッケージをインストールする - package
  8.  yumリポジトリを登録する - yumrepo
  9.  サービスを起動する - service
  10. ファイルやディレクトリを作成する - file
  11. ユーザやグループを作成する - user/group
  12. 任意のコマンドを実行する - exec
  13. td-agentのmanifestを書く
  14. resource typeのグルーピング - class
  15. manifestに関連するファイルをまとめる - module
  16. サーバの役割を定義する Part.1
  17. サーバの役割を定義する Part.2
  18. manifestの共通部分をくくりだす
  19. 最低限必要なPuppet言語の構文を学ぶ
  20. システム状態をテストする - serverspec
  21. リモートホストに対してmanifestを適用する
  22. 再び、なぜPuppetが必要なのか？
  23. おわりに

## 事前準備

  1. [calibre](http://calibre-ebook.com/)をインストール
  2. calibreの設定画面から、コマンドラインツールをインストールする
  3. 確認用にKindleアプリ([Mac版](http://www.amazon.com/gp/feature.html?ie=UTF8&docId=1000464931))を入れておくとよいでしょう
    * HTML, epubも出力するので、そちらで確認もできます。
  4. `bundle install`を実行

## 書き方

  1. `ja/*.md`に書く(連番で)

## 書籍ファイルの作り方

  1. `rake`と、引数なしで実行
  2. `open puppet-book.拡張子`して確認
    * HTML, epub, mobi版があります。

用意されているrakeタスクを見るには、`rake -T`を実行してください。

## Thanks to

naoyaさんはいいひとだな〜。

  * https://twitter.com/naoya_ito/status/312557007326572544
  * https://twitter.com/naoya_ito/status/312558894041923584
  * https://twitter.com/naoya_ito/status/312559368774221824
