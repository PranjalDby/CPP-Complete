#! bin/bash
echo "While loops "

read -p "Enter the Number: " a
echo "printing multiplication table of $a"
i=1;
while [ $i -le 10 ]
do
	echo "$a * $i = `echo "$a*$i" | bc`"
	i=$(($i+1))
done

echo "Printing the table in reverse order: "

i=10
while [ $i -eq 0 ]
do
	echo "$a * $i = `echo "$a*$i" | bc`"
	$i=$(($i-1))
done

