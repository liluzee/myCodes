#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    string s;
    cin >> s;

    int ans = 0;
    set<char> top3;

    for (int i = 0; i < s.length(); i++)
    {
      if (!top3.count(s[i]))
      {
        top3.insert(s[i]);
      }

      if (top3.size() > 3)
      {
        ans++;
        top3.clear();
        top3.insert(s[i]);
      }
    }

    if (top3.size())
      ans++;

    cout << ans << endl;
  }
}