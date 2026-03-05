#include <bits/stdc++.h>
// #define MOD 1000000007ll
#define MOD 998244353ll
#define INF (1ll<<60)
#define EPS 1e-14
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define ciN cin
#define npos string::npos
#define nextp next_permutation
#define prevp prev_permutation
#define maxe max_element
#define mine min_element
#define accu accumulate
#define popcount __builtin_popcount
#define clzll __builtin_clzll
#define elif else if 
#define nall(A) A.begin(), A.end()
#define rall(A) A.rbegin(), A.rend()
#define rep(i, n) for(int i = 0; i < (n); i++) 
#define rrep(i, n) for(int i = (n)-1; i >= 0; i--)
#define each(i, a) for(auto& i : a)
#define out(x, y) (!(0 <= x && x < H && 0 <= y && y < W))
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define yesno(a) cout<<(a?"Yes":"No")<<endl
#define sanko(a, b, c) (a? b: c)
#define ci cin
#define tostr to_string
#define func function
#define uniqueerase(A) A.erase(unique(A.begin(), A.end()), A.end())
using namespace std;
using cd = complex<long double>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define pii pair<int, int>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vv<T>>;
template<typename T> using vvvv = vector<vvv<T>>;
template<typename T> using vvvvv = vector<vvvv<T>>;
// template<typename T> using uset = unorderd_set<T>;
// template<typename T> using umap = unorderd_map<T>;
template<typename T> using mset = multiset<T>;
const ll ROOT = (MOD == 998244353ll? 3: 5);
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy8[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const long double PI = acosl(-1);
const string abcdefghijklmnopqrstuvwxyz = "abcdefghijklmnopqrstuvwxyz";
const string ABCDEFGHIJKLMNOPQRSTUVWXYZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string num0123456789 = "0123456789";
const ll tens[19] = {
    1ll,
    10ll,
    100ll,
    1000ll,
    10000ll,
    100000ll,
    1000000ll,
    10000000ll,
    100000000ll,
    1000000000ll,
    10000000000ll,
    100000000000ll,
    1000000000000ll,
    10000000000000ll,
    100000000000000ll,
    1000000000000000ll,
    10000000000000000ll,
    100000000000000000ll,
    1000000000000000000ll,
};

template<typename T> void chmin(T& x, T y){
    x = min(x, y);
}

template<typename T> void chmax(T& x, T y){
    x = max(x, y);
}

template<typename T> istream& operator >> (istream& is, deque<T>& v) {
	for (T& x : v) is >> x;
	return is;
}

template<typename T> ostream& operator << (ostream& os, const deque<T>& v){
	for (int i = 0; i < v.size(); i++){
		if (i < v.size()-1) os << v[i] << ' ';
		else os << v[i] << '\n';
	}
	return os;
}

template<typename T> istream& operator >> (istream& is, vector<T>& v) {
	for (T& x : v) is >> x;
	return is;
}

template<typename T> ostream& operator << (ostream& os, const vector<T>& v){
	for (int i = 0; i < v.size(); i++){
		if (i < v.size()-1) os << v[i] << ' ';
		else os << v[i] << '\n';
	}
	return os;
}

template<typename T, typename U> istream& operator >> (istream& is, pair<T, U>& p){
    is >> p.first >> p.second;
    return is;
}

template<typename T, typename U> istream& operator >> (istream& is, vector<pair<T, U>>& p){
    for (auto& i : p) cin >> i.first >> i.second;
    return is;
}

template<typename T, typename U> istream& operator >> (istream& is, deque<pair<T, U>>& p){
    for (auto& i : p) cin >> i.first >> i.second;
    return is;
}

vector<pair<char, int>> to_rle(const string& S){
	vector<pair<char, int>> res;
	for (char i : S) {
		if (res.empty() || res.back().first != i) res.push_back({ i, 1 });
		else res.back().second++;
	}
	return res;
}

template<typename T> vector<pair<T, int>> to_rle(const vector<T>& A){
	vector<pair<T, int>> res;
	for (T i : A){
		if (res.empty() || res.back().first != i) res.push_back({i, 1});
		else res.back().second++;
	}
	return res;
}

string to_base2(long long N){
    string res;
    while (N > 0){
        if (N%2 > 0) res += '1';
        else res += '0';
        N /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> zaatu(const string& A){
	int N = (int)A.size();
	string B = A;
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	vector<int> res(N);
	for (int i = 0; i < N; i++){
		res[i] = lower_bound(B.begin(), B.end(), A[i])-B.begin();
	}
	return res;
}

template<typename T> vector<int> zaatu(const vector<T>& A){
	int N = (int)A.size();
	vector<T> B = A;
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	vector<int> res(N);
	for (int i = 0; i < N; i++){
		res[i] = lower_bound(B.begin(), B.end(), A[i])-B.begin();
	}
	return res;
}

bool iskaibun(string s){
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}