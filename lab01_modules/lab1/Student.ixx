export module Student;

import <vector>;
import <string>;

export class Student {
private:
    std::string name;
    std::vector<int> grades;
public:
    Student(std::string studentName) : name(studentName) {}

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    double getAverage() const {
        if (grades.empty()) return 0.0;
        int sum = 0;
        for (int grade : grades) sum += grade;

        return static_cast<double>(sum) / grades.size();
    }

    std::string getName() const {
        return name;
    }

};
