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
	int c,v0,v1,a,l;
	std::cin>>c>>v0>>v1>>a>>l;

	int pages=c;
	int prevNum=-1;

	int cnt=0;
	while(pages>0)
	{
		++cnt;
		int numPages=0;
		int effpages=0;
		if(prevNum==-1){
			numPages=v0;
			effpages = v0;
		}
		else{
			numPages=std::min(prevNum+a,v1);
			// numPages-=l;
			effpages=numPages-l;
		}
		pages=pages-(effpages);
		if(pages<=0)
			break;
		// pages+=l;
		// std::cout<<pages<<" "<<prevNum<<" "<<numPages<<" "<<effpages<<std::endl;
		prevNum=numPages;
	}

	std::cout<<cnt<<std::endl;
	return 0;	
}

/*#include <iostream>
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
	int c,v0,v1,a,l;
	std::cin>>c>>v0>>v1>>a>>l;

	int pages=c;
	int prevNum=-1;

	int cnt=0;
	int ival=0;
	while(pages>0)
	{
		++cnt;
		int numPages=0;
		if(prevNum==-1)
			numPages=v0;
		else{
			numPages=std::min(v0-l+a*ival,v1);
		}
		pages=pages-(numPages);

		std::cout<<pages<<std::endl;
		prevNum=numPages;
		++ival;
	}

	std::cout<<cnt<<std::endl;
	return 0;	
}
*/