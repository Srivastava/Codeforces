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
#include <unordered_set>

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

	vi a(m+1,0);
	for(int i=0;i<m;++i)
	{
		std::cin>>a[i+1];
	}

	vi res(n+1,-1);

	std::unordered_map<int,int> map;

	std::unordered_set<int> set;
	for(int i=1;i<=n;++i)
		set.insert(i);

	for(int i=1;i<m;++i)
	{
		int val = (a[i+1]-a[i]);
		val = val<0 ? (n+val)%n : val%n;
		val = val==0?n:val;

		//std::cout<<a[i]<<" "<<val<<std::endl;
		if(res[a[i]]==-1){
			if(map.count(val))
			{
				std::cout<<-1<<std::endl;
				return 0;
			}
			res[a[i]]=val;
			map[val]=a[i];
			set.erase(val);
		}
		else
		{
			if(res[a[i]]!=val)
			{
				std::cout<<-1<<std::endl;
				return 0;
			}
		}
	}

	for(int i=1;i<=n;++i)
	{
		if(res[i]==-1)
		{
			int val = *set.begin();
			set.erase(val);
			res[i]=val;
		}
	}
	for(int i=1;i<=n;++i)
		std::cout<<res[i]<<" ";
	std::cout<<std::endl;
	return 0;	
}
