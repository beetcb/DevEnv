### rc surface pro 6
> 首先需要改变一下微软拼音的双拼方案
> - 找到注册表 `计算机\HKEY_CURRENT_USER\Software\Microsoft\InputMethod\Settings\CHS`
> - 新建字符串 `UserDefinedDoublePinyinScheme0`
> - 修改其值为 `小鹤双拼*2*^*iuvdjhcwfg^xmlnpbksqszxkrltvyovt`

> win10预装了许多没用的软件，所以我倾向使用一个开源的powershell脚本移除它们，下载地址[cdn](https://cdn.jsdelivr.com/gh/Sycnex/Windows10Debloater/Windows10SysPrepDebloater.ps1)
[Github README](https://github.com/Sycnex/Windows10Debloater)
---
#### list of tools 使用`chocolatey`做安装

- **GUI (Graphical User Interface)**

  - `firefox`
  
  - `chrome`

  - `quicklook`[cinst]
  
  - `7zip`[cinst]

  - `windows terminal`[ms store]

  - `clash for windows`[github]

  - `photoshop`[local]

  - `tianruo ocr`

  - `vlc media player`[cinst]

  - `vs code`

  - less important

    - `obs studio`
    - `Ableton Live` [local]
    
- **CLI (Command-line Interface) in wsl** & **dev environment=> in wsl** 

  - `git`
  - `scrcpy`[outside wsl]
  - `nodejs` (and `nrm` `yarn`) 
  - `neovim`


#### wsl 配置

- 安装：参考官方文档

- 切换阿里源

- update && upgrade

- [挂载其他磁盘](https://docs.microsoft.com/zh-cn/archive/blogs/wsl/file-system-improvements-to-the-windows-subsystem-for-linux)

  ```bash
  sudo mkdir /mnt/d
  sudo mount -t drvfs D: /mnt/d
  # 支持本地磁盘、u盘、网络位置、光驱
  ```

  `取消`

  ```bash
  sudo umount /mnt/d
  ```

- 设置shell环境

  zsh安装成功后，可以不用配置，因为我会使用onmyzsh来配置zsh（会重写zsh配置）

  ```bash
  sudo apt install zsh
  # 安装z shell
  zsh --version
  # 检验安装时候成功 => 期望返回：zsh 5.8 (x86_64-ubuntu-linux-gnu)
  chsh -s $(which zsh)
  # 将z shell设为默认shell，然后重启终端
  $SHELL --version
  # 检验默认shell => 期望返回：zsh 5.8 (x86_64-ubuntu-linux-gnu)
  ```

- 简单配置zsh => 使用onmyzsh

  ```bash
  sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
  # 安装onmyzsh
  ```

  如果联网失败（或者网速极慢），可以考虑使用代理，具体流程如下

  - 安装`proxychains-ng`

    这里采用比较懒惰的方法(不需要安装make版)：[点击查看此源官方包地址](/https://packages.ubuntu.com/search?keywords=proxychains&searchon=names&suite=eoan&section=all)

  ```bash
  sudo apt install proxychains4
  ```

  - 查看主机 IP 

     wsl2 中使用 `localhost` 可以访问 linux 网络应用，但是反过来就不行(详情请阅官方文档)。所以我们首先要获得主机的 IP 地址

  ```bash
  cat /etc/resolv.conf
  # 返回信息中最后一行地址即为所需，假设为 x.x.x.x
  ```
  可以临时设置：
  > export https_proxy="http://x.x.x.x:7890"; export http_proxy="http://x.x.x.x:7890";
  > 但是他的缺点就是不能设置其他linux应用的代理（比如git又需要另外设置代理）

  ​         注意，代理软件需要打开局域网（LAN）访问
  **在`.bashrc`或者`.zshrc`下写入以下简单的内容**
  ```bash
  export localhostIp=$(cat /etc/resolv.conf |grep -oP '(?<=nameserver\ ).*')
  # 读取主机ip地址，因为ip会有变化，所以不能使用固定的ip
  sudo sed -i "115c http ${localhostIp} 7890" /etc/proxychains4.conf
  # 将读取的ip地址替换原有的设置代理的那一行
  ```

  - 食用方法

    只需在需要代理的命令前面加上proxychains4前缀即可连接代理访问（可以自己设置alias简写）

  ```bash
  proxychains4 [commands need proxy]
  ```

  比如刚才的onmyzsh安装命令

  ```bash
  sh -c "$(proxychains4 curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
  ```
  比如使用git

  ![image](https://tva3.sinaimg.cn/large/005K67iLgy1ggyfsjos64j31j70pr1ky.jpg)
就算是vim插件的安装也可以走代理（直接设置http proxy做不到）
  ```bash
  proxychains4 nvim +PlugInstall
  ```
  

  剩下就是一些主题、插件的安装和配置，不详细说了

#### wsl中使用nvim

- 安装nvim（[源包地址]( https://packages.ubuntu.com/focal/neovim）

  ```bash
  sudo apt install neovim 
  ```

- 进入nvim ， 习惯性地 `:checkhealth`
  > 这里报错某个文件没有权限，把权限给它就行了

- 安装 `vim plug` 作为插件管理

  ```bash
  curl -fLo ~/.local/share/nvim/site/autoload/plug.vim --create-dirs \
      https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  ```

- 配置nvim：

  ```bash
  vim ~/.config/nvim/init.vim
  ```



#### nodejs

```bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.35.3/install.sh | bash
# 安装nvm，方便切换版本
nvm ls-remote
列出可用的node version
nvm install v12.18.2 
# install latest LTS
```
使用zsh做shell遇到了command not found的错误， 所以需要编辑 `~./zshrc` 导入下面的代码

```bash
export NVM_DIR="$([ -z "${XDG_CONFIG_HOME-}" ] && printf %s "${HOME}/.nvm" || printf %s "${XDG_CONFIG_HOME}/nvm")"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" # This loads nvm
```



> 附加说明：`nvm ls`  `nvm use` `nvm alias default v10.10.0` 用于切换版本

#### git

安装最新的 git => ubuntu特有

```bash
sudo add-apt-repository -y ppa:git-core/ppa
sudo apt-get update
sudo apt-get install git -y
```

#### windows terminal右键

创建`.reg` 的脚本文件如下，管理员打开

```bash
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;comment 
; beet 需要修改成自己的用户名
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;comment
Windows Registry Editor Version 5.00

[HKEY_CLASSES_ROOT\Directory\Background\shell\wt]
@="Terminal Here"
"Icon"="C:\\Users\\beet\\AppData\\Local\\Microsoft\\WindowsApps\\terminal.ico"
; ico格式的logo图片可以指定自定义路径
; ico logo下载地址=> https://raw.githubusercontent.com/microsoft/terminal/master/res/terminal.ico
[HKEY_CLASSES_ROOT\Directory\Background\shell\wt\command]
@="C:\\Users\\beet\\AppData\\Local\\Microsoft\\WindowsApps\\wt.exe"
```
> 另外还需要给windows terminal配置文件加上 `"startingDirectory": null`
#### alias

- powershell 
  ```bash
  alias ps='powersehll.exe '
  # 方便启用choco
  ```
- proxychains-ng
  ```bash
  alias px='proxychains4'
  alias sudo='sudo ' #防止出现command not found
  ```
