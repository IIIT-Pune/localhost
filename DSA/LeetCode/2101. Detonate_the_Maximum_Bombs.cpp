//Code by Rohan Sharma(Naruto_Uchiha-CF)(rs2002-CC)
#include<bits/stdc++.h>
#define f(i,a,n,c)          for(int i=a;i<n;i+=c)
#define fr(i,a,n,c)         for(int i=a;i>=n;i-=c)
#define ll                  long long int
#define l(s)                s.size()
#define all(x)              (x).begin(), (x).end()
#define vll ;               vector<ll>
#define vsort(v)            sort(v.begin(), v.end());
#define vrsort(v)           sort(v.begin(), v.end(),greater<ll>());
#define vmax(v)             *max_element(all(v))
#define vmin(v)             *min_element(all(v))
#define vsum(v)             accumulate(all(v),0ll)
#define vprint(v);          f(i,0,l(v),1){cout<<v[i]<<' ';}cout<<endl;
#define pb                  push_back
#define ff                  first
#define ss                  second
#define mpll ;              map<ll,ll>
#define p(x);               cout<<x<<endl;
#define setbit(x)           __builtin_popcountll(x)


using namespace std;

ll expo(ll a, ll b) { return pow(a,b); }

class Solution {
public:
    ll cc=0;
    void dfs(vector<vector<ll>>& adj, vector<ll>& vis, ll node)
    {
        vis[node] = 1;
        cc++;
        for (auto i : adj[node])
        {
            if (vis[i]==0)
            {
                
                dfs(adj, vis, i);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& a)
    {
        ll n = l(a), m = l(a[0]);
        vector<vector<ll>>adj(n);
        f(i, 0, n - 1, 1)
        {
            f(j, i + 1, n, 1)
            {
                if ((expo(abs(a[i][0] - a[j][0]), 2) + expo(abs(a[i][1] - a[j][1]), 2) <= expo((a[i][2]), 2)))
                {
                    adj[i].pb(j);
                }
                if ((expo(abs(a[i][0] - a[j][0]), 2) + expo(abs(a[i][1] - a[j][1]), 2) <= expo(a[j][2], 2)))
                {
                    adj[j].pb(i);
                }
            }
        }

        ll ans =1;
        ll c = 0;
        f(i, 0, n, 1)
        {
            vector<ll>vis(n, 0);
            if (vis[i]==0)
            {
                cc=0;
                
                dfs(adj, vis, i);
                ans=max(cc,ans);
            }
        }
        return ans;
    }
};