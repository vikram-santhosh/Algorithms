/*Find all strings that match specific pattern in a dictionary Given a
dictionary of words, find all strings that matches the given pattern where
every character in the pattern is uniquely mapped to a character in the
dictionary.

Examples:

Input:
dict = ["abb", "abc", "xyz", "xyy"];
pattern = "foo"
Output: [xyy abb]
Explanation:
xyy and abb have same character at index 1 and 2 like the pattern
*/

#include <bits/stdc++.h>
using namespace std;

string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string findHash(string str)
{
	int id = 0;
	string res = "";
	unordered_map<char, int> m;

	for(char ch : str)
	{
		if(m.find(ch) == m.end())
			m[ch] = id++;
		res += to_string(m[ch]);
	}
	return res;
}
void patternMatch(unordered_set<string> dict,string pattern)
{
	int pattern_length = pattern.length();
	string pattern_hash = findHash(pattern);

	for(string word : dict)
	{
		int word_length = word.length();
		string word_hash = findHash(word);
		if(word_length == pattern_length && word_hash == pattern_hash )
		{
			cout<<word<<" ";
		}
	}
}
int main()
{
	unordered_set<string> dict;
	string temp,pattern;
	int n;

	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>temp;
		dict.insert(temp);
	}

	cin>>pattern;

	patternMatch(dict,pattern);
}
