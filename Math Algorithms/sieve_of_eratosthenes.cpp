/*

Computes all the prime numbers less than equal to n

Idea:
	Initialize isPrime array to all true from 2
	for each prime, mark its multiple as non-prime 

Time complexity : O(n logn)

*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> sieve_of_eratosthenes (int n)
{
	vector <bool> isPrime (n+1,true);
	isPrime[0] = isPrime[1] = false;

	for(int i=2;i*2<=n;i++)
	{
		if(isPrime[i])
		{
			for(int j = 2*i; j<=n;j+=i)
				isPrime[j]=false;
		}
	}

	vector<int> result;
	for(int i=2;i<=n;i++)
	{
		if(isPrime[i])
		result.push_back(i);
	}
	return result;
}

int main()
{
	vector <int>  primes = sieve_of_eratosthenes(100);
	for(auto x : primes){cout<<x<<" ";}
	
	return 0;
}