/*

Primes

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

bool isprime(ll n){
    if(n == 0 || n == 1){
        return 0;
    }
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    ll n;
    cin >> n;
    for(ll i = 0; i<=n; i++){
        if(isprime(i)){
            cout << i << E;
        }
    }
    return 0;
}
