/*
Given a string and indexes l and r find if it is possible to rearrange the characters between indexes l and r 
both inclusive to form a palindrome.

Hint: Use Hash Array and Prefix Sum logic.

Count the number of occurrences of a character in a string from index l to r. if more than 2 are odd then no, else yes.
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
        ll l, r, flag = 2;
        cin >> l >> r;
        l--; 
        r--;
        for(ll i = l; i<=r; i++){
            if((hash[s[i]-'a'][r] - hash[s[i] - 'a'][l-1])%2){
                flag--;
            }
            if(!flag){
                cout << "NO" << E;
                break;
            }
        }
        if(flag){
            cout << "YES" << E;
        }
    }
    return 0;
}
