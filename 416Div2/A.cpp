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
	ll a,b;
	std::cin>>a>>b;

	int val=1;

	ll i=1;
	while(a>=0 and b>=0)
	{
		if(i%2!=0){
			if(val>a)
			{
				std::cout<<"Vladik"<<std::endl;
				return 0;
			}
			a-=val;
		}
		else{

			if(val>b)
			{
				std::cout<<"Valera"<<std::endl;
				return 0;
			}
			b-=val;
		}
		++i;
		++val;
	}

	return 0;

}
