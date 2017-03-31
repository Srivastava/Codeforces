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


int gcd(int a,int b)
{
	return b==0 ? a : gcd(b,a%b);
}

int lcm(int a,int b)
{
	int g=gcd(a,b);
	return a*b/g;
}
int main()
{

	int n,m,z;
	std::cin>>n>>m>>z;

	int l=lcm(n,m);

	std::cout<<z/l<<std::endl;

	return 0;
}
