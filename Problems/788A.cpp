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

ll kadane(vll a)
{
	ll sum=a[0];
	ll ans=a[0];

	int n=a.size();
	for(int i=1;i<n-1;++i)
	{
		if(sum<0)
			sum=a[i];
		else
			sum+=a[i];
		ans=std::max(ans,sum);
	}
	return ans;
}


int main()
{
	int n;
	std::cin>>n;

	vll a(n,0);
	for(int i=0;i<n;++i)
		std::cin>>a[i];

	vll b(n,0),c(n,0);
	for(int i=0;i<n-1;++i){
		b[i]=std::abs(a[i+1]-a[i]);
		c[i]=b[i];
	}

	for(int i=0;i<n;++i)
	{
		if(i%2==0)
			b[i]=-b[i];
		else
			c[i]=-c[i];
	}

	std::cout<<std::max(kadane(b),kadane(c))<<std::endl;
	return 0;
}
