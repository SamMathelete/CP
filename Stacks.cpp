/*

Stacks:
1. Last In First Out
2. push: Inserting to Stack Top Position.
3. pop: Removing from Stack Top Position.
4. top: Viewing the Top Element of the Stack.
5. Declaration:
    stack<_datatype_> _stack name_;

Use while loops to traverse queues and stacks.

*/


#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

int main(){
    ll n, inp;
    cin >> n;
    stack<ll> st; //Declaring Stack
    for(ll i = 0; i<n; i++){
        cin >> inp;
        st.push(inp); //Pushing Input to Stack 
    }
    while(!(st.empty())){   //st.empty() returns 1 if stack is empty or 0 if it is not.
        cout << st.top() << E; //printing the top element
        st.pop();          //removing the top element.
    }
    return 0;
}
