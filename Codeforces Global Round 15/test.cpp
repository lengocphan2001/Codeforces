#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a, n) for (int i = a; i < n; i++)
#define Fd(n, a) for (int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define read(a) for (int i = 0; i<sz(a); i++) cin >> a[i]
const ll mod = 1e9 + 7;
void solve()
{
	string s;
	cin >> s;
	if (s.back() != 'B' || s[0] == 'B'){
		no;
		return;
	}
	vector<int> cur;
	for (int i = 0; i<sz(s); i++){
		if (s[i] == 'B') cur.pb(i);
	}
	for (int i = 1; i<sz(cur); i++){
		if (cur[i] == cur[i-1] + 1){
			no;
			return;
		}
	}
	yes;
}	
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    	solve();
}