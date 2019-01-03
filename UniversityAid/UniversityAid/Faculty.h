#pragma once
#include "Libraries.h"
#include "Departament.h"
#include "Subjects.h"
using namespace std;
class Faculty {

public:
	string name;
	string address;
	vector<Departament> departamentet;
	vector<S_Program> programet;
	vector<Subjects> sub;

	Faculty()
	{
		name = "";
		address = "";
	}
	Faculty(string name, string address, vector<Departament> d, vector<S_Program> prog, vector<Subjects> sub )
	{
		this->name = name;
		this->address = address;
		this->departamentet = d;
		this->programet = prog;
		this->sub = sub;

	}

};

void DebugSize(vector<Faculty> faculties) {

	cout << faculties.size()<<endl;
	for (int i = 0; i < faculties.size(); i++) {
		cout << faculties[i].departamentet.size() << endl;
	}

}

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
		for (int j = 0; j < faculties[i].departamentet.size(); j++)
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
		for (int j = 0; j < departamentet[i].programet.size(); j++)
		{
			cout << "ID: " << departamentet[i].programet[j].getId() << endl;
			cout << "Emer: " << departamentet[i].programet[j].nameProgram << endl;
			cout << "Vitet: " << departamentet[i].programet[j].programYears << endl;
		}
	}
}

void checkPrograms(vector<S_Program> programet) {
	for (int i = 0; i < programet.size(); i++)
	{
		cout << "Te dhenat e programit " << i + 1 << endl;
		cout << programet[i].Id << endl;
		cout << programet[i].nameProgram << endl;
		cout << programet[i].programYears << endl;
		cout << "Lendet jane: " << endl;
		for (int j = 0; j < programet[i].lendet.size(); i++)
		{
			cout << "Emer: " << programet[i].lendet[j].name << endl;
			cout << "Oret: " << programet[i].lendet[j].getHours() << endl;
			cout << "Kreditet: " << programet[i].lendet[j].getCredits() << endl;
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
