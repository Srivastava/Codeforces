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
	ll a,b;
	std::cin>>a>>b;

	vll f(15,0);
	f[0]=0;
	f[1]=1;

	for(int i=2;i<=15;++i)
	{
		f[i]=f[i-1]*i;
	}

	ll min=std::min(a,b);
	std::cout<<f[min]<<std::endl;
	return 0;
}
