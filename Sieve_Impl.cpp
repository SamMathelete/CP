/*

Methods using sieve algorithm
1. Finding the smallest prime factor of x.
2. Finding the largest prime factor of x.
3. Finding Prime Factorisation.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e7+10;
vector<pair<ll, ll> > primes(N, {0, 0}); //pair of largest and smallest prime factor of each index of primes.

//Using Sieve Algorithm to store lowest and highest prime factor
void sieve(){
    primes[0] = {0, 0};
    primes[1] = {1, 1};
    for(ll i = 2; i<N; i++){
        if(primes[i].first == 0 && primes[i].second == 0){
            primes[i] = {i, i};
            for(ll j = 2*i; j<N; j+=i){
                primes[j].second = i;
                if(primes[j].first == 0){
                    primes[j].first = i;
                }
            }
        }
    }
    return;
}

//using largest prime factor of a number to derive its prime factorisation
vector<pair<ll,ll> > prime_factn_hp(ll n){
    vector<pair<ll, ll> > pf;
    ll ct = 0;
    while(n > 1){
        ll pft = primes[n].second;
        ct = 0;
        while(n % pft == 0){
            ct++;
            n /= pft;
        }
        pf.pb(mp(pft, ct));
    }
    return pf;
}

int main(){
    sieve();
    ll q, n;
    cin >> q;
    while(q--){
       cin >> n;
       vector<pair<ll, ll> > pf = prime_factn_hp(n);
       for(auto &it : pf){                          //prints prime factorisation
           cout << it.first sp it.second << E;
       }
    }
    return 0;
}