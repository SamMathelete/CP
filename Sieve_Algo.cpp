/*

Sieve Algorithm
Time Complexity: O(M(log(log(M))))

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll M = 1e7+10;

vector<bool> primes(M+1, 1);

int main(){
    primes[1] = primes[0] = 0;
    for(ll i = 2; i <= M; i++){
        if(primes[i]){
            for(ll j = 2; i * j <= M; j++){
                primes[i * j] = 0;
            }
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll inp;
        cin >> inp;
        if(primes[inp]){
            cout << "YES" << E;
        }
        else{
            cout << "NO" << E;
        }
    }
    return 0;
}