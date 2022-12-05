/*

Binary Search
1. Implemented on monotonic data sets(increasing or decreasing) like sorted vectors, monotonic functions, etc.
2. Time complexity: O(log2(n))
3. Also implemented on predicate functions.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

ll binary_search(vector<ll> &v, ll low, ll high, ll element){
    if(!(is_sorted(v.begin(), v.end()))){
        sort(v.begin(), v.end());
    }
    if(low > high){
        return -1;
    }
    ll mid = (low + high)/2;
    if(v[mid] == element){
        return mid;
    }
    else if(v[mid] < element){
        return binary_search(v, mid+1, high, element);
    }
    else{
        return binary_search(v, low, mid-1, element);
    }
}

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &it : v){
        cin >> it;
    }
    ll qry;
    cin >> qry;
    cout << binary_search(v, 0, n-1, qry) << E;
    return 0;
}