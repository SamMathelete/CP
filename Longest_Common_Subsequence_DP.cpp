/*

String DP tricks:
1. Define Brute Force Recursion and apply Memoisation.
2. Take both the strings simultaneously and start from the friend
        Case 1: Reduce one from first string and recurse
        Case 2: Reduce one from second string and recurse
        Case 3: Reduce one from both strings and recurse
        Take maximum of all three.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

string s1, s2;
vector<vector<ll> > dp;

ll lcs(ll ind1, ll ind2){
    if(ind1 == 0 && ind2 == 0) return s1[ind1] == s2[ind2];
    if(dp[ind1][ind2] + 1) return dp[ind1][ind2];
    ll ans = 0;
    if(ind1 - 1 >= 0) ans = max(ans, lcs(ind1 - 1, ind2));  //We are skipping one character so do not use the checking
    if(ind2 - 1 >= 0) ans = max(ans, lcs(ind1, ind2 - 1));  //line here i.e. s1[ind1] == s2[ind2]
    if(ind1 - 1 >= 0 && ind2 - 1 >= 0) ans = max(ans, lcs(ind1 - 1, ind2 - 1) + (s1[ind1] == s2[ind2])); //We do not skip so check
    return dp[ind1][ind2] = ans;
}

int main(){
    ll n, m;
    cin >> n >> m;
    dp.resize(n+1, vector<ll>(m+1, -1));
    cin >> s1 >> s2;
    cout << lcs(n-1, m-1) << E;
    return 0;
}
