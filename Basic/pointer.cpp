// Gourab

// 09 - 05 - 2026, 9:00 PM

// Pointer in c++

#include <bits/stdc++.h>
using namespace std;

void add_10(int *value)
{
  *value = 20; // dereference that pointer to get that variable
};

void add_10_alias(int &value) // two variable points same address
{
  value += 10;
}
int main()
{
  // &A gives the address of variable A
  string name = "Gourab";
  cout << (&name) << endl; // print memory address

  // Pointer store the address of another variable using the variable type

  string *name_address = &name;

  cout << name_address << endl;

  float price = 12;
  float *price_address = &price;

  cout << price << endl;
  cout << price_address << endl; // gives the memory address

  // *(address) or *(&variable)  gives the value of that address, Dereference operator
  cout << *(&price) << endl;
  cout << *price_address << endl; // gives the value of that address, of that variable

  // Null pointer nullptr
  int *ptr = nullptr; // It represents pointer don't store any memory address
  cout << ptr << endl;

  // Pass by reference, pass the reference of variable in a function to change original value

  int value = 10;
  add_10(&value);
  cout << "value + 10 = " << value << endl;

  int count = 5;

  add_10_alias(count);

  cout << "count + 10 =" << count << endl;

  // Array pointer

  int array[] = {1, 2, 3};

  // array is a pointer that points to the first value of that array, 0th index

  cout << (array) << endl;  // points 0th index, constant pointer can't be change
  cout << (*array) << endl; // prints value of 0th index

  // pointer arithmatic

  // increment, pointer++, points to next address by the memory size
  // decrement, pointer-- , points to the previous address by the memory size

  int a = 10;

  int *ptr_a = &a;

  cout << (ptr_a) << endl;

  ptr_a++;

  cout << (ptr_a) << endl; // point next integer address, +4 byte

  ptr_a--;
  cout << (ptr_a) << endl;

  /// can d0 +1, +2, +x

  // Can compare, subtract two pointers  ptr1 < ptr2, ptr1 == ptr2
}
