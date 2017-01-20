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

	vi jump(n,0),visit(n,0);

	for(int i=0;i<n;++i)
		std::cin>>jump[i];

	int i=0;
	bool inf=false;
	while(1)
	{
		if(visit[i]==1){
			inf=true;break;
		}

		visit[i]=1;
		int len=s[i]=='>' ? jump[i]:-jump[i];
		if(i+len>=n || i+len<0)
			break;
		i+=len;
	}

	if(inf)
		std::cout<<"INFINITE"<<std::endl;
	else
		std::cout<<"FINITE"<<std::endl;

	return 0;
}