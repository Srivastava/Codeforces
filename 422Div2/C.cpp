/*#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>

typedef long ll;
typedef unsigned long long ull;

// const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<int,int> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

bool check(int li,int ri,int lj,int rj)
{
	return (rj<li or ri<lj);
}
int main()
{
	int n,x;
	std::cin>>n>>x;

	vi l(n,0),r(n,0);
	vi c(n,0);

	std::unordered_map<ll,vi> map;
	for(int i=0;i<n;++i)
	{
		int li,ri,ci;
		std::cin>>li>>ri>>ci;
		l[i]=li;
		r[i]=ri;
		c[i]=ci;

		//d[i]=ri-li+1;
		map[ri-li+1].push_back(i);

	}

	vpa indices;
	for(int i=0;i<n;++i)
	{
		int dur=r[i]-l[i]+1;
		int val=x-dur;
		if(map.find(val)!=map.end())
		{
			for(auto j:map[val])
				indices.push_back({i,j});
		}
	}

	map.clear();

	int sz=indices.size();
	if(sz==0)
	{
		std::cout<<-1<<std::endl;
		return 0;
	}

	ll mincost=1e12;


	for(auto p:indices)
	{
		int i=p.first,j=p.second;
		if(check(l[i],r[i],l[j],r[j]))
		{
			long val = c[i]+c[j];
			
			if(mincost>val)
				mincost=val;
		}
	}
	std::cout<<mincost<<std::endl;
	return 0;
}*/
/*
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

// const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<int,int> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

bool check(int li,int ri,int lj,int rj)
{
	return (rj<li or ri<lj);
}
int main()
{
	int n,x;
	std::cin>>n>>x;

	vi l(n,0),r(n,0);
	vi c(n,0);

	std::unordered_map<ll,vi> map;
	for(int i=0;i<n;++i)
	{
		int li,ri,ci;
		std::cin>>li>>ri>>ci;
		l[i]=li;
		r[i]=ri;
		c[i]=ci;
		map[ri-li+1].push_back(i);

	}

	ll mincost=1e15;

	for(int i=0;i<n;++i)
	{
		int dur=r[i]-l[i]+1;
		int val=x-dur;
		if(map.find(val)!=map.end())
		{
			for(auto j:map[val])
			{
				if(i!=j and check(l[i],r[i],l[j],r[j]))
				{
					long val = (long)c[i]+(long)c[j];
					
					if(mincost>val)
						mincost=val;
				}
			}
		}
	}

	for(auto it:map)
	{

		// int dur=r[i]-l[i]+1;
		int val=x-it.first;
		if(map.find(val)!=map.end())
		{
			for(auto i:it.second)
			{
				for(auto j:map[val])
				{
					if(i!=j and check(l[i],r[i],l[j],r[j]))
					{
						long val = (long)c[i]+(long)c[j];
						
						if(mincost>val)
							mincost=val;
					}
				}
			}
		}
	}
	map.clear();
	
	if(mincost==1e15)
	{
		std::cout<<-1;
	}
	else
	{
		std::cout<<mincost;
	}

	return 0;
}
*/


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

// const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<int,int> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

bool check(int li,int ri,int lj,int rj)
{
	return (rj<li or ri<lj);
}
int main()
{
	int n,x;
	std::cin>>n>>x;

	std::vector<std::pair<std::pair<int,pa>>> lr;
	lr.reserve(n);
	vi c(n,0);

	std::unordered_map<ll,vi> map;
	for(int i=0;i<n;++i)
	{
		int li,ri,ci;
		std::cin>>li>>ri>>ci;
		lr.push_back({ri-li+1,{li,{ri,ci}}});
		
	}

	std::sort(lr.begin(),lr.end());
	int l=0,r=n-1;

	while(l<r)
	{
		if()
	}

	return 0;
}
