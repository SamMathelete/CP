/*

Finding Fibonnaci Numbers using Dynamic Programming(using Top-Down Approach)

Concept: If already computed, store it and re-use it rather than recomputing it

- Dynamic Programming converts:
    O(2^N) --> O(N)
    O(N!) --> O(2^N)

In Top down approach, we break down a bigger problem to smaller problems and solve them and use 
them to solve the bigger problem.

majorly use top down approach.

Steps to solve problem:
1. Solve the problem using brute force recursion.
2. Make the dynamic programming array as per the state of the recursive function.
3. Optimise by using the DP memoisation lines.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e5+10;
vector<ll> fibn(N, -1); //dynamic programming array: if calculated, stor it and re-use it and do not recalculate it.
const ll M = 1e9+7;

ll fib(ll n){           // Here n is the state of the recursive function.
    if(fibn[n]+1) return fibn[n];   //This step is called memoisation. This prevents recalculation.
    return fibn[n] = (fib(n-2) + fib(n-1)) % M; //if not there then store it
}


int main(){
    fibn[0] = 0;
    fibn[1] = 1;
    ll q, n;
    cin >> q;
    while(q--){
        cin >> n;
        for(ll i = 1; i<=n; i++){
            cout << fib(i) << " ";
        }
        cout << E;
    }
    return 0;
}