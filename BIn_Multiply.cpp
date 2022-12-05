/*

Binary Multiplication:

e.g.: 3 x (13(base 10)) = 3 x ((1101)(base 2))
                        = 1 x 3 x 8 + 1 x 3 x 4 + 0 x 3 x 2 + 1 x 3 x 1

*/


#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll M = 1e9+7; //Modulo To check overflow

ll bin_mult(ll a, ll b){
    ll ans = 0;
    while(b){
        if(b & 1){
            ans = ((ans+a)%M);
        }
        a = ((a+a)%M);
        b >>= 1;
    }
    return ans;
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << bin_mult(a,b) << E;
    return 0;
}