/*

Modular Multiplicative Inverse

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll M = 1e9+7;

ll bin_exp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

ll mmi(ll n){
    return bin_exp(n, M-2);
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << ((a % M) * (mmi(b) % M)) % M << E;
    return 0;
}

//Modular Multiplicative Inverse is a big number. So chill.