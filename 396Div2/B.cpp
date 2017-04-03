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
	
	int n;
	std::cin>>n;

	vll a(n,0);

	for(int i=0;i<n;++i)
		std::cin>>a[i];

	std::sort(a.begin(),a.end());

	for(int i=0;i<n;++i)
	{
		int l=i+1,r=n-1;

		while(l<r)
		{
			while(l<r && a[r]-a[l]>=a[i])
				--r;
			if(l==r)
				break;
			else
			{
				if(a[i]+a[l]>a[r])
				{
					// std::cout<<a[i]<<" "<<a[l]<<" "<<a[r]<<std::endl;
					std::cout<<"YES"<<std::endl;

					return 0;
				}
			}
		}
	}

	std::cout<<"NO"<<std::endl;
	return 0;
}
