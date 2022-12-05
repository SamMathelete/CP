#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> ans(n, -1);
    for(auto &it : v){
        cin >> it;
    }
    stack<ll> st;
    for(ll i = 0; i<n; i++){
        while(!(st.empty()) && v[i]>=v[st.top()]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for(ll i = 0; i<n; i++){
        cout << v[i] << " " << (ans[i] == -1 ? -1 : v[ans[i]]) << E;
    }
    return 0;
}