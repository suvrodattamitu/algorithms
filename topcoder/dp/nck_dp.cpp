//https://arena.topcoder.com/#/u/practiceCode/19194/260455/17559/2/337021
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long Int;
const int N = 2205;

Int fact[N], invfact[N], inv[N];
int DP[2048 * 2048 / 2][26];

void init()
{
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = -inv[MOD%i] * (MOD / i) % MOD;
    if (inv[i] < 0) inv[i] += MOD;
  }
  invfact[0] = 1;
  for (int i = 1; i < N; i++) {
    invfact[i] = invfact[i - 1] * inv[i] % MOD;
  }
}

Int nCk(Int n, Int k)
{
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

Int nPk(Int n, Int k)
{
  return fact[n] * invfact[n - k] % MOD;
}

long long solve(const string& name, int pos, int prev, int K) 
{
  if (K == 0)
    return 1;
  if (pos + K > name.size())
    return 0;
  int& ret = DP[(2 * 2004 - K + 1) * K / 2 + pos][prev];
  if (ret >= 0)
    return ret;
  int cur = name[pos] - 'A';
  long long r = solve(name, pos + 1, prev, K);
  if (prev <= cur) {
    r += solve(name, pos + 1, cur, K - 1);
  }
  return ret = (r % MOD);
}

class ImproveName {
 public:
  int improve(string name, int K) {
    memset(DP, -1, sizeof(DP));
    return solve(name, 0, 0, K);
  }
};

int main() {
    init();
    Int k = 3;
    string str = "EEDDCCBBAA";
    Int n = str.size();
    ImproveName obj;
    int ret = obj.improve(str, k);
    cout << (nCk(n, k) + MOD - ret) % MOD << endl;
}