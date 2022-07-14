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
    vector<string> a(8);
    for (int i = 0; i<8; i++){
        cin >> a[i];
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            if (a[i][j] == '#') ans.pb({i, j});
        }
    }
    for (auto i: ans){
        int r = i.ff;
        int c = i.ss;
        if (r >= 1 && r < 8 && c >= 1 && c < 7 && a[r-1][c-1] == '#' && a[r-1][c+1] == '#' && a[r+1][c-1] == '#' && a[r+1][c+1] == '#'){
            cout << r + 1 << " " << c + 1 << endl;
            return;
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