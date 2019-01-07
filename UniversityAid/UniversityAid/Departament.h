#pragma once
using namespace std;
#include "Faculty.h"
#include "S_Program.h"
class Departament {
private:
	int id;
public:
	string nameDepartament;
	vector<S_Program> programet;
	Departament()
	{
		id = 0;
		nameDepartament = "Unknown";
	}
	Departament(int id, string name)
	{
		this->id = id;
		this->nameDepartament = name;
	}
	int getId()
	{
		return id;
	}
	void setId(int id)
	{
		this->id = id;
	}

};