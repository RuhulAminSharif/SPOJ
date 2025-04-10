#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mx = 1e7 + 8 ;
set<ll> primes;
vector<bool> vis( mx , true );
void sieve() {
  vis[0] = vis[1] = false;
  for( ll i = 3; i * i <= mx; i += 2 ) {
    if( vis[i] ) {
        for( ll j = i * i; j <= mx; j += 2 * i ) {
            vis[j] = false;
        }
    }
  }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    sieve();
    vector<ll> marks(mx,0);
    for( ll x = 0; x * x <= mx; x += 1 ) {
        for( ll y = 0; y * y * y * y <= mx; y += 1 ) {
            ll num = x * x + y * y * y * y;
            if( num >= mx ) {
                break;
            }
            if( num == 2 || ( ( num & 1) && (vis[num]) ) ) {
                marks[num] = 1;
            }
        }
    }
    for( ll i = 1; i < mx; i += 1 ) {
        marks[i] += marks[i-1];
    }
    ll t; cin >> t;
    while( t-- ) {
        ll n; cin >> n;
        cout << marks[n] << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/HS08PAUL/