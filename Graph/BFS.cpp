#include <bits/stdc++.h>
using namespace std;

int vis[1004];
vector<int> v[1004];

void bfs(int d)
{

  vis[d] = 1;
  queue<int> q;

  q.push(d);

  while (!q.empty())
  {
    int d = q.front();
    q.pop();
    vis[d] = 1;
  }
}

int main()
{
}