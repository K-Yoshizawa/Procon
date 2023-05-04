.SILENT:
cp:
	g++ code.cpp -std=c++17 -I . -o code.o

do:
	./code.o

test: cp do