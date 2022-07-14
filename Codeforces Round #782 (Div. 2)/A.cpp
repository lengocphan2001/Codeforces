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
    int n, r, b;
    cin >> n >> r >> b;
   	if (b == 1){
   		string cur = string(n-2, 'R');
   		cur.pb('B');
   		cur.pb('R');
   		cout << cur << endl;
   		return;
   	}
   	vector<string> temp;
   	int res = INT_MAX;
    string ans = string(n, 'R');
    for (int i = 1; i<=n/2; i++){
    	bool check = true;
    	if (b * i >= n) check = false;
    	if (check){
    		string cur = ans;
    		for (int k = 0, j = 0; k<n && j < b; k+=i, j++) cur[k] = 'B';
    		temp.pb(cur);
    		int temp = 0;
    	}	
    }
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