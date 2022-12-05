/*
Given a number n, find the number of set bits in its binary expansion.
1<=n<=10^9;
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    unsigned ll n, ctr = 0, c = 1; //use unsigned as signed integers have extra bits
    cin >> n;
    for(ll i = 0; i<36; i++){
        if((n & (c << i)) != 0){
            ctr++;
        }
    }
    cout << ctr << E;
    return 0;
}