/*
Binary Exponentiation (Recursive Method)
(a^b means a raised to the power b)

e.g.: 3^10 
        = 3^5 * 3^5 
        = (3 * 3^2 * 3^2) * (3 * 3^2 * 3^2)
        = (3 * (3 * 3) * (3 * 3)) * (3 * (3 * 3) * (3 * 3))
        
Complexity for a^b = O(log(b))

Prefer using this over pow function to avoid precision errors.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

ll binexp(ll n, ll m){
    if(m == 0){
        return 1;
    }
    ll a = binexp(n, m/2);
    if(m % 2){
        return n * a * a;
    }
    else{
        return a * a;
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    cout << binexp(n, m) << E;
    return 0;
}

