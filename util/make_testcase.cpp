#include <bits/stdc++.h>  // clang-format off
#include <stdio.h>
#include <sys/time.h>
using namespace std;using ll=long long;constexpr int INF=1001001001;constexpr long long INFll=1001001001001001001;namespace viewer{template <class T>string f(T i){string s=(i==INF||i==INFll?"inf":to_string(i));s=string(max(0,3-int(s.size())),' ')+s;return s;}
template<class T>auto v(T&x,string end)->decltype(cerr<<x){return cerr<<x<<end;}void v(int x,string end){cerr<<f(x)<<end;}void v(long long x,string end){cerr<<f(x)<<end;}void v(float x,string end){cerr<<fixed<<setprecision(16)<<x<<end;}void v(double x,string end){cerr<<fixed<<setprecision(16)<<x<<end;}void v(long double x,string end){cerr<<fixed<<setprecision(16)<<x<<end;}
template<class T,class U>void v(const pair<T,U>&p,string end="\n"){cerr<<"(";v(p.first,", ");v(p.second,")"+end);}template<class T,class U>void v(const tuple<T,U>&t,string end="\n"){auto[a,b]=t;cerr<<"(";v(a,", ");v(b,")"+end);}template<class T,class U,class V>void v(const tuple<T,U,V>&t,string end="\n"){auto[a,b,c]=t;cerr<<"(";v(a,", ");v(b,", ");v(c,")"+end);}template<class T,class U,class V,class W>void v(const tuple<T,U,V,W>&t,string end="\n"){auto[a,b,c,d]=t;cerr<<"(";v(a,", ");v(b,", ");v(c,", ");v(d,")"+end);}
template<class T>void v(const vector<T>&vx,string);template<class T>auto ve(int,const vector<T>&vx)->decltype(cerr<<vx[0]){cerr<<"{";for(const T&x:vx)v(x,",");return cerr<<"}\n";}template <class T>auto ve(bool,const vector<T> &vx){cerr << "{\n";for(const T&x:vx)cerr<<"  ",v(x,",");cerr<<"}\n";}template<class T>void v(const vector<T>&vx, string){ve(0,vx);}template<class T>void v(const deque<T>&s,string e){vector<T>z(s.begin(),s.end());v(z,e);}
template<class T,class C>void v(const set<T,C>&s,string e){vector<T>z(s.begin(),s.end());v(z,e);}template<class T,class C>void v(const multiset<T,C>&s,string e){vector<T>z(s.begin(),s.end());v(z,e);}template<class T>void v(const unordered_set<T>&s,string e){vector<T>z(s.begin(),s.end());v(z,e);}template<class T>void v(const priority_queue<T>&p,string e){priority_queue<T>q=p;vector<T>z;while(!q.empty()){z.push_back(q.top());q.pop();}v(z,e);}
template<class T,class U>void v(const map<T,U>&m,string e){cerr<<"{"<<(m.empty()?"":"\n");for(const auto&kv:m){cerr<<"  [";v(kv.first,"");cerr<<"] : ";v(kv.second,"");cerr<<"\n";}cerr<<"}"+e;}template<class T>void _view(int n,string s,T&var){cerr<<"\033[1;32m"<<n<<"\033[0m: \033[1;36m"<<s<<"\033[0m = ";v(var,"\n");}template<class T>void grid(T _){}void grid(const vector<vector<bool>>&vvb){cerr<<"\n";for(const vector<bool>&vb:vvb){for(const bool&b:vb)cerr<<(b?".":"#");cerr<<"\n";}}
void _debug(int,string){}template<typename H,typename...T>void _debug(int n,string S,H h,T... t){int i=0,cnt=0;for(;i<int(S.size());i++){if(S[i]=='(')cnt++;if(S[i]==')')cnt--;if(cnt==0&&S[i]==',')break;}if(i==int(S.size()))i=-1;if(i==-1)_view(n,S,h);else {string s1=S.substr(0,i);string s2=S.substr(i+2);if(s2=="\"grid\"")cerr<<"\033[1;32m"<<n<<"\033[0m: \033[1;36m"<<s1<<"\033[0m = ",grid(h);else _view(n,s1,h),_debug(n,s2,t...);}}}
template<class T>bool chmax(T&a,const T&b){return a<b?a=b,1:0;}template<class T>bool chmin(T&a,const T&b){return a>b?a=b,1:0;} // https://rsk0315.hatenablog.com/entry/2021/01/18/065720
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) viewer::_debug(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#endif

// longlongに対応するために、普段のとは少し異なる64bit対応の乱数生成器
struct Rand64{// https://docs.python.org/ja/3/library/random.html
    Rand64():gen(random_device()()){};
    // ランダムな浮動小数点数（範囲は[0.0, 1.0)) を返します
    inline double random(){return double(gen())/double(gen.max());}
    // a <= b であれば a <= N <= b 、b < a であれば b <= N <= a であるようなランダムな浮動小数点数 N を返します
    inline double uniform(double a,double b){if(b<a)swap(a,b);return a+(b-a)*double(gen())/double(gen.max());}
    // range(0, stop) の要素からランダムに選ばれた要素を返します
    inline uint64_t randrange(uint64_t r){return gen()%r;}
    // range(start, stop) の要素からランダムに選ばれた要素を返します
    inline uint64_t randrange(uint64_t l,uint64_t r){return gen()%(r-l)+l;}
    // a <= N <= b であるようなランダムな整数 N を返します randrange(a, b + 1) のエイリアスです
    inline uint64_t randint(uint64_t l,uint64_t r){return gen()%(r-l+1)+l;}
    // シーケンス x をインプレースにシャッフルします
    template<class T>void shuffle(vector<T>&x){for(int i=x.size(),j;i>1;){j=randrange(i);swap(x[j],x[--i]);}}
    // 空でないシーケンス seq からランダムに要素を返します
    template<class T>T choice(const vector<T>&seq){assert(!seq.empty());return seq[randrange(seq.size())];}
    // 相対的な重みに基づいて要素が選ばれます (※複数回呼ぶ場合は処理を変えた方が良い)
    template<class T,class U>T choice(const vector<T>&seq,const vector<U>&weights){assert(seq.size()==weights.size());vector<U>acc(weights.size());acc[0]=weights[0];for(int i=1;i<int(weights.size());i++)acc[i]=acc[i-1]+weights[i];return seq[lower_bound(acc.begin(),acc.end(),random()*acc.back())-acc.begin()];}
    // 母集団のシーケンスまたは集合から選ばれた長さ k の一意な要素からなるリストを返します 重複無しのランダムサンプリングに用いられます
    template<class T>vector<T>sample(const vector<T>&p,int k){int j,i=0,n=p.size();assert(0<=k&&k<=n);vector<T>ret(k);unordered_set<int>s;for(;i<k;i++){do{j=randrange(n);}while(s.find(j)!=s.end());s.insert(j);ret[i]=p[j];}return ret;}
    // 正規分布です mu は平均で sigma は標準偏差です
    double normalvariate(double mu=0.0,double sigma=1.0){double u2,z,NV=4*exp(-0.5)/sqrt(2.0);while(true){u2=1.0-random();z=NV*(random()-0.5)/u2;if(z*z/4.0<=-log(u2))break;}return mu+z*sigma;}
    private: mt19937_64 gen;
}myrand;
// clang-format on

struct TestCase {
    string testcase;
    TestCase(){};

    // 範囲[mi,ma]の整数を書き込む 小さい数もやや多めに生成する
    // 負数も可能だが abs(mi) == abs(ma) を仮定
    long long add_int(long long mi, long long ma) {
        double p = myrand.random();
        if (p < 0.2) mi = min(ma, max(mi, -10000ll));
        if (p < 0.2) ma = max(mi, min(ma, 10000ll));
        if (p < 0.1) mi = min(ma, max(mi, -100ll));
        if (p < 0.1) ma = max(mi, min(ma, 100ll));
        assert(mi <= ma);
        long long ret = myrand.randint(mi, ma);
        if (mi < 0 && myrand.random() < 0.5) ret *= -1;
        testcase += to_string(ret);
        testcase += "\n";
        return ret;
    }
    // 長さ[mi,ma]の小文字alphabet列を書き込む
    string add_stirng_alphabet(int mi, int ma) {
        assert(mi <= ma);
        double p = myrand.random();
        if (p < 0.2) ma = max(mi, min(ma, 10000));
        if (p < 0.1) ma = max(mi, min(ma, 100));
        string ret;
        int len = myrand.randint(mi, ma);
        for (int _ = 0; _ < len; _++) ret += 'a' + myrand.randint(0, 25);
        testcase += ret + "\n";
        return ret;
    }
    // 長さ[mi,ma]の小文字alphabet列を書き込む
    string add_stirng_ALPHABET(int mi, int ma, char last = 'Z') {
        assert(mi <= ma);
        double p = myrand.random();
        if (p < 0.2) ma = max(mi, min(ma, 10000));
        if (p < 0.1) ma = max(mi, min(ma, 100));
        string ret;
        int len = myrand.randint(mi, ma);
        for (int _ = 0; _ < len; _++)
            ret += 'A' + myrand.randint(0, last - 'A');
        testcase += ret + "\n";
        return ret;
    }
    // 桁数[mi,ma]の整数を書き込む 桁dpなど用 0始まりあり
    string add_big_int(int mi, int ma) {
        assert(mi <= ma);
        double p = myrand.random();
        if (p < 0.2) ma = max(mi, min(ma, 10000));
        if (p < 0.1) ma = max(mi, min(ma, 100));
        string ret;
        int len = myrand.randint(mi, ma);
        for (int _ = 0; _ < len; _++) ret += '0' + myrand.randint(0, 9);
        testcase += ret + "\n";
        return ret;
    }
    // 桁数[mi,ma]の整数を書き込む 桁dpなど用 0始まりなし
    string add_big_int_start_with_nonzero(int mi, int ma) {
        assert(mi <= ma);
        double p = myrand.random();
        if (p < 0.2) ma = max(mi, min(ma, 10000));
        if (p < 0.1) ma = max(mi, min(ma, 100));
        string ret;
        ret += '0' + myrand.randint(1, 9);
        int let = myrand.randint(mi, ma);
        for (int _ = 1; _ < let; _++) ret += '0' + myrand.randint(0, 9);
        testcase += ret + "\n";
        return ret;
    }
    // 長さNの順列(0-indexed)を書き込む
    vector<int> add_permutation_0idxed(int N) {
        assert(N <= 200000);
        vector<int> Ps(N);
        iota(Ps.begin(), Ps.end(), 0);
        myrand.shuffle(Ps);
        for (int i : Ps) testcase += to_string(i) + " ";
        testcase += "\n";
        return Ps;
    }
    // 長さNの順列(1-indexed)を書き込む
    vector<int> add_permutation_1idxed(int N) {
        assert(N <= 200000);
        vector<int> Ps(N);
        iota(Ps.begin(), Ps.end(), 1);
        myrand.shuffle(Ps);
        for (int i : Ps) testcase += to_string(i) + " ";
        testcase += "\n";
        return Ps;
    }
    // H行W列のgridを生成する
    vector<vector<bool>> add_grid(int H, int W) {
        assert(H <= 200000 && W <= 200000);
        vector<vector<bool>> grid(H, vector<bool>(W, false));
        double prob = myrand.random();
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                grid[h][w] = (myrand.random() < prob);
                testcase += grid[h][w] ? "#" : ".";
            }
            testcase += "\n";
        }
        return grid;
    }
};

string f(int x, int width) {
    string ret = to_string(x);
    ret = string(width - ret.size(), '0') + ret;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    TestCase testcase;

    [[maybe_unused]] const long long TEN5 = 200000;                // 2*10^5
    [[maybe_unused]] const long long TEN9 = 1000000000;            // 10^9
    [[maybe_unused]] const long long TEN12 = 1000000000000;        // 10^9
    [[maybe_unused]] const long long TEN18 = 1000000000000000000;  // 10^18

    int N = testcase.add_int(2, 10);
    int M = testcase.add_int(1, 10);
    for (int i = 0; i < M; i++) {
        testcase.add_int(1, TEN9);
        testcase.add_int(1, TEN9);
        testcase.add_int(1, TEN9);
        testcase.add_int(1, TEN9);
        testcase.add_int(1, N);
        testcase.add_int(1, N);
    }

    cout << testcase.testcase << endl;

    return 0;
}
