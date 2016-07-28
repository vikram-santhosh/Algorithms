/*The Sieve of Eratosthenes can be used to find all the prime numbers less than
or equal to a given number N. It can also be used to find out if a number is
prime or not, by just looking up at the sieve.

The basic idea behind the sieve of eratosthenes is that at each iteration, we
pick one prime number and eliminate all the multiples of that prime number.
After the elimination process ends, all the unmarked numbers which are left
are prime!
Total complexity: N * (½ + ⅓ + ⅕ + … ) = O(NloglogN)
*/

#include <bits/stdc++.h>
using namespace std;

void sieve_of_eratosthenes(int n)
{
	bool isPrime[n+1];
	memset(isPrime,true,sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;
	for(int i=2;i*i<=n;i++)
	{
		if(isPrime[i])
		{
			for(int j=i*2;j<=n;j+=i)
			{
				isPrime[j] = false;
			}
		}
	}

	for(int i=0;i<=n;i++)
	{
		if(isPrime[i])
		{
			cout<<i<<" ";
		}
	}
}
int main()
{
	int n;
	cin>>n;
	sieve_of_eratosthenes(n);
}
