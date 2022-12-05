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

void solve(){
    string s;
    cin >> s;
    ll n = s.size(), open = 0, close = 0, flag = 0;
    for(auto &it : s){
        if(it == '('){
            open++;
        }
        else if(it == ')'){
            close++;
        }
    }
    ll cntq = 0;
    for(auto &it : s){
        if(it == '?'){
            cntq++;
        }
    }
    if(cntq == abs(open-close)){
        cout << "YES" << E;
        return;
    }
    cntq -= open-close;
    cntq /= 2;
    for(auto &it : s){
        if(it == '?'){
            if(cntq > 1){
                it = '(';
                cntq--;
            }
            else if(cntq == 1){
                if(flag){
                    it = '(';
                    cntq--;
                }
                else{
                    it = ')';
                    flag = 1;
                }
            }
            else{
                it = ')';
            }
        }
    }
    open = 0, close = 0;
    for(auto &it : s){
        if(it == '(') open++;
        else close++;
        if(open-close < 0){
            cout << "YES" << E;
            return;
        }
    }
    cout << "NO" << E;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}