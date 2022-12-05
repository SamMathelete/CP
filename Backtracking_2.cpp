/*

Backtracking 2 

Question at: https://leetcode.com/problems/subsets/

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

vector<vector<ll> > ans;

void generate(vector<ll> &v, vector<ll> &v1, ll ind){
    if(ind == -1){
        ans.pb(v);
        return;
    }
    v.pb(v1[ind]);          //case 1: take the element
    generate(v, v1, ind-1);
    v.pop_back();           //undo changes for next independent case: backtracking
    generate(v, v1, ind-1); //case 2: don't take the element
}

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n), v1;
    for(auto &it : v){
        cin >> it;
    }
    generate(v1, v, n-1);
    for(auto &it : ans){
        for(auto &it1 : it){
            cout << it1 << " ";
        }
        cout << E;
    }
    return 0;
}

