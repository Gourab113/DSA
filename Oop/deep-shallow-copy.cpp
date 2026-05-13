// Gourab, sri krishna
// 13-5-2026, 12:21PM

// copy constructor: copies one object to another
// Shallow copy: copies the values of one object to another
// Deep copy: copies the values of object also makes copies of dynamically allocated memory

// *() : gives the value of that address

// Destructor
//  Destructor: Destroy object, free memory, called automatically.
//  But destructor free only the static memory, not the dynamically allocated memory.

// delete pinter, delete the pinter from the address;

#include <bits/stdc++.h>
using namespace std;

// shallow copy
class student
{
public:
  string name;
  double cgpa;
  string *address;

  void show_info()
  {
    cout << "Name: " << this->name << endl;
    cout << "Cgpa: " << this->cgpa << endl;
    cout << "address: " << *(this->address) << endl;
  }
};

// deep copy, need to create custom constructor
class teacher
{
public:
  string name;
  string *address;
  teacher()
  {
  }
  teacher(teacher &obj)
  {
    this->name = obj.name;
    this->address = new string;
    *(this->address) = *(obj.address);
  }

  // destructor
  ~teacher()
  {
    cout << "HI I DELETE EVERYTHING" << endl;
  }

  void show_info()
  {
    cout << "Name: " << this->name << endl;
    cout << "address: " << *(this->address) << endl;
  }
};

int main()
{
  student s1;

  s1.name = "gourab";
  s1.cgpa = 3.22;
  *(s1.address) = "Rajbari Dhaka";

  student s2(s1); // shallow copy, so both s1,s2 address ponter points same address
  // change in one address value change others.

  s1.show_info();
  *(s2.address) = "Mohakhali dhaka";
  s1.show_info(); // change the address of s1 object, because shallow copy not copy
  // the dynamically allocated values

  cout << "Teacher" << endl;
  teacher t1;
  t1.name = "teach1";
  *(t1.address) = "Bonani, dhaka";

  teacher t2(t1);

  t1.show_info();
  *(t2.address) = "Mohakhali dhaka";
  t1.show_info();
  t2.show_info();
}