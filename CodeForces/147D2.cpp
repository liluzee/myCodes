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

vector<int> inputArr(int n)
{
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    ans.push_back(tmp);
  }

  return ans;
}

int main()

{
  int n;
  cin >> n;

  int lh = -1;
  int lm = -1;
  int cans = 1;
  int maxans = -1;

  for (int i = 0; i < n; i++)
  {
    int h, m;

    cin >> h >> m;

    if (lh == h && lm == m)
    {
      cans++;
    }
    else
    {
      cans = 1;
    }

    lh = h;
    lm = m;
    maxans = max(cans, maxans);
  }
  cout << maxans << endl;
}