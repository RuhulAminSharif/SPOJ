#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define inf 1e9
ll calc(vector<ll>&v, ll idx)
{
    if( idx < 0 ) return 0;
    return v[idx] + calc(v,idx-1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    for( ll tt = 1; tt <= t; tt += 1 ) {
        cout << "Case " << tt << ": ";
        ll n; cin >> n;
        vector<ll> v( n );
        for( ll i = 0; i < n; i += 1 ) cin >> v[i];
        cout << calc(v,n-1) << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/HRECURS/