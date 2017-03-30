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

int main()
{
	int n,m;
	std::cin>>n>>m;

	int res=INT_MAX;

	std::vector<vi> grid(n,vi(3,100000));
	for(int i=0;i<n;++i)
	{
		std::string temp;
		std::cin>>temp;

		for(int j=0;j<m;++j)
		{
			if(isalpha(temp[j]))
				grid[i][0]=std::min(grid[i][0],std::min(j,m-j));
			else if(isdigit(temp[j]))
				grid[i][1]=std::min(grid[i][1],std::min(j,m-j));
			else if(temp[j]=='*' || temp[j]=='&' || temp[j]=='#')
				grid[i][2]=std::min(grid[i][2],std::min(j,m-j));
		}
	}

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
			{
				if(i!=j && j!=k && k!=i)
					res=std::min(res,grid[i][0]+grid[j][1]+grid[k][2]);
			}
		}
	}
	std::cout<<res<<std::endl;
	return 0;
}
