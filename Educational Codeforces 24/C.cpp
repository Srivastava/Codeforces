#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vi> vvll;

int main()
{
	int d;
	std::cin>>d;

	int m,n;
	std::cin>>m>>n;

	vvll a(m+1,vi(n+1,0));

	vpa p;
	for(int i=0;i<d-1;++i)
	{
		int x1,y1,x2,y2;
		std::cin>>x1>>y1>>x2>>y2;
		a[x1][y1]=1;
		a[x2][y2]=1;
		p.push_back()
	}
	int cntl,cntr,cntt,cntb;
	std::cin>>cntl>>cntr>>cntt>>cntb;

	vi top(m+1,0);
	for(int i=0;i<m+1;++i)
	{
		for(int j=1;j<n+1;++j)
		{
			a[i][j]+=a[i][j-1];
		}
		if(i==0)
			top[0]=a[0][n];
		if(i>=1)
			top[i]=a[i][n]+top[i-1];
	}


}


/*
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include<cctype>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<time.h>
#include<iterator>
#include <deque>
#include <sstream>
#include<queue>
#include<stdlib.h>
#include<bitset> 
#include <utility>
#include<assert.h>
#include<functional>
#include<limits.h>

#define fn(i,n) for(int (i) = 0;(i) < (n);(i)++)
#define f1n(i,n) for(int (i) = 1;(i) <= (n);(i)++)
#define mk(f,s) make_pair((f),(s))

#define defV(dp,e) memset(dp,e,sizeof dp)

#define ri(n) scanf("%d",&n)
#define rl(n) scanf("%lld",&n)
#define rs(s) scanf("%s",s)

#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef pair<int, int > pp;

typedef vector<int  > v1;
typedef vector<ll  > vl;
typedef vector<pp  > vpp;
typedef vector<bool  > vb;
typedef vector<char > vc;
typedef vector<v1 > v2;

int const oo = 1e9, bound = 1e6 + 1, mod = oo + 7, N = 5e5 + 2, CON = 30000001;
ll const OO = 1e18;

int top[N],bot[N],rgt[N],lft[N];
vector<pair<pp,pp> > dd;
int d,n,m,cl,cr,ct,cb;
int main() {
	//freopen("input.txt", "r", stdin);
	cin>>d>>n>>m;
	fn(i,d){
	    int x1,y1,x2,y2;
	    cin>>x1>>y1>>x2>>y2;
	    dd.push_back({{x1,y1},{x2,y2}});
	    top[min(y1,y2)]++;
	    bot[max(y1,y2)]++;
	    lft[min(x1,x2)]++;
	    rgt[max(x1,x2)]++;
	}
	cin>>cl>>cr>>ct>>cb;
	f1n(i,N-1)top[i+1]+=top[i],bot[i+1]+=bot[i],lft[i+1]+=lft[i],rgt[i+1]+=rgt[i];
	fn(i,d){
	    int x1=dd[i].first.first,y1=dd[i].first.second,x2=dd[i].second.first,y2=dd[i].second.second;
	    int tl=lft[max(x1,x2)-1],
	        tr=rgt[N]-rgt[min(x1,x2)],
	        tt=top[max(y1,y2)-1],
	        tb=bot[N]-bot[min(y1,y2)];
	        if(x1!=x2)tl--,tr--;
	        else tt--,tb--;
	        if(tl==cl&&tr==cr&&tt==ct&&tb==cb){
	            cout<<i+1<<endl;
	            return 0;
	        }
	}
	cout<<-1<<endl;
	return 0;
}
*/