#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    string s;
    cin >> s;

    int n = s.length();
    unordered_map<char, int> m1;

    for (int i = 0; i < n; i++)
    {
      m1[s[i]]++;
    }

    int ci = 0;
    for (int i = 0; i < n; i++)
    {
      if (m1[s[i]] > 1)
      {
        m1[s[i]]--;
        ci = i;
        continue;
      }
      else
      {
        ci = i;
        break;
      }
    }

    cout << s.substr(ci, n - ci) << endl;
  }
}