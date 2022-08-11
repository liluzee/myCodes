#include <iostream>
#include <bits/stdc++.h>
// USE LONG LONG INTS EVERYWHERE OR CODEFORCES GOES NUTS FOR SOME DAMN REASON
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
  vector<int> sortedarr;
  vector<long long int> prefixSum(n);
  vector<long long int> sortedPrefixSum(n);
  long long int csum = 0;
  for (int i = 0; i < n; i++)
  {
    sortedarr.push_back(arr[i]);
    csum += arr[i];
    prefixSum[i] = csum;
  }

  sort(sortedarr.begin(), sortedarr.end());
  csum = 0;
  for (int i = 0; i < n; i++)
  {
    csum += sortedarr[i];
    sortedPrefixSum[i] = csum;
  }
  int m;
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    int type, l, r;
    cin >> type >> l >> r;
    long long int ans;
    if (type == 1)
    {
      ans = prefixSum[r - 1] - prefixSum[l - 1] + arr[l - 1];
      cout << ans << endl;
    }
    else
    {
      ans = sortedPrefixSum[r - 1] - sortedPrefixSum[l - 1] + sortedarr[l - 1];
      cout << ans << endl;
    }
  }
}