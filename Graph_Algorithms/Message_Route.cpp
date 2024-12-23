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
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
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
#define intmax INT_MAX
ll N;
vll adj(100001);
vl vis(100001,0);
vl par(100001);
ll bfs()
{
queue<ll>q;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        ll curr=q.front();
        q.pop();
        for(auto i:adj[curr])
        {
            if(!vis[i])
            {
            par[i]=curr;
            vis[i]=1;
            q.push(i);
            if(i==N)
            {
               return N;
            }
            }
        }
    }
    return -1;
}
void write()
{
    ll n,m;
    cin>>N>>m;
    lo(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
       adj[x].pb(y);
       adj[y].pb(x);
    }
    if(bfs()==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    ll tem=N;
    vl res;res.pb(N);
    while(tem!=1)
    {
        res.pb(par[tem]);
        tem=par[tem];
    }
    cout<<res.size()<<endl;
    reverse(all(res));
    cout<<res;
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