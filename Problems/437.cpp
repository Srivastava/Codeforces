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

// vi topo;
vb visit;
vll g[1005];

/*void dfs(int u)
{
	if(visit[u])
		return;
	visit[u]=true;

	for(auto& v:g[u])
	{
		if(!visit[v])
			dfs(v);
	}
	topo.push_back(u);
	return;
}*/

int main()
{
	int n,m;
	std::cin>>n>>m;

	visit.resize(n+1,false);

	vi cost(n+1,0);

	vpa p;
	for(int i=1;i<=n;++i)
		std::cin>>cost[i],p.push_back({cost[i],i});

	std::sort(p.begin(),p.end());

	for(int i=0;i<m;++i)
	{
		int u,v;
		std::cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	ll ans=0;
	for(int i=p.size()-1;i>=0;--i)
	{
		int u=p[i].second;
		if(!visit[u])
		{
			for(auto& v:g[u]){
				if(!visit[v])
					ans+=cost[v];
			}
		}
		visit[u]=true;
	}
	std::cout<<ans<<std::endl;
	return 0;
}