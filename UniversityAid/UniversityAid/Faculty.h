#pragma once
#include "Libraries.h"
using namespace std;
class Faculty {
protected:
	int classes;
	int labs;
	int secretary;
	int library;

public:
	int buildings;

	Faculty() {
		buildings = 0;

	}

	Faculty(int buildings) {
		this->buildings = buildings;
	
	}

	void setClasses(int classes) {
		this->classes = classes;
	}
	int getClasses () {
		return classes;
	}

	void setLabs(int labs) {
		this->labs = labs;
	}
	int getLabs() {
		return labs;
	}

	void setSecretary(int secretary) {
		this->secretary = secretary;
	}
	int getSecretary() {
		return secretary;
	}
	void setLibrary(int library) {
		this->library = library;
	}
	int getLibrary() {
		return library;
	}


};