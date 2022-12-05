/*

Backtracking

Question at: https://leetcode.com/problems/generate-parentheses/

*/


#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

vector<string> v;                     //vector of all valid strings

void generate(string &s, ll open, ll close){
    if(open == 0 && close == 0){
        v.pb(s);        //if open and close brackets are exhausted, string is valid and push it in v
        return;
    }
    if(open>0){         //case 1: if open > 0 then we can push in open bracket to s
        s.pb('(');
        generate(s, open-1, close);
        s.pop_back();   // we need to make sure that to case 2 i.e. closing case, the same string s goes in as it is independent
                        // from case 1, so, we revert the change after operations. This is called backtracking.
    }                    
    if(close>0 && open<close){ // case 2: if close > 0 and open < close i.e. we have excess of openings in string, then we add a closing bracket. 
        s.pb(')');
        generate(s, open, close-1);
        s.pop_back();   // Again, we need to make sure that after the closing case, the same string s is preserved for further operations as it is independent
                        // from case 2, so, we revert the change after operations. This is also called backtracking.
    }
}

// In such multi case tree traversal type operations, make sure to undo operations after recursion using backtracking.

int main(){
    ll n;
    cin >> n;
    string s = "";
    generate(s, n, n);
    for(auto &it : v){
        cout << it << E;
    }
    return 0;
}
