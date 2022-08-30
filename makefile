.SILENT:
cp:
	g++ code.cpp -std=c++17 -I . -o code.o

test:
	./code.o < in.txt