/*

Question at: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/?utm_source=header&utm_medium=search&utm_campaign=he-search

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e6+10;
vector<ll> v(N, 0);
vector<ll> vp(N, 0);    // stores 1 for values and powers

vector<ll> dpf(ll n){   //generates distinct prime factors
	vector<ll> dpf;
	while(n > 1){
		ll k = v[n];
		while(n % k == 0){
			n /= k;
		}
		dpf.pb(k);
	}
	return dpf;
}

void sieve(){           // generates highest prime factor
    for(ll i = 2; i<N; i++){
        if(v[i] == 0){
            for(ll j = i; j<N; j += i){
                v[j] = i;
            }
        }
    }
}

int main(){
	vp[1] = 1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    ll n, q, inp;
    cin >> n >> q;
    for(ll i = 0; i<n; i++){
		cin >> inp;
		if(inp > 1){
			for(ll j = inp; j<N; j*=inp){
				vp[j] = 1;
			}
		}
	}
    ll x;
    while(q--){
		ll flag = 0;
        cin >> x;
        vector<ll> pf = dpf(x);
		for(ll i = 0; i<pf.size(); i++){
			for(ll j = i; j<pf.size(); j++){
				ll ii = pf[i] * pf[j];
				if(x % ii == 0 && (vp[x/ii])){
					cout << "YES" << E;
					flag = 1;
					break;
				} 
			}
			if(flag == 1){
				break;
			}
		}
		if(flag == 0){
			cout << "NO" << E;
		}
	}
    return 0;
}