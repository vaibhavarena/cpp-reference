#include <cassert>
#include <stdexcept>
#include <string>
#include <iostream>
using std::cout;
using std::string;

class Student
{
private:
    string name;
    int grade;
    float gpa;

    void validate()
    {
        if ((grade < 0 || grade > 12) || (gpa < 0 || gpa > 4))
            throw std::invalid_argument("Grade or GPA is invalid");
    }

public:
    Student(string s, int g, float h) : name(s), grade(g), gpa(h) {
        validate();
    }

    string getName();
    int getGrade();
    float getGpa();

    void setName(string s);
    void setGrade(int g);
    void setGpa(float g);

};

string Student::getName(){
    return name;
}

int Student::getGrade(){
    return grade;
}

float Student::getGpa(){
    return gpa;
}

void Student::setName(string s){
    name = s;
    validate();
}

void Student::setGrade(int g){
    grade = g;
    validate();
}

void Student::setGpa(float g){
    gpa = g;
    validate();
}

int main()
{
    Student v("Vaibhav Chhabra", 3, 3.3);
    cout << v.getName() << " has " << v.getGrade() << " grade with " << v.getGpa() << " GPA\n";

    bool caught{false};

    try{
    Student invalid("V", 15, 3);
    }
    catch(...){
        caught = true;
    }
    
    assert(caught);
}