#include<bits/stdc++.h>
using namespace std;

void pandaString(string str)
{
	int n = str.length(),i;
	map<char,int> m;
	for(i=0;i<n;i++)
		m[str[i]]++;

	map<char,int>::iterator it,it1;
	it = m.begin();
	for(it1=++m.begin();it1!=m.end();it1++)
	{
		if(it1->second>it->second)
			it = it1;
	}
	int sum=0;
	for(it1=m.begin();it1!=m.end();it1++)
	{
		if(it1!=it)
			sum = sum + it1->second;
	}
	if(it->second-sum > 0)
		cout<<"yes"<<endl<<it->first;
	else
		cout<<"no";
}

int main()
{
	string str;
	cin>>str;
	pandaString(str);
	return 0;
}