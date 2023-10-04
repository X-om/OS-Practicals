#!bin/bash
echo "Enter the Number 1 : "
read a 
echo "Enter the Number 2 : "
read b
var=0
while[ $var!= 5 ] do
echo "1.Addition"
echo "2.Substraction"
echo "3.Multiplication"
echo "4.Divison"
echo "5.Exit"
echo ""
echo "Enter your choice : "
read var
case $var in 

1) echo "$a + $b =" `expr $a + $b`;;
2) echo "$a - $b =" `expr $a - $b`;;
3) echo "$a * $b =" `expr $a \* $b`;;
4) echo "$a / $b =" `expr $a / $b`;;
5) echo "EXITING !";;
*) echo "invalid input !";;
esac 

