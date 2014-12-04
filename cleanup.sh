#!/bin/bash
LOG_DIR=/var/log
ROOT_UID=0   #$UID为0的时候，用户才具有根用户的权限
LINES=50	#默认的保存行数
E_XCD=66	#不能修改目录？
E_NOTROOT=67	#非根用户将以error退出



#当然要使用根用户来运行
if [ "$UID" -ne "$ROOT_UID" ]
then
	echo "Must be root to run this script."
	exit $E_NOTROOT
fi

if [ -n "$1" ]	#测试是否有命令行参数（非空）
then
	lines=$1
else
	line=$LINES	#默认，如果不在命令行中指定
fi

#Stephane Chazelas 建议使用下边的更好方法来检测命令行参数，但对于这章来说还是有点超前

# E_WRONGARGS=65	#非数值参数（错误的参数格式）
# case "$1" in
# "" ) lines=50;;
# *[!0-9]*)echo "Uaage:`basename $0` file-to-cleanup";exit $E_WRONGARGS;;
# * )lines=$1;;
# esac
#* 直到"Loops"的章节才会对上边的内容进行详细的描述。


cd $LOG_DIR

if [ `pwd` != "$LOG_DIR" ] #或者if["$PWD" != "$LOG_DIR"]
	#不在/var/log中？
then
	ceho "Can't change to $LOG_DIR."
	exit $E_XCD
fi  #在处理log file之前，再确认一遍当前目录是否正确。

# 更有效率的做法是
# cd /var/log || {
#  echo "Can't change to necessary directory." >&2
#  exit $E_XCD;
# }

tail -$lines messages > mesg.temp #保存log file 消息的最后部分。
mv mesg.temp messages  # 变为新的log 目录。

# cat /dev/null > messages
# *不再需要了，使用上边的方法更安全。

cat /dev/null > wtmp # ':>wtmp' 和 '>wtmp' 具有相同的作用
echo "Logs cleaned up."
exit 0
# 退出之前返回0， 返回0表示成功。
## End Script

# echo "Cannot change to necessary dirctory." >&
	


