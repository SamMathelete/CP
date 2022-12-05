/*

XOR properties:
(for an integer x)
1. x ^ x = 0
2. 0 ^ x = x
3. XOR is commutative and associative.

4. 1 ^ x = x-1 if x is odd
5. 1 ^ x = x+1 if x is even

*/
/*

Swapping two numbers using XOR operator

*/

#include<bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main(){
    int n, m;
    cin >> n >> m;
    swap(n, m);
    cout << n << " " << m << endl;
    return 0;
}