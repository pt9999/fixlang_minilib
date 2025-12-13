#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

int main1()
{
    int n = 200000;
    int mod = 100000;
    set<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(rand() % mod);
        s.erase(rand() % mod);
    }
    cout << "s.size=" << s.size() << endl;
    return 0;
}

int main()
{
    using ll = long long;

    ll n = (ll) 1e6;
    ll mod = 998244353;
    set<ll> s;
    for(ll i = 0; i < n; i++) {
        s.insert((i * 12345) % mod);
    }
    cout << "s.size=" << s.size() << endl;
    return 0;
}

