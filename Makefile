all:
	cc -o removecr removecr.c
	g++ -o concat concat.cpp

clean:
	rm removecr concat
