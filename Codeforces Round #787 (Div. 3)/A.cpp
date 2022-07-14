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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> temp;
    int i = 0;
    for (; i<n; i++){
        int cur = i;
        while(s[i] == s[i + 1]){
            i++;
        }
        temp.pb(i - cur + 1);
    }
    int ans = 0, res = 0;
    vector<int> cur = temp, need = temp;
    for (int i = 0; i<sz(temp) - 1; i++){
        if (temp[i] % 2 != 0){
            temp[i]++;
            temp[i+1]--;
            ans++;
        }
    }
    for (int i = sz(cur) - 1; i>0; i--){
        if (cur[i] % 2 != 0){
            cur[i]++;
            cur[i-1]--;
            res++;
        }
    }
    if (min(ans, res) == 0){
        cout << "0 " << sz(cur) << endl;
    }else{
        int remain = sz(need);
        int k = min(ans, res);
        int i =  0;
        for (; i<sz(need); i++){
            bool check = false;
            if (need[i] <= k){
                remain--;
                k-=need[i];
                check = true;
            }
            if (check) i+=2;
        }
        cout << min(ans, res) << " " << remain << " " << k << endl;
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