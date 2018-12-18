#pragma once
using namespace std;
#include "Faculty.h"
class Departament:public Faculty {
protected:
    string clubs;
public:
	Departament() :Faculty() {}
	Departament(int classes,int labs,int secretary,int library):Faculty(classes, labs, secretary, library) {}

	
	void setClubs(string clubs) {
		this->clubs = clubs;
	}
	string getClubs() {
		return clubs; 
	}

};
