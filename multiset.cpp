/*
MultiSets:
1. Allows multiple values in sets.
2. Stores in sorted order.
3. Declaration:
    multiset<_data type_> _multiset name_;
4. Can be used instead of priority queues.
5. _multiset name_.find(_element_) returns iterator to the first instance of the element or _multiset name_.end() if not there.
6. _multiset name_.erase(_value_) erases all instances of that value in the multiset.
7. _multiset name_.erase(_iterator1_, _iterator2_) erases all elements between the iterators including the starting iterator.
8. In order to delete only one instance of the value from the multiset use _multiset name_.erase(_multiset name_.find(_value_).
9. All operations are O(log(n)).
*/


/*
Question:
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/

*/


#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k, inp, ans = 0;
        cin >> n >> k;
        multiset<ll> ss;         //Used instead of priority queue.
        for(ll i = 0; i<n; i++){
            cin >> inp;
            ss.insert(inp);
        }
        for(ll i = 0; i<k; i++){
            auto it = ss.end();  //You have to redeclare 'it' every time as the end is changing.
            it--;
            ans += *(it);
            ss.erase(it);
            ss.insert(*(it)/2);
        }
        cout << ans << E;
    }
    return 0;
}

