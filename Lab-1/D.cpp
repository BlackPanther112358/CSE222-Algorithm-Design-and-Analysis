#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; 
using namespace __gnu_pbds;

#define printtest cout << "Case #" << tt << ": ";
#define tc watch(tt); solve();

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

void output(bool x, ostream& os = cout){ os << x; }
void output(int x, ostream& os = cout){ os << x; }
void output(char x, ostream& os = cout){ os << x; }
void output(string x, ostream& os = cout){ os << x; }
void output(ld x, ostream& os = cout){ os << x; }
template<class T, class R> void output(pair<T, R> p, ostream& os = cout){ output(p.first, os); os << " "; output(p.second, os); }
template<class T> void output(vector<T> v, ostream& os = cout){ for(T i:v){output(i, os); os << " ";} os << nline; }
template<class T> void output(set<T> v, ostream& os = cout){ for(T i:v){output(i, os); os << " ";}}
template<class T> void output(multiset<T> v, ostream& os = cout){ for(T i:v){output(i, os); os << " ";}}
template<class T, class R> void output(map<T, R> v, ostream& os = cout){ for(pair<T, R> i:v){output(i.first, os); os << ":- "; output(i.second, os); os << "    ";}}

const int inf = LLONG_MAX;
const int neg_inf = LLONG_MIN;
const int mod = 1000000007;
// const int mod = 998244353;
const int N = 1e5;     
const ld pi = 3.141592653589793;

/*  0 for single test case
    1 for multiple test cases
    2 for multiple test cases with case number */
#define RUN_TESTS 1

string shuffle_sort(string s){
    int n = sz(s);
    if(n&1) return s;
    string a = shuffle_sort(s.substr(0, n/2));
    string b = shuffle_sort(s.substr(n/2, n/2));
    if(a < b) return a + b;
    return b + a;
}

void solve(){
    int n;
    string a, b;
    cin >> n >> a >> b;
    a = shuffle_sort(a);
    b = shuffle_sort(b);
    watch(a);
    watch(b);
    cout << (a == b ? "YES" : "NO") << nline;
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
        int t; cin >> t; for(int tt = 1; tt <= t; tt++){tc}
    #elif RUN_TESTS == 2
        int t; cin >> t; for(int tt = 1; tt <= t; tt++){printtest tc}
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