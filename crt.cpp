ll crt(vector<ll> &p, vector<ll> &res){
    ll k = 1, ans = 1, n = p.size();
    for(ll i = 0; i<n; i++){
        while(ans % p[i] != res[i]) ans += k;
        k *= p[i];
    }
    return ans;
}