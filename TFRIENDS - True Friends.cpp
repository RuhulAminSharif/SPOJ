#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
vector<vector<int>> sccs;
void dfs( vector<vector<int>>& adj, int node, vector<bool>& vis, stack<int>& finishTime )
{
    vis[node] = true;
    for( int adjNode : adj[node] ) {
        if( !vis[adjNode] ) {
            dfs( adj, adjNode, vis, finishTime );
        }
    }
    finishTime.push( node );
    return ;
}
void reverseDFS( vector<vector<int>>& transposedAdj, int node, vector<bool>& vis, vector<int>& comp )
{
    vis[node] = true;
    comp.push_back( node );
    for( int adjNode : transposedAdj[node] ) {
        if( !vis[adjNode] ) {
            reverseDFS( transposedAdj, adjNode, vis, comp );
        }
    }
    return ;
}
int SCC( vector<vector<int>>& adj, vector<vector<int>>& transposedAdj, int V )
{
    stack<int> finishTime;
    vector<bool> vis( V + 1, false);
    // To fill the stack with vertices in order of their finishing time
    for( int i = 1; i <= V; i += 1 ) {
        if( !vis[i] ) {
            dfs( adj, i, vis, finishTime );
        }
    }
    sccs.clear();
    fill(vis.begin(), vis.end(), false);
    vector<int> componentID( V + 1, 0 );
    int currID = 0;
    while( finishTime.size() > 0 ) {
        int node = finishTime.top();
        finishTime.pop();
        if( !vis[node] ) {
            vector<int> comp;
            reverseDFS( transposedAdj, node, vis, comp);
            currID += 1;
            sccs.push_back( comp );
            for( auto x : comp ) {
                componentID[x] = currID;
            }
        }
    }
    return sccs.size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    for( ll test = 1; test <= t; test += 1 ) {
        int V, E; cin >> V;
        vector<vector<int>> adj ( V + 1 );
        vector<vector<int>> transposedAdj ( V + 1 );
        for( int u = 1; u <= V; u += 1 ) {
            string x; cin >> x;
            for( int v = 1; v <= V; v += 1 ) {
                if( x[v-1] == 'Y' ) {
                    adj[u].push_back( v );
                    transposedAdj[v].push_back( u );
                }
            }
        }
        cout << SCC( adj, transposedAdj, V ) << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/TFRIENDS/en/