#!/bin/bash

if [[ -z $1 || -z $2 || -z $3 ]]
then
	echo "mksd-s3c6410 Usage:"
	echo "	mksd-s3c6410 <device> <MLO> <u-boot.bin>"
	echo "	Example: mksd-s3c6410 /dev/sdb nand_spl/u-boot-spl-16k.bin u-boot.bin"
	exit
fi

if ! [[ -e $2 ]]
then
	echo "Incorrect MLO location!"
	exit
fi

if ! [[ -e $3 ]]
then
	echo "Incorrect u-boot.img location!"
	exit
fi


echo "All data on "$1" now will be destroyed! Continue? [y/n]"
read ans
if ! [ $ans == 'y' ]
then
	exit
fi

echo "[Partitioning $1...]"

DRIVE=$1

SIZE=`fdisk -l $DRIVE | grep Disk | awk '{print $5}'`

echo DISK SIZE - $SIZE bytes


BL0POS=`echo $SIZE/512-1024-18 | bc`
BL1POS=`echo $BL0POS-2048 | bc`

echo "BL0POS :" $BL0POS
echo "BL1POS :" $BL1POS


echo "[Writing MLO...]"
dd if=$2 of=$1 bs=512 seek=$BL0POS

echo "[Writing u-boot.bin...]"
dd if=$3 of=$1 bs=512 seek=$BL1POS


#echo "[Making filesystems...]"
#umount $1
#mkfs.vfat -F 32 -n sd $1 &> /dev/null


echo "[Done]"

