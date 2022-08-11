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

// Regular Sieve
vector<bool> primes(int n)
{
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++)
  {
    if (is_prime[i] && (long long)i * i <= n)
    {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }

  return is_prime;
}

// interesting observation -> ONLY squares of prime numbers are T-Primes.
int main()

{
  int n;
  cin >> n;

  vector<bool> myPrimes = primes(10e6);

  set<long long int> s;
  for (long long int i = 0; i < myPrimes.size(); i++)
  {
    if (myPrimes[i])
    {
      long long int x = i * i;

      s.insert(x);
    }
  }

  for (int i = 0; i < n; i++)
  {
    long long int m;
    cin >> m;

    if (s.count(m))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}