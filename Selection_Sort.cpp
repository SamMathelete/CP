/*
Selection Sort
*/

#include <bits/stdc++.h>
#define ll long long int
#define E '\n'


using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i<n; i++){
        cin >> v[i];
    }
    for(ll i = 0; i<n; i++){
        ll mini = i;
        for(ll j = i+1; j<n; j++){
            if(v[j]<v[mini]){
                mini = j;
            }
        }
        swap(v[mini], v[i]);
    }
    for(ll i  = 0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << E;
    return 0;
}