/*

Lower Bound:
1. Function Prototype:
    For Vectors: 
        lower_bound(_start iterator_, _end iterator_, _element_);
        *(_end iterator_ is excluded in the search).
    For Sets and Maps:
        _set/map name_.lower_bound(_element_);
2. Always used on sorted data structures.
3. Works with O(log(n)) complexity.
4. Returns
    a. iterator of first instance of element OR
    b. iterator of first element greater than the element passed OR
    c. .end() iterator if none of the above 2 exist.

Upper Bound:
1. Function Prototype:
    For Vectors: 
        upper_bound(_start iterator_, _end iterator_, _element_);
        *(_end iterator_ is excluded in the search).
    For Sets and Maps:
        _set/map name_.upper_bound(_element_);
2. Always used on sorted data structures.
3. Works with O(log(n)) complexity.
4. Returns
    a. iterator of first element greater than the element passed OR
    b. .end() iterator if the above does not exist.

*/

/*
Given a set of N integers and an integer, find if the integer exists in the set and if yes, print "YES", else print "NO".
Also print the number in the set just greater than the integer in a new line. If none such exist, print -1.
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, inp, m;
    cin >> n;
    set<ll> ss;                     //using sets because we need sorted unique list of numbers as we dont care about multiple instances
    for(ll i = 0; i<n; i++){
        cin >> inp;
        ss.insert(inp);
    }
    cin >> m;
    auto it1 = ss.lower_bound(m);
    auto it2 = ss.upper_bound(m);
    if(it1 != ss.end() && *it1 == m){
        cout << "YES" << E;
    }
    else{
        cout << "NO" << E;
    }
    if(it2 != ss.end()){
        cout << *it2 << E;
    }
    else{
        cout << -1 << E;
    }
    return 0;
}