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

int main()
{
	int n,a;
	std::cin>>n>>a;

	int cnt=0;

	// std::priority_queue<pa,vpa,std::greater<pa>> pq;
	std::unordered_map<int,int> map;


	std::unordered_map<int,int> removed;
	for(int i=0;i<n;++i)
	{
		int val;
		std::cin>>val;

		if(val==a and map.empty())
		{
			std::cout<<-1<<std::endl;
			return 0;
		}
		if(val!=a and removed.find(val)==removed.end()){
			if(map[val]<cnt)
			{
				removed[val]++;
				map.erase(val);
				continue;
			}
			map[val]++;
		}
		else if(val==a)
		{
			++cnt;
			std::unordered_map<int,int> temp;
			for(auto it:map)
			{
				if(it.second<cnt)
					removed[it.first]++;
				else
					temp[it.first]=it.second;
			}
			map=temp;
		}
	}

	for(auto it:map)
	{
		// std::cout<<it.first<<" "<<it.second<<" "<<cnt<<std::endl;
		if(it.second>=cnt)
		{
			std::cout<<it.first<<std::endl;
			return 0;
		}
	}
	std::cout<<-1<<std::endl;
	return 0;
}
