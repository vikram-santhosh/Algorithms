/*Euler’s Totient function Φ(n) for an input n is count of numbers in {1, 2,
3, …, n} that are relatively prime to n, i.e., the numbers whose GCD (Greatest
Common Divisor) with n is 1. The above code calls gcd function O(n) times.
Time complexity of the gcd function is O(h) where h is number of digits in
smaller number of given two numbers. Therefore, an upper bound on time
complexity of above solution is O(nLogn) [How? there can be at most Log10n
digits in all numbers from 1 to n]

The idea is based on Euler’s product formula which states that value of
totient functions is below product over all prime factors p of n.
eulersproduct*/

#include <bits/stdc++.h>
using namespace std;

bool *isPrime;
void seive_of_eratosthense(int n)
{
	isPrime = new bool[n+1];
	for(int i=0;i<=n;i++)
        isPrime[i] = true;
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
}

float Eulers_Totient(int n)
{
	float res = n;
	if(isPrime[n])
		return n-1;
	for(int i=2;i<=n;i++)
	{
		if(n%i == 0 && isPrime[i])
		{
            res = res * (1.0 - (1.0 /(float)i));
		}
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	seive_of_eratosthense(n);
	cout<<"Euler's Totient of "<<n<<" is : "<<Eulers_Totient(n)<<endl;
}
