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
	int n,m;
	std::cin>>n>>m;

	std::string s,t;
	std::cin>>s>>t;

	vi res;
	int mincnt=INT_MAX;
	for(int i=0;i<m-n+1;++i)
	{
		std::string temp=t.substr(i,n);
		vi tv;
		int cnt=0;

		// std::cout<<temp<<std::endl;
		for(int j=0;j<n;++j)
		{
			
			if(s[j]!=temp[j])
			{
				++cnt;
				tv.push_back(j+1);
			}
		}

		// std::cout<<cnt<<std::endl;
		if(mincnt>cnt)
		{
			res=tv;
			mincnt=cnt;
		}
	}

	std::cout<<mincnt<<std::endl;
	for(auto it:res)
		std::cout<<it<<" ";
	std::cout<<std::endl;
	return 0;
}
