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

ll check(ll x,ll k)
{
	// return x*(3*x-2);
	return x+2*k*x-(k*(k+1));
}

ll f(ll x, ll k,ll n)
{
	ll res=0;
	// ll val=1;
	/*for(int i=k-1;i>=1;--i)
	{
		res+=x+(k-i);
	}
	for(int i=k+1;i<n;++i)
	{
		res+=x-(i-k);
	}*/
	ll left=std::min(x-1,k-1);
	ll right=std::min(x-1,n-k);

	res+=left*x-(left*(left+1))/2;
	res+=right*x-(right*(right+1))/2;
	res+=x;

	return res;
}
int main()
{
	ll n,m,k;

	std::cin>>n>>m>>k;

	int pillows= m-n;

	ll l=0,r=pillows+1;

	ll ans=0;
	/*while(l<r)
	{
		ll m=(l+r)/2;

		ll tip=std::min(m,)

		ll val = check(m);

		std::cout<<"------------"<<std::endl;
		std::cout<<l<<" "<<r<<std::endl;
		std::cout<<m<<" "<<val<<" "<<pillows<<std::endl;
		if(val+1<pillows)
			l=m+1;
		else if(val>pillows)
			r=m;
		else
		{
			ans=m;
			break;
		}
	}*/

	while(l<r)
	{
		ll m=(l+r)/2;

		// ll tip=std::min(m,)

		ll val = f(m,k,n);

		// std::cout<<"------------"<<std::endl;
		// std::cout<<l<<" "<<r<<std::endl;
		// std::cout<<m<<" "<<val<<" "<<pillows<<std::endl;
		if(val<pillows)
			l=m+1;
		else if(val>pillows)
			r=m-1;
		if(val==pillows){
			l=m;
			break;
		}
		/*else{ 
			r=m;
			break;
		}*/
		/*else
		{
			ans=m;
			break;
		}*/
	}
	if(f(l,k,n)>pillows)
		--l;
	
	std::cout<<l+1<<std::endl;
	return 0;
}