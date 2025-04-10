#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t;
    while( t-- ) {
        ll a, b; cin >> a >> b;
        ll g = __gcd(a,b);
        set<ll> st;
        for( ll i = 1LL; i * i <= g; i += 1 ) {
            if( g % i == 0 ) {
                st.insert(i);
                st.insert(g/i);
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/COMDIV/