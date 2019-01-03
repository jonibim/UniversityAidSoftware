#pragma once
#include "Libraries.h"
#include "Departament.h"
using namespace std;
class Faculty {

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

void checkFaculties(vector<Faculty> faculties) {
	cout << R"(
+----------------+
| Available Data |
|                |
+----------------+)" << endl;

	for (int i = 0; i < faculties.size(); i++)
	{
		cout << "Te dhenat e fakultetit " << i + 1 << endl;
		cout << faculties[i].name << endl;
		cout << faculties[i].address << endl;
		cout << "Departamentet jane: " << endl;
		for (int j = 0; j < faculties[i].departamentet.size(); i++)
		{
			cout << "Emer: " << faculties[i].departamentet[j].nameDepartament << endl;
			cout << "Id: " << faculties[i].departamentet[j].getId() << endl;
		}
	}
};

void checkDepartments(vector<Departament> departamentet) {
	for (int i = 0; i < departamentet.size(); i++)
	{
		cout << "Te dhenat e departamentit " << i + 1 << endl;
		cout << departamentet[i].nameDepartament << endl;
		cout << "Lendet jane: " << endl;
		for (int j = 0; j < departamentet[i].programet.size(); i++)
		{
			cout << "ID: " << departamentet[i].programet[j].getId() << endl;
			cout << "Emer: " << departamentet[i].programet[j].nameProgram << endl;
			cout << "Vitet: " << departamentet[i].programet[j].programYears << endl;
		}
	}
};

//leftover code

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
