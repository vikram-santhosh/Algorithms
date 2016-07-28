/*Consider two positive numbers N and D such that N is divisible by D and D is
less than the square root of N. Then, (N / D) must be greater than the square
root of N. N is also divisible by (N / D). So, if there is a divisor of N that
is less than square root of N then there will be a divisor of N that is
greater than square root of N. Therefore, we just need to traverse till the
square root of N.
Time complexity: Time complexity of this function is
O(sqrt(N)) as we are traversing from 1 to sqrt(N).
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int count=0;
	for(int i=1;i*i <= n;i++)
	{
		if(n%i == 0)
		{
			if(i*i == n)
				count++;
			else
				count+=2;
		}
	}
	if(count == 2)
		return true;
	else
		return false;
}
int main()
{
	int n;
	cin>>n;

	cout<<isPrime(n)<<endl;
}
