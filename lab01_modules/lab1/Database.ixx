export module Database;

import <vector>;
import <string>;
import <iostream>;

import Student;

export class StudentDatabase {
private:
    std::vector<Student> students;
public:
    void addStudent(const std::string& name) {
        students.push_back(name);
    }

    Student* findStudent(const std::string& name) {
        for (auto& student : students) {
            if (student.getName() == name) return &student;
        }
        return nullptr;
    }

    void printStudents() const {
        std::cout << "\033[2J\033[1;1H";
        for (const auto& student : students) {
            std::cout << "Student: " << student.getName()
                << ", Average grade: " << student.getAverage() << "\n";
        }
    }
};
