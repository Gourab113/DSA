
#include <bits/stdc++.h>
using namespace std;

int main()
{

  set<int> st;

  // insert element
  st.insert(0);
  st.insert(1);
  st.insert(2);
  st.insert(3);
  st.insert(2);

  // iterate through element

  for (auto it = st.begin(); it != st.end(); it++)
  {
    cout << (*it) << " ";
  }
  cout << endl;

  // loop

  for (auto x : st)
  {
    cout << x << " ";
  }
  cout << endl;

  // set.find(value): used to find a value in set, return iterator
  // need this
  if (st.find(2) != st.end())
  {
    cout << "FOUND" << endl;
  }

  // remove value from set: st.erase(value)

  st.erase(2);

  for (auto x : st)
  {
    cout << x << " ";
  }
  cout << endl;

  // can use lower, upper bound

  auto it = st.lower_bound(-1);
  cout << (*it) << endl;
}
