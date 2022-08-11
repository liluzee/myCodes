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

// Nearest Greater To Right
int NGR(vector<int> arr, int index)
{
  stack<int> s;
  int n = arr.size();
  vector<int> NGR(n, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    if (!s.empty())
    {
      if (s.top() > arr[i])
      {
        NGR[i] = s.top();
      }
      else
      {
        while (!s.empty() && s.top() <= arr[i])
        {
          s.pop();
        }

        if (s.empty())
        {
          NGR[i] = -1;
        }
        else
        {
          NGR[i] = s.top();
        }
      }
    }
    else
    {
      NGR[i] = -1;
    }

    s.push(arr[i]);
  }

  printArr(NGR);
  return NGR[index];
}

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << NGR(arr, 2);
}