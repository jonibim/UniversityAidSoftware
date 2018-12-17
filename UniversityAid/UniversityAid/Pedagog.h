#pragma once
using namespace std;
class Pedagog {
	class Pedagog :public Person {
	private:
		string ID;
		string password;
		int paga;
    public:
		Pedagog() :Person() {}
		Pedagog(string name, string surname) :Person(name, surname) {}
		string showName() {
			return name;
		}
		void setID() {
			this->ID = ID;
		}
		string getID() {
			return ID;
		}

		void setPassword() {
			this->password = password;
		}

		string getPassword() {
			return password;
		}
		void setPaga() {
			this->paga = paga;
		}
		 
		int getPaga() {
			return paga;
		}
};