.SILENT:
cp:
	g++ code.cpp -std=c++14 -I . -o code.o

test:
	./code > result.txt