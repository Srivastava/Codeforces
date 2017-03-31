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
typedef std::pair<int,int> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

const int maxn= 100010;

vi g[maxn];
// vi dp[maxn];


vi c;

bool dfs(int u, int p,int& color)
{

	bool res=true;
	for(auto v:g[u])
	{
		if(v==p)
			continue;

		if(c[v]!=color){
			return false;
		}

		if(!dfs(v,u,color))
			return false;
	}
	return res;
}

bool solve(int u)
{
	for(auto v:g[u])
	{
		if(!dfs(v,u,c[v]))
			return false;
	}
	return true;
}

int main()
{
	int n;
	std::cin>>n;

	c.resize(n+1,0);
	
	for(int i=0;i<n-1;++i)
	{
		int u,v;
		std::cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);

	}


	for(int i=1;i<=n;++i)
		std::cin>>c[i];

	int root1=-1,root2=-1;

	for(int i=1;i<=n;++i)
	{
		for(auto u:g[i])
		{
			if(c[i]!=c[u])
			{
				root1=i;
				root2=u;
				break;
			}
		}
	}

	if(root1==-1){
		std::cout<<"YES"<<std::endl;
		std::cout<<1<<std::endl;
		return 0;
	}
	
	bool res1= solve(root1);
	bool res2= solve(root2);

	if(res1)
	{
		std::cout<<"YES"<<std::endl;
		std::cout<<root1<<std::endl;
	}
	else if(res2)
	{
		std::cout<<"YES"<<std::endl;
		std::cout<<root2<<std::endl;
	}
	else
	{
		std::cout<<"NO"<<std::endl;
	}
	return 0;
}
