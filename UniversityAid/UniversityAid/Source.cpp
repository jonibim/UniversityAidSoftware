#include "Student.h"
#include "Faculty.h"
#include "S_Program.h"
using namespace std;

vector<Faculty> faculties;
void welcomeScreen(void);
void mainMenu();
void addDepartament();
void addFaculty();
void addStudy();
void cls(void);

int main() {

	int ProgramExit = 0;
	while (ProgramExit !=1) {
		welcomeScreen();
		mainMenu();
		int choice;
		cout << "Enter option: (0-12): " << endl;
		cin >> choice;
		cls();
		if (choice == 1) {
			addFaculty();
		}

		if (choice == 2) {
			addDepartament();
		}
		if (choice == 3) {
			addStudy();
		}

		if (choice > 3 && choice < 12) {
			cout << "Under Construction :(" << endl;
			Sleep(5000);
		}

		if (choice <= 0) {
			cout << "Select an option using numbers from 1 - 12" << endl;
		}

		if (choice == 12) {
			return 0;
		}

	}






}

void cls() {
	system("CLS");
	}

void welcomeScreen(void){
	cout << R"(
##############################################################################

 _   _      _                _ _            _   _    _   _____         _ 
| | | |_ _ (_)_ _____ _ _ __(_) |_ _  _    /_\ (_)__| | |_   _|__  ___| |___
| |_| | ' \| \ V / -_) '_(_-< |  _| || |  / _ \| / _` |   | |/ _ \/ _ \ (_-<
 \___/|_||_|_|\_/\___|_| /__/_|\__|\_, | /_/ \_\_\__,_|   |_|\___/\___/_/__/
                                   |__/                                     

##############################################################################
)";
}

void mainMenu() {
	cout << R"(
+----------------------------------------+-------------------------------------------+
|              Add a Faculty             |              Add a Department             |
|                   01                   |                     02                    |
+----------------------------------------+-------------------------------------------+
|           Add a Study Program          |               Add a Subject               |
|                   03                   |                     04                    |
+----------------------------------------+-------------------------------------------+
| Register a Student  in a Study program | Deregister a Student from a Study program |
|                   05                   |                     06                    |
+----------------------------------------+-------------------------------------------+
|            Add Student Marks           |           Delete a Study Program          |
|                   07                   |                     08                    |
+----------------------------------------+-------------------------------------------+
|           Delete a Department          |              Delete a Faculty             |
|                   09                   |                     10                    |
+----------------------------------------+-------------------------------------------+
|             Add a Pedagogue            |                    Exit                   |
|                   11                   |                     12                    |
+----------------------------------------+-------------------------------------------+
)";

}


void addDepartament() {
	cout << R"(
+---------------------+
| Adding a Department |
|                     |
+---------------------+)" << endl;

	cout << "Add ID dhe Departmanet's name" << endl;
	int id;
	string name;
	cout << "ID: ";
	cin >> id;
	verifyInt(id);
	//noZeroInt(id);
	cout << "Name: " << endl;
	cin >> name;
	Departament departamentIRi(id, name); //Krijohet nje departament i ri ku regjistrohen id dhe emri
	cout << "Cilit fakultet do i perkasi?" << endl;
	string fName;
	cin >> fName;
	int poz = -1; //Vendoset poz i barabarte me -1, per te mos krijuar konflikte me vektorin ne rast se nuk gjendet emri, pasi poz -1 nuk ekziston ne vektor
	for (int i = 0; i < faculties.size(); i++) //Nje cikel qe bredh ne vektorin faculties per te gjetur emrin e fakultetit te dhene 
	{
		if (faculties[i].name == fName)
		{
			poz = i; //poz merr indexin ku ndodhet emri i fakulteti ne vektor
			break;
		}
	}
	if (poz == -1)
	{
		cout << "This faculty cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl; 
		char input;
		cin >> input;
		if (input == 'y' || 'Y') {
			cls();
			checkFaculties(faculties);
		}
			cout << "Press Enter to return to Menu";
			cin.ignore();
			cin.ignore(); //Pse 2 here? https://stackoverflow.com/a/37234270
			return;
	}
	faculties[poz].departamentet.push_back(departamentIRi);
};
void addFaculty() {
	string adresa, emer;
	cout << "Vendosni emrin dhe adresen e Fakultetit" << endl;
	cin >> emer;
	cin >> adresa;
	Faculty fakultetIRi;
	fakultetIRi.name = emer;
	fakultetIRi.address = adresa;
	faculties.push_back(fakultetIRi);
};
void addStudy() {
	cout << R"(
+------------------------+
| Adding a Study Program |
|                        |
+------------------------+_)" << endl;
	int id;
	string name;
	cout << "Add Study Program ID, name and years:" << endl;
	cout << "ID: ";
	cin >> id;
	verifyInt(id);
	//noZeroInt(id);
	cout << endl;
	int years;
	cout << "Years: ";
	cin >> years;
	verifyInt(years);
	//noZeroInt(years);
	S_Program newProgram(id, name, years);
	cout << "Cilit fakultet do i perkasi?" << endl;
	string fName;
	cin >> fName;
	int poz = -1; 
	for (int i = 0; i < faculties.size(); i++) 
	{
		if (faculties[i].name == fName)
		{
			poz = i; 
			break;
		}
	}
	if (poz == -1)
	{
		cout << "This faculty cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		char input;
		cin >> input;
		if (input == 'y' || 'Y') {
			cls();
			checkFaculties(faculties);
		}
		cout << "Press Enter to return to Menu";
		cin.ignore();
		cin.ignore(); 
		return;
	}
	cout << "Cilit departament do i perkasi?" << endl;
	cin >> fName;
	int poz2 = -1;
	for (int i = 0; i < faculties[poz].departamentet.size(); i++)
	{
		if (faculties[poz].departamentet[i].nameDepartament == fName)
		{
			poz2 = i;
			break;
		}
	}
	if (poz2 == -1)
	{
		cout << "This faculty cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		char input;
		cin >> input;
		if (input == 'y' || 'Y') {
			cls();
			checkFaculties(faculties);
		}
		cout << "Press Enter to return to Menu";
		cin.ignore();
		cin.ignore();
		return;
	}
	faculties[poz].departamentet[poz2].programet.push_back(newProgram);


	

};
