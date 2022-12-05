/*

Divisors

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

//Brute-Force method to count divisors and find their sum using square root

ll ctdiv_bf(ll n){
    ll ct = 0, i;
    for(i = 1; i*i<=n; i++){
        if(n % i == 0){
            ct += 2;
        }
    }
    ll chc = i-1;
    return (chc * chc == n ? --ct : ct);
}

ll sumdiv_bf(ll n){
    ll ct = 0, i;
    for(i = 1; i*i<=n; i++){
        if(n % i == 0){
            ct += (i + n/i);
        }
    }
    ll chc = i-1;
    return (chc * chc == n ? ct-chc : ct);
}

int main(){
    ll n;
    cin >> n;
    cout << ctdiv_bf(n) sp sumdiv_bf(n) << E;
    return 0;
}