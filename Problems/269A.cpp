
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


typedef std::vector<ll> vll;
typedef std::vector<ull> vull;


typedef std::vector<std::pair<ull,ull> > pvull;
typedef std::vector<std::pair<ll,ll> > pvll;


ull maxLevel(const pvull& sq)
{
	ull max=sq[0].first+1;


	while(1)
	{
		bool all=true;
	 	// std::cout<<max<<std::endl;
	 	ull p=0;
		for(int i=0;i<sq.size();++i)
		{
			p=max-sq[i].first-1;
			std::cout<<p<<" "<<3*std::pow(4,p)<<" "<<sq[i].second-1<<std::endl;
			if(3*std::pow(4,p) < sq[i].second-1)
			{
				all=false;
				// max+=1;
				break;
			}
			else
			{
				all=true;
			}


		}
		if(!all){max+=1;}
		if(all)
		{	
			if(3*std::pow(4,p)>sq[0].second-1 && sq.size()==1 && p!=0){max=sq[0].first+p;}
			// if(p==max-1){max=p;}
			// max=std::min(max,p);
			break;
		}
	}
	return max;

}
int main()
{
	ll n;
	std::cin>>n;

	int ans=0,max=0;

	for(int i=0;i<n;++i)
	{
		int k,a;
		std::cin>>k>>a;

		max=std::max(max,k);
		int s=1;
		int m=0;
		while(s<a)
		{
			s*=4;
			++m;
		}
		ans=std::max(ans,k+m);
	}
	
	if(ans==max){++ans;}
	std::cout<<ans<<std::endl;
	return 0;
}