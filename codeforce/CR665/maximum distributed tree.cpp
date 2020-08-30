#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, m, A[N], SZ[N];
vector < int > Adj[N];
vector < ll > vec;
void DFS(int v, int p)
{
    SZ[v] = 1;
    for (int u : Adj[v])
        if (u != p)
            DFS(u, v), SZ[v] += SZ[u];
    if (p != 0)
        vec.push_back(1LL * SZ[v] * (n - SZ[v]));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    for (; q; q --)
    {
        cin >> n;
        vec.clear();
        for (int i = 1; i <= n; i ++)
            Adj[i].clear();
        for (int i = 1; i < n; i ++)
        {
            int v, u;
            cin >> v >> u;
            Adj[v].pb(u);
            Adj[u].pb(v);
        }
        cin >> m;
        for (int i = 1; i <= m; i ++)
            cin >> A[i];
        sort(A + 1, A + m + 1);
        while (m > n - 1)
            A[m - 1] = (1LL * A[m - 1] * A[m]) % Mod, m --;
        DFS(1, 0);
        sort(vec.begin(), vec.end());
        int tot = 0;
        for (int i = n -2 ; i >= 0; i --)
        {
            if (m == 0)
                tot = (tot + vec[i]) % Mod;
            else
                tot = (tot + 1LL * vec[i] % Mod * A[m]) % Mod, m --;
        }
        printf("%d\n", tot);
    }
    return 0;
}
