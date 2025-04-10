#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
#define inf 1e18
vector<ll> dist ( 510, inf );
void dijkstra(vector<vector<pair<ll, ll>>> &adj, ll src)
{
    set<pair<ll, ll>> st;
    st.insert( {0, src} );
    dist[src] = 0;
    while( st.size() > 0 ) {
        auto it = *(st.begin());
        ll node = it.second;
        st.erase(st.begin());
        for( auto it : adj[node] ) {
            ll adjNode = it.first;
            ll adjWeight = it.second;
            ll nextWeight = dist[node] + adjWeight;
            if( nextWeight < dist[adjNode] ) {
                st.erase( {dist[adjNode], adjNode} );
                dist[adjNode] = nextWeight;
                st.insert( { nextWeight, adjNode } );
            }
        }
    }
    return ;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<vector<pair<ll, ll>>> adj ( 510 );
    for( ll i = 1; i <= n ; i += 1 ) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back( { v, w } );
        adj[v].push_back( { u, w } );
    }
    ll src ; cin >> src;
    dijkstra(adj, src );
    ll q; cin >> q;
    while( q-- ) {
        ll v; cin >> v;
        if( dist[v] == inf ) cout << "NO PATH" << endl;
        else cout << dist[v] << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/TRVCOST/