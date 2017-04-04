#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <set>

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

vi color;
int ans[100005];

vb visit;

std::set<int> g[100005];

void dfs(int u)
{
	if(visit[u])
		return;
	visit[u]=true;

	int k=color[u];
	for(auto& v:g[u])
	{
		if(!visit[v])
		{
			if(k!=color[v])
				ans[k]++;
			dfs(v);
		}
		else
		{
			if(k!=color[v])
				ans[k]++;
		}
	}
	return;
}
int main()
{
	int n,m;
	std::cin>>n>>m;

	color.resize(n+1,0);
	// ans.resize(n+1,0);
	visit.resize(n+1,false);

	std::set<int> v;
	for(int i=1;i<=n;++i)
		std::cin>>color[i],v.insert(color[i]);

	for(int i=0;i<m;++i)
	{
		int u,v;
		std::cin>>u>>v;

		if(color[u]!=color[v])
		{
			g[color[u]].insert(color[v]);
			g[color[v]].insert(color[u]);
		}
		
	}

	int ans=0;

	for(auto& c:v)
	{
		if(ans==0 || g[c].size()>g[ans].size())
			ans=c;
	}

	std::cout<<ans<<std::endl;
}