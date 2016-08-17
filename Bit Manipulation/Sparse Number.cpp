/*Check if a given number is sparse or not A number is said to be a sparse
number if in binary representation of the number no two or more consecutive
bits are set. Write a function to check if a given number is Sparse or not.

Example:

Input:  x  = 72
Output: true
Explanation:  Binary representation of 72 is 01001000. 
There are no two consecutive 1's in binary representation

If we observe carefully, then we can notice that if we can use bitwise AND of
binary representation of the “given number its “right shifted number”(i.e.,
half the given number) to figure out whether the number is sparse or not.
Result of AND operator would be 0 if number is sparse and non-zero if not
sparse.

*/

#include <bits/stdc++.h>
using namespace std;

bool isSparse(int num)
{
	if(n & n>>1)
		return false;
	return true;
}
int main()
{
	int num;
	cin>>num;

	cout<<isSparse(num)<<endl;
}
