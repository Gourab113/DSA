// Gourab Biswas
// 12-05-2026, 10:16PM

#include <bits/stdc++.h>
using namespace std;

class teacher
{
  // Properties

public:
  string name;
  float salary;

  teacher()
  {
    cout << "HELLO I AM TEACHER CONSTRUCTOR" << endl;
  }
  teacher(teacher &obj)
  {
    cout << "customize copy constructor" << endl;
    this->name = obj.name;
    this->salary = 11111;
  }
  teacher(string name, float salary)
  {
    this->name = name;
    this->salary = salary;
  }

  // Methods/ member-functions

  void update_name(string name)
  {
    this->name = name;
  }
  void show_details()
  {
    cout << "Name " << this->name << endl;
    cout << "Salary " << this->salary << endl;
  }
};

int main()
{
  teacher tec1;

  // use dot to access data
  tec1.name = "Gourab";
  tec1.salary = 1233;

  tec1.show_details();

  teacher tec2("Gourab chandra", 1222);

  tec2.show_details();

  // Copy contructor, copy one object parameter to other, and it is default constructor

  teacher tec3(tec2);

  tec3.show_details();

  // can Create custom copy constructor

  teacher tec4(tec3);
  tec4.show_details();
}