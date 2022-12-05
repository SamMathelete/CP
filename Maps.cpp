/*
Maps
1. Maps store {key, value} pairs arranged in ascending order of keys.
2. Keys are unique and cannot be repeated.
3. Maps are defined by:
    map<_key type_, _value type_> _map name_;
4. Inserting values can be done by the following ways:
    _map name_[_key_] = _value_; OR
    _map name_.insert({_key_, _value_}); OR
    _map name_.insert(make_pair(_key_, _value_));
    Insertions are done in sizeof(_key_)*O(log(n)) complexity where n = current size of map.
5. Maps are discontinuous memory allocations and are accessed via iterators in loops.
6. Iterator declaration is as per the general rule.
7. _map name_.begin() points at the first element.
8. _map name_.end() points at the element next to the last element.
9. For declared iterator 'it':
    it++ moves to next pair,
    it->first gives the key in the pair,
    it->second gives the value in the pair.
10. In auto declaration in loops e.g. for(auto _iterator name_ : _map name_), 
    _iterator name_.first gives the key,
    _iterator name_.second gives the value.
11. _map name_.find(_value_) returns the iterator to the key-value pair if it is present,
    else it returns _map name_.end(). O(log(n)) complexity.
12. _map name_.erase(key) deletes the key-value pair corresponding to the key.
13. _map name_.erase(_iterator1_, _iterator2_) deletes all pairs between both the iterators including the starting iterator.
14. _map name_.count(_key_) gives 1 if key is present or 0 if it is not.
*/


/*
Given N Strings, print unique strings in lexicographical order with their frequency.
1<=N<=10^5
1<=|S|<=100
*/
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

int main(){
    map<string, ll> m;
    string s;
    ll n;
    cin >> n;
    for(ll i = 0; i<n; i++){
        cin >> s;
        if(m.count(s)){
            m[s]++;
        }
        else{
            m.insert(mp(s, 1));
        }
    }
    for(auto it : m){
        cout << it.first sp it.second << E; // automatically stores in lexicographical order so prints it accordingly.
    }
    return 0;
}

