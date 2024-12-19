#! bin/bash

echo "Numericals"
#read -p "Number = " n

fact=1

#for (( i=$n; i>=1; --i))
#do
#	fact=$(($i*$fact));
#done

#echo "fact of $n = $fact"

#echo "reversing a number: "
#read -p "Enter the Number: " num
#len=$(echo "length($num)" | bc)
#echo "number of digits in $num = $len"


#reversed=0
#len=$(($len-1))
#while [ $num -ne 0 ]
#do	
	#rem=$(($num%10))
	#echo "reversed = $rem"
#	pow=$((10**$len))
#	echo "pow = $pow"

#	updated=$(($rem*$pow))
#	echo "updated = $updated"
#	reversed=$(($reversed+$updated))
#	len=$(($len-1))
#	num=$(($num/10))
#done

#echo "reversed digit = $reversed"


echo "Listing the files in directory. "

read -p "Enter the directory name: " dir

if [ -d $dir ]; then
	echo "List no of files "
	count=$(ls | wc -l)
	echo $count

else
	echo "not a dir"

fi

