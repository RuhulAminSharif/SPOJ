#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mx = 1e6 + 8 ;
set<ll> primes;
vector<ll> afraidPrimes;
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
  primes.insert(2);
  for( ll i = 3; i <= mx; i += 2 ) {
    if( vis[i] ) {
        primes.insert(i);
    }
  }
}
bool check(ll p )
{
    string s = to_string(p);
    ll len = s.size();
    for( ll i = 0; i < len; i += 1 ) {
        ll num = stoll(s.substr(i, len-i));
        if( primes.find(num) == primes.end() ) return false;
    }
    for( ll i = 0; i < len; i += 1 ) {
        if( s[i] == '0' ) return false;
    }
    return true;
}
void afraid( )
{
    ll len = primes.size();
    for( auto p : primes ) {
        if( check(p) ) afraidPrimes.push_back(p);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    sieve();
    afraid();
    ll t; cin >> t;
    while( t-- ) {
        ll n; cin >> n;
        ll low = 0, high = afraidPrimes.size()-1, mid;
        while( low <= high ) {
            mid  = low + ( high - low ) / 2;
            if( afraidPrimes[mid] > n ) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        cout << low << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/VECTAR8/