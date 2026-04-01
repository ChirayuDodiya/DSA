#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;

long long fact[MAXN], invFact[MAXN];

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    invFact[MAXN - 1] = power(fact[MAXN - 1], mod - 2);

    for (int i = MAXN - 2; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (fact[n] * invFact[r] % mod * invFact[n - r] % mod) % mod;
}

long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (fact[n] * invFact[n - r] % mod) % mod;
}

int main(){
    precompute();
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
    cout << nPr(n, r) << endl;
    return 0;
}