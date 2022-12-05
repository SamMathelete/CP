/*

Predicate Function:
1. A function which returns True(1) or False(0).

2. A predicate function is called monotonic in a domain if it returns a continuous stream of True/False
   followed by a continuous stream of False/True respectively and such combinations like T,F,T or F,T,F 
   do not exist in the return sequence on that domain.
    
    e.g: T F F F
         F F T T are monotonic
         but T F T T is not monotonic.

3. Binary Search can be implemented to find the junction point between the True and False streams of a
   monotonic predicate function.

4. Use predicate function whenever you try to minimise or maximise a quantity(in complicated situations).

*/

/*

Question at: https://www.spoj.com/problems/EKO/

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

ll N;
ll m;
vector<ll> trees;

bool iswoodsufficient(ll h){ //predicate function
    ll sum = 0;
    for(auto &it : trees){
        if(it > h){
            sum += (it-h);
        }
    }
    return sum >= m;
}

int main(){
    ll inp;
    cin >> N >> m;
    for(ll i = 0; i<N; i++){
        cin >> inp;
        trees.pb(inp);
    }
    ll lo = 0, hi = 1e9+10, mid;
    while(hi - lo > 1){            //we search for the last true that is generated by the predicate function
        mid = (hi+lo)/2;
        if(iswoodsufficient(mid)){
            lo = mid;
        }
        else{
            hi = mid-1;
        }
    }
    if(iswoodsufficient(hi)){
        cout << hi << E;
    }
    else{
        cout << lo << E;
    }
    return 0;
}


