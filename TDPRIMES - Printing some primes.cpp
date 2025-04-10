#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int mx = 1e8+5;
vector<bool> is_prime(mx);
vector<int> prime;
void sieve( )
{
    is_prime[0] = is_prime[1] = true;
    for( int i = 3; i * i < mx; i += 1 ) {
        if( is_prime[i] == false ) {
            for( int j = i * i; j < mx; j += 2 * i ) {
                is_prime[j] = true;
            }
        }
    }
    prime.push_back(2);
    for( int i = 3; i < mx; i += 2 ) {
        if( is_prime[i] == false ) {
            prime.push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    for( ll i = 1; i < prime.size() ; i += 100 ) {
        cout << prime[i-1] << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/TDPRIMES/