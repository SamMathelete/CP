/*
Subset Generation using bitmasking
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
    vector<ll> v(n);
    vector<vector<ll> > sub(1<<n);
    for(auto &it : v){
        cin >> it;
    }
    for(ll j = 0; j<(1<<n); j++){
        for(ll k = 0; k<n; k++){
            if(j & (1 << k)){
                sub[j].pb(v[k]);
            }
        }
    }
    for(auto &it1 : sub){
        for(auto &it: it1){
            cout << it << " ";
        }
        cout << E;
    }
    return 0;
}