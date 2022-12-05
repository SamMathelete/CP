/*

Bitmasking:
1. Suppose you have 4 different items indexed as 0, 1, 2, 3 and 4 different persons A, B, C.
   Suppose A has items 0, 2, 3; B has 1, 2, 3; C has 1, 3, 0.
   Now, one way of representing it is by using nested pairs and vectors which has high space complexity.
   Another way is bitmasking:
        Represent A as 1101, B as 1110, C as 1010. So, index of set bits in the representation represents
        the items available. Space complexity also reduces drastically. Common items can be found by using &.

   This is called bitmasking(representation using bits).

2. __builtin_popcountll(x) finds the number of set bits in long long integer x.(Notice the 2 underscores before builtin)

3. Use bitmasking only when number of items to be bitmasked is less than or equal to 63.

*/

/*

Question:
 There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). 
 For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. 
 You need to assign an important project to two workers but they will be able to work on the project only when they are both available. 
 Find two workers that are best for the job — maximize the number of days when both these workers are available.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

int main(){
    ll n, inp1, inp2, av, max1, max2, maxq = 0;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i<n; i++){
        cin >> inp1;
        av = 0;
        for(ll j = 0; j<inp1; j++){
            cin >> inp2;
            av += (1<<(inp2-1));            //using bitmasking to represent available days by 1 and unavailable by 0.
        }
        v[i] = av;
    }
    for(ll i = 0; i<n-1; i++){
        for(ll j = i+1; j<n; j++){
            if(__builtin_popcountll(v[i] & v[j]) > maxq){
                maxq = __builtin_popcountll(v[i] & v[j]);
                max1 = i;
                max2 = j;
            }
        }
    }
    cout << ++max1 sp ++max2 sp maxq << E;
    return 0;
}

