#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;
const int N = 1e5+5;
vector<int> g[N];
vector<bool> vis(N);
void dfs( int node )
{
    vis[node] = true;
    for( auto it : g[node] ) {
        if( vis[it] == false ) {
            dfs(it);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for( int i = 0; i < m; i += 1 ) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for( int i = 1; i <= n; i += 1 ) {
        if( vis[i] == false ) {
            dfs(i);
            cnt += 1;
        }
    }
    if( cnt == 1 && m < n ) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/PT07Y/