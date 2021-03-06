#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <stack>
#include <utility>
using namespace std;

#define s(n)    scanf("%d",&n)
#define sl(n)   scanf("%lld",&n)
#define p(n)    printf("%d ",n)
#define pl(n)   printf("%lld",n)
#define sf(n)   scanf("%f",&n)
#define sd(n)   scanf("%lf",&n)
#define ss(n)   scanf("%s",n)
#define pf(n)   printf("%f ",n)
#define pd(n)   printf("%lf ",n)
#define ps(n)   printf("%s ",n)
#define nl      putchar('\n')
#define e1      first
#define e2      second

#define INF     (int)1e9
#define MOD     (int)(1e9+7)
#define LINF    (ll)1e18
#define EPS     1e-11
const double PI = acos(-1.0)

#define pow2(n) (1<<(n))
#define pow2l(n) ((ll)1<<(n))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(n)   ((a)<0?-(a):(a))
#define MAXE(...)   max_element(__VA_ARGS__)
#define MINE(...)   min_element(__VA_ARGS__)

#define FOR(i,a,b)  for(int i=a;i<b;i++)
#define RNG(i,n)    FOR(i,0,n)
#define REV(i,a,b)  for(int i=a;i>=b;--i)
#define FORECH(v,c) for(typeof((c).begin()) v=(c).begin(); v!=(c).end(); ++v)
#define ALL(a)      (a).begin(),(a).end()
#define LEN(a)      ((int)(a.size()))
#define PB(x)       push_back(x)
#define TIMES(x)    while((x)--)
#define UPB         upper_bound
#define LWB         lower_bound
#define MP          make_pair

#ifndef ONLINE_JUDGE
#define DEBUG__
#endif
#ifdef DEBUG__
    #define derr(x)     cerr<<"<"<<#x<<": "<<x<<">"<<endl
    #define _DEBUG(...) __VA_ARGS__
    ;template<typename T> void debug(T a, T b){ for(;a!=b;++a) cerr<<*a<<" "; cerr<<endl; }
#else
    #define derr(...)
    #define _DEBUG(...)
    ;template<typename T> void debug(T a, T b){}
#endif

typedef long long       ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll; 
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef vector<vi>  vvi;
typedef vector<vl>  vvl;
typedef list<int>   li;
typedef map<int,int> mii;

template<typename T> T modPow(T b, T e, T m=(ll)MOD){T res=1;while(e){if(!(e&0x1))res=(res*b)%m;e>>=1;b=(b*b)%m;}return res; }
template<typename T> T gcd (T u, T v){ return (u==0||v==0||u==v)?(u|v):((~u&1)?((v&1)?gcd(u>>1,v):gcd(u>>1,v>>1)<<1):((~v&1)?gcd(u,v>>1):((u>v)?gcd((u-v)>>1,v):gcd((v-u)>>1,u)))); }
template<typename T> T lcm (T a, T b){ return a*b/gcd(a,b); }
//#undef DEBUG__
///////////////////////////////          FAST  IO          ///////////////////////////////////////
#define gc getchar_unlocked
void si(int &n){
    register int ch=gc();
    int neg = 0;
    n=0;
    while((ch<48||ch>57) && ch!='-')ch=gc();
    if(ch=='-'){ neg=1; ch=gc(); }
    for(;ch>47 && ch<58; ch=gc()) n = (n<<1)+(n<<3)+ch-48;
    if(neg)n=-n;
}
vector<double> conn_components;
double mark;
int bfs(bool visited[], queue<int> &que, int r, int c, int graph[]){
	int temp;
	int count = 0;
	int flag = 0;
	queue <int > output;
	int n = r * c;
	visited[que.front()] = 1;
	while(!que.empty()){
		temp = que.front();
		if(temp == n-1) flag = 1;
		//cout << "Front: " << temp << endl;
		if (temp % c && !visited[temp -1]){
			visited[temp - 1] = 1;que.push(temp - 1);
		}
		if(temp % c != c-1 && !visited[temp + 1]){
			visited[temp + 1] = 1;que.push(temp + 1);
		}
		if (temp / c && !visited[temp - c]){
			visited[temp - c] = 1;que.push(temp - c);
		}
		if(temp / c != r-1 && !visited[temp + c]){
			visited[temp + c] = 1;que.push(temp + c);
		}
		que.pop();
		// output.push(temp);
		count ++;
	}
	if(flag) mark = count;
	else conn_components.PB(count);
	return flag;
}
int number_islands(int graph[], int r, int c){
	int n = r * c;
	bool visited[n];
	int i;
	RNG(i, n){
		if(!graph[i]) visited[i] = 1;
		else visited[i] = 0;
	}
	queue<int> que;
	//cout << "reached point 1\n";
	int count = 0;
	RNG(i, n){
		if (!visited[i]){
			que.push(i);
			//cout << "Pushing :" << graph[i] << i << endl;
			bfs(visited, que, r, c, graph);
			count++;
		}
	}
	return count;
}

int main(){
	// std::ios::sync_with_stdio(false);
	int t, m, n, r, c, i, q;
	char p;
	cin >> t;
	// t = 1;
	while(t--){
		cin >> r >> c;
		// r = c = 3;
		n  = r * c;
		int graph[n];
		i = 0;
		RNG(i, n){
			cin >> p;
			if(p == 'o') graph[i] =1;
			else graph[i] = 0;
		}
		double xx = number_islands(graph, r, c);
		double ans = 1;

		RNG(i, xx - 1) ans += conn_components[i]/(conn_components[i] + mark);
		cout.precision(8);
		cout << fixed << ans << endl;
		conn_components.clear();
	}

return 0;
}
