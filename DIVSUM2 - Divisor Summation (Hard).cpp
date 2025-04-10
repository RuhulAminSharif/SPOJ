#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define endl "\n"
const ll mx = 1e8 + 8 ;
vector<ll> primes;
void sieve() {
  vector<bool> vis( mx , true );
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
ll power( ll x, ll y )
{
    ll res = 1;
    while( y ) {
        if( y & 1 ) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}
ll get_sod( ll n )
{
    ll sod = 1;
    for( ll i = 0; i < primes.size() && primes[i] * primes[i] <= n; i += 1 ) {
        ll cnt = 0;
        while( n % primes[i] == 0 ) {
            cnt += 1;
            n /= primes[i];
        }
        sod *= ( ( power( primes[i], cnt+1 ) - 1 ) / ( primes[i] - 1 ));
    }
    if( n > 1 ) sod *= ( n + 1);
    return sod;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    sieve();
    ll t; cin >> t;
    while( t-- ) {
        ll n; cin >> n;
        cout << get_sod(n) - n  << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/DIVSUM2/