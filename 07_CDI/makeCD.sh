#! /bin/sh
#automating script for making CD games

DIR=$PWD
PROJECT_NAME="project_name"
TARGET="main.elf"

# go to build directory
# make clean
#make

#elf transform ---- make sure the *.elf name matches your .elf file.
sh-elf-objcopy -R .stack -O binary $TARGET output.bin

#scraming process
$KOS_BASE/utils/scramble/scramble output.bin 1ST_READ.bin

#creating iso -> -o outputname.iso
mkisofs -C 0,11702 -V DC_GAME -G IP.BIN -r -J -l -m '*.o' -x $DIR/builds -o builds/$PROJECT_NAME.iso $DIR

#transform iso into a CDI
$KOS_BASE/utils/cdi4dc/cdi4dc builds/$PROJECT_NAME.iso builds/$PROJECT_NAME.cdi > cdi.log

#YOU MIGHT WANT TO EDIT THE IP ADRESS HERE !!!!
sudo arp -s 192.168.0.99 00:d0:f1:03:14:02

#start the game
#sudo ../dc-tool-ip -t dreamcast -c ./ -x main.elf
#lxdream ../$PROJECT_NAME.iso
#reicast ../$PROJECT_NAME.cdi
redream builds/$PROJECT_NAME.cdi
 mine
