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
#define fori for (i = 0; i < n; i++)
template <class T>
void print_v(vector<T> &v)
{
    cout << "{";
    for (auto x : v)
        cout << x << ",";
    cout << "\b}";
}
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
int power(int x, unsigned int y)
{
    int res = 1; // Initialize result
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
ll min(ll a, int b)
{
    if (a < b)
        return a;
    return b;
}
ll min(int a, ll b)
{
    if (a < b)
        return a;
    return b;
}
ll max(ll a, int b)
{
    if (a > b)
        return a;
    return b;
}
ll max(int a, ll b)
{
    if (a > b)
        return a;
    return b;
}
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
void dfs(ll node, vll &adj, vl &vis) {
        vis[node] = 1; 
        // ls.push_back(node); 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis); 
            }
        }
    }
#define intmax INT_MAX
#define inf 10000000000
void write() {
    ll n,m;
    cin>>n>>m;
    vll adj1(n+1),adj2(n+1);
    vll edges(m,vl(3));
    lo(i,0,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edges[i]={a,b,-c};
        adj1[a].pb(b);
        adj2[b].pb(a);  
    }
    vl dist(n+1,1e10);
    vl vis1(n+1,0);
    vl vis2(n+1,0);
    // vl ls;
    dfs(1,adj1,vis1);
    dfs(n,adj2,vis2);
    dist[1]=0;
    lo(i,0,n)
    {
        lo(j,0,m)
        {
            ll u=edges[j][0];
            ll v=edges[j][1];
            ll c=edges[j][2];
            if(dist[v]>dist[u]+c)
            {
                dist[v]=dist[u]+c;
                if(i==n-1 && vis1[v] && vis2[v]){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }
    cout<<-dist[n]<<endl;
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