/**
* @file main.cpp
* @course 1. Ögretim A
* @assignment 1.
* @date 8/16/2020
* @author sinan urgun(G171210015)
*/
#include"Iki_Yonlu_Dairesel_Bagil_Liste.h"
#include<fstream>
#include<sstream>
#include<vector>
#include<string.h>

using namespace std;

int main(){
	ifstream metin;
	metin.open("Sayilar.txt");
	vector<Iki_Yonlu_Dairesel_Bagil_Liste> butun_listeler;
	string temp_line;	
	while(getline(metin, temp_line)){
		butun_listeler.push_back(Iki_Yonlu_Dairesel_Bagil_Liste());
		int value;		
		stringstream fin(temp_line);
		while(fin>>value){
			butun_listeler.back().bogum_ekle(value);
		}
		butun_listeler.back().cikti_yansit();
	}
	metin.close();
}
