# [dd]
lsblk
dd bs=4M if=/path/to/archlinux.iso of=/dev/sdx status=progress && sync

# [wifi connection]
iwctl # wpa_supplicant / dhcpcd
station wlan1 scan
station wlan1 connect beet-5G
####type passwd####

# [check time]
timedatectl set-ntp true

# [Partition & Format & Mount]
gdisk /dev/nvme0n1

mkfs.fat /dev/nvme0n1p1
mkfs.ext4 /dev/nvme0n1p2

mount /dev/nvme0n1p2 /mnt
mount /dev/nvme0n1p1 /mnt/boot/efi

# [config mirrorlist]
...

# [init with `pacstrap`]
pacstrap /mnt base base-devel openrc linux linux-firmware plasma iwl neovim intel-ucode grub efibootmgr konsole NerworkManager

# [chroot]
genfstab -U /mnt >> /mnt/etc/fstab
arch-chroot /mnt

# [timezone]
ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
hwclock --systohc

# [locale]
nvim /etc/locale.gen
locale-gen 
nvim /etc/locale.conf # LANG=en_US.UTF-8

# [host related]
nvim /etc/hostname # be
nvim /etc/hosts # 127.0.0.1	localhost ::1		localhost 127.0.1.1	be.localdomain	be

# [Initramfs]
mkinitcpio -P

# [user]
passwd # ...
add-user -m -G wheel beet
passwd beet
nvim /etc/sudoers # uncummnet whell all

# [grub]
grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=GRUB
grub-mkconfig -o /boot/grub/grub.cfg 
sync 

# [🐈]
exit
umount -R /mnt
reboot
