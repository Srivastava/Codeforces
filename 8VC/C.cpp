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

int find(int u,vi&s)
{
	return u==s[u]? u : s[u]=find(s[u],s);
}

void join(int u,int v,vi& s)
{
	s[find(u,s)]=find(v,s);
}



int main()
{
	int n;
	std::cin>>n;

	vi s(n+1,0);
	for(int i=0;i<=n;++i)
	{
		s[i]=i;
	}

	vi p(n+1,0);
	for(int i=1;i<=n;++i){
		std::cin>>p[i];
		join(i,p[i],s);
	}

	for(int i=1;i<=n;++i)
		find(i,s);
	
	std::set<int> myset(s.begin()+1,s.end());
	std::cout<<myset.size()<<std::endl;
	
	return 0;
}