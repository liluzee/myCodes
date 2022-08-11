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

unordered_map<int, int> memo;
// memoized DP solution
int answer(int n, int a, int b, int c)
{
  if (n == 0)
    return 0;

  if (n < 0)
    return INT_MIN;
  if (memo.count(n) != 0)
  {
    return memo[n];
  }
  int aUse = 1 + answer(n - a, a, b, c);
  int bUse = 1 + answer(n - b, a, b, c);
  int cUse = 1 + answer(n - c, a, b, c);

  memo[n] = max(aUse, max(bUse, cUse));
  return memo[n];
}
int main()

{
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  cout << answer(n, a, b, c);
}