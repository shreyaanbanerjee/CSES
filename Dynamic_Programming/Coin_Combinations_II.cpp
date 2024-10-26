#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL); 
    ll n,x;
    cin>>n>>x;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
     cin>>v[i];
sort(v.begin(),v.end());
    vector<ll> dp(x+1,0);
    dp[0]=1;
    for(ll i=0;i<n;i++)
    {
        for(ll j=v[0];j<=x;j++)
        {
            if(j>=v[i])
           dp[j]=(dp[j]+dp[j-v[i]])%mod;
        }
    }
    cout<<dp[x]<<endl;
}