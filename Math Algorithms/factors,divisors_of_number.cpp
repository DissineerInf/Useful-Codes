/*

Compute all the factors of the given number

Idea : if 4 is factor of 100 -> 100/4 =25 is also factor of 100

Time Complexity : sqrt(n);

*/

#include<iostream>
#include<list>
#include<cmath>

using namespace std;

typedef long long ll;

list <ll> factors_of_number(ll n)
{
	list<ll>result;
	list<ll>part2;

	ll k = sqrt(n);
	for(ll i = 1; i<k;i++)
	{
		if(n % i == 0)
		{
			result.push_back(i);
			part2.push_front(n/i);
		}
	}

	if(n%k == 0){
		result.push_back(k);
		if (k != n/k) part2.push_front(n/k);
	}

	// Attach the second part at end of result.
	result.splice(result.end(),part2);
	return result;
}

int main()
{
	list<ll> res = factors_of_number(100);
	for(auto x : res){cout<<x<<" ";} cout<<endl;

	return 0;
}