hepsi: derle calistir
Nesneler :=  ./lib/Node.o ./lib/Heap.o

derle:
	g++ -I ./include/ -o ./lib/Heap.o -c ./src/Heap.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./bin/Test $(Nesneler) ./src/Test.cpp
	
calistir:
	./bin/Test