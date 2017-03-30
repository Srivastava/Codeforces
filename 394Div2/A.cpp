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
	int a,b;
	std::cin>>a>>b;

	if(std::abs(a-b)>1 || (a==0 && b==0))
		std::cout<<"NO"<<std::endl;
	else
		std::cout<<"YES"<<std::endl;

	return 0;
	/*int num=a+b;

	int odd1=num/2,even1=num-odd1;
	int even2=num/2,odd2=num-even2;

	if(a==even1 && b==odd1)
		std::cout<<"YES"<<std::endl;
	else if(a==even2 && b==odd2)
		std::cout<<"YES"<<std::endl;
	else
		std::cout<<"NO"<<std::endl;
	return 0;*/

}
