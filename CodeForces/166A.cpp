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

// good for 10e7 inputs
// No idea how this works though
vector<int> linearSieve(int n)
{
  const int N = n;
  vector<int> lp(N + 1);
  vector<int> pr;

  for (int i = 2; i <= N; ++i)
  {
    if (lp[i] == 0)
    {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
    {
      lp[i * pr[j]] = pr[j];
    }
  }

  return pr;
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
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++)
  {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;

    arr[i] = {tmp1, tmp2};
  }

  sort(arr.begin(), arr.end());

  int p = n - k;
  pair<int, int> win = arr[p];
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i].first << " " << arr[i].second << endl;
    if (arr[i] == win)
      cnt++;
  }

  cout << cnt;
}