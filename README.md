# ProjectD
Dynamic Language

How to run:

flex flex.l

bison -d bison.y

g++ -o test bison.tab.c -lm

./test
