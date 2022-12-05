/*

    author: SamTheMathlete
    submitted on: "<cmd + k> on me"

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a[x]++;
		}
		int sum = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i];   //fills the array, so the upcoming one has to start from next index
			ans = max(ans, (int)ceil(((double)sum)/i)); //max of all equal and else wise
            //The above step is done because, once anew array is added, it has elements in it and
            //it caanot be removed, but not taking max may remove it.
		}
		cout << ans << '\n';
	}
	return 0;
}

//Trick for ceil(n/x):
//    (int)ceil((double)n/x) = (n+x-1)/x