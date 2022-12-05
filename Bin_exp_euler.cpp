/*

Calculating (a ^ (b ^ c)) using binary exponentiation and euler's totient function

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll M = 1e9 + 7; //prime number

ll bin_mult(ll a, ll b, ll m){
    ll ans = 0;
    while(b){
        if(b & 1){
            ans = (ans + a) % m;
        }
        a = (a + a) % m;
        b >>= 1;
    }
    return ans;
}

ll bin_exp(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = bin_mult(ans, a, m);
        }
        a = bin_mult(a, a, m);
        b >>= 1;
    }
    return ans;
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    cout << bin_exp(a, bin_exp(b, c, M-1), M);
    return 0;
}
