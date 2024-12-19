#! bin/bash

echo "Basic arithmetic operation on using expr"

read -p "Enter two number: " n1 n2

echo "Num1 = $n1 and Num2 = $n2"

echo "boolean comparison\n"

res=$(expr "$n1" \> "$n2")
if [ $res -eq 1 ]; then
	echo "n1 is greater"
else
	echo "n2 is greater"
fi
sum=$(($n1**$n2))

echo "power of two number is = $sum"


echo "using bc basic calculator"

res=`echo "$n1**$n2" | bc`

echo $res
