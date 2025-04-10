#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t;
    while( t-- ) {
        ll n; cin >> n;
        ll sum = 0;
        for( ll i = 1LL; i * i <= n; i += 1 ) {
            if( n % i == 0 ) {
                sum += i;
                if( n/i != i ) {
                    sum += n/i;
                }
            }
        }
        cout << sum-n << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/DIVSUM/