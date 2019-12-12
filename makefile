hepsi: derle calistir
Nesneler :=  ./lib/Dugum.o ./lib/Agac.o ./lib/Oyun.o

derle:
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.cpp
	g++ -I ./include/ -o ./bin/Test $(Nesneler) ./src/Test.cpp
	
calistir:
	./bin/Test