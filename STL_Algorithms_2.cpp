/*

More STL Algorithms:

1. Lambda Functions:
    - These are small functions that can be directly declared and used within some functions.
    - Declaration:
        [](_parameters_){
            _lambda function code_
        }(_values_);
    - These can also be assigned to variables using auto keyword.
        auto _variable name_ = [](_parameters_){
            _lambda function code_
        };
        
        - The assigned variable can be called as a function.
            _variable name_(_values_);

2. Checker Function: A function which returns 1 if the condition defined in the function is satisfied
                     by the parameters and 0 otherwise.

3. all_of(_begin iterator_, _end iterator_, _checker function_); 
        -> returns 1 if all of the elements in the range return 1 in checker function, or 0 otherwise.

4. any_of(_begin iterator_, _end iterator_, _checker function_); 
        -> returns 1 if any one of the  elements in the range returns 1 in checker function, or 0 otherwise.

5. none_of(_begin iterator_, _end iterator_, _checker function_); 
        -> returns 1 if none of the elements in the range return 1 in checker function, or 0 otherwise.

6. Generally lambda functions are used to write checker functions as they are simple one liner functions.

*/

/*
Given an array of N integers, print if
    a. All integers are positive. (1 or 0)
    b. Any integer is negative. (1 or 0)
    c. None of the integers are 0. (1 or 0)
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
    vector<ll> v(n);
    for(auto &it : v){
        cin >> it;
    }
    cout << all_of(v.begin(), v.end(), [](int x){return x > 0;}) << E; //using lambda function as checker
    cout << any_of(v.begin(), v.end(), [](int x){return x < 0;}) << E;
    cout << none_of(v.begin(), v.end(), [](int x){return x == 0;}) << E;
}
