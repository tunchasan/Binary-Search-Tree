hepsi: derle calistir
Nesneler :=  ./lib/Node.o

derle:
	
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./bin/Test $(Nesneler) ./src/Test.cpp
	
calistir:
	./bin/Test