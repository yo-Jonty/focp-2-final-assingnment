#include <iostream>
#include <string>
class Student {
private:
    std::string name;
    int rollNumber;
    float cgpa;
    std::string* courses;
    int courseCount;
public:
    Student() {
        name = "Unknown";
        rollNumber = 0;
        cgpa = 0.0;
        courseCount = 0;
        courses = nullptr;
    }
    Student(std::string n, int roll, float c, std::string* courseList, int count) {
        name = n;
        rollNumber = roll;
        cgpa = c;
        courseCount = count;
        courses = new std::string[courseCount];
        for (int i = 0; i < courseCount; ++i) {
            courses[i] = courseList[i];
        }
    }
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        cgpa = other.cgpa;
        courseCount = other.courseCount;
        courses = new std::string[courseCount];
        for (int i = 0; i < courseCount; ++i) {
            courses[i] = other.courses[i];
        }
    }
    ~Student() {
        delete[] courses;
    }
    void display() const {
        std::cout << "Name: " << name << "\nRoll No: " << rollNumber
                  << "\nCGPA: " << cgpa << "\nCourses Enrolled:\n";
        for (int i = 0; i < courseCount; ++i) {
            std::cout << "- " << courses[i] << "\n";
        }
    }
};
int main() {
    std::string courseList[] = {"Math", "Physics", "CS"};
    Student s1("Lavit", 101, 8.7, courseList, 3);
    Student s2 = s1; 
    s1.display();
    std::cout << "\nCopied Student Details:\n";
    s2.display();
    return 0;
}