#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    queue<int> q;
    for( int i = 0; i < t; i += 1 ){
        int type; cin >> type;
        if( type == 1 ) {
            int data; cin >> data;
            q.push( data );
        }
        else if( type == 2 ) {
            if( !q.empty() ) q.pop();
        }
        else {
            if( q.empty() ) cout << "Empty!" << endl;
            else cout << q.front() << endl;
        }
    }
}
// https://www.spoj.com/problems/QUEUEEZ/