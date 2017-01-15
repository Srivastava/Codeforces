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
	int n,k;
	std::cin>>n>>k;

	vi s(n+1,0);

	vi ans(n+1,0);
	ans[0]=1;
	// s[1]=1;
	int cnt=1;


	int u=1;
	while(cnt<=n)
	{
		
		int j=u+k;
		if(j<=n)
		{
			int val=0;
			/*for(int i=u+1;i<j;++i)
				val+=s[i];*/
			for(int i=1;i<=n;++i){
				if(i==u || i==j){continue;}
				val+=s[i];
			}
			// s[u]++;
			s[j]++;
			ans[cnt]=ans[cnt-1]+val+1;
			u=j;
		}
		else
		{
			int rem=j-n;
			int val=0;
			/*for(int i=u+1;i<=n;++i)
				val+=s[i];
			for(int i=1;i<rem;++i)
				val+=s[i];*/
			for(int i=1;i<=n;++i){
				if(i==rem || i==u){continue;}
				val+=s[i];
			}
			// s[u]++;
			s[rem]++;
			ans[cnt]=ans[cnt-1]+val+1;
			u=rem;
		}

		std::cout<<u<<" "<<s[u]<<" "<<ans[cnt]<<std::endl;
		++cnt;
	}

	for(int i=1;i<=n;++i)
	{
		std::cout<<ans[i]<<" ";
	}
	std::cout<<std::endl;
	return 0;
}