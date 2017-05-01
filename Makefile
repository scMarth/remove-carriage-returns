all:
	cc -o removecr removecr.c
	g++-4.9 -std=c++11 -o concat concat.cpp

clean:
	rm removecr concat
