#include <bits/stdc++.h>
using namespace std;

typedef struct trie
{
	map<char,struct trie*> branch;
	bool isLeaf;
}trieNode;


trieNode* getNode()
{
	trieNode* node = new trieNode();
	node->isLeaf = false;
	return node;
}

void insert(trieNode* root, string str)
{
	int m = str.length()-1;

	for(int i=0;i<=m;i++)
	{

		if(root->branch.count(str[i]) != 0)
        {
            root = root->branch[str[i]];
        }
		else
		{
			trieNode* node = getNode();
			if(i == m) //end of word
				node->isLeaf = true;
			root->branch[ str[i] ] = node;
			root = root->branch[str[i]];
		}
	}
}

bool search(trieNode* root, string str)
{
	int m = str.length()-1;
	for(int i=0;i<=m;i++)
	{
		char ch = str[i];
		if(root->branch.count(ch) != 0)
			root = root->branch[ch];
		else
			return false;
	}

	if(root->isLeaf == true)
		return true;
	else
		return false;
}

int main()
{
	int n;
	int q; // num of queries
	string str;
	trieNode* root = NULL;
	root = getNode();

	//insert values
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		insert(root,str);
	}

	//search
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>str;
		cout<<search(root,str)<<endl;
	}


}
