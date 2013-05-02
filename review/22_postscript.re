
= おわりに


筆者の勤務先は、大規模なホスティング事業を、その収益の柱のうちのひとつとして行っています。大量のサーバをいかに効率よく扱えるかは、事業の成否に直結する重要な技術的前提となります。そのため、早い段階からPuppetやChefを高度に使いこなし、サービス運営を行ってきました。


ホスティング事業にとっては、ユーザに提供するサーバそのものが、Webサービスにおけるアプリケーションのようなものであるともいえます。となると、Webアプリケーションをプログラムするのと同様の感覚でもって、ユーザに直接価値を提供するサーバの構築を「コード」化したいという欲求は、自然なものであるといえるでしょう。


筆者は、現在の勤務先に移ってくるまで、PuppetやChefについて、その存在はもちろん知ってはいたものの、正直いってほとんど興味がありませんでした。以前の勤務先でもPuppetやChefは高度に使われてはいたのですが、オペレーションエンジニアまかせにして、自分で触るということはほとんどありませんでした。


しかし、@<href>{https://github.com/mizzy/maglica,maglica}(前述serverspecの開発者・宮下剛輔氏による)という、パーソナルクラウドツールとでもいうべきツールを前提とした開発環境や社内ツールの整備を行っていったり、AWS等のクラウドを積極的に使っているうちに、これは自分のいままでのやり方を変えてなんとかしないとおいつかないなと自覚し、PuppetやChefの学習を始めたのでした。


本書は、そのような環境に飛び込んでくるエンジニアのための研修資料として企画・作成されたものです。Puppetに関するドキュメントは公式サイトに充実していますが、当然すべて英語で書かれたものですし、その分量の多さゆえに、初学者にとってはどこから手をつけたらいいのか悩ましいでしょう。また、「第2章 本書の方針」で述べたような、類書にはない新しい観点からPuppetの入門を書いてみたいという気持ちもありました。


本書は「はじめに」で、以下の目標を掲げました。

//quote{
本書の目標は、この本を読んだ読者がPuppetの基本についてひととおり知り、オペレーションエンジニアの書いたmanifest(サーバのあるべき状態を記述した設定ファイルのようなもの。後述)に変更を加えたり、ある程度の規模のものなら自力でいちから書けるようになったりすることです。
//}


本書をここまで読んでこられた読者が、実際に知識を身につけることができ、今後さらに進んだ実践に取り組んでいく一助になれたとしたら幸いです。


最後になりましたが、本書執筆においてお世話になった方々のお名前を挙げることで、謝辞にかえたいと思います。


まずは、本書に結実した内容について、日々の業務を通して知見を与えてくださったり、レビュワーをつとめてくださったりした同僚の宮下剛輔、柴田博志、黒田良、伊藤洋也、常松伸哉、長谷川浩平、吉田真世登、黒瀧悠太の各氏。

野田達也、内藤建の各氏には、たくさんの誤字・脱字などを指摘、修正していただきました。

本書のカバーは、「@<href>{http://iroirodesign.com/,いろいろデザイン}」の長山武史氏にデザインしていただきました。


伊藤直也氏は、「『入門Chef Solo』の姉妹本といった体裁でPuppetについての本を書きたいのですが、どうでしょう」という不躾なお願いを快く許可してくださった上に、貴重なレビューもたくさんいただきました。


2013年5月 栗林健太郎 (@<href>{http://kentarok.org/,http://kentarok.org/})
