#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <set>

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

	if(n>m){
		std::cout<<"YES"<<std::endl;
		return 0;
	}
	if(m>n)
	{
		std::cout<<"NO"<<std::endl;
		return 0;
	}

	std::set<std::string> myset;

	for(int i=0;i<n+m;++i)
	{
		std::string s;
		std::cin>>s;
		myset.insert(s);
	}

	int sz=myset.size();
	if(sz%2==0)
		std::cout<<"NO"<<std::endl;
	else
		std::cout<<"YES"<<std::endl;
	return 0;
}