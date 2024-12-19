#! bin/bash

# flow control using if elif else statements

read -p "Enter your age = " age

if [ $age -gt 1 -a $age -lt 10 ]; then
	echo "you're a child.👶"

elif [ $age -gt 10 -a $age -lt 18 ]; then
	echo "you're a teenager."

elif [ $age -gt 18 -a $age -lt 30 ]; then
	echo "you're a yong male."

elif [ $age -gt 30 ]; then
	echo "do you need anything old man."
else
	echo "Seriously! you are a moron."

fi

echo "File checking\n"

read -p "Enter the name of file or dir = " file

if [ -f $file ]; then
	echo "it is a file"

fi


