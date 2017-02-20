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

vpa g[100010];
// vll dist;

vi a;
int ans;
void dfs(int u,int p,ll lim)
{
	if(lim>a[u])
		return;

	lim=std::max(0LL,lim);
	++ans;
	for(auto& v:g[u])
	{
		int node=v.first,cost=v.second;
		if(node==p)
			continue;
		
		dfs(node,u,lim+cost);
	}
	return;
}
int main()
{
	int n;
	std::cin>>n;

	a.resize(n+1,0);

	for(int i=1;i<=n;++i)
	{
		std::cin>>a[i];
	}

	for(int i=1;i<=n-1;++i)
	{
		int u,c;
		std::cin>>u>>c;

		g[i+1].push_back({u,c});
		g[u].push_back({i+1,c});
		// g[v].push_back(u);

	}

	ans=0;
	dfs(1,0,0);

	std::cout<<n-ans<<std::endl;
	// dist.resize(n+1,0);
	// h.resize(n+1,0);

	return 0;
}