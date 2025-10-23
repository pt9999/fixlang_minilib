#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 200000;
    int mod = 100000;
    set<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(rand() % mod);
        s.erase(rand() % mod);
    }
    cout << "s.size=" << s.size() << endl;
}
