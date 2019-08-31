#!/bin/bash

#variable
#a=2
#b='ing'
#c=9.18
#arr=(11 22 33 44)
#echo $a
#echo $b
#echo $c
#echo ${arr[0]}
#echo ${arr[1]}

#calculate
#i=10
#let i++
#echo $i
#((i++))
#echo $i
#((i%=4))
#echo $i

#judge if case
#read s
#if [ "$s" == "hello" ];then 
#	echo "HELLO"
#elif [ "$s" == "world" ];then 
#	echo "WORLD"
#else 
#	echo "$s"
#fi
#
#read s
#if [ "$s" == "hello" ]
#then 
#	echo "HELLO"
#elif [ "$s" == "world" ]
#then 
#	echo "WORLD"
#else 
#	echo "$s"
#fi
#


#a=50
#b=20
#if [ $a==$b ]
#then 
#	echo "is equal"
#elif [ $a -gt $b ]
#then 
#	echo "more"
#else 
#	echo "less"
#fi

#case
#read op
#case $op in 
#	'start')
#	echo "command start..."
#	;;
#	'stop')
#	echo "command stop"
#	;;
#	'restart')
#	echo "restarting..."
#	;;
#	*)
#	echo "default"
#	;;
#esac

#cilcle
#for((i=0;i<100;i++))
#do
#	echo "hello world:$i"
#done
#
#for i in {1..100}
#do
#	echo "hello linux:$i"
#done
#i=2
#while(($i <= 10))
#do
#	printf "hello:%d\n""$i"
#	let "i++"
#done

#die circle
#for((;;))
#do 
#	echo "die"
#done
#while :
#do
#	echo "double die"
#done

#if instand
#printf "please enter your file:"
#read s
#if [ -f $s ];then
#	echo "file"
#elif [ -d $s ];then
#	echo "dir"
#elif [ -b $s ];then
#	echo "block"
#elif [ -c $s ];then
#	echo "char"
#else
#	echo "unknown"
#fi

#read d
#if [ $d -eq 1 ];then
#	echo "1+1"
#elif [ $d -eq 2 ];then
#	echo "2+2"
#else 
#	echo "$d"
#fi

#function
#myfun(){
#	echo "hello myfun"
#}
#
#myfun
