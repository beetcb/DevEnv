### Pin Yin
> - register `computer\HKEY_CURRENT_USER\Software\Microsoft\InputMethod\Settings\CHS`
> - String name `UserDefinedDoublePinyinScheme0`
> - String value `小鹤双拼*2*^*iuvdjhcwfg^xmlnpbksqszxkrltvyovt`


> debloater window10 powershell script:
  - [cdn](https://cdn.jsdelivr.com/gh/Sycnex/Windows10Debloater/Windows10SysPrepDebloater.ps1)
  - [Github README](https://github.com/Sycnex/Windows10Debloater)


### window terminal profile

```js
// This file was initially generated by Windows Terminal Preview 1.2.2234.0
// It should still be usable in newer versions, but newer versions might have additional
// settings, help text, or changes that you will not see unless you clear this file
// and let us generate a new one for you.
// To view the default settings, hold "alt" while clicking on the "Settings" button.
// For documentation on these settings, see: https://aka.ms/terminal-documentation
{
  "$schema": "https://aka.ms/terminal-profiles-schema",
  "defaultProfile": "{a5a97cb8-8961-5535-816d-772efe0c6a3f}",
  // You can add more global application settings here.
  // To learn more about global settings, visit https://aka.ms/terminal-global-settings
  // If enabled, selections are automatically copied to your clipboard.
  "copyOnSelect": true,
  // If enabled, formatted data is also copied to your clipboard
  "copyFormatting": false,
  // A profile specifies a command to execute paired with information about how it should look and feel.
  // Each one of them will appear in the 'New Tab' dropdown,
  //   and can be invoked from the commandline with `wt.exe -p xxx`
  // To learn more about profiles, visit https://aka.ms/terminal-profile-settings
  "profiles": {
    "defaults": {
      "acrylicOpacity": 0.88,
      "closeOnExit": true,
      "colorScheme": "Dracula",
      "fontFace": "Hack NF",
      "fontSize": 16,
      "useAcrylic": true,
      "startingDirectory": "//wsl$/Arch/home/be"
    },
    "list": [
      {
        // Make changes here to the powershell.exe profile.
        "guid": "{61c54bbd-c2c6-5271-96e7-009a87ff44bf}",
        "name": "Windows PowerShell",
        "commandline": "powershell.exe",
        "hidden": false
      },
      {
        // Make changes here to the cmd.exe profile.
        "guid": "{0caa0dad-35be-5f56-a8ff-afceeeaa6101}",
        "name": "命令提示符",
        "commandline": "cmd.exe",
        "hidden": false
      },
      {
        "guid": "{a5a97cb8-8961-5535-816d-772efe0c6a3f}",
        "hidden": false,
        "name": "Arch",
        "source": "Windows.Terminal.Wsl"
      },
      {
        "guid": "{b453ae62-4e3d-5e58-b989-0a998ec441b8}",
        "hidden": false,
        "name": "Azure Cloud Shell",
        "source": "Windows.Terminal.Azure"
      }
    ]
  },
  // Add custom color schemes to this array.
  // To learn more about color schemes, visit https://aka.ms/terminal-color-schemes
  "schemes": [
    {
      "name": "Dracula",
      "background": "#272935",
      "black": "#21222C",
      "blue": "#BD93F9",
      "cyan": "#8BE9FD",
      "foreground": "#F8F8F2",
      "green": "#50FA7B",
      "purple": "#FF79C6",
      "red": "#FF5555",
      "white": "#F8F8F2",
      "yellow": "#FFB86C",
      "brightBlack": "#6272A4",
      "brightBlue": "#D6ACFF",
      "brightCyan": "#A4FFFF",
      "brightGreen": "#69FF94",
      "brightPurple": "#FF92DF",
      "brightRed": "#FF6E6E",
      "brightWhite": "#F8F8F2",
      "brightYellow": "#FFFFA5"
    }
  ],
  // Add custom keybindings to this array.
  // To unbind a key combination from your defaults.json, set the command to "unbound".
  // To learn more about keybindings, visit https://aka.ms/terminal-keybindings
  "keybindings": [
    // Copy and paste are bound to Ctrl+Shift+C and Ctrl+Shift+V in your defaults.json.
    // These two lines additionally bind them to Ctrl+C and Ctrl+V.
    // To learn more about selection, visit https://aka.ms/terminal-selection
    {
      "command": {
        "action": "copy",
        "singleLine": false
      },
      "keys": "ctrl+c"
    },
    {
      "command": "paste",
      "keys": "ctrl+v"
    },
    // Press Ctrl+Shift+F to open the search box
    {
      "command": "find",
      "keys": "ctrl+shift+f"
    },
    // Press Alt+Shift+D to open a new pane.
    // - "split": "auto" makes this pane open in the direction that provides the most surface area.
    // - "splitMode": "duplicate" makes the new pane use the focused pane's profile.
    // To learn more about panes, visit https://aka.ms/terminal-panes
    {
      "command": {
        "action": "splitPane",
        "split": "auto",
        "splitMode": "duplicate"
      },
      "keys": "alt+shift+d"
    }
  ]
}

```
### wsl 

- Prerequisites:

```bash
sudo pacman -S git which openssh make gcc ruby nodejs npm 
```

- `zsh`:

```bash
sudo pacman -S zsh 
chsh -s $(which zsh)
```

- `n`: 

```bash
npm i -g n
sudo pacman -Rns nodejs npm 
n lts
```
- `dotdotdot`
- neovim \ zplug \ vim-plug \ colorls \ pure



### autohotkey
```bash
;;;hotStr use `,,` as suffix
:*:pwgit,,::xx
:*:@,,::zpharno@163.com
:*:159,,::111111
:*:pw,,::1414
;;;CapsLock to ctrl
+CapsLock::CapsLock
CapsLock::Ctrl
;;;Alt+hjkl => direction key
!h::
    Send, {Left}
    Return
!j::
    Send, {Down}
    Return
!k::
    Send, {Up}
    Return
!l::
    Send, {Right}
    Return
```


### Surface kernel & Grub boot

https://wiki.archlinux.org/index.php/GRUB_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)/Tips_and_tricks_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)#%E5%A4%9A%E4%B8%AA%E5%90%AF%E5%8A%A8%E6%9D%A1%E7%9B%AE

```bash
sudo pacman -S linux-surface-headers linux-surface surface-ipts-firmware iptsd
sudo grub-mkconfig -o /boot/grub/grub.cfg
```

### Bluetooth
```bash
systemctl enable bluetooth.service  and
systemctl start bluetooth.service
```

### Chinese fonts & emoji

```bash
# https://wiki.archlinux.org/index.php/Localization_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)/Simplified_Chinese_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)
sudo pacman -S noto-fonts-emoji
```
