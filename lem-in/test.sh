#!/bin/bash
make -s
make -sC ~/verifier
timefunc(){
printf "MAP: TIME"
for dir in flow-one flow-ten flow-thousand big big-superposition
do
	for i in {0..9}
	do
		local time=$(time ./lem-in < maps/$dir/$i > /dev/null)
		printf "%s: %s" $dir/$i time
	done
done
}
func2(){
printf "PREDICTED|RESULT:DIFF\n"
local average=0
for dir in flow-one flow-ten flow-thousand big big-superposition
do
	for i in {0..9}
	do
		local predict=$(tail -n 1 maps/$dir/$i | awk '{print $8}')
		./lem-in < maps/$dir/$i > out
		local result=$(~/verifier/verifier < out)
		local diff=$(expr $result - $predict)
		average+=diff
		printf "%9s|" $predict
		if [ $diff -lt 5 ]
		then
			printf "\033[32m"
		elif [ $diff -lt 10 ]
		then
			printf "\033[33m"
		else
			printf "\033[31m"
		fi
		printf "%-6s" $result
		printf "\033[0m"
		printf :"%2d\n" $diff
	done
	printf "AVERAGE DIFF:%d\n" $sum / $i
done
}
func3(){
printf "##|PREDICTED|RESULT:DIFF\n"
local sum=0

for (( i = 0; i < $2; i++ ))
do
	~/Downloads/generator $1 > genmap$i
	./lem-in < genmap$i > out

	local predict=$(tail -n 1 genmap$i | awk '{print $8}')
	local result=$(~/verifier/verifier < out)
	local diff=$(expr $result - $predict)
	if [ $diff -gt 25 ]
	then
		$i-=1
		continue
	fi
	printf "%2d|" $i
	printf "%9s|" $predict
	printf "%-6s:" $result
	if [ $diff -lt 5 ]
	then
		printf "\033[32m"
	elif [ $diff -lt 15 ]
	then
		printf "\033[33m"
	else
		printf "\033[31m"
	fi

	printf "%2d\n" $diff
	printf "\033[0m"
	sleep 1
	sum=$(expr $sum + $diff)
done

average=$(awk "BEGIN {print $sum / $i}")
printf "AVERAGE DIFF:\033[32m%s\033[0m\n" $average
}
if [ $# -gt 0 ]
then
	
		if [ $# = 2 ]
		then
			func3 $1 $2
		elif [ $# = 1 ]
		then
			func3 $1
		fi
else
	func2
fi
