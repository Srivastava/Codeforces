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


int main()
{
	int m,d;
	std::cin>>m>>d;

	std::unordered_map<int,int> month;
	month[1]=31;
	month[2]=28;
	month[3]=31;
	month[4]=30;
	month[5]=31;
	month[6]=30;
	month[7]=31;
	month[8]=31;
	month[9]=30;
	month[10]=31;
	month[11]=30;
	month[12]=31;

	int ans=1;
	int first=7-d+1;
	int rem=month[m]-first;

	ans+=rem/7 + (rem%7>0);
	std::cout<<ans<<std::endl;
	
	return 0;
}