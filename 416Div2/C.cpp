#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

#include <unordered_map>
#include <unordered_set>
typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<int,int> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

int main()
{
	int n;
	std::cin>>n;
	vi a(n,0);


	std::unordered_map<int,pa> map;
	for(int i=0;i<n;++i){
		std::cin>>a[i];


		if(map.find(a[i])!=map.end())
		{
			pa temp = map[a[i]];
			temp.first = std::max(temp.first,i);
			temp.second = std::min(temp.second,i);
			map[a[i]]=temp;
		}
		else
		{
			map[a[i]]={i,i};
		}
	}

	// std::cout<<"here"<<std::endl;
	std::vector<vll> dp(n+1,vll(n+1,0));
	for(auto it:map)
	{
		int i=it.second.second;
		int j= it.second.first;

		std::unordered_set<int> ans(a.begin()+i,a.begin()+j+1);
		long long res=0;
		for(auto setIt:ans)
			res^=setIt;
		dp[i][j]=res;
	}
	
	for(int i=n-1;i>=0;--i)
	{
		for(int j=i;j<n-1;++j)
		{
			dp[i][n-1]=std::max(dp[i][n-1],dp[i][j]+dp[j+1][n-1]);
		}
	}
	std::cout<<dp[0][n-1]<<std::endl;
}
