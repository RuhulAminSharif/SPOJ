#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9+7;
class Trie {
private:
    class Node {
    public:
        Node * edges[30];
        ll words, prefix;
        Node() {
            words = 0;
            prefix = 0;
            for( ll i = 0; i < 30; i += 1 ) {
                edges[i] = nullptr;
            }
        }
    };
public:
    Node *root;
    Trie() {
        root = new Node();
    }
 
    int getIndex( char ch ) {
        return ch - 'a';
    }
 
    void insertStr(string &word) {
        Node* curr = root; // staring with the root node
        for( ll i = 0; i < word.size(); i += 1 ) {
            int idx = getIndex(word[i]);
            if( curr->edges[idx] == nullptr ) { // indicates no edge
                curr->edges[idx] = new Node(); // then create a new edge
            }
            curr = curr ->edges[idx]; // to the next edge
            curr->prefix += 1; // increasing prefix count
        }
        curr->words += 1; // increasing words count
    }
    
    ll startsWith(string &prefix) {
        Node* curr = root;
        for( ll i = 0; i < prefix.size(); i += 1 ) {
            int idx = getIndex(prefix[i]);
            if( curr->edges[idx] == nullptr ) {
                return false;
            }
            curr = curr ->edges[idx];
        }
        return curr->prefix;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    Trie* tr = new Trie();
    ll n, q; cin >> n >> q;
    for( ll i = 0; i < n; i += 1 ) {
        string s; cin >> s;
        tr ->insertStr(s);
    }
    while( q-- ) {
        string s; cin >> s;
        cout << tr -> startsWith(s) << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/ADAINDEX/