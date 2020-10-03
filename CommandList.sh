# [dd]
lsblk
dd bs=4M if=/path/to/archlinux.iso of=/dev/sdx status=progress && sync

# [wifi connection]
ip a
rfkill unblock wifi
ip link set mlan0 up
connmanctl 
scan wifi
services
agent on
connect xxx
####type passwd####
exit

# [check time]
timedatectl set-ntp true

# [Partition & Format & Mount]
cfdisk /dev/nvme0n1

mkfs.fat /dev/nvme0n1p1
mkfs.ext4 /dev/nvme0n1p2

mount /dev/nvme0n1p2 /mnt
mount /dev/nvme0n1p1 /mnt/boot/efi

# [config mirrorlist]
...

# [init with `pacstrap`]
basestrap /mnt base base-devel openrc linux linux-firmware plasma iwd neovim intel-ucode grub efibootmgr konsole nerworkmanager-openrc bluedevil bluez-openrc sddm-theme-artix  artix-grub-theme artix-dark-theme artix-branding-base
 
# [chroot]
fstabgen -U /mnt >> /mnt/etc/fstab
artools-chroot /mnt

# [timezone]
ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
hwclock --systohc

# [locale]
nvim /etc/locale.gen
locale-gen 
nvim /etc/locale.conf # LANG=en_US.UTF-8

# [host related]
nvim /etc/hostname # be
nvim /etc/hosts # 127.0.0.1	localhost ::1		localhost 127.0.1.1	be.localdomain	be  199.232.4.133 raw.githubusercontent.com

# [Initramfs]
mkinitcpio -P

# [user]
passwd # ...
useradd -m -G wheel beet
passwd beet
nvim /etc/sudoers # uncummnet whell all

# [grub]
grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=GRUB
grub-mkconfig -o /boot/grub/grub.cfg 
sync 

# [sddm]
pacman -S displaymanager-openrc sddm
nvim /etc/conf.d/xdm        <- edit and set DISPLAYMANAGER="sddm"


# [🐈]
rc-update add xdm default
rc-update add NetworkManager default
rc-update add bluetoothd default

exit
umount -R /mnt
reboot
