/*

    Illustration of map and multiset nesting.
    Question at: https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, inp;
    cin >> n;
    string s;
    map<int, multiset<string> > ss; 
    /* 
    Names of two people can be same and using sets we will eliminate one of them.
    This will lead to wrong answer. So, we use multiset here.
    */
    for(ll i = 0; i<n; i++){
        cin >> s;
        cin >> inp;
        ss[(-1*inp)].insert(s);
        //We use negative numbers as this is as ascending order of negative numbers is similar to descending of positives.
    }
    for(auto &it : ss){
        for(auto &it1 : it.second){
            cout << it1 sp (-1*(it.first)) << E;
        }
    }
    return 0;
}
