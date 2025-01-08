//
//  main.cpp
//  friends
//
//  Created by Samantha Shon on 3/6/24.
//

#include <iostream>
using namespace std;

class Student
{
private:
    float GPA;
    
public:
    friend float Admin(Student TA);
    
    int Year;
    
    Student(float ActualGPA, int ClassYear);
    
    float getGPA();
    void setGPA(float WGPA);
};

void PrintResult(float Grade);

int main()
{
    Student John (3.07, 3);
    cout << "John's GPA (friend)" << Admin(John) << endl;
    cout << "John's GPA (getter)" << John.getGPA() << endl;
    
    if(John.Year < 3)
        John.setGPA(1.5);
    
    PrintResult (John.getGPA());
    
    return 0;
}

//constructor
Student :: Student(float ActualGPA, int ClassYear)
{
    GPA = ActualGPA;
    Year = ClassYear;
}

//accessor
float Student :: getGPA()
{
    return GPA;
}

//setter
void Student::setGPA(float WGPA)
{
    GPA = GPA * WGPA;
}

void PrintResult(float Grade)
{
    cout << "John's Weighted GPA is " << Grade << endl;
}

float Admin(Student TA)
{
    return TA.GPA;
}

//float Admin(Student TA)
//{
//    TA.GPA = TA.GPA * 1.5;
//    return TA.GPA;
//}
