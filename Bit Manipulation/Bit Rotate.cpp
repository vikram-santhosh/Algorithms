#include <bits/stdc++.h>
#define WIDTH 32
using namespace std;

int RightRotate(int n,int d)
{
	return (n>>d | n<<(WIDTH-d));
}

int LeftRotate(int n,int d)
{
	return (n<<d | n>>(WIDTH-d));
}

int main()
{
	int n,d;
	cin>>n>>d;

	cout<<"Input : "<<bitset<32>(n)<<endl;

	cout<<"Left Rotate : "<<bitset<32>(LeftRotate(n,d))<<endl;
	cout<<"Right Rotate : "<<bitset<32>(RightRotate(n,d))<<endl;

}
