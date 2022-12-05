/*

Here we are using simulation again. For graph games with movable obstacles, first
move them and get store of location of them at different time periods. Then,
move the player and find the solution.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

ll n, m;
const ll N = 1005;
const ll INF = LLONG_MAX;
vector<vector<ll> > paths(N, vector<ll>(N));
queue<pair<ll, ll> > q;
vector<vector<pair<ll, ll> > > from(N, vector<pair<ll, ll> >(N));
pair<ll, ll> A;
string ans;
bool possible = false;

void retrace(pair<ll, ll> v){
    pair<ll, ll> origin = from[v.first][v.second];
    if(origin == pair<ll, ll>(0,0)) return;
    if(origin.first == v.first + 1){
        ans.pb('U');
    }
    if(origin.first == v.first - 1){
        ans.pb('D');
    }
    if(origin.second == v.second + 1){
        ans.pb('L');
    }
    if(origin.second == v.second - 1){
        ans.pb('R');
    }
    retrace(origin);
}

void check(pair<ll, ll> origin, pair<ll, ll> dest){
    ll pl = paths[origin.first][origin.second];
    if(pl + 1 < paths[dest.first][dest.second]){
        paths[dest.first][dest.second] = pl + 1;
        q.push(dest);
        from[dest.first][dest.second] = origin;
    }
}

bool mora = false;

void bfs() {
    while(!q.empty()){
        pair<ll, ll> x = q.front(), next; q.pop();
        next = x; next.first++; check(x, next);
        next = x; next.first--; check(x, next);
        next = x; next.second++; check(x, next);
        next = x; next.second--; check(x, next);
        if(mora && (x.first == 1 || x.second == 1 || x.first == n || x.second == m)){
            cout << "YES" << E;
            cout << paths[x.first][x.second] << E;
            retrace({x.first, x.second});
            possible = true;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i<=n; i++){
        string s;
        cin >> s;
        for(ll j = 1; j<=m; j++){
            paths[i][j] = INF;
            if(s[j - 1] == '#') paths[i][j] = 0;
            if(s[j - 1] == 'M') {
                q.push({i, j});
                paths[i][j] = 0;
            }
            if(s[j - 1] == 'A'){
                A = {i, j};
            }
        }
    }
    bfs();
    mora = true;
    from[A.first][A.second] = {0, 0};
    paths[A.first][A.second] = 0;
    q.push(A);
    bfs();
    if(possible){
        reverse(ans.begin(), ans.end());
        cout << ans << E;
    }
    else{
        cout << "NO" << E;
    }
    return 0;
}
