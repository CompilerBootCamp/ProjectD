# ProjectD
Dynamic Language

How to run:
required: g++, bison 3.0.0 ++, flex

flex flex.l

bison -d bison.y

g++ -o test bison.tab.c -lm

./test || ./test.out