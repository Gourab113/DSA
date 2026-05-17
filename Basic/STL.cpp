
#include <bits/stdc++.h>
using namespace std;

int main()
{

  // priority queue, used like max heap, or mean heap
  // orders values according to priority
  // default is max heap, return max value from top

  // max priority queue
  priority_queue<int> q;

  q.push(1);
  q.push(2);

  cout << "top " << q.top() << endl;

  // min priority queue
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(1);
  pq.push(2);

  cout << "top " << pq.top() << endl;

  // queue : fcfs: first come first serve

  queue<int> que;

  que.push(1); // insert element to queue front
  que.push(2);

  cout << "queue front: " << que.front() << endl; // front element 1
  cout << "queue back: " << que.back() << endl;   // back element 2
  que.pop();                                      // remove element from queue front
  cout << "queue front " << que.front() << endl;  // 2

  // pair

  pair<int, int> v;
  v.first = 1;
  v.second = 2;
}
