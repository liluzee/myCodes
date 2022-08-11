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

  vector<int> arr = inputArr(n);

  sort(arr.begin(), arr.end());

  long long int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += abs(arr[i] - i - 1);
  }

  cout << ans << endl;
}