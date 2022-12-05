/*
Given a string of length N consisting of only parantheses, check if the parantheses are balanced. 
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    for(ll i = 0; i<n; i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                cout << "NO" << E;
                return 0;
            }
            st.pop();   //popping as it already covers the current closing.
        }
    }
    if(st.empty()){
        cout << "YES" << E;
        return 0;
    }
    cout << "NO" << E;
    return 0;
}