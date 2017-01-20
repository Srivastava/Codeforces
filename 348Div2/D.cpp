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
	int n,q;
	std::cin>>n>>q;

	vi boys(n,0);

	for(int i=0;i<n;++i)
	{
		boys[i]=i+1;
	}

	int c=0;
	for(int i=0;i<q;++i)
	{
		int a,b;
		std::cin>>a;
		if(a==1)
		{
			if(c==1)
			{
				for(int i=0;i<n-1;i+=2)
					std::swap(boys[i],boys[i+1]);
				c=0;
			}

			std::cin>>b;
			if(b>0)
				std::rotate(boys.rbegin(),boys.rbegin()+b,boys.rend());
			else
				std::rotate(boys.begin(),boys.begin()-b,boys.end());
		}
		else
		{
			c=1-c;
		}
	}

	if(c==1)
	{
		for(int i=0;i<n-1;i+=2)
			std::swap(boys[i],boys[i+1]);
		c=0;
	}
	

	std::copy(boys.begin(),boys.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;

	return 0;
}