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
int diff(string s1, string s2){
	int res = 0;
	for (int i = 0; i<sz(s1); i++){
		int cur = s1[i] - 'a', temp = s2[i] - 'a';
		if (cur != temp){
			res += abs(cur - temp);
		}
	}
	return res;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    read(a);
    map<ll, int> cur;
    int temp = 0;
    for (int i = 0; i<n; i++){
    	cur[a[i]]++;
    	temp = max(temp, cur[a[i]]);
    }
    if (temp < k){
    	cout << -1 << endl;
    }else{
    	set<ll> ans;
    	vector<ll> b;
    	pair<ll, ll> res = {-1, -1};
    	for (int i = 0; i<n; i++){
    		if (cur[a[i]] >= k){
    			ans.insert(a[i]);
    		}
    	}
    	for (auto i: ans) b.pb(i);
    	sort(all(b));
    	for (int i = 0; i<sz(b); i++){
    		ll l = b[i], r = 1e9;
    		while(l <= r){
    			ll mid = (l + r)/2;
    			auto it = lower_bound(all(b), mid);
    			if (*it == mid && it != b.end() && it - b.begin() - i == mid - b[i]){
    				if (res.ff == -1){
    					res.ff = b[i];
    					res.ss = mid;
    				}else{
    					if (mid - b[i] > res.ss - res.ff){
    						res.ff = b[i];
    						res.ss = mid;
    					}
    				}
    				l = mid + 1;
    			}else{
    				r = mid - 1;
    			}
    		}
    	}
    	cout << res.ff << " " << res.ss << endl;
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