/*
Merge Sort
*/

#include <bits/stdc++.h>
#define ll long long int
#define E '\n'


using namespace std;

void merge(ll *arr, ll l, ll r, ll mid){
    ll l_sz = mid - l + 1;
    ll r_sz = r - mid;
    vector<ll> L(l_sz+1);
    vector<ll> R(r_sz+1);
    for(ll i = 0; i<l_sz; i++){
        L[i] = *(arr+l+i);
    }
    for(ll i = 0; i<r_sz; i++){
        R[i] = *(arr+mid+1+i);
    }
    L[l_sz] = R[r_sz] = INT_MAX;
    ll l_ind = 0, r_ind = 0;
    for(ll i = l; i<=r; i++){
        if(L[l_ind]<R[r_ind]){
            *(arr+i) = L[l_ind];
            l_ind++;
        }
        else{
            *(arr+i) = R[r_ind];
            r_ind++;
        }
    }
    return;
}

void mergesort(ll *arr, ll l, ll r){
    ll mid = (l+r)/2;
    if(l == r){
        return;
    }
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    merge(arr, l, r, mid);
}

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i<n; i++){
        cin >> v[i];
    }
    mergesort(&v[0], 0, n-1);
    for(ll i = 0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << E;
    return 0;
}