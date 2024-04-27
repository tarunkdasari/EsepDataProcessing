dbRun: main.o DB.o
	g++ -o dbRun main.o DB.o

main.o: main.cpp DB.h
	g++ -c main.cpp

DB.o: DB.cpp DB.h
	g++ -c DB.cpp
