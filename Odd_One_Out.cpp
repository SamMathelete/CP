/*

Given array a of n integers. All integers are present in even
count except one. Find the one which is in odd count using 
O(N) time complexity and O(1) space complexity.

*/

/*

Logic: If we take XOR of an integer even number of times, it becomes zero.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

int main(){
    ll inp, n, ans = 0;
    cin >> n;
    while(n--){
        cin >> inp;
        ans ^= inp;
    }
    cout << ans << E;
    return 0;
}
