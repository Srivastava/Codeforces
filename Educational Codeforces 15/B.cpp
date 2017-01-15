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


/*int main()
{
	int n;
	std::cin>>n;

	vll a(n,0);

	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	int ans=0;
	for(int i=0;i<n-1;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			int val=a[i]+a[j];
			if(val>0 && (val & (val-1))==0)
				++ans;
		}
	}
	std::cout<<ans<<std::endl;
	return 0;
}*/

/*ll power2(ll x)
{
	ll pow=1;
	while(pow<=x)
	{
		pow*=2;
	}
	return pow;
}*/

int main()
{
	int n;
	std::cin>>n;

	vll a(n,0);

	
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	std::sort(a.begin(),a.end());

	std::pair<std::vector<ll>::iterator,std::vector<ll>::iterator> bounds;

	std::vector<ll> b(32,0);
	for(int i=0;i<32;++i)
	{
		b[i]=std::pow(2,i);
	}
	ll ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<32;++j)
		{
			if(a[i]<b[j])
			{
				bounds=std::equal_range (a.begin(), a.begin()+i, b[j]-a[i]);
				ans+=bounds.second-bounds.first;
				/*if(bounds.first<a.begin()+i)
				{
					ans+=bounds.second-bounds.first;
				}  */     
			}
		// std::cout<<val<<std::endl;
			
		}
		
	}
	std::cout<<ans<<std::endl;

	// ans=0;
	// for(int i=0;i<n-1;++i)
	// {
	// 	for(int j=i+1;j<n;++j)
	// 	{
	// 		int val=a[i]+a[j];
	// 		if(val>0 && (val & (val-1))==0)
	// 			++ans;
	// 	}
	// }
	// std::cout<<ans<<std::endl;
	return 0;
}