#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
 
const ll mx = 1e7;
vector<bool>vis(mx+1);
vector<ll>prime;
 
void sieve()
{
    vis[0]=vis[1] = true;
    for(ll i=3; i*i<=mx;i+=2){
        if(vis[i]==false){
            for(ll j=i*i; j<=mx; j+=2*i){
                vis[j]=true;
            }
        }
    }
    prime.push_back(2);
    for(ll i=3; i<=mx; i+=2){
        if(vis[i]==false){
            prime.push_back(i);
        }
    }
}
void prime_factor( ll n )
{
    for(ll i=0; prime[i] * prime[i] <= n; i += 1  ) {
        if( n % prime[i] == 0 ) {
            cout << prime[i] << endl;
            while( n % prime[i] == 0 ) {
                n /= prime[i];
            }
        }
    }
    if( n > 1 ) cout << n << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    ll n; cin >> n;
    prime_factor(n);
    return 0;
}
// https://www.spoj.com/problems/OPCPRIME/