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

vi dist(const int l, const vi& k)
{
	int n=k.size();

	vi track1(n,0);
	int sum=0;
	for(int i=0;i<n-1;++i)
	{
		track1[i]=k[i+1]-k[i];
		sum+=track1[i];
	}
	track1[n-1]=l-sum;

	// std::sort(track1.begin(),track1.end());
	return track1;
}

int main()
{
	int n,l;
	std::cin>>n>>l;

	vi k(n,0),s(n,0);

	for(int i=0;i<n;++i)
		std::cin>>k[i];
	
	for(int i=0;i<n;++i)
		std::cin>>s[i];

	
	vi track1=dist(l,k);
	vi track2=dist(l,s);

	// std::copy(track1.begin(),track1.end(),std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;

	// std::copy(track2.begin(),track2.end(),std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;


	
	for(int i=0;i<n;++i)
	{
		if(track1==track2){
			std::cout<<"YES"<<std::endl;
			return 0;
		}
		std::rotate(track2.begin(),std::next(track2.begin()),track2.end());
	}

	std::cout<<"NO"<<std::endl;
	return 0;	
}

