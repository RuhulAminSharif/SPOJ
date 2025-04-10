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
        ll n, m; cin >> n >> m;
        vector<vector<char>> grid(n+2, vector<char>(m+2));
        for( ll i = 1; i <= n; i += 1 ) {
            for( ll j = 1; j <= m; j += 1 ) {
                cin >> grid[i][j];
            }
        }
        vector<vector<ll>> dist( n + 1, vector<ll> ( m + 1, LLONG_MAX ) );
        deque<pair<ll,ll>> dq;
        dq.push_front( {1,1} );
        dist[1][1] = 0;
        vector<ll> dx = {-1,0,0,1};
        vector<ll> dy = {0,-1,1,0};
        while( dq.size() > 0 ) {
            auto [x,y] = dq.front();
            dq.pop_front();
            for( ll i = 0; i < 4; i += 1 ) {
                ll new_x = x + dx[i];
                ll new_y = y + dy[i];
                ll currCost = 0;
                if ( new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m ) {
                    if( grid[x][y] != grid[new_x][new_y] ) currCost += 1;
 
                    if( dist[x][y] + currCost < dist[new_x][new_y] ) {
                        dist[new_x][new_y] = dist[x][y] + currCost;
                        if( currCost ) dq.push_back( {new_x, new_y} );
                        else dq.push_front( {new_x, new_y} );
                    }
                }
            }
        }
        cout << dist[n][m] << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/KATHTHI/