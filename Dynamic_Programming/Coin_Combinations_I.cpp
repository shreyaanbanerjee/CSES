#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n,x;
    cin>>n>>x;
    ll c[n];
    for(ll i=0;i<n;i++) cin>>c[i];
    // sort(c.begin(),c.end());
    ll dp[x+1];
    for(ll i=1;i<=x;i++)
    dp[i]=0;
    dp[0]=1;
    for(ll i=1;i<=x;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i<c[j]) continue;
            
                dp[i]=(dp[i]+dp[i-c[j]])%mod;
            
        }
    }
    // cout<<dp<<endl;
cout<<dp[x]<<endl;
}