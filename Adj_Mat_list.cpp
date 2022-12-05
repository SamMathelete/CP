/*

Adjacency matrix and Adjacency List representation of graph

Adjacency Matrix:
1. If V vertices are there, consider a V x V matrix A initiated by 0 and if ith and jth vertices are
   connected(there exists an edge from i to j which can be traversed from i to j), then A[i][j] = 1.
  
2. If an edge joining i to j is having weight k, then A[i][j] = k.

(In both cases for undirected, A[i][j] = A[j][i])

3. Space Complexity: O(N^2)

Due to high space complexity of this approach it is less used and adjacency list method is more used.

Adjacency List:
1. If V vertices are there, initiate V vectors and in vector at index i, push back all the vertex indexes
   which are connected to vertex i.
   
   Space Complexity: O(V + E)

2. To store weights, use vector of pairs pair<_vertex_, _weight_>.

3. For more optimisation sets and multisets can be used in specific special cases. 

*/

/*

Given a undirected graph of N vertices and M edges, find the most edged vertex and all the vertices it is connected to.
Each edge has a weight W and if i and j are connected by an edge of weight W, then
it is equivalent of having W edges between them, so more connected.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll> > > v(n+1);  //Adjacency list
    vector<ll> v11(n+1, 0);
    for(ll i = 0; i<m; i++){
        ll v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        v[v1].pb(mp(v2, wt));       //Adding vertex v2 to the adjacency list of v1
        v[v2].pb(mp(v1, wt));       //Adding vertex v1 to the adjacency list of v2 as it is undirected
        v11[v2] += wt;              //Adding weight to v2
        v11[v1] += wt;              //Adding weight to v1
    }
    ll maxi = 0, maxn = 0;
    for(ll i = 1; i<=n; i++){       //checking for maximum weight
        if(v11[i] > maxn){
            maxi = i;
            maxn = v11[i];
        }
    }
    cout << maxi << E;
    for(auto &it : v[maxi]){
        cout << it.first << " ";
    }
    cout << E;
    return 0;
}


