#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<pair<int, int>> coordinates;

  for (int i = 0; i < n; i++)
  {
    int tmpa, tmpb;

    cin >> tmpa >> tmpb;

    coordinates.push_back({tmpa, tmpb});
  }
}