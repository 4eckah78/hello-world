// lesson_18_project_part1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "objects.h"
#include "Architect.h"
#include "BMPRenderer.h"


using namespace std;


bool testArchitectAddQuantity() {
	Architect ar;
	Id id = ar.addElement(1, 1);
	Array<Id> ids = ar.getALLIds();
	if (ids.Size() != 1) return false;
	if (ids[0] != id) return false;
	id = ar.addElement(1, 1);
	ids = ar.getALLIds();
	if (ids.Size() != 2) return false;

	return true;
}

bool testArchitectAddType() {
	Architect ar;
	Id id = ar.addElement(1, 1);
	Array<Id> ids = ar.getALLIds();
	if (ar.getObjTypeById(id) != FI_POINT) 
		return false;
	return true;
}


int main(){

	/*BMPRenderer renderer("sample.bmp");
	for (int k = 0; k < 100; ++k)
		renderer.draw(k, 4);

	Architect ar;
	ar.addElement(4, 5.6);
	ar.addElement(4, 5.6, 3, 5.4);
	ar.addElement(4, 5.6, 3, 5.4, 2.5);
	point2 p;
	p.id = 12;
	
	

	list<int> l1(1);
	list<int> l2(2);
	list<int> l3(3);
	l1 = l2 = l3;
	list<int>::Pointer p1(l1);
	list<int>::Pointer p2(l2);

	cout << *p1 << " " << *p2 << endl;*/
	

    return 0;
}

