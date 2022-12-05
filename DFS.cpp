/*

Depth First Search:
1. Visited Array: If vertex i is visited then, v[i] = 0, else v[i] = 1;
2. Uses Recursion and Backtracking to traverse graphs and trees.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e5+10;
vector<vector<ll> > g(N);   //adjacency list representation of matrix
vector<bool> vis(N, 0);        //visited array

//dfs recursive function
void dfs(ll vertex){
    /**
     * Code Part 1
     * Take Action on the vertex after entering the vertex
     **/
    if(vis[vertex]) return; //if visited return before entering children
    vis[vertex] = 1;      //visited = 1 as we visited it
    for(ll child : g[vertex]){
        /**
         * Code Part 2
         * Take Action on child before entering the 
         * child node
         * */
        dfs(child);
        /**
         * Code Part 3
         * Take Action on child after entering
         * the child node
         * */
    }
    /**
     * Code Part 4
     * Take Action on the vertex before exiting the vertex
     * */
}

int main(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i<m; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    ll vinp;
    cin >> vinp;
    dfs(vinp);
    return 0;
}