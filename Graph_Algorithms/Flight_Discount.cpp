#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define vpl vector<pll>
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vl>
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>
#define pb push_back
#define all(x) begin(x), end(x)
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
bool vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}
vector<int> SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    vector<int> primes; 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    return primes; 
}
#define lo(i,f,t) for(ll i=f;i<t;i++)
int mex(vl &arr, ll n)
{
    mll mp;
    lo(i,0,n) {
        mp[arr[i]]++;
    }
    ll mex = 0;
    lo(i,0,n+1) {
        if (mp[i] == 0) {
            mex = i;
            break;
        }
    }
    return mex;
}
ostream& operator<<(ostream& dout, vector<ll>& vec) 
{
    lo(i, 0, vec.size())
    {
        dout << vec[i] << " ";
    }
    dout << endl;
    return dout;
}
 
istream& operator>>(istream& din, vector<ll>& vec) 
{
    lo(i, 0, vec.size())
    {
        din >> vec[i];
    }
    return din;
}
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
#define intmax INT_MAX
void write()
{
    ll n,m;
    cin>>n>>m;
    vector<vpl> adj1(n+1);
    vector<vpl> adj2(n+1);
    vll edges(m,vl(3,0));
    lo(i,0,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edges[i]={a,b,c};
        adj1[a].pb({c,b});
        adj2[b].pb({c,a});
    }
      priority_queue<pll, vector<pll>, greater<pll>> pq;
            vl dist1(n + 1, 1e9);
            vl dist2(n + 1, 1e9);
            vl vis(n+1,0);
            // for (int i = 1; i <= n; i++)
            //     parent[i] = i;
            dist1[1] = 0; 
            pq.push({0, 1});
            while (!pq.empty())
            {
                auto it = pq.top();
                pq.pop();

                ll node = it.second;
                ll dis = it.first;
                if(vis[node]) continue;
                vis[node]=1;
                for (auto it : adj1[node])
                {
                    ll edW = it.first;
                    ll adjNode = it.second;
                    // cout<<adjNode<<" "<<edW<<endl;
                    if (dis + edW < dist1[adjNode])
                    {
                        dist1[adjNode] = dis + edW;
                        pq.push({dis + edW, adjNode});
                        // parent[adjNode] = node;
                    }
                }
            }
    dist2[n] = 0;
    pq.push({0, n});
fill(all(vis),0);
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;
        if(vis[node]) continue;
        vis[node]=1;
        for (auto it : adj2[node])
        {
            int edW = it.first;
            int adjNode = it.second;
            if (dis + edW < dist2[adjNode])
            {
                dist2[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
            }
        }
    }
    // cout<<dist1;
    // cout<<dist2;
    ll ans=1e9;
    lo(i,0,m)
    {
        ll u,v,c;
        u=edges[i][0];
        v=edges[i][1];
        c=edges[i][2];
        ans=min(ans,dist1[u]+c/2+dist2[v]);
    }
    cout<<ans<<endl;
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