/*
Unordered Sets:
1. Same as Sets but elements are not arranged in sorted order.
2. Allowed data types are same as unordered maps keys.
3. If order does not matter and values are of allowed data types, use unordered sets.
4. All Functions have time complexity O(1).
5. Internal Implementation via hash tables.
6. .find(), .count(), .insert(), etc same as sets.
7. Declaration:
    unordered_set<_data type_> _set name_;
*/

/*
Given N Strings and Q queries and each query has a string, print YES if the string is present in the N Strings
and NO if it is not.
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
    unordered_set<string> ss;
    string s;
    for(ll i = 0; i<n; i++){
        cin >> s;
        ss.insert(s);
    }
    ll q;
    cin >> q;
    while(q--){
        cin >> s;
        if(ss.count(s)){
            cout << "YES" << E;
        }
        else{
            cout << "NO" << E;
        }
    }
    return 0;
}