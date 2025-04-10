#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mx = 1e8;
vector<ll> primes;
void sieve()
{
    vector<bool> vis(mx,true);
    vis[0] = vis[1] = false;
    for( ll i = 3; i * i <= mx; i += 2 ) {
        if( vis[i] ) {
            for( ll j = i * i; j <= mx; j += 2 * i ) {
                vis[j] = false;
            }
        }
    }
    primes.push_back(2);
    for( ll i = 3; i <= mx; i += 2 ) {
        if( vis[i] ) {
            primes.push_back(i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve();
    ll t; cin >> t;
    while( t-- ) {
        ll n; cin >> n;
        cout << primes[n-1] << endl;
    }
}
// https://www.spoj.com/problems/TDKPRIME/