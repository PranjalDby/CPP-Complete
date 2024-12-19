#! bin/bash


echo "case esac operations: "

echo ">>>>>>>>>>>>>>>>>>>>>>>>>> BASIC CALCULATOR <<<<<<<<<<<<<<<<<<<<<<<<<"

read -p "Enter the numbers space seprated " a b

read -p "Enter the op you want to perform " op

case $op in
	'+')
	echo "Sum: "
	res=$(($a + $b))
	echo "add = $res"
	;;
	'-')
	echo "Subs: "
	echo "$a-$b" | bc
	;;
	'*')
	echo "Mul: "
	echo "$a*$b" | bc
	;;
	'r')
	echo "square-root of first num : "
	r=`echo "sqrt($a)" | bc`
	echo "$r" 
	;; 
	

esac

