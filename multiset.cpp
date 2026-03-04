/*********************************************************************************************************
*****     __________   __     __    __________   _______        ___      __     __    __     __      *****
*****    |   ___   |  |  |   |  |  |___    ___| |   _  |_      | _ |    |  |   |  |  |  |   |  |     *****
*****    |  |   |__|  |  |___|  |      |  |     |  |_|  _|    | |_| |    |  | |  |   |  |   |  |     *****
*****    |  |    __   |   ___   |      |  |     |   _  |_    |  ___  |    |     |    |  |   |  |     *****
*****    |  |___|  |  |  |   |  |   ___|  |___  |  | |  |   |  |   |  |     |  |     |  |___|  |     *****
*****    |_________|  |__|   |__|  |_________|  |__| |__|  |__|     |__|    |__|     |_________|     *****
*****                                                                                                *****
**********************************************************************************************************/

#include<bits/stdc++.h>
#include <limits.h>
#include <iterator>
#include <algorithm>

using namespace std;

#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define CHIRAYU cout.tie(NULL)

#define ll long long int
#define lld long double
#define ull unsigned long long int

const lld pi = 3.141592653589793238;
const ll INF = __LONG_LONG_MAX__;
const ll mod = 1e9 + 7;

//Pair
typedef pair<ll, ll> pll;
#define p(A, B) pair<A, B>
#define mp make_pair

//Vector
#define v(T) vector<T>
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll> > vvll;

//Set
typedef set<ll> sll;
typedef unordered_set<ll> usll;

//Map
typedef map<ll, ll> mll;
typedef map<char,ll> mcll;
typedef unordered_map<ll, ll> umll;
typedef unordered_map<char,ll> umcll;

//Heap
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T>, greater<T>>

//Loop
#define f(i, b, r) for (ll i = b; i < r; i++)
#define rf(j, r, b) for (ll j = b-1; j >= r; j--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sot(v) sort(all(v))

//Precision
#define ps(x, y) fixed << setprecision(y) << x;

//shortcut
#define ff first
#define ss second
#define py cout << "YES"<< endl
#define pm cout << "-1" << endl
#define pn cout << "NO"<< endl
#define pe cout << endl
#define p1(x) cout << x << endl

#define i1(a) \
    ll a;      \
    cin >> a
#define i2(a, b)\
    ll a, b;     \
    cin >> a >> b
#define i3(a, b, c)\
    ll a, b, c;     \
    cin >> a >> b >> c
#define i4(a, b, c, d)\
    ll a, b, c, d;     \
    cin >> a >> b >> c >> d
#define i5(a, b, c, d, e)\
    ll a, b, c, d, e;     \
    cin >> a >> b >> c >> d >> e
#define i6(a, b, c, d, e, f)\
    ll a, b, c, d, e, f;     \
    cin >> a >> b >> c >> d >> e >> f

#define o1(a) cout << a<<endl
#define o2(a, b) cout << a << " " << b<<endl
#define o3(a, b, c) cout << a << " " << b << " " << c<<endl
#define o4(a, b, c, d) cout << a << " " << b << " " << c << " " << d<<endl
#define o5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e<<endl
#define o6(a, b, c, d, e, f) cout << a << " " << b << " " << c << " " << d << " " << e << " " << f<<endl

#define inarr(arr, n)          \
vector<ll> arr(n);         \
for (ll i = 0; i < n; i++) \
    cin >> arr[i];

#define outarr(arr, n)          \
for (ll i = 0; i < n; i++) \
cout << arr[i] << " ";

#define instr(n) \
string n;    \
cin >> n;

//sort vector of pair
template <typename A, typename B>
bool seconda(const pair<A,B> &a, const pair<A,B> &b) { return (a.second < b.second); }
template <typename A, typename B>
bool secondd(const pair<A,B> &a, const pair<A,B> &b) { return (a.second > b.second); }
template <typename A, typename B>
bool firsta_secondd(const pair<A,B> &a, const pair<A,B> &b) { if(a.first!=b.first){ return (a.first<b.first);} return (a.second > b.second);}
template <typename A, typename B>
bool firstd_seconda(const pair<A,B> &a, const pair<A,B> &b) { if(a.first!=b.first){ return (a.first>b.first);} return (a.second < b.second);}

//math
ll gcd(ll a, ll b){if (b == 0) return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll binarySearch_index(ll low, ll high, vector<ll> &a, ll element){ll mid; while (low <= high){mid = (low + high) / 2;if (a[mid] >= element)high = mid - 1;else low = mid + 1;}return max(mid, low);}
ll power(ll a, ll b){if (a == 0)return 0;else if (b == 0)return 1;else{ll result = a;for (int i = 1; i < b; i++)result = result * a;return result;}}
string bin_str(ll num){ll p = num;string s = "";while (num != 0){s += to_string(num % 2);num /= 2;}reverse(s.begin(), s.end());if (p == 0)return "0";else return s;}
bool isPowerOfTwo(int n){if (n == 0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPrime(ll n){if (n <= 1)return false;if (n <= 3)return true;if (n % 2 == 0 || n % 3 == 0)return false;for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false;return true;}
bool isPerfectSquare(ll x){if (x >= 0){ll sr = sqrtl(x);return (sr * sr == x);}return false;}

//--------------------------------------------------------------------------------
void solve()
{
    multiset<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    cout<<s.count(1)<<endl;
    
    cout<<*s.begin()<<endl;

    cout<<*s.rbegin()<<endl;
    
    for(auto it:s)
    {
        cout<<it<<" ";
    }
    
}

int main()
{
Code By CHIRAYU;
int t=1;
while(t--)
{
solve();      
}
return 0;
}