/**
* @file iki yonlu dairesel bagil liste.cpp
* @course 1. Ögretim A
* @assignment 1.
* @date 8/16/2020
* @author sinan urgun(G171210015)
*/
#include "Iki_Yonlu_Dairesel_Bagil_Liste.h"
#include "Bogum.h"
using namespace std;

Iki_Yonlu_Dairesel_Bagil_Liste::Iki_Yonlu_Dairesel_Bagil_Liste(){
	on_kisim = NULL;
	arka_kisim = NULL;
	max = 0;
}
Iki_Yonlu_Dairesel_Bagil_Liste::~Iki_Yonlu_Dairesel_Bagil_Liste(){
	Bogum* temp = on_kisim;
	while(on_kisim){
		temp = on_kisim->on_bogum;
		delete on_kisim;
		on_kisim = temp;
	}
}
void Iki_Yonlu_Dairesel_Bagil_Liste::aralikla_ekle(Bogum* bogum,int aralik,int value){
	Bogum* yeni_bogum = new Bogum(value);
	if(on_kisim){
		Bogum* imlec = on_kisim;
		while(aralik != 0 && imlec->arka_bogum){
			aralik--;
			imlec = imlec->arka_bogum;
		}
		if(imlec->arka_bogum){	
			yeni_bogum->arka_bogum = imlec->arka_bogum;
			yeni_bogum->on_bogum = imlec;
			yeni_bogum->arka_bogum->on_bogum = yeni_bogum;
			imlec->arka_bogum = yeni_bogum;
		}
		else{
			imlec->arka_bogum = yeni_bogum;
			yeni_bogum->on_bogum = imlec;
			on_kisim = yeni_bogum;
		}
	}
}
int obeb(int v1, int v2) {
   if (v2 == 0)
       return v1;
   return obeb(v2, v1 % v2);
}
void Iki_Yonlu_Dairesel_Bagil_Liste::bogum_ekle(int value){
	if(on_kisim){
		int aralik;
		Bogum* imlec = on_kisim;
		int current_obeb = obeb(imlec->adet,value);
		if(current_obeb >= max){
			max = current_obeb;
            if(value > imlec->adet){
                aralik = value%imlec->adet;
            }
			else{
                aralik = imlec->adet%value;
            }
		}
		else{
			while(current_obeb < max && imlec->on_bogum){
				imlec = imlec->on_bogum;
				current_obeb = obeb(imlec->adet,value);
			}
			if(value > imlec->adet){
                aralik = value % imlec->adet;
            }
			else{
                aralik = imlec->adet % value;
            }
		}
		if(aralik){
			this->aralikla_ekle(imlec, aralik-1, value);
		}
		else{
			Bogum* yeni_bogum = new Bogum(value);
			yeni_bogum->on_bogum = imlec->on_bogum;
			yeni_bogum->arka_bogum = imlec;
			imlec->on_bogum = yeni_bogum;
			yeni_bogum->on_bogum->arka_bogum = yeni_bogum;
			if(imlec == arka_kisim){
                arka_kisim = arka_kisim->on_bogum;
            }
		}
	}
	else{
		Bogum* yeni_bogum = new Bogum(value);
		on_kisim = yeni_bogum;
		arka_kisim = on_kisim;
	}
}
int Iki_Yonlu_Dairesel_Bagil_Liste::aralik(int value){
	Bogum* imlec = on_kisim;
	int current_obeb = obeb(imlec->adet, value);
	if(current_obeb >= max){
		max = current_obeb;
        if(value > imlec->adet){
            return value % imlec->adet;    
        }
        else{
            return imlec->adet % value;
        }
	}
	else{
		while(current_obeb < max && imlec->on_bogum){
			imlec = imlec->on_bogum;
			current_obeb = obeb(imlec->adet, value);
		}
		if(value > imlec->adet){
            return value % imlec->adet;    
        }
        else{
            return imlec->adet % value;
        }
	}
}
void Iki_Yonlu_Dairesel_Bagil_Liste::cikti_yansit(){
	cout<<"Sifre: ";
	Bogum* imlec = on_kisim;
	while(imlec){
		cout<<char(imlec->adet);
		imlec = imlec->on_bogum;
	}
	cout<<endl;
}
