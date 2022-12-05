/*
Sets:
1. Sets store unique elements in sorted order.
2. Declaration:
    set<_data type_> _set name_;
3. Inserting:
    _set name_.insert(_value_);
    Complexity: O(log(n)), n = current size of set
4. _set name_.find(_value_) returns iterator to value or _set name_.end() if value not there.
5. Loops and Range based loops declarations as per general rule.
6. In function calls, use &_set name_ (by reference) in order to change the actual set not the copy.
    (applies for maps and unordered maps as well)
7. In loops use &_iterator name_ (by reference) in order to change the actual set not the copy.
    (applies for maps and unordered maps as well)
8. _set name_.count(_value_) returns 1 if value present or 0 if absent.
9. _set name_.erase(_value_) erases the value.
10. _set name_.erase(_iterator1_, _iterator2_) erases values between both the iterators including starting iterator.
11. In questions where order matters and unique values are given/required, and frequency of values is not required, use sets.
12. Sets are implemented internally by Red and Black Trees.

*/

/*
Given N strings, print unique strings in lexicographical order.
1<=N<=10^5
1<=|S|<=10^5
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
    set<string> ss;
    string s;
    for(ll i = 0; i<n; i++){
        cin >> s;
        ss.insert(s); // You do not need to check for count. If s already exists in ss, it will simply skip.
    }
    for(auto &it : ss){
        cout << it << E;
    }
    return 0;
}
