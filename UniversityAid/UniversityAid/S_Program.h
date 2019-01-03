#pragma once
using namespace std;
#include "Libraries.h"
#include "Subjects.h"
class S_Program {

private:
	int Id;

public:
	int programYears;
	string nameProgram;


	S_Program() {
		Id = 0;
		nameProgram = "Unknown";
		programYears = 0;

	}

	S_Program(int Id, string nameProgram, int programYears) {
		this->Id = Id;
		this->nameProgram = nameProgram;
		this->programYears = programYears;


	}
	int getId()
	{
		return Id;
	}
	void setId(int Id)
	{
		this->Id = Id;
	}



};