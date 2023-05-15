.SILENT:
cp:
	g++ code.cpp -std=c++17 -I . -o code.o

do:
	./code.o

in:
	./code.o < input.txt

in:
	./code.o < in.txt

test: cp do