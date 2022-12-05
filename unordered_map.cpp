/*
Unordered Maps:
1. All functions same as ordered maps.
2. Keys are not stored in ordered manner.
3. Ordered maps use Red Black trees for implementation,
   Unordered maps use Hash Tables for implementation.
4. Declaration:
    unordered_map<_key type_, _data type_> _map name_;
5. Insertions Time Complexity(Average) = O(1)
6. .find() works in O(1)
7. .count() works in O(1)
8. Whenever order does not matter, use unordered maps.
9. Ordered maps can take any datatype for key.
   For unordered maps, allowed data types:
   1. int, long long int, long int
   2. float, double
   3. char, string
   All those whose hash functions exist.
10. If keys are not very complex and Question does not require order, use unordered_map.
*/

/*
Given N Strings and Q Queries.
In each query you are given a string, print frequency of the string.

1<=N<=10^6
1<=|S|<=100
Q<=10^6
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

int main(){
    ll n;
    cin >> n;
    string s;
    unordered_map<string, ll> m; //order does not matter in Question. To save time, use unordered_map.
    for(ll i = 0; i<n; i++){
        cin >> s;
        if(m.count(s)){
            m[s]++;
        }
        else{
            m.insert(mp(s, 1));
        }
    }
    ll q;
    cin >> q;
    while(q--){
        cin >> s;
        if(m.count(s)){
            cout << m[s] << E;
        }
        else{
            cout << 0 << E;
        }
    }
    return 0;
}
