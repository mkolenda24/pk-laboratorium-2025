import Student;
import Database;

#include <iostream>
#include <limits>

int main() {

    StudentDatabase db;
    int choice;

    do {
        std::cout << "1. Add Student\n2. Add grade\n3. Display students\n4. Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::string name;
            std::cout << "Student's name: ";
            std::cin >> name;
            std::cout << "\n";
            db.addStudent(name);
            std::cout << "\033[2J\033[1;1H";
            break;
        }
        case 2: {
            std::string name;
            int grade;
            std::cout << "Student's name: ";
            std::cin >> name;
            Student* student = db.findStudent(name);
            if (student) {
                std::cout << "Type grade: ";
                std::cin >> grade;
                std::cout << "\n\n";
                student->addGrade(grade);
            }
            else {
                std::cout << "Student not found!\n\n";
            }
            std::cout << "\033[2J\033[1;1H";
            break;
        }
        case 3: {
            db.printStudents();
            std::cout << "\n";
            break;
        }
        default: {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[2J\033[1;1H";
            break;
        }
        }

    } while (choice != 4);

    return 0;
}
