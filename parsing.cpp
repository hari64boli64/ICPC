#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t lll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef tuple<ll, ll, ll> tt;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pl> vp;
typedef vector<tt> vt;
typedef vector<string> vs;

const ll INF = 1000000010;
const ll INFL = INF * INF;
const ld epsilon = 1e-10;

#define ovl(a, b, c, d, e, ...) e
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define DEBUG(...) DEBUG_(#__VA_ARGS__, __VA_ARGS__)
#define REP1(i, r) for (int i = 0; i < (r); i++)
#define REP2(i, l, r) for (int i = (l); i < (r); i++)
#define REP3(i, l, r, d) for (int i = (l); i < (r); i += (d))
#define REP(...) ovl(__VA_ARGS__, REP3, REP2, REP1)(__VA_ARGS__)
#define RREP1(i, r) for (int i = (r)-1; i >= 0; i--)
#define RREP2(i, l, r) for (int i = (r)-1; i >= (l); i--)
#define RREP3(i, l, r, d) for (int i = (r)-1; i >= (l); i -= (d))
#define RREP(...) ovl(__VA_ARGS__, RREP3, RREP2, RREP1)(__VA_ARGS__)
#define EACH1(x, a) for (auto &x : a)
#define EACH2(x, y, a) for (auto &[x, y] : a)
#define EACH3(x, y, z, a) for (auto &[x, y, z] : a)
#define EACH(...) ovl(__VA_ARGS__, EACH3, EACH2, EACH1)(__VA_ARGS__)
#define ALL(x) begin(x), end(x)
#define RALL(x) (x).rbegin(), (x).rend()
#define sz(x) (ll) x.size()
#define LB(a, x) (lower_bound(ALL(a), x) - a.begin())
#define UB(a, x) (upper_bound(ALL(a), x) - a.begin())
#define FLG(x, i) (((x) >> (i)) & 1)
#define CNTBIT(x) __builtin_popcountll(x)
#define IN(x, a, b) ((a) <= (x) && (x) < (b))
#define int ll

template <class T>
void DEBUG_(string_view name, const T &a) {
    cerr << name << ": " << a << endl;
}

template <class T>
void DEBUG_(string_view name, const vector<T> &a) {
    cerr << name << ": ";
    REP(i, sz(a)) cerr << a[i] << " ";
    cerr << endl;
}

template <class T, class U>
bool chmax(T &x, const U &y) {
    return x < y ? x = y, 1 : 0;
}
template <class T, class U>
bool chmin(T &x, const U &y) {
    return x > y ? x = y, 1 : 0;
}

//-----------------------------------------------------------------------

typedef string::const_iterator State;
typedef vector<vector<int>> Mat;

constexpr int MOD = 1 << 15;

Mat matadd(const Mat &m1, const Mat &m2) {
    assert(m1.size() == m2.size() && m1[0].size() == m2[0].size());
    Mat m3 = m1;
    REP(h, (int)m1.size())
    REP(w, (int)m1[0].size()) {
        m3[h][w] += m2[h][w];
        m3[h][w] %= MOD;
    }
    return m3;
}

Mat matsub(const Mat &m1, const Mat &m2) {
    assert(m1.size() == m2.size() && m1[0].size() == m2[0].size());
    Mat m3 = m1;
    REP(h, (int)m1.size())
    REP(w, (int)m1[0].size()) {
        m3[h][w] += MOD - m2[h][w] % MOD;
        m3[h][w] %= MOD;
    }
    return m3;
}

Mat matmul(const Mat &m1, const Mat &m2) {
    if (int(m1.size()) == 1 && int(m1[0].size()) == 1) {
        Mat m3 = m2;
        REP(h, int(m3.size()))
        REP(w, int(m3[0].size())) {
            m3[h][w] *= m1[0][0];
            m3[h][w] %= MOD;
        }
        return m3;
    } else if (int(m2.size()) == 1 && int(m2[0].size()) == 1) {
        Mat m3 = m1;
        REP(h, int(m3.size()))
        REP(w, int(m3[0].size())) {
            m3[h][w] *= m2[0][0];
            m3[h][w] %= MOD;
        }
        return m3;
    } else {
        assert(m1[0].size() == m2.size());
        Mat m3(m1.size(), vl(m2[0].size(), 0));
        REP(i, (int)m1.size())
        REP(j, (int)m2[0].size())
        REP(k, (int)m1[0].size()) {
            m3[i][j] += m1[i][k] * m2[k][j] % MOD;
            m3[i][j] %= MOD;
        }
        return m3;
    }
}

Mat unary_minus(const Mat &m) {
    Mat m3 = m;
    REP(h, (int)m.size())
    REP(w, (int)m[0].size()) { m3[h][w] = MOD - m[h][w]; }
    return m3;
}

Mat mattranspose(const Mat &m) {
    Mat m3(m[0].size(), vl(m.size()));
    REP(h, (int)m.size())
    REP(w, (int)m[0].size()) { m3[w][h] = m[h][w]; }
    return m3;
}

Mat matindex(const Mat &p, const Mat &m1, const Mat &m2) {
    assert((int)m1.size() == 1 && (int)m2.size() == 1);
    Mat m3(m1[0].size(), vl(m2[0].size()));
    REP(h, (int)m1[0].size())
    REP(w, (int)m2[0].size()) { m3[h][w] = p[m1[0][h] - 1][m2[0][w] - 1]; }
    return m3;
}

map<string, Mat> store;

Mat assignment(State &bein);
string var(State &begin);
Mat expr(State &begin);
Mat term(State &begin);
Mat factor(State &begin);
Mat primary(State &begin);
Mat matrix(State &begin);

Mat assignment(State &begin) {
    string X = var(begin);
    assert(*begin == '=');
    begin++;
    Mat mat = expr(begin);
    store[X] = mat;
    return mat;
}

string var(State &begin) {
    assert('A' <= *begin && *begin <= 'Z');
    string ret(1, *begin);
    begin++;
    return ret;
}

Mat expr(State &begin) {
    Mat mat = term(begin);
    while (*begin != '.') {
        if (*begin == '+') {
            begin++;
            Mat mat2 = term(begin);
            mat = matadd(mat, mat2);
        } else if (*begin == '-') {
            begin++;
            Mat mat2 = term(begin);
            mat = matsub(mat, mat2);
        } else {
            break;
        }
    }
    return mat;
}

Mat term(State &begin) {
    Mat mat = factor(begin);
    while (*begin == '*') {
        begin++;
        Mat mat2 = factor(begin);
        mat = matmul(mat, mat2);
    }
    return mat;
}

Mat factor(State &begin) {
    if (*begin == '-') {
        begin++;
        return unary_minus(factor(begin));
    } else {
        return primary(begin);
    }
}

int inum(State &begin) {
    int ret = 0;
    while (isdigit(*begin)) {
        ret *= 10;
        ret %= MOD;
        ret += *begin - '0';
        ret %= MOD;
        begin++;
    }
    // DEBUG(*begin);
    return ret;
}

Mat row(State &begin) {
    // DEBUG("row");
    Mat mat = expr(begin);
    // DEBUG(*begin);
    while (*begin == ' ') {
        begin++;
        Mat mat2 = expr(begin);
        // DEBUG(mat2);
        assert(mat.size() == mat2.size());
        REP(h, int(mat.size())) {
            EACH(e, mat2[h]) { mat[h].pb(e); }
        }
    }
    return mat;
}

Mat rowseq(State &begin) {
    Mat mat = row(begin);
    while (*begin == ';') {
        begin++;
        Mat mat2 = row(begin);
        EACH(r, mat2) { mat.pb(r); }
    }
    return mat;
}

Mat primary_sub(State &begin) {
    if (isdigit(*begin)) {
        return Mat(1, vl(1, inum(begin)));
    }
    if ('A' <= *begin && *begin <= 'Z') {
        Mat ret = store[string(1, *begin)];
        begin++;
        return ret;
    }
    if (*begin == '[') {
        begin++;
        Mat mat = rowseq(begin);
        assert(*begin == ']');
        begin++;
        return mat;
    }
    if (*begin == '(') {
        begin++;
        Mat mat = expr(begin);
        assert(*begin == ')');
        begin++;
        return mat;
    }
    assert(false);
}

Mat primary(State &begin) {
    Mat p = primary_sub(begin);
    while (*begin == '(' || *begin == '\'') {
        if (*begin == '(') {
            begin++;
            Mat mat1 = expr(begin);
            assert(*begin == ',');
            begin++;
            Mat mat2 = expr(begin);
            assert(*begin == ')');
            begin++;
            p = matindex(p, mat1, mat2);
        } else {
            begin++;
            p = mattranspose(p);
        }
    }
    return p;
}

vector<Mat> solve(int N) {
    store.clear();
    vector<Mat> mats;
    REP(i, N) {
        string S;
        getline(cin, S);
        // DEBUG(S);
        State begin = S.begin();
        Mat mat = assignment(begin);
        // DEBUG("mat");
        // EACH(m, mat) { DEBUG(m); }
        mats.pb(mat);
    }
    return mats;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    vector<vector<Mat>> answers;
    while (true) {
        string n;
        getline(cin, n);
        State begin = n.begin();
        int N = inum(begin);
        if (N == 0) break;
        // DEBUG(N);
        vector<Mat> answer = solve(N);
        answers.pb(answer);
    }

    EACH(as, answers) {
        EACH(a, as) {
            REP(h, (int)a.size()) {
                REP(w, (int)a[h].size()) {
                    cout << a[h][w] << (w == int(a[h].size()) - 1 ? "" : " ");
                }
                cout << endl;
            }
        }
        cout << "-----" << endl;
    }

    return 0;
}
