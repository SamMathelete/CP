/*

Large Exponentiation using binary multiplication and binary Exponentiation
when M = 1e18.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll M = 1e18;

ll bin_mult(ll a, ll b){
    ll ans = 0;
    while(b){
        if(b & 1){
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

ll bin_exp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = bin_mult(ans , a);
        }
        a = bin_mult(a, a);
        b >>= 1;
    }
    return ans;
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << bin_exp(a, b) << E;
    return 0;
}