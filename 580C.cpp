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

vi g[200005];

vi a(200005,0);
// vb visit(200005,false);

int dfs(int u,int pr,int m,int rem, bool cat)
{
	
	
	if(cat && a[u])
		--rem;

	// std::cout<<u<<" ** "<<m<<" "<<rem<<" ** "<<cat<<std::endl;

	if(rem<0)
	{
		return 0;
	}
	/*if(g[u].size()==0)
	{
		// if(rem==0 && cat && a[u])
		// 	return 0;
		// else
		// 	return 1;
		return 1;
	}*/
	
	int cnt=1,ans=0;
	for(auto& v:g[u])
	{
		// std::cout<<u<<" "<<v<<std::endl;
		if(v!=pr)
		{
			cnt=0;
		
			if(cat && a[u]==1)
				ans+=dfs(v,u,m,rem,a[u]);
			else	
				ans+=dfs(v,u,m,m,a[u]);
		}
		
	}
	ans+=cnt;
	return ans;
}

int main()
{
	int n,m;
	std::cin>>n>>m;

	for(int i=1;i<=n;++i)
		std::cin>>a[i];

	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		std::cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	// visit[1]=true;
	std::cout<<dfs(1,0,m,m,a[1])<<std::endl;

	return 0;
}