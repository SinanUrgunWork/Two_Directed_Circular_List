/**
* @file iki yonlu dairesel bagil liste.h
* @course 1. Ögretim A
* @assignment 1.
* @date 8/16/2020
* @author sinan urgun(G171210015)
*/
#ifndef _IKI_YONLU_DAIRESEL_BAGIL_Iki_Yonlu_Dairesel_Bagil_Liste_
#define _IKI_YONLU_DAIRESEL_BAGIL_Iki_Yonlu_Dairesel_Bagil_Liste_
#include "Bogum.h"

class Iki_Yonlu_Dairesel_Bagil_Liste{
private:
	Bogum* on_kisim;
	Bogum* arka_kisim;
	int max;
public:
	Iki_Yonlu_Dairesel_Bagil_Liste();
	~Iki_Yonlu_Dairesel_Bagil_Liste();
	void bogum_ekle(int value);
	int aralik(int value);
	void aralikla_ekle(Bogum* bogum,int aralik,int value);
	void cikti_yansit();
};

#endif
