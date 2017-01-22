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

/*
int main()
{
	std::string s;
	std::cin>>s;

	vi ans(4,0);

	int n=s.size();
	vi arr(n,0);

	bool no=true;

	int todo=0;
	for(int i=0;i<n;++i)
		if(s[i]=='!') ++todo;
	while(no && todo!=0)
	{
		no=false;
		// std::cout<<s<<std::endl;
		for(int i=0;i<n-3;++i)
		{
			if(todo==0){break;}
			int cnt=0;
			for(int j=i;j<i+4;++j)
			{
				if(s[j]=='!')
					++cnt,no=true;
			}
			if(cnt==1)
			{
				--todo;
				// no=false;
				bool r=false,g=false,y=false,b=false;
				int index=0;
				for(int j=i;j<i+4;++j)
				{
					if(s[j]=='R')
						r=true;
					else if(s[j]=='G')
						g=true;
					else if(s[j]=='B')
						b=true;
					else if(s[j]=='Y')
						y=true;
					else
						index=j;
				}
				if(!r)
					s[index]='R',ans[0]++;
				else if(!g)
					s[index]='G',ans[3]++;
				else if(!b)
					s[index]='B',ans[1]++;
				else if(!y)
					s[index]='Y',ans[2]++;
			}

		}
	}

	for(int i=0;i<4;++i)
		std::cout<<ans[i]<<" ";
	std::cout<<std::endl;
	return 0;
}*/


int main()
{
	std::string s;
	std::cin>>s;

	vi ans(4,0);

	int n=s.size();
	vi arr(n,0);
	
	std::unordered_map<char,int> map;
	map['R']=0;
	map['B']=1;
	map['Y']=2;
	map['G']=3;

	std::unordered_map<int,char> charMap;
	for(int i=0;i<n;++i)
	{
		if(s[i]!='!')
			charMap[i%4]=s[i];
	}

	/*for(auto it=charMap.begin();it!=charMap.end();++it)
	{
		std::cout<<it->first<<" "<<it->second<<std::endl;
	}*/
	for(int i=0;i<n;++i)
	{
		if(s[i]=='!')
			ans[map[charMap[i%4]]]++;
	}


	// std::cout<<s<<std::endl;
	for(int i=0;i<4;++i)
		std::cout<<ans[i]<<" ";
	std::cout<<std::endl;
	return 0;
}