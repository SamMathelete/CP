/*
Nth root using Binary Search
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

double prs = 1e-6;                      //precision

double multiply(double x, double n){
    if(n == 1){
        return x;
    }
    return x*multiply(x, n-1);
}

/*
We implement binary search in an array of reals from 0 to x with step of prs precision and check whose nth power
(multiplying n times) is given number x.
*/

double root(double x, double low, double high, double n){ 
    double mid = (low+high)/2;
    if(high - low <= prs){
        return low;
    }
    if(multiply(mid, n) == x){
        return mid;
    }
    else if(multiply(mid, n) < x){
        return root(x, mid, high, n);
    }
    else{
        return root(x, low, mid, n);
    }
}


int main(){
    ll x, n;
    cin >> x >> n;
    cout << root(x, 0, x, n) << E;
    return 0;
}