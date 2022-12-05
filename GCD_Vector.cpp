/*
GCD of n integers
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

ll gcd(ll a, ll b){
    if(a == 0){
        return b;
    }
    return gcd(b%a, a);
}

ll gcdn(vector<ll> v){
    if(!(v.size())){
        return -1;
    }
    ll res = v[0];
    for(auto &it : v){
        if(res == 1){
            return 1;
        }
        res = gcd(it, res);
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &it : v){
        cin >> it;
    }
    cout << gcdn(v) << E;
    return 0;
}