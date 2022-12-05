/*

Sort:
1. Function Structure:
    sort(_begin address_, _end address_, _comparator_ (if any)_);
2. For arrays, use pointers and for containers use iterators.
3. _end address_ should be the address of the memory location next to the last element to be sorted.
4. Uses Introsort: Insertion Sort + Quick Sort + Heap Sort.

Comparator Function:
1. Inbuilt STL sorting algorithm uses swapping and we can use a comparator function to do that swapping for
   a different condition than the inbuilt one.
2. If comparator returns FALSE, swapping is DONE. If the comparator returns TRUE, swapping is NOT DONE.
3. These are boolean functions.

*/

/*
Given a vector of pair of integers, sort it in descending order of first elements and if first elements are
equal then sort is in ascending order of second elements.
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

bool cmp(pair<ll, ll> &p1, pair<ll, ll> &p2){
    if(p1.first != p2.first){
        return p1.first > p2.first; //If true then no swapping, else swap.
    }
    return p1.second < p2.second; //If true then no swapping, else swap.
}

int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll> > v(n);
    for(auto &it : v){
        cin >> it.first >> it.second;
    }
    sort(v.begin(), v.end(), cmp); //using comparator function
    for(auto &it : v){
        cout << it.first sp it.second << E;
    }
    return 0;
}