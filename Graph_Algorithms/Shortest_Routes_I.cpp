#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpl vector<pll>
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vl>
#define mii map<int, int>
#define si set<int>
#define sll set<ll,ll>
#define sc set<char>
#define pb push_back
#define all(x) begin(x), end(x)
#define fori for (i = 0; i < n; i++)
#define lo(i,f,t) for(ll i=f;i<t;i++)
ostream& operator<<(ostream& dout, vector<ll>& vec) 
{
    lo(i, 0, vec.size())
    {
        dout << vec[i] << " ";
    }
    dout << endl;
    return dout;
}
#define intmax INT_MAX
void write()
{
ll n,m;
cin>>n>>m;
vector<vector<pair<ll,ll>>>v(n);
for(int i=0;i<m;i++)
{
    ll a,b,c;
    cin>>a>>b>>c;
    v[a-1].pb({c,b-1});
}
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
vector<ll>dist(n,1e18);
vl vis(n,0);
dist[0]=0;
q.push({0,0});
while(!q.empty())
{
   auto p=q.top();
   ll y=p.second;
    q.pop();
   if(vis[y]) continue;
   vis[y]=1;
    for(auto x:v[y])
    {
        ll fi=x.first;
        ll se=x.second;
        if(dist[se]>dist[y]+fi)
        {
            dist[se]=dist[y]+fi;
            q.push({dist[se],se});
        }
    }
}
cout<<dist;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL); 
    int t=1;
    // cin >> t;
    while (t--)
    {
        write();
    }
    return 0;
}