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
class segment{
public:
    int n;
    vector<set<int>> seg;
public:
    void init(int n){
        n = n;
        seg.resize(4 * n);
    }
    void build(int u, int l, int r,  vector<int> a){
        if (l == r){
            seg[u].insert(a[l]);
            return;
        }
        int mid = (l + r)/2;
        build(2 * u, l, mid, a);
        build(2 * u + 1, mid + 1, r, a);
        seg[u].insert(seg[2 * u].begin(), seg[2 * u].end());
        seg[u].insert(seg[2 * u + 1].begin(), seg[2 * u + 1].end());
    }
    set<int> query(int u, int l, int r, int i, int j){
        set<int> left, right, ans;
        if (j < l || i > r){
            return ans;
        } 
        if (i <= l && r <= j)
            return seg[u];
        int mid = (l + r)/2;
        left = query(2 * u, l, mid, i, j);
        ans.insert(left.begin(), left.end());
        right = query(2 * u + 1, mid + 1, r, i, j);
        ans.insert(right.begin(), right.end());
        return ans;
    }
};
void solve()
{
    segment sm;
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);
    sm.init(n);
    sm.build(1, 0, n - 1, a);
    int q;
    cin >> q;
    while(q--){
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        cout << sz(sm.query(1, 0, n - 1, i, j)) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}