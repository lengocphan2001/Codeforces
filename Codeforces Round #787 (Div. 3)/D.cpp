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
vector<vector<int>> ans;
vector<int> cur;
vector<bool> vis;
void dfs(int u, vector<bool> &vis, vector<vector<int>> &graph){
	vis[u] = true;
	cur.pb(u);
	if (sz(graph[u]) == 0){
		ans.pb(cur);
		cur.resize(0);
	}
	for (int i = 0; i<sz(graph[u]); i++){
		if (!vis[graph[u][i]]){
			dfs(graph[u][i], vis, graph);
		}
	}
}
void solve()
{
    int n, root = 1;
    cin >> n;
    vector<int> a(n);
    read(a);
    if (n == 1){
    	cout << 1 << endl;
    	cout << 1 << endl;
    	cout << 1 << endl;
    	return;
    }
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i<n; i++){
    	graph[a[i]].pb(i + 1);
    	if (a[i] == i + 1) root = a[i];
    }
    vis.resize(n + 1, false);
    dfs(root, vis, graph);
    cout << sz(ans) << endl;
    for (int i = 0; i<sz(ans); i++){
    	cout << sz(ans[i]) << endl;
    	for (auto j: ans[i]) cout << j << " ";
    	cout << endl;
    }
    ans.resize(0);
    graph.resize(0);
    vis.resize(0);
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