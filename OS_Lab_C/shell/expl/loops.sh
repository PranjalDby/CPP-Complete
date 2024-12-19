#! bin/bash

echo "Looping statements"

arr=("Red" "Green" "blue")

for i in "${arr[@]}"
do
	echo $i

done


echo "While loop"

while read line
do
	my_arr=("${my_arr[@]}" $line)

done

echo "length of arr = ${#my_arr[@]}"
echo ${my_arr[@]}


echo "sum of array element = "
sum=0
for e in ${my_arr[@]}
do
	sum=$(($sum+$e))
done

echo "Sum of elements of arr = $sum"
