/*

Computes all the prime factors of the given number

Constraint n > 1;

Time Complexity : O(sqrt(n))
*/
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef vector<pair<int,int>> vii;

// vector of <prime factor, its power>
vii prime_factorization(long long n)
{
	vii result;

	// Power of 2
	int power = 0;
	while(n%2 ==0)
	{
		power++;
		n/=2;
	}
	if(power>0) result.push_back({2,power});

	// From 3 to sqrt(n) in steps of 2
	int prime = 3;
	while(n>1 && prime<=sqrt(n))
	{
		power =0;
		while(n%prime ==0)
		{
			power++;
			n/=prime;
		}
		if(power>0)
			result.push_back({prime,power});

		prime+=2;

	}
	// the number itself is prime
	if(n>1)
		result.push_back({n,1});

	return result;
}

int main()
{
	vii res = prime_factorization(120);
	for(auto x : res)
	{
		cout<<x.first<<" : "<<x.second<<endl;
	}
	
	return 0;
}