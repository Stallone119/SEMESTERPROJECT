
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Course {
    string name;
    int creditHours;
    char grade;
};

int getGradePoints(char grade) {
    switch (grade) {
        case 'A': return 8;
        case 'B+': return 7;
        case 'B': return 6;
        case 'C+': return 5;
        case 'C' : return 4;
        case 'D' : return 3;
        case 'E' : return 2;
        case 'F' : return 1;
        default: return 0;
    }
}

double calculateSemesterGPA(const vector<Course>& courses) {
    double totalGradePoints = 0;
    int totalCreditHours = 0;

    for (const Course& course : courses) {
        totalGradePoints += getGradePoints(course.grade) * course.creditHours;
        totalCreditHours += course.creditHours;
    }

    return totalGradePoints / totalCreditHours;
}

double calculateCGPA(const vector<Course>& allCourses) {
    double totalGradePoints = 0;
    int totalCreditHours = 0;

    for (const Course& course : allCourses) {
        totalGradePoints += getGradePoints(course.grade) * course.creditHours;
        totalCreditHours += course.creditHours;
    }

    return totalGradePoints / totalCreditHours;
}

string getClass(double cgpa) {
    if (cgpa >= 3.6) return "First Class";
    if (cgpa >= 2.5) return "Second Class Upper";
    if (cgpa >= 2.0) return "Second Class Lower";
    if (cgpa >= 1.5) return "Third class";
    return "Pass";
}

int main() {
cout<<"GRADING SYSTEM"<<endl;
cout <<"============"<<endl;
    vector<Course> courses;
    char continueAdding;

    do {
        Course course;
        cout <<"Enter course name: "<< endl;
        cin >> course.name;
        cout<<endl;
        cout <<"Enter credit hours: "<< endl;
        cin >> course.creditHours;
        cout <<"Enter grade (A, B+, B, C+, C, D, E, F, etc.): "<<endl;
        cin >> course.grade;

        courses.push_back(course);

        cout << "Do you want to add another course? (Y/N): "<<endl;
        cin >> continueAdding;
    } while (continueAdding == 'Y' || continueAdding == 'y');

    double semesterGPA = calculateSemesterGPA(courses);
    cout << "Semester GPA: " << semesterGPA << endl;

    double cgpa = calculateCGPA(courses);
    cout << "CGPA: " << cgpa << endl;

    string studentClass = getClass(cgpa);
    cout << "Student Class: " << studentClass << endl;

    return 0;
}