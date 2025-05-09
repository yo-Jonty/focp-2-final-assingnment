#include <iostream>
#include <cstring>
using namespace std;
class Student {
private:
    char name[100];
    int rollNumber;
    float cgpa;
    char courses[10][100];  
    int courseCount;
public:
    Student() {
        strcpy(name, "Unknown");
        rollNumber = 0;
        cgpa = 0.0;
        courseCount = 0;
    }
    Student(const char* n, int roll, float c, const char courseList[][100], int count) {
        strcpy(name, n);
        rollNumber = roll;
        setCGPA(c);
        courseCount = 0;
        for (int i = 0; i < count && i < 10; i++) {
            addCourse(courseList[i]);
        }
    }
    Student(const Student& other) {
        strcpy(name, other.name);
        rollNumber = other.rollNumber;
        cgpa = other.cgpa;
        courseCount = other.courseCount;
        for (int i = 0; i < courseCount; i++) {
            strcpy(courses[i], other.courses[i]);
        }
    }
    ~Student() {
    }
    void addCourse(const char* course) {
        for (int i = 0; i < courseCount; i++) {
            if (strcmp(courses[i], course) == 0) {
                cout << "Course already enrolled.\n";
                return;
            }
        }
        if (courseCount < 10) {
            strcpy(courses[courseCount], course);
            courseCount++;
            cout << "Course added successfully.\n";
        } else {
            cout << "Maximum course limit reached.\n";
        }
    }
    void setCGPA(float newCGPA) {
        if (newCGPA >= 0.0 && newCGPA <= 10.0) {
            cgpa = newCGPA;
        } else {
            cout << "Invalid CGPA. Must be between 0 and 10.\n";
        }
  }
    void display() const {
        cout << "Name: " << name << "\nRoll No: " << rollNumber
             << "\nCGPA: " << cgpa << "\nCourses Enrolled:\n";
        for (int i = 0; i < courseCount; i++) {
            cout << "- " << courses[i] << "\n";
        }
    }
};
int main() {
    const char initialCourses[2][100] = {"Math", "Physics"};
    Student s1("Lavit", 102, 8.5, initialCourses, 2);
    s1.display();
    cout << "\nTrying to add 'Math' again:\n";
    s1.addCourse("Math");
    cout << "\nAdding 'Chemistry':\n";
    s1.addCourse("Chemistry");
    cout << "\nUpdating CGPA to 9.2:\n";
    s1.setCGPA(9.2);
    cout << "\nFinal Student Info:\n";
    s1.display();
    return 0;
}