/*
Given a string of brackets consisting of '()', '{}' and '[]', check if they are balanced.
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

unordered_map<char, int> m = {{'(', -1},{'{', -2},{'[', -3},{')', 1},{'}', 2},{']', 3}};

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    for(auto &it : s){
        if(m[it] < 0){
            st.push(it);
        }
        else{
            if(st.empty() || m[it]+m[st.top()] != 0){
                cout << "NO" << E;
                return 0;
            }
            st.pop();
        }
    }
    if(st.empty()){
        cout << "YES" << E;
        return 0;
    }
    cout << "NO" << E;
    return 0;
}