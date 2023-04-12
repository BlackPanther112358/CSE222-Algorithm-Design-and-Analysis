#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; 
using namespace __gnu_pbds;

#ifdef BlackPanther112358
    #define watch(x) cerr << #x << " = "; output(x, cerr); cerr << nline;
#else
    #define watch(x) 0
#endif

#define int long long int
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef set<int> si;
typedef set<pair<int, int>> sii;
typedef multiset<int> msi;
typedef priority_queue<int> maxhi;
typedef priority_queue<pii> maxhii;
typedef priority_queue <int, vector<int>, greater<int>> minhi;
typedef priority_queue <pii, vector<pii>, greater<pii>> minhii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define nline "\n"
#define sz(x) (int)x.size()
#define rep(xx) for(int aa = 0; aa < xx; aa++)
#define rep_u(ii, aa, bb) for(int ii = aa; ii < bb; ii++)
#define rep_d(ii, aa, bb) for(int ii = aa; ii >= bb; ii--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sum_all(x) accumulate(all(x), 0LL)
#define max_idx(x) max_element(all(x)) - x.begin()
#define min_idx(x) min_element(all(x)) - x.begin()
#define pcnt(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)  
#define prec(x) setprecision(x) << fixed
#define yesno(x) cout << (x ? "YES" : "NO") << nline

void output(bool x, ostream& os = cout){ os << x; }
void output(int x, ostream& os = cout){ os << x; }
void output(char x, ostream& os = cout){ os << x; }
void output(string x, ostream& os = cout){ os << x; }
void output(ld x, ostream& os = cout){ os << x; }
template<size_t n> void output(bitset<n> x, ostream& os = cout){ os << x; }
template<class T, class R> void output(pair<T, R> p, ostream& os = cout){ output(p.first, os); os << " "; output(p.second, os); }
template<class T> void output(vector<T> v, ostream& os = cout){ for(T i:v){output(i, os); os << " ";} os << nline; }
// template<class T> void output(tupe<T> v, ostream& os = cout){  }
template<class T> void output(set<T> v, ostream& os = cout){ for(T i:v){output(i, os); os << " ";}}
template<class T> void output(multiset<T> v, ostream& os = cout){ for(T i:v){output(i, os); os << " ";}}
template<class T, class R> void output(map<T, R> v, ostream& os = cout){ for(pair<T, R> i:v){output(i.first, os); os << ":- "; output(i.second, os); os << "    ";}}

int bin_exp(int x, int y, int m){
    int res = 1;
    x %= m;
    while(y > 0){
        if(y & 1) res = (res * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return res;
}

const int inf = LLONG_MAX;
const int neg_inf = LLONG_MIN;
const int mod = 1000000007;
// const int mod = 998244353;
const int N = 4e5;     
const ld pi = 3.141592653589793;

/*  0 for single test case
    1 for multiple test cases
    2 for multiple test cases with case number */
#define RUN_TESTS 0

int n, m;
vector<vector<pair<int, pii>>> adj;
vi min_time;
minhii pq;

int optimal_time(int y){
    if(y == 0) return 0;
    int l = 1, r = 1e5, root = -1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(mid * mid <= y){
            root = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    watch(root);
    int a = root - 1 + y/root, b = root + y/(root + 1);
    if(a <= b) return root - 1;
    else return root;
}

int reach_time(int x, int y, int start){
    int t = optimal_time(y);
    if(t < start) return start + y/(start + 1) + x;
    return t + y/(t + 1) + x;
}

void dijkstra(){
    pq.push({0, 0});
    while(!pq.empty()){
        int u = pq.top().second;
        int t = pq.top().first;
        watch(u);
        pq.pop();
        if(min_time[u] == inf) min_time[u] = t;
        else continue;
        if(u == (n - 1)) return;
        if(t > min_time[u]) continue;
        for(auto v: adj[u]){
            int x = v.second.first, y = v.second.second;
            if(min_time[v.first] != inf) continue;
            int new_time = reach_time(x, y, t);
            pq.push({new_time, v.first});
        }
    }
}

void solve(){
    cin >> n >> m;
    adj.resize(n);
    min_time.resize(n, inf);
    rep(m){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--; v--;
        if(u == v) continue;
        adj[u].pb({v, {x, y}});
        adj[v].pb({u, {x, y}});
    }
    watch(adj);
    dijkstra();
    cout << (min_time[n - 1] == inf ? -1 : min_time[n - 1]) << nline;
    return;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifdef BlackPanther112358
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
        auto start = chrono::high_resolution_clock::now();
    #endif

    #if RUN_TESTS == 1
        int t; cin >> t; for(int tt = 1; tt <= t; tt++){watch(tt); solve();}
    #elif RUN_TESTS == 2
        int t; cin >> t; for(int tt = 1; tt <= t; tt++){cout << "Case " << tt << ": "; watch(tt); solve();}
    #else
        solve();
    #endif

    #ifdef BlackPanther112358
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cerr << "\nTime elapsed: " << duration.count() / 1000.0 << " ms.\n";
    #endif

    return 0;
}