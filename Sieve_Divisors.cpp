/*

Using Sieve Algorithm to find all divisors of a number

*/


#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e5+10;
vector<vector<ll> > divi(N);

void sieve(){
    for(ll i = 1; i<N; i++){
        for(ll j = i; j<N; j+=i){
            divi[j].pb(i);
        }
    }
    return;
}

int main(){
    sieve();
    ll q, n;
    cin >> q;
    while(q--){
        cin >> n;
        for(auto &it : divi[n]){
            cout << it << " ";
        }
        cout << E;
    }
    return 0;
}