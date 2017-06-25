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
	int m,b;
	std::cin>>m>>b;

	ll res=0;

	for(int j=0;j<=b;++j)
	{
		ll x = m*(b-j);
		ll sum = (j*(j+1))/2 + (x*(x+1))/2 + (x*j*(x+j+2))/2;
		res=std::max(res,sum); 
	}
	std::cout<<res<<std::endl;
}
