#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
#define inf 1e18
vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &adj, ll src, ll V)
{
    set<pair<ll, ll>> st;
    st.insert( {0, src} );
    vector<ll> dist ( V + 1, inf );
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
    return dist;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;
    while( t-- ) {
        ll n, m, src, dst; cin >> n >> m >> src >> dst;
        vector<vector<pair<ll, ll>>> adj ( n + 1 );
        for( ll i = 1; i <= m ; i += 1 ) {
            ll u, v, w; cin >> u >> v >> w;
            adj[u].push_back( { v, w } );
            adj[v].push_back( { u, w } );
        }
        vector<ll> dist = dijkstra(adj, src, n);
        if( dist[dst] == inf ) cout << "NONE" << endl;
        else cout << dist[dst] << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/HIGHWAYS/