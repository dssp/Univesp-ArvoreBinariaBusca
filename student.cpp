#include "student.h"
using namespace std;

Student::Student()
{
    ra = -1;
    name = "";
}

Student::Student(int r, string n)
{
    ra = r;
    name = n;
}

string Student::GetName()
{
    return name;
};

int Student::GetRa()
{
    return ra;
};