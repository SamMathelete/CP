/*

Knapsack 2 (0/1 knapsack):
Question at: https://atcoder.jp/contests/dp/tasks/dp_d

Hint:
Decide all states of the brute force recursive function.
Here, States can be N and v as O(100 * 10^3) = O(10^5)

Hint 2:
Iterate over all values from 1 to 10^3 and find the largest value for which minimum weight
required to build is less than or equal to W.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
using namespace std;

ll v[105], w[105], vl[105][100005];

ll minw(ll ind, ll val){
    if(val == 0) return 0;
    if(ind < 0) return 1e15;
    if(vl[ind][val] + 1) return vl[ind][val];
    ll wt = 0;
    wt = minw(ind-1, val);
    if(val-v[ind] >= 0) wt = min(wt, w[ind] + minw(ind-1, val-v[ind]));
    return vl[ind][val] = wt;
}

int main(){
    memset(vl, -1, sizeof(vl));
    ll n, wl;
    cin >> n >> wl;
    for(ll i = 0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    ll max_val = 1e5;
    for(ll i = max_val; i >= 0; i--){
        if(minw(n-1, i) <= wl){
            cout << i << E;
            break;
        }
    }
    return 0;
}
