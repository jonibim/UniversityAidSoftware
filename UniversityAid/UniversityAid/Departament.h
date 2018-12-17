#pragma once
using namespace std;
#include "Libraries.h"
class Departament {
protected:

	string clubs;
	
public:
	int classes;
	int labs;
	int buildings;

	Departament() {
		classes = 0;
		labs = 0;
		buildings = 0;
	}
	Departament(int classes, int labs, int buildings) {
		this->classes = classes;
		this->labs = labs;
		this->buildings = buildings;
	}
	void setClubs(string clubs) {
		this->clubs = clubs;
	}
	string getClubs() {
		return clubs; 
	}

};
