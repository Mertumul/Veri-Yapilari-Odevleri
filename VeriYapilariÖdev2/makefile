all:derle bagla calistir

derle:
	g++ -c -I ./include/ -o ./lib/main.o  ./src/main.cpp
	g++ -c -I ./include/ -o ./lib/organizma.o  ./src/organizma.cpp
	g++ -c -I ./include/ -o ./lib/sistem.o  ./src/sistem.cpp
	g++ -c -I ./include/ -o ./lib/organ.o  ./src/organ.cpp
	g++ -c -I ./include/ -o ./lib/doku.o  ./src/doku.cpp
	g++ -c -I ./include/ -o ./lib/hucre.o  ./src/hucre.cpp
	g++ -c -I ./include/ -o ./lib/ikiliAramaAgaci.o  ./src/ikiliAramaAgaci.cpp
	g++ -c -I ./include/ -o ./lib/queue.o  ./src/queue.cpp
	g++ -c -I ./include/ -o ./lib/radix.o  ./src/radix.cpp
	g++ -c -I ./include/ -o ./lib/kontrol.o  ./src/kontrol.cpp

bagla:
	g++ ./lib/main.o ./lib/organizma.o ./lib/sistem.o ./lib/organ.o ./lib/doku.o ./lib/hucre.o ./lib/ikiliAramaAgaci.o ./lib/queue.o ./lib/radix.o ./lib/kontrol.o -o ./bin/program
calistir:
	./bin/program