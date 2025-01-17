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
ll n,m,qu;
cin>>n>>m>>qu;
vll v(n,vl(n,1e18));
for(int i=0;i<m;i++)
{
    ll a,b,c;
    cin>>a>>b>>c;
    v[a-1][b-1]=v[b-1][a-1]=min(v[a-1][b-1],c);
}
for(int i=0;i<n;i++) {
    v[i][i]=0;
}
lo(k,0,n)
{
    lo(i,0,n)
    {
        lo(j,0,n)
        {
            v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
        }
    }
}
while(qu--)
{
    ll a,b;
    cin>>a>>b;
    cout<<(v[a-1][b-1]<1e18?v[a-1][b-1]:1)<<endl;
}
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