#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;
    while( t-- ) {
        ll n, m; cin >> n;
        m = n - 1;
        vector<vector<ll>> adj(n+1);
        for( ll i = 1;i <= m; i += 1 ) {
            ll u = i;
            ll x; cin >> x;
            for( ll j = 1; j <= x; j += 1 ) {
                ll v; cin >> v;
                adj[u].push_back(v);
            }
            sort( adj[i].begin(), adj[i].end() );
        }
 
        queue<ll> q;
        q.push(1);
        vector<ll> parent( n + 1, 0 );
        parent[1] = -1;
        while( q.size() > 0 ) {
            ll node = q.front();
            q.pop();
            for( auto adjNode : adj[node] ) {
                if( parent[adjNode] == 0 ) {
                    parent[adjNode] = node;
                    q.push( adjNode );
                }
            }
        }
        if( parent[n] == 0 ) cout << "-1" << endl;
        else {
            vector<ll> path;
            while( parent[n] != -1 ) {
                path.push_back( parent[n] );
                n = parent[n];
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for( auto p : path ) cout << p << " ";
            cout << endl;
            if( t ) cout << endl;
        }
    }
    return 0;
}
// https://www.spoj.com/problems/DIGOKEYS/