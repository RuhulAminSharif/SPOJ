#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
ll primsAlgo(vector<vector<pair<int, int>>> &adj, int V, int src)
{
    vector<bool> vis( V + 1, false );
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;

    pq.push({0, src, -1});
    ll mstWeight = 0;
    vector<tuple<int, int, int>> mstEdges;
    while( pq.size() > 0 ) {
        auto [wt, u, parent] = pq.top();
        pq.pop();
        if( vis[u] ) continue;
        vis[u] = true;
        mstWeight += wt;
        if( parent != -1 ) {
            mstEdges.push_back( { parent, u, wt } );
        }
        for( auto &[v,w] : adj[u] ) {
            if( !vis[v] ) {
                pq.push( {w, v, u} );
            }
        }
    }
    return mstWeight;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int V, E;
    while( cin >> V >> E && ( V + E ) ) {
        vector<vector<pair<int, int>>> adj ( V + 1 ); /// node -> node, weight
        ll ans = 0;
        for( ll i = 0; i < E; i += 1 ) {
            ll u, v, w; cin >> u >> v >> w;
            adj[u].push_back( { v, w } );
            adj[v].push_back( { u, w } );
            ans += w;
        }
        ll mstWeight = primsAlgo(adj, V, 0);
        ans -= mstWeight;
        cout << ans << endl;
    }
    return 0;
}
