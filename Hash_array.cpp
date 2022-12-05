/*
Count the number of occurrences of a character in a string from index l to r.

Important: Do Not use hashing when no. of items in hash array is greater than 10^7. If it is greater than 10^5 declare hash array in global scope.
Here, it is 26 only(26 alphabets). Always check constraints of elements to be hashed(e.g. 1<=N<=10^5).

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
    cin >> s;
    vector<vector<ll> > hash(26, vector<ll>(n, 0));
    for(ll i = 0; i<n; i++){
        hash[s[i] - 'a'][i]++;
    }
    for(ll i = 0; i<26; i++){
        for(ll j = 1; j<n; j++){
            hash[i][j] += hash[i][j-1];
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        char c;
        cin >> l >> r >> c;
        l--;
        r--;
        cout << hash[c-'a'][r] - hash[c-'a'][l-1] << E;
    }
    return 0;
}