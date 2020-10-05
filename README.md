> Wifi: `networkmanager-openrc`  `iwd-openrc`

> Openrc: https://wiki.artixlinux.org/Main/OpenRC#Installation_of_services
### init

［Prerequisites］:

```bash
sudo pacman -S git which openssh make gcc ruby nodejs npm neovim chromium latte-dock dolphin
```
［`zsh`］:

```bash
sudo pacman -S zsh 
chsh -s $(which zsh)
```

［`n`](https://github.com/tj/n): 

```bash
npm i -g n
sudo pacman -Rns nodejs npm 
n lts
```
[ssh init]:
```bash
ssh-keygen -t rsa -b 4096 -C "zpharnoex@gmail.com"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
```
> Add the SSH key GitHub
[`dotdotdot`]:
```bash
mkdir repo | cd $_
git clone git@github.com:beetcb/dotdotdot.git
cd dotdotdot
./install
```
[shell]
- [Dracula](https://draculatheme.com/konsole)
- [`pure`](https://github.com/sindresorhus/pure)
- [`zplug`](https://github.com/zplug/zplug)
- [`vim-plug`](https://github.com/junegunn/vim-plug)
- [`colorls`](https://github.com/athityakumar/colorls)

### Surface kernel & Grub boot
[Linux-Surface](https://github.com/linux-surface/linux-surface/wiki/Installation-and-Setup)

[GRUB change Kernel](https://wiki.archlinux.org/index.php/GRUB_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)/Tips_and_tricks_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)#%E5%A4%9A%E4%B8%AA%E5%90%AF%E5%8A%A8%E6%9D%A1%E7%9B%AE)

```bash
sudo pacman -S linux-surface-headers linux-surface surface-ipts-firmware iptsd
sudo grub-mkconfig -o /boot/grub/grub.cfg
```

### Bluetooth


### Chinese fonts & emoji

[Chinese Font](https://wiki.archlinux.org/index.php/Localization_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)/Simplified_Chinese_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))
```bash
sudo pacman -S wqy-microhei
```
[Emoji]
```bash
sudo pacman -S noto-fonts-emoji
```
[pinyin]
```bash
sudo pacman -S fcitx-im fcitx-configtool

# {warning}: this will rewrite .xprofile
echo "export GTK_IM_MODULE=fcitx \nexport QT_IM_MODULE=fcitx \nexport XMODIFIERS="@im=fcitx"" > ~/.xprofile
```
