all:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/satirListesi.cpp -o ./lib/satirListesi.o
	g++ -c -I "./include" ./src/satirListesiDugum.cpp -o ./lib/satirListesiDugum.o
	g++ -c -I "./include" ./src/yoneticiListesiDugum.cpp -o ./lib/yoneticiListesiDugum.o
	g++ -c -I "./include" ./src/yoneticiListesi.cpp -o ./lib/yoneticiListesi.o
	g++ -c -I "./include" ./src/dosyaOkuma.cpp -o ./lib/dosyaOkuma.o
	g++ -c -I "./include" ./src/ekranYazdir.cpp -o ./lib/ekranYazdir.o
	
bagla:
	g++  ./lib/ekranYazdir.o ./lib/dosyaOkuma.o ./lib/yoneticiListesi.o ./lib/yoneticiListesiDugum.o ./lib/satirListesi.o  ./lib/satirListesiDugum.o ./lib/main.o -o ./bin/program

calistir:
	./bin/program