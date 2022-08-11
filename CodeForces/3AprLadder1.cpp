#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArr(vector<int> &a)
{
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}
int main()

{
  int n, m;
  cin >> n >> m;
  vector<int> arr;

  int tmp;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    arr.push_back(tmp);
  }

  set<int> s1;

  for (int i = n - 1; i >= 0; i--)
  {
    s1.insert(arr[i]);
    arr[i] = s1.size();
  }
  // printArr (arr);

  for (int i = 0; i < m; i++)
  {
    cin >> tmp;
    cout << arr[tmp - 1] << endl;
  }
}