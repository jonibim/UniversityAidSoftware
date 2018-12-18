#include "Student.h"
using namespace std;

void welcomeScreen(void);
void mainMenu();
void addDepartament();
void addFaculty();
void addStudent();
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
			addStudent();
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

void addDepartament() {};
void addFaculty() {};
void addStudent() {
	
	cout << R"(
+-------------------------------------------+
|               Add a Student               |
| Enter Name (press Enter than) and Surname |
+-------------------------------------------+)" << endl;
	string name, surname;
	cin >> name;
	cin >> surname;
	Student std(name, surname);
	//pergjysem
};
