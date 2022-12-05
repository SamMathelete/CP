/*

Question at: https://www.spoj.com/problems/NAKANJ/

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

vector<pair<ll, ll> > mvmts = {
    {2, 1}, {2, -1},
    {-2, 1}, {-2, -1},
    {1, 2}, {1, -2},
    {-1, 2}, {-1, -2}
}

ll getX(string s){
    return (ll)(s[0] - 'a');
}

ll getY(string s){
    return (ll)(s[1] - '1');
}

bool isValid(ll X, ll Y){
    return X >= 0 && Y >= 0 && X < 8 && Y < 8; 
}

ll bfs(ll startX, ll startY, ll destX, ll destY){
    vector<vector<ll> > vis(8, vector<ll>(8, 0));
    vector<vector<ll> > level(8, vector<ll>(8, 0));
    queue<pair<ll, ll> > q;
    q.push({startX, startY});
    vis[startX][startY] = 1;
    while(!q.empty()){
        pair<ll, ll> x = q.front();
        pair<ll, ll> y;
        q.pop();
        for(auto &it : mvmts){
            y.first = x.first + it.first;
            y.second = x.second + it.second;
            if(!isValid(y.first, y.second)) continue;
            if(vis[y.first][y.second]) continue;
            q.push(y);
            vis[y.first][y.second] = 1;
            level[y.first][y.second] = level[x.first][x.second] + 1;
        }
    }
    return level[destX][destY];
}

int main(){
    ll n;
    cin >> n;
    while(n--){
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(getX(s1), getY(s1), getX(s2), getY(s2)) << E;
    }
    return 0;
}

