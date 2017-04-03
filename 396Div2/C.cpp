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

	std::string s;
	std::cin>>s;

	vi a(26,0);
	for(int i=0;i<26;++i)
		std::cin>>a[i];

	// std::cout<<s<<std::endl;
	int maxNum=1,cnt=0;


	vll dp(n,0),split(n,1e18);
	vb visit(26,0);

	dp[0]=1;
	split[0]=1;
	for(int i=1;i<n;++i)
	{
		for(int k=0;k<26;++k)
			visit[k]=false;
		visit[s[i]-'a']=true;

		for(int j=i;j>=0;--j)
		{
			int len=i-j+1;
			bool poss=true;

			visit[s[j]-'a']=true;

			for(int k=0;k<26;++k)
			{
				if(visit[k]==true)
				{
					if(len>a[k])
						poss=false;
				}
			}
			if(poss)
			{
				maxNum=std::max(maxNum,len);
				ll num=(j==0) ? 1:dp[j-1];
				dp[i] =(dp[i] + num)%MOD;
				split[i]=std::min(split[i],(j==0 ? 0 : split[j-1])+1);
			}
			else
				break;
		}
	}

	std::cout<<dp[n-1]<<std::endl;
	std::cout<<maxNum<<std::endl;
	std::cout<<split[n-1]<<std::endl;
	return 0;
}
