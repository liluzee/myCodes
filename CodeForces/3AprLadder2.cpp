#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// kind of brute force O(n^2)
// subsequence of maximal sum improvement of this method would be O(n)
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
  }
  int maxans = -1;
  for (int i = 0; i < n; i++)
  {
    int net = 0;
    int maxnet = -1;
    for (int j = i; j < n; j++)
    {
      if (!arr[j])
      {
        net++;
      }
      else
      {
        net--;
      }
      maxnet = max(net, maxnet);
    }

    int cans = tot + maxnet;
    maxans = max(cans, maxans);
  }

  cout << maxans << endl;
}