OS : **Ubuntu 14.04**
Tuto : https://olimex.wordpress.com/2013/11/05/building-the-ultimate-debian-sd-card-for-linux-with-kernel-3-4-for-a20-olinuxino-micro/

Corrections du tuto:
====================

**uboot-mkimage** n'existe pas sous Ubuntu 14.04 -> remplacez par __u-boot-tools__

à faire à la place de **make a20-olinuxino_micro CROSS_COMPILE=arm-linux-gnueabihf-** (car j'ai rencontre une erreur Makefile:479) :
sudo apt-get install gcc-arm-linux-gnueabi (car je ne l'avais pas...)
__make A20-OLinuXino-Micro_config CROSS_COMPILE=arm-linux-gnueabihf-__
__make CROSS_COMPILE=arm-linux-gnueabihf-__
 

Ajout PWD drivers:
==================
Apres avoir fait 
make ARCH=arm menuconfig
ajouter le driver Sunxi PWD Drive (dans Misc devices). Ne pas oublier de sauvegarder en ecrasant le .config deja existant.


Remarque:
=========
attention : git clone https://github.com/linux-sunxi/linux-sunxi **est tres long**

Problemes:
==========

Compilation des modules : 2 WARNINGS 
WARNING: drivers/net/wireless/bcmdhd/bcmdhd: 'bcmsdh_probe' exported twice. Previous export was in drivers/net/wireless/bcm4330/bcm4330.ko
WARNING: drivers/net/wireless/bcmdhd/bcmdhd: 'bcmsdh_remove' exported twice. Previous export was in drivers/net/wireless/bcm4330/bcm4330.ko
