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

	vi a(n+1,0);
	for(int i=1;i<=n;++i)
	{
		std::cin>>a[i];
	}	

	int k=0;
	std::cin>>k;
	
	vll b(k+1,0);
	for(int i=1;i<=k;++i)
	{
		std::cin>>b[i];
	}

	/*vi sum(n,0);
	sum[0]=a[0];
	for(int i=1;i<n;++i)
		sum[i]=sum[i-1]+a[i];*/

	int i=1;
	int j=1;

	bool poss=true;
	while(i<=n && j<=k)
	{
		int val=b[j];
		int summing=0;
		while(summing<b[j]){
			summing+=a[i];
			++i;
		}
		std::cout<<summing<<std::endl;
		if(summing==val)
			++j;
		else{
			poss=false;
			break;
		}
		// ++i;
	}

	if(!poss)
	{
		std::cout<<"NO"<<std::endl;
		return 0;
	}
	else
	{
		if(i!=n+1 || j!=k+1)
			std::cout<<"NO"<<std::endl;
		else
			std::cout<<"YES"<<std::endl;
		return 0;
	}

	return 0;
}