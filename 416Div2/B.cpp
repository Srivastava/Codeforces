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

typedef std::vector<vll> vvll;

bool check(vi& t,int x,int l,int m)
{
	int val = t[x];

	int cnt=0;
	for(int i=l;i<=m;++i)
	{
		if(t[i]<val)
			++cnt;
	}
	return cnt==x-l;
}
int main()
{
	int n,m;
	std::cin>>n>>m;

	vi p(n+1,0);

	for(int i=1;i<=n;++i)
		std::cin>>p[i];

	for(int i=0;i<m;++i)
	{
		int l,m,x;
		std::cin>>l>>m>>x;

		// std::sort(t.begin()+l,t.begin()+m+1);

		// if(t[x]==p[x])
		if(check(p,x,l,m))
			std::cout<<"Yes"<<std::endl;
		else
			std::cout<<"No"<<std::endl;
		// t=p;
	}
	return 0;
}

/*

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000007
#define MOD INF
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI ((4.0) * atan(1.0))
#define MAXN 5010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int N;
int arr[MAXN];
int dp[MAXN];
int lt[MAXN], rt[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf811c.in", "r"))
	{	
		freopen ("cf811c.in", "r", stdin);
		freopen ("cf811c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i <= 5000; i++)
	{
		lt[i] = INF;
		rt[i] = -INF;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		lt[arr[i]] = min(lt[arr[i]], i);
		rt[arr[i]] = max(rt[arr[i]], i);
	}
	for (int i = 0; i < N; i++)
	{
		int lf = i, rf = i;
		int xo = 0;
		for (int j = i; j >= 0; j--)
		{
			//check if the range j, i is fine
			lf = min(lf, lt[arr[j]]);
			rf = max(rf, rt[arr[j]]);
			if (lt[arr[j]] == j)
			{
				xo ^= arr[j];
				//							cerr << "XOR " << j << endl;
			}
			if (rf > i || lf < j)
			{
				continue;
			}
			//			cerr << j << ' ' << i << ' ' << xo << endl;
			if (j == 0)
			{
				dp[i] = max(dp[i], xo);
			}
			else
			{
				dp[i] = max(dp[i], dp[j - 1] + xo);
			}
		}
//		cerr << dp[i] << endl;
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}
	cout << dp[N] << '\n';
	return 0;
}*/