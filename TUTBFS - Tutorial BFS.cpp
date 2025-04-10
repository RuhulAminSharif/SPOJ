#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
vector<ll> x = {-1,-1,-1,0,0,1,1,1};
vector<ll> y = {-1,0,1,-1,1,-1,0,1};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;
    while( t-- ) {
        ll n, m; cin >> n >> m;
        vector<vector<char>> adjMat( n, vector<char>(m) );
        for( ll i = 0; i < n; i += 1 ) {
            for( ll j = 0; j < m; j += 1 ) {
                cin >> adjMat[i][j];
            }
        }
        ll ans = 0;
        queue<pair<ll,ll>>q;
        vector<vector<ll>> level( n + 1, vector<ll> ( m + 1, 0 ) );
        q.push({0,0});
        adjMat[0][0]= '#';
        while( q.size() > 0 ){
            ll i = q.front().first, j = q.front().second;
            q.pop();
            for( ll k = 0; k < 8; k += 1 ) {
                ll nr = i + x[k], nc = j + y[k];
                if( nr >= 0 && nr < n && nc >= 0 && nc < m && adjMat[nr][nc] == '.' ){ //
                    q.push({nr,nc});
                    level[nr][nc] = level[i][j] + 1;
                    adjMat[nr][nc]= '#';
                    ans = max( ans, level[nr][nc] );
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/TUTBFS/