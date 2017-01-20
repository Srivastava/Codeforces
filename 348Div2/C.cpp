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
	int n,m,q;
	std::cin>>n>>m>>q;

	vi row(n,0),col(m,0);

	std::vector<vi> matrix(n,vi(m,0)),queries;


	for(int i=0;i<q;++i)
	{
		int type;
		std::cin>>type;
		if(type==3)
		{
			int r,c,val;
			std::cin>>r>>c>>val;
			--r;--c;
			queries.push_back(std::vector<int>{type,r,c,val});
		}
		else
		{
			int val;
			std::cin>>val;
			--val;

			queries.push_back(std::vector<int>{type,val});
		}
	}

	for(int i=q-1;i>=0;--i)
	{
		int type=queries[i][0];

		if(type==1 || type==2)
		{
			int val=queries[i][1];
			// type==1 ? row[val]++ : col[val]++;

			if(type==1)
			{
				
				int temp=matrix[val][m-1];
				for(int i=m-1;i>0;--i){
					// std::cout<<matrix[val][i]<<" ** "<<i<<std::endl;
					matrix[val][i]=matrix[val][i-1];
					// std::cout<<matrix[val][i]<<" "<<i<<std::endl;
				}
				matrix[val][0]=temp;
			}
			if(type==2)
			{
				int temp=matrix[n-1][val];
				for(int i=n-1;i>0;--i)
					matrix[i][val]=matrix[i-1][val];
				matrix[0][val]=temp;
			}
		}
		else
		{
			int r=queries[i][1],c=queries[i][2],x=queries[i][3];
			matrix[r][c]=x;
		}
	}

	for(int i=0;i<n;++i)
	{
		std::copy(matrix[i].begin(),matrix[i].end(),std::ostream_iterator<int>(std::cout," "));
		std::cout<<std::endl;
	}

	return 0;
}