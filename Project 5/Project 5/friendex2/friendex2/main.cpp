//
//  main.cpp
//  friendex2
//
//  Created by Samantha Shon on 3/7/24.
//

#include <iostream>
#include <string>
using namespace std;

class Student;

class Teacher
{
public:
    int UID;
    
    Teacher(int ID);
    
    float Admin(Student &TA);
    
};

class Student
{
private:
    float GPA;
    
public:
    friend float Teacher::Admin(Student &TA);
    
    int Year;
    
    Student(float ActualGPA, int ClassYear);
    
    float getGPA();
    void setGPA(float WGPA);
};

void PrintResult(float Grade);

int main()
{
    Student John (3.07, 3);
    Teacher Dan (123456);
    
    cout << "John's GPA (friend) = " << Dan.Admin(John) << endl;
    
    cout << "John's GPA is " << John.getGPA() << endl;
    
    if(John.Year < 3)
        John.setGPA(3.5);
    
    PrintResult(John.getGPA());
    
    return 0;
}

Student::Student(float ActualGPA, int ClassYear)
{
    GPA = ActualGPA;
    Year = ClassYear;
}

void Student::setGPA(float WGPA)
{
    GPA = GPA * WGPA;
}
void PrintResult(float Grade)
{
    cout << "John's Weighted GPA is " << Grade << endl;
}
float Teacher::Admin(Student &TA)
{
    TA.GPA = TA.GPA * 1.5;
    return TA.GPA;
}
