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

/*bool check(ll m,vll& a,vll& b)
{
	int k=0;

	int l=0;
	int n=a.size();
	for(int i=0;i<b.size();++i)
	{
		ll low=b[i]-m;
		ll hi=b[i]+m;

		while(l<n && b[i]>= a[l] && low<=a[l])
			++l;
		while(l<n && b[i]<= a[l] && hi>=a[l])
			++l;
		// if(l==n){return true;}
	}
	return l>=n;	
}

int main()
{
	int n,m;
	std::cin>>n>>m;

	vll a(n,0),b(m,0);

	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}
	for(int i=0;i<m;++i)
	{
		std::cin>>b[i];
	}

	ll l=0,r=1e10;

	while(l<r)
	{
		ll m=(l+r)/2;

		// std::cout<<m<<std::endl;
		if(check(m,a,b))
		{
			r=m;
		}
		else
			l=m+1;
	}
	std::cout<<r<<std::endl;
	return 0;
}*/

int main()
{

	int n,m;
	std::cin>>n>>m;

	vll a(n,0),b(m,0);

	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}
	for(int i=0;i<m;++i)
	{
		std::cin>>b[i];
	}

	int i=0,j=0;

	ll ans=0;
	while(i<n)
	{
		ll d =std::abs(a[i]-b[j]);

		while(j<m-1 && std::abs(a[i]-b[j+1])<=d)
			d=std::abs(a[i]-b[++j]);
		ans=std::max(ans,d);
		++i;
	}

	std::cout<<ans<<std::endl;
	return 0;
}