all:bclean start movemain aclean 

movemain:
	mv main.out ../bin

start: main.o
	g++ main.o -o main.out

main.o: Lexer.o
	g++ -Wall -ansi -std=c++11 -g -c ../main.cpp

buffer.o:
	g++ -Wall -ansi -std=c++11 -g -c ../buffer.cpp

Tokenizator.o: buffer.o
	g++ -Wall -ansi -std=c++11 -g -c ../Tokenizator.cpp

Lexer.o: Tokenizator.o
	g++ -Wall -ansi -std=c++11 -g -c ../Lexer.cpp

test.o:
	g++ -Wall -ansi -std=c++11 -g -c ../test.cpp

bclean:
	rm -rf *.o ../parser
	
aclean:
	rm -rf *.o ../parser
