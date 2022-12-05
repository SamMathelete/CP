/*

    Problem showing the importance of sparse table.

    use Sparse table in questions where we need range sum queries or range minimum queries.
    more on sparse table: https://cp-algorithms.com/data_structures/sparse-table.html#range-minimum-queries-rmq
    question at: https://codeforces.com/contest/1709/problem/D

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> block(m);
    for(auto &it : block){
        cin >> it;
    }
    ll l = 0;
    while((1 << l) <= m) ++l;
    vector<vector<ll> > st(l, vector<ll>(m));
    for(ll i = 0; i<m; i++){
        st[0][i] = block[i];
    }
    for(ll j = 1; j<l; j++){
        for(ll i = 0; i<m; i++){
            st[j][i] = st[j-1][i];
            if((i + (1 << (j-1))) < m){
                st[j][i] = max(st[j][i], st[j-1][i+(1<<(j-1))]);
            }
        }
    }
    vector<ll> lg2(m+1, 0);
    for(ll i = 2; i<=m; i++){
        lg2[i] = lg2[i/2] + 1;
    }
    auto get = [&](ll a, ll b){
        if(a > b) swap(a, b);
        ++b;
        ll len = lg2[b-a];
        return max(st[len][a], st[len][b-(1<<len)]);
    };
    ll q;
    cin >> q;
    while(q--){
        ll xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        --xs, --ys, --xf, --yf;
        if(ys % k != yf % k || xs % k != xf % k){
            cout << "NO" << E;
            continue;
        }
        ll mx = ((n - xs - 1)/k) * k + xs;
        cout << (get(ys, yf) <= mx ? "YES" : "NO") << E;
    }
    return 0;
}