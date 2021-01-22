derlecalistir: program calistir

program: Iki_Yonlu_Dairesel_Bagil_Liste.o Bogum.o main.o
	g++ ./lib/Iki_Yonlu_Dairesel_Bagil_Liste.o ./lib/Bogum.o ./lib/main.o -o ./bin/program
Iki_Yonlu_Dairesel_Bagil_Liste.o:
	g++ -I "./include" -c ./src/Iki_Yonlu_Dairesel_Bagil_Liste.cpp -o ./lib/Iki_Yonlu_Dairesel_Bagil_Liste.o
Bogum.o:
	g++ -I "./include" -c ./src/Bogum.cpp -o ./lib/Bogum.o
main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
calistir:
	./bin/program.exe