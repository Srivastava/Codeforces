/*#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <set>

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

	vi a;
	std::set<int> set;

	int cnt=1;

	int res=0;
	

	
	for(int i=0;i<n*2;++i)
	{
		std::string str;
		int num;
		std::cin>>str;

		
		if(str[0]=='a')
		{
			std::cin>>num;
			// std::cout<<str<<" --- "<<num<<" --- "<<i<<std::endl;
			a.push_back(num);
			set.insert(num);
		}
		else
		{
			// std::cout<<str<<" --- "<<i<<std::endl;
			if(a.back()==cnt)
			{
				set.erase(cnt);
				a.pop_back();
				++cnt;
				continue;
			}
			else
			{
				// std::cout<<a.back()<<std::endl;
				// std::sort(a.begin(),a.end(),std::greater<int>());
				++res;
				std::vector<int> temp(set.rbegin(),set.rend());
				a=temp;
				a.pop_back();
				set.erase(cnt);
				++cnt;
			}
		}
	}
	std::cout<<res<<std::endl;	
}
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <set>
#include <stack>

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

	int cnt=1;

	int res=0;
	


	std::stack<int> stk;
	bool reorder=false;
	for(int i=0;i<n*2;++i)
	{
		std::string str;
		int num;
		std::cin>>str;

		// std::cout<<str<<" "<<res<<std::endl;
		if(str[0]=='a')
		{
			std::cin>>num;
			
			stk.push(num);

		}
		else
		{
			if(!stk.empty())
			{
				if(stk.top()!=cnt)
				{
					++res;
					while(!stk.empty())
						stk.pop();
				}
				else
					stk.pop();
			}
			++cnt;
		}
	}
	std::cout<<res<<std::endl;	
}
