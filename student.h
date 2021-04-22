#include <iostream>
using namespace std;

class Student
{
private:
    int ra;
    string name;

public:
    Student();
    Student(int r, string n);
    string GetName();
    int GetRa();
};

