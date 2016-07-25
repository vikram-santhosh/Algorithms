/*
Given an unsigned integer, swap all odd bits with even bits. For example, if
the given number is 23 (00010111), it should be converted to 43 (00101011).
Every even position bit is swapped with adjacent bit on right side and every odd
position bit is swapped with adjacent on left side.
*/

#include <bits/stdc++.h>
#define SIZE 16
using namespace std;

int bitSwap(int n)
{
	int even_bits = n & 0xAAAAAAAA;
	int odd_bits = n & 0x55555555;

	even_bits = even_bits >> 1;
	odd_bits = odd_bits << 1;

	return (even_bits | odd_bits);
}
int main()
{
	int n;
	cin>>n;
	cout<<bitSwap(n);
}
