/*

Euclid's gcd algorithm

Time Complexity : O(logn)  where n = min(a,b);

*/

#include <iostream>

using namespace std;

typedef long long ll;

ll gcd (ll a , ll b)
{
    ll rhs;
    while(b != 0)
    {
        rhs = a%b;
        a=b;
        b=rhs;
    }
    return a;
}

ll lcm (ll a , ll b)
{
    return (a*b)/gcd(a,b);
}


int main()
{
    cout<<gcd(20,15)<<endl;
    cout<<lcm(15,20)<<endl;
   
    return 0;
}