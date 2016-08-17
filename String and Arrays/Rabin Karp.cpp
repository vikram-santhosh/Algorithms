/**
 *
 * Rabin Karp algorith for substring matching.
 *
 * Time complexity :
 * 		Worst Case 		-  O(n^2)
 * 		Average Case	-  O(m+n)
 * Space complexity O(1)
 * Hashing Technique : Rolling Hash
 * References
 * https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm
 */

#include <bits/stdc++.h>
using namespace std;

int prime = 101;
long int calulateHash(string str,int n)
{
	long int val = 0;
	for(int i=0;i<n;i++)
		val += ((int)str[i] * pow(prime,i));
	return val;
}

long int recalculateHash(string str,long int text_hash,int old_index,int new_index)
{
	int len = new_index - old_index;
	text_hash -= (int)str[old_index];
	text_hash /= prime;
	text_hash += (int)str[new_index]  * pow(prime,len-1);
	return text_hash;
}

bool isEqual(string text,string pattern,int start,int len)
{
	for(int i=0;i<len;i++)
	{
		if(text[start+i] != pattern[i])
			return false;
	}
	return true;
}
int RabinKarp(string text,string pattern)
{
	int text_length = text.length();
	int pattern_length = pattern.length();

	long int text_hash = calulateHash(text,pattern_length);
	long int pattern_hash = calulateHash(pattern,pattern_length);

	for(int i=0;i<text_length - pattern_length +1 ;i++)
	{
		if((text_hash == pattern_hash) && isEqual(text,pattern,i,pattern_length))
			return i;

		text_hash = recalculateHash(text,text_hash,i,i+pattern_length);
	}

	return -1;
}
int main()
{
	string text,pattern;
 	cin>>text>>pattern;

 	cout<<RabinKarp(text,pattern)<<endl;
}
