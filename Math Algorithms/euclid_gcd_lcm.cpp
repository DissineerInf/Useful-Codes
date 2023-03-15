/*

Euclid's gcd algorithm

Time Complexity : O(logn)  where n = min(a,b);

*/

#include <iostream>

using namespace std;

template <typename T>
T gcd (T a , T b)
{
    T rhs;
    while(b != 0)
    {
        rhs = a%b;
        a=b;
        b=rhs;
    }
    return a;
}

template <typename T>
T lcm (T a , T b)
{
    return (a*b)/gcd(a,b);
}


int main()
{
    cout<<gcd(20,15)<<endl;
    cout<<lcm(15,20)<<endl;
   
    return 0;
}