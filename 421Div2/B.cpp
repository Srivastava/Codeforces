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
	long double n,a,b,min=10000000000000;
	std::cin>>n>>a;

	double intangle = (n-2) * 180.0/n;
	double aposs=180.0/n;

	std::vector<double> angles;

	long double t=intangle;
	while(t>0)
	{
		angles.push_back(t);
		t-=aposs;
	}

	long double temp,temp1;
	for(int i=3;i<=n;i++)
	{
		temp=((n+1-i)*180)/n;
		temp1=fabs(temp-a);
		if(temp1<min)
		{
			b=i;
			min=temp1;	
		}
	}
		std::cout<<"1 2 "<<b<<std::endl;

}
/*
	int v1=1,v2=2,v3=3;
	double res=INT_MAX;
	for(int i=0;i<angles.size();++i)
	{
		
		// std::cout<<i<<" "<<angles[i]<<" "<<angles.size()<<" --- "<<std::endl;
		if(res>std::abs(angles[i]-a))
		{
			std::cout<<std::abs(angles[i]-a)<<std::endl;
			v2=i+2;
			v3=i+3;
			res=std::abs(angles[i]-a);
		}
	}
	std::cout<<v1<<" "<<v2<<" "<<v3<<std::endl;
}
*/