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
vector<vector<int>> graph;
int ans;
pair<int, int> cur;
string s;
int n;
void dfs(int u){
	queue<int> t;
	t.push(u);
	while(!t.empty()){
		int tmp = t.front();
		if (s[tmp] == 'W') cur.ff++;
		else cur.ss++;
		cout << "TMP: " << tmp << endl;
		for (auto j: graph[tmp]){
			if (s[j] == 'W') cur.ff++;
			else cur.ss++;
			t.push(j);
		}
		t.pop();
	}
}
void solve()
{ 	
    cin >> n;
    graph.resize(n + 2);
    vector<int> a(n + 2);
    for (int i = 2; i<=n; i++) cin >> a[i];
	cin >> s;
	s = " " + s;
	for (int i = 2; i<=n; i++){
		graph[a[i]].pb(i);
	}
	for (int i = 1; i<=n; i++){
		cur = {0, 0};
		dfs(i);
		cout << cur.ff << " " << cur.ss << endl;
		ans += (cur.ff == cur.ss);
		cout << endl;
	}
	graph.clear();
	cout << ans << endl;
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