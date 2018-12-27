#pragma once
#include "Libraries.h"
#include "Departament.h"
using namespace std;
class Faculty {
//protected:
//	int classes;
//	int labs;
//	int secretary;
//	int library;
//
//public:
//	int buildings;
//
//	Faculty() {
//		buildings = 0;
//	}
//	
//	Faculty(int classes, int labs, int secretary, int library) {
//
//		this->classes = classes;
//		this->labs = labs;
//		this->secretary = secretary;
//		this->library = library;
//	
//	}
//
//	Faculty(int buildings) {
//		this->buildings = buildings;
//	
//	}
//
//	void setClasses(int classes) {
//		this->classes = classes;
//	}
//	int getClasses () {
//		return classes;
//	}
//
//	void setLabs(int labs) {
//		this->labs = labs;
//	}
//	int getLabs() {
//		return labs;
//	}
//
//	void setSecretary(int secretary) {
//		this->secretary = secretary;
//	}
//	int getSecretary() {
//		return secretary;
//	}
//	void setLibrary(int library) {
//		this->library = library;
//	}
//	int getLibrary() {
//		return library;
//	}
//
//

public:
	string name;
	string address;
	vector<Departament> departamentet;
	Faculty()
	{
		name = "";
		address = "";
	}
	Faculty(string name, string address, vector<Departament> d)
	{
		this->name = name;
		this->address = address;
		this->departamentet = d;
	}

};