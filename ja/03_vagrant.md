# 第3章: Vagrantで試験環境を用意する

本書では、「はじめに」で述べたように、Puppetの試験環境としてLinux(Amazon LinuxとCentOS)を使用します。といっても、いますぐ手元に、自分の自由になるLinux環境を用意できないという読者も多いでしょう。

そこで、Puppetの実践に入る前に、まずはVagrantというツールを使って、試験環境を用意してみましょう。

### Vagrantとは？

[Vagrant](http://www.vagrantup.com/)は、[VirtualBox](https://www.virtualbox.org/)や[VMware](http://www.vmware.com/)、[Amazon EC2](http://aws.amazon.com/ec2/)といった仮想化ツールを、簡単にコントロールするためのラッパツールです。元々はVirtualBox専用に開発されたものでしたが、本書で使用するバージョン1.1以降は、[Providersという仕組み](http://docs.vagrantup.com/v2/providers/)を導入したことで、プラグインによってVirtulaBox以外の仮想化ツールにも対応するようになりました。

本書では、これまでVagrantでの利用実績が豊富なVirtualBoxを使っていくことにします。

ちなみに、VagrantにはPuppetと連携できる機能があり、仮想ホストの起動時や起動後に、指定した設定をもとにmanifestを適用する仕組みがあります。しかし、本書は現場で使えるPuppet入門を目指しており、より実践的な方法を採るため、その機能は使いません。

### Vagrantのインストール

まずはVirtualBoxをインストールしましょう。[VirtualBoxのダウンロードページ](https://www.virtualbox.org/wiki/Downloads)からお使いの環境にあったパッケージをダウンロードし、インストーラの指示に従ってインストールしてください。

VirtualBoxのインストールが終わったら、今度はVagrantをインストールします。[Vagrantのダウンロードページ](http://downloads.vagrantup.com/)からお使いの環境にあったパッケージをダウンロードしてください。その際、本書の環境と合わせるため、1.1.0以上のバージョンをダウンロードするようにしてください。その後、インストーラの指示に従ってインストールします。

### 仮想ホストの起動

Vagrantで利用できる仮想ホストのひな形(boxといいます)は、有志により様々なディストリビューションのものが提供されています([http://www.vagrantbox.es/](http://www.vagrantbox.es/))。ここでは、CentOS 6.4のものを利用します。

仮想ホストを起動するための設定は、非常に簡単です。適当なディレクトリに、以下の内容のファイルを`Vagrantfile`という名前で作成してください。

```ruby
Vagrant.configure("2") do |config|
  config.vm.box      = "centos-6.4"
  config.vm.box_url  = "http://developer.nrel.gov/downloads/vagrant-boxes/CentOS-6.4-x86_64-v20130309.box"
  config.vm.hostname = "puppet-book.local"
  config.vm.network :forwarded_port, guest: 80, host: 8000
end
```

このファイルでは、以下の設定を行っています。

  * 仮想ホストに使用するbox名
  * boxが存在しなかった場合に取得する先のURL
  * 仮想ホストのhostnameの指定
  * ホストOSの8080番ポートへのアクセスを、仮想ホストの80番ポートに転送する

ファイルを作成したのと同じディレクトリで、`vagrant up`コマンドを実行すると、仮想ホストが起動します。

```
$ vagrant up
Bringing machine 'default' up with 'virtualbox' provider...
[default] Box 'centos-6.4' was not found. Fetching box from specified URL for
the provider 'virtualbox'. Note that if the URL does not havea box for this provider, you should interrupt Vagrant now and addthe box yourself. Otherwise Vagrant will attempt to download the
full box prior to discovering this error.
Downloading with Vagrant::Downloaders::HTTP...
Downloading box: http://developer.nrel.gov/downloads/vagrant-boxes/CentOS-6.4-x86_64-v20130309.boxExtracting box...Cleaning up downloaded box...
Successfully added box 'centos-6.4' with provider 'virtualbox'!
[default] Importing base box 'centos-6.4'...
[default] Matching MAC address for NAT networking...
[default] Setting the name of the VM...
[default] Clearing any previously set forwarded ports...
[default] Fixed port collision for 22 => 2222. Now on port 2205.
[default] Creating shared folders metadata...
[default] Clearing any previously set network interfaces...
[default] Preparing network interfaces based on configuration...
[default] Forwarding ports...
[default] -- 22 => 2205 (adapter 1)
[default] -- 80 => 8000 (adapter 1)
[default] Booting VM...
[default] Waiting for VM to boot. This can take a few minutes.
[default] VM booted and ready for use!
[default] Setting hostname...
[default] Configuring and enabling network interfaces...
[default] Mounting shared folders...
[default] -- /vagrant
```

以下、本書の説明を通じて、`vagrant`コマンドは、`Vagrantfile`のあるディレクトリで実行してください。

初回実行時には、boxをダウンロードするために時間がかかりますが、次回からは既にダウンロードしたboxを使用するため、すぐに起動します。

### 仮想ホストにSSHログインする

以下のコマンドを実行すると、仮想ホストにSSHでログインできます。

```
$ vagrant ssh
```

また、のちの章では通常のsshコマンドによるログインが必要になりますので、以下のようにコマンドを実行して、準備しておいてください。

```
$ vagrant ssh-config --host puppet-book.local >> ~/.ssh/config
```

これで、いつものようにsshコマンドで仮想ホスト(ここではpuppet-book.localというホスト名を指定)にログインできます。

```
$ ssh puppet-book.local
```

ログインしたら、適当にコマンドを実行してみたりして、触ってみてください。ふだん使っているLinuxと変わらない環境が簡単にできてしまったことに、驚くことでしょう。

また、あれこれといじってみた結果、たとえ壊してしまったとしても、後述の通り簡単にリセットして元通りにできますので、安心です。

### 仮想ホストの停止・破棄

仮想ホストを停止するには`halt`サブコマンドを、破棄(リセット)するには`destroy`サブコマンドを使います。

```
$ vagrant halt
```

を実行すると一時停止、

```
$ vagrant destroy
```

で破棄(リセット)されます。再度、仮想ホストを起動したい場合は、最初と同じく

```
$ vagrant up
```

を実行してください。

Vagrantには、上記で紹介したものの他にもたくさんの便利なサブコマンドがありますが、本書の範囲内では、以上で十分です。より詳しく知りたい方は、[Vagrantのドキュメント](http://docs.vagrantup.com/v2/cli/)を参照するとよいでしょう。

### まとめ

本章では、Puppetを実際に使う前段階として、Vagrantを使ってPuppetの試験環境を用意しました。`vagrant up`で起動し、あれこれいじった後に気に入らなくなってきたら`vagrant destroy`でまっさらなんてことも、簡単にできてしまいます。これからPuppetでこの仮想ホストをいじり倒していくには、もってこいの機能です。

これからmanifestを書いていく上で、何度も仮想ホストを作り直していくことになるでしょう。言葉を変えていえば、何度作り直してもmanifestさえあればすぐに元通りになるという状態を作っていくことが、manifestを書くということになるのです。