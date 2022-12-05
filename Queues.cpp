/*

Queues:
1. First In First Out
2. push: Inserting to end of queue.
3. pop: Removing from begin of queue.
4. front: Viewing the begin element.
5. Declaration:
    queue<_datatype_> _queue name_;

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
    ll n;
    cin >> n;
    string s;
    queue<string> qs;       //declaring queue
    for(ll i = 0; i<n; i++){
        cin >> s;
        qs.push(s);         //pushing to the back of the queue
    }
    while(!(qs.empty())){   //checking if queue is empty(same as stack)
        cout << qs.front() << E; //printing from the front of the queue
        qs.pop();               //removing from the front of the queue.
    }
    return 0;
}
