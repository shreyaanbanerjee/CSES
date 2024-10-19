#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--)
    {
       ll n,m,x;
    cin>>n>>m;
    vector<ll> t(m);
      map<int,int>mp;
    for(ll i=0;i<n;i++) {
        ll x;
        cin>>x;
        mp[x]++;
    }
    for(ll i=0;i<m;i++) cin>>t[i];
    for(ll i=0;i<m;i++)
    {
        auto u=mp.upper_bound(t[i]);
        if(u==mp.begin())
        {
            cout<<-1<<endl;
            continue;
        }
        u--;
        cout<<u->first<<endl;
        u->second--;
        if(u->second==0)
        mp.erase(u);
    }
    }
}