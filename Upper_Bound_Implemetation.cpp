/*
Upper Bound Implementation
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

ll upper_bound(vector<ll> &v, ll low, ll high, ll element){
    if(!is_sorted(v.begin(), v.end())){
        sort(v.begin(), v.end());
    }
    ll mid = (low+high)/2;
    if(low == high){
        if(v[low] > element){
            return low;
        }
        else{
            return -1;
        }
    }
    if(v[mid] <= element){
        return upper_bound(v, mid+1, high, element);
    }
    else{
        return upper_bound(v, low, mid, element);       // we need to include mid in search range as for upper bound v[mid] > element.
    }
}

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &it : v){
        cin >> it;
    }
    ll ele;
    cin >> ele;
    ll ans = upper_bound(v, 0, n-1, ele);
    cout << (ans == -1 ? -1 : v[ans]) << E;
    return 0;
}
