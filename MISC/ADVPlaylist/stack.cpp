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
// 3 Conditions
// Stack Empty -> -1
// Stack Not Empty && Top > Curr -> ans[i] = top
// Stack Not Empty and Top<=Curr -> Pop until empty and top <= curr.
int NGR(vector<int> arr, int index)
{
  stack<int> s;
  int n = arr.size();
  vector<int> NGR(n, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    if (s.empty())
    {
      NGR[i] = -1;
    }
    else if (!s.empty() && s.top() > arr[i])
    {
      NGR[i] = s.top();
    }
    else if (!s.empty() && s.top() <= arr[i])
    {
      while (!s.empty() && s.top() <= arr[i])
      {
        s.pop();
      }

      if (s.empty())
        NGR[i] = -1;
      else
        NGR[i] = s.top();
    }
    s.push(arr[i]);
  }

  printArr(NGR);
  return NGR[index];
}

// Nearest Greater to Left
// Almost same code only difference is the for loop direction
int NGL(vector<int> arr, int index)
{
  stack<int> s;
  int n = arr.size();
  vector<int> NGL(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (s.empty())
    {
      NGL[i] = -1;
    }
    else if (!s.empty() && s.top() > arr[i])
    {
      NGL[i] = s.top();
    }
    else if (!s.empty() && s.top() <= arr[i])
    {
      while (!s.empty() && s.top() <= arr[i])
      {
        s.pop();
      }

      if (s.empty())
        NGL[i] = -1;
      else
        NGL[i] = s.top();
    }
    s.push(arr[i]);
  }
  printArr(NGL);

  return NGL[index];
}

// NSL
// Nearest Smaller to Left

int NSL(vector<int> arr, int index)
{
  stack<int> s;
  int n = arr.size();
  vector<int> NSL(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (s.empty())
    {
      NSL[i] = -1;
    }
    else if (!s.empty() && s.top() < arr[i])
    {
      NSL[i] = s.top();
    }
    else if (!s.empty() && s.top() >= arr[i])
    {
      while (!s.empty() && s.top() >= arr[i])
      {
        s.pop();
      }

      if (s.empty())
        NSL[i] = -1;
      else
        NSL[i] = s.top();
    }
    s.push(arr[i]);
  }
  printArr(NSL);

  return NSL[index];
}

// NSR
// Nearest Smaller to Right

int NSR(vector<int> arr, int index)
{
  stack<int> s;
  int n = arr.size();
  vector<int> NSR(n, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    if (s.empty())
    {
      NSR[i] = -1;
    }
    else if (!s.empty() && s.top() > arr[i])
    {
      NSR[i] = s.top();
    }
    else if (!s.empty() && s.top() <= arr[i])
    {
      while (!s.empty() && s.top() <= arr[i])
      {
        s.pop();
      }

      if (s.empty())
        NSR[i] = -1;
      else
        NSR[i] = s.top();
    }
    s.push(arr[i]);
  }
  printArr(NSR);

  return NSR[index];
}

// Stock Span Problem
// Given an array of prices of stock on day i
// For each day, we need to give how many consecutive days before the current day, the price was smaller or equal to it.

// Approach -> Required answer for index i is = i - NGL[i];
int main()
{
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << NSL(arr, 2);
}