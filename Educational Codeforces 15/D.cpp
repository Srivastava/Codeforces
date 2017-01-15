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

const ll maxi=1e18;
int rec(ll d,bool rep,ll k,ll a,ll b,ll t)
{
	if(d==0){return 0;}
	
	std::cout<<d<<std::endl;
	ll ans=maxi;
	if(d>=k)
	{
		ll val=a*k+rec(d-k,true,k,a,b,t);
		if(rep)
			ans=std::min(ans,std::min(t+val,d*b));
		else
			ans=std::min(ans,std::min(val,d*b));
	}
	else
	{
		ll val=a*d;
		if(rep)
			ans=std::min(ans,std::min(t+val,d*b));
		else
			ans=std::min(ans,std::min(val,d*b));
	}
	return ans;
}

int main()
{
	ll d,k,a,b,t;
	std::cin>>d>>k>>a>>b>>t;

	std::cout<< rec(d,false,k,a,b,t)<<std::endl;

	return 0;
}