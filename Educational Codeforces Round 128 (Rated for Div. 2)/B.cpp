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
void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}
int *constructBITree(int arr[], int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
    return BITree;
}
int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void update(int BITree[], int l, int r, int n, int val)
{
    // Increase value at 'l' by 'val'
    updateBIT(BITree, n, l, val);
  
    // Decrease value at 'r+1' by 'val'
    updateBIT(BITree, n, r+1, -val);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    read(a);
    int r, c;
    bool check = false;
    for (int i = 0; i<n; i++){
    	for (int j = 0; j<m; j++){
    		if (a[i][j] == 'R'){
    			r = i, c = j;
    			check = true;
    			break;
    		}
    	}
    	if (check) break;
    }
    for (int i = r; i<n; i++){
    	for (int j = 0; j<c; j++){
    		if (a[i][j] == 'R'){
    			no;
    			return;
    		}
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