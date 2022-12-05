/*

    author: SamTheMathlete
    submitted on: "<cmd + k> on me"

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;
 
struct segtree{
    ll size;
    vector<ll> sums;

    void init(ll n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        sums.assign(2 * size + 1, 0LL);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx){
        if(rx - lx == 1){
            if(lx < a.size()){
                sums[x] = a[lx];
            }
            return;
        }else{
            ll m = (lx + rx)/2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        }
    }

    void build(vector<ll> &a){
        build(a, 0, 0, size);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(rx - lx == 1){
            sums[x] = v;
            return;
        }
        ll m = (lx+rx)/2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m); //upper bound is not counted
        }else{
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(ll i, ll v){
        set(i, v, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx){
        if(rx <= l || lx >= r) return 0; //r and rx will never be considered
        if(lx >= l && rx <= r) return sums[x];
        ll m = (lx + rx)/2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m ,rx);
        return s1 + s2;
    }

    ll sum(ll l, ll r){
        return sum(l, r, 0, 0, size);
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, inp;
    cin >> n >> m;
    segtree st;
    st.init(n);
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    st.build(a);
    while(m--){
        ll q, i, v;
        cin >> q >> i >> v;
        if(q == 2){
            cout << st.sum(i, v) << E;
        }else{
            st.set(i, v);
        }
    }
    return 0;
}