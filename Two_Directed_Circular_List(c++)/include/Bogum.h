/**
* @file Bogum.h
* @course 1. Ögretim A
* @assignment 1.
* @date 8/16/2020
* @author sinan urgun(G171210015)
*/
#include <iostream>
#ifndef _BOGUM_
#define _BOGUM_

class Bogum{
public:
	Bogum* on_bogum;
	Bogum* arka_bogum;
	int adet;
	Bogum();
	Bogum(int adet);
}; 

#endif
