/*

Disjoint Set Union:
1. Used while distributing objects into disjoint sets.
2. Functions:
    - Make: Adds new node
    - Find: Returns Parent/Root Node of the group(tree) to which object belongs
    - Union: Joins Two groups to which two different objects belong to.(joins as a tree: parent -> child)
             Joint happens at the root of both the groups.
3. Union Optimisations:
    - By size (Joining small tree to larger tree)
    - By Path Compression(Changing parent to root node)
    

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e5+10;
vector<ll> parent(N, 0);
vector<ll> siz(N, 0);

void make(ll v){        //makes v as an independent node
    parent[v] = v;      //sets its parent as itself
    siz[v] = 1;        //sets size as 1;
    return;
}

ll fin(ll v){
    if(v == parent[v]) return v;    //if it is its own parent, then it is root node, so return it
    return parent[v] = fin(parent[v]); //recurse until root node and then return. In each step change the parent and do so till root node.
                                        //This is called path compression.
}

void Union(ll a, ll b){
    a = fin(a);                //Joint happens at root, so find root
    b = fin(b);
    if(a != b){
        if(siz[a] < siz[b]) swap(a,b);    //smaller joins to bigger. So, make A bigger and B smaller
        parent[b] = a;          //join B to A
        siz[a] += siz[b];     //increase size of A
    }
}

//Time Complexity: O(a(N)): a(N) is called Inverse Ackerman Function. It is called amotorised time complexity.

//Counting the connected components in a graph
int main(){
    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i<=n; i++){
        make(i);
    }
    while(k--){
        ll u, v;
        cin >> u >> v;
        Union(u, v);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        if(fin(i) == i){
            ans++;
        }
    }
    cout << ans << E;
    return 0;
}