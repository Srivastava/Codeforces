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

bool tSum(vi &numbers, int target)
{
	std::unordered_map<int, int> hash;

	for (int i = 0; i < numbers.size(); i++) 
	{
		int num = target - numbers[i];

     
		if (hash.find(num) != hash.end()) 
		{
			return true;
		}
		hash[numbers[i]] = i;
	}
	return false;
}

int main()
{
	int n;
	std::cin>>n;

	std::vector<vi> a(n,vi(n,0));

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			std::cin>>a[i][j];
		}
	}

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(a[i][j]==1)
				continue;

			vi temp = a[i];
			temp.erase(temp.begin()+j);
			for(int k=0;k<n;++k)
			{
				if(k!=i)
					temp.push_back(a[k][j]);
			}

			if(!tSum(temp,a[i][j]))
			{
				std::cout<<"No"<<std::endl;
				return 0;
			}
		}
	}

	std::cout<<"Yes"<<std::endl;

	return 0;
}
