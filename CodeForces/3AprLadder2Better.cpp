#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// subsequence of maximal sum DP solution O(n)
// Only change was an edge test case where all elements are 1
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

  vector<int> arr = inputArr(n);

  int tot = 0;
  for (int i = 0; i < n; i++)
  {
    tot += arr[i];
    if (arr[i] == 0)
      arr[i] = 1;
    else
      arr[i] = -1;
  }

  if (tot == n)
  {
    cout << n - 1 << endl;
    return 0;
  }

  int maxSum = INT_MIN;
  int cmax = 0;
  for (int i = 0; i < n; i++)
  {
    cmax += arr[i];
    if (cmax < 0)
      cmax = 0;
    maxSum = max(cmax, maxSum);
    // cout << maxSum << endl;
  }

  cout << maxSum + tot;
}