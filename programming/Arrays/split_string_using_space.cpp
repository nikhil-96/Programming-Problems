#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str("Split,me,by,whitespaces");
    string buf;
    stringstream ss(str); 

    vector<string> tokens;
    while (getline(ss,buf,','))
        tokens.push_back(buf);

    for (int i=0;i<tokens.size();i++)
    {
   		cout<<tokens[i]<<endl;
    }

    return 0;	
}