#include <bits/stdc++.h>
using namespace std;

struct employee
{
  int id;
  string name;
};

// Or can define structure
typedef struct student
{
  int id;
  string name;
} st;

int main()
{
  struct employee emp1;

  emp1.name = "gourab";
  emp1.id = 113;

  cout << "employee name = " << emp1.name << endl;
  cout << "employee id = " << emp1.id << endl;

  st student;

  student.name = "Gourab";
  student.id = 113;

  cout << "student name =  " << student.name << endl;
  cout << "student id = " << student.id << endl;
}