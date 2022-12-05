/*

Binary Exponentiation (Iterative Method)

e.g: 3^(13(base 10)) 
        = 3^((1101)(base 2))
        = 1*3^8 * 1*3^4 * 0*3^2 * 1*3^1

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans *= a;   //if bit is set the ans includes
        }
        a *= a;         // generates a^2, a^4, ...
        b >>= 1;
    }
    return ans;
}

int main(){
    ll n, m;
    cin >> n >> m;
    cout << binexp(n, m) << E;
    return 0;
}