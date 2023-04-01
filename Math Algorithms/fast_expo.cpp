/*

Calculate (x^n) % modval;

Idea : 
    -- recursive : 
       -- x^25 = x^12 *  x^12 * x
    -- iterative : 
       -- 13 = 1101
       -- 3^13 = 3^8 . 3^4 . 3^1
       -- next power = square of previous
       -- only multiply bit which is 1 with result

Time Complexity : O(logn)

*/

#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll modval = pow(10,9)+7;

// recursive
ll fast_expo_recursive(ll x, ll n)
{
    if (n==0) return 1;
    if (n==1) return x;
    int y = fast_expo_recursive(x,n/2);
    if (n % 2 == 0) return (y*y)%modval;
    else return (((y*y)%modval)*x)%modval;
}


ll fast_expo_iterative(ll x, ll n)
{
    ll result = 1;
    while(n>0){
        if(n&1) result = (result*x)%modval;

        x= (x*x)%modval;
        n>>=1;
    }
    return result;
}


int main(){

    cout<<fast_expo_recursive(2,13)<<endl;
    cout<<fast_expo_iterative(2,13)<<endl;
    cout<<fast_expo_iterative(27,45)<<endl;
    
    return 0;
}