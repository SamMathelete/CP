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
    vector<pair<ll, ll> > v(n);
    for(auto &it : v){                  //to change so used &
        cin >> it.first >> it.second;
    }
    for(auto it : v){                   //not to change so did not use &
        cout << it.first << " " << it.second << E; // 'it' is not an iterator but a copy of the pair so do not use '->' operator.
    }
    return 0;
}
//It is recommended to use & always.