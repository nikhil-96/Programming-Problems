#include<iostream>
using namespace std;
int maxProfit(int s[],int f[],int pro[],int n)
{
	int i,j,result=0;
	int dp[n];
	
	for(i=0;i<n;i++)
	{
		dp[i]=pro[i];
	}
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(s[i]>=f[j])
			dp[i]=dp[j]+pro[i];
			
			result = max(result,dp[i]);
		}
	}
	
	return result;
}

int main()
{
	int n,i;
	cin>>n;
	int s[n],f[n],pro[n];
	
	for(i=0;i<n;i++)
	{
		cin>>s[i]>>f[i]>>pro[i];
	}
	
	cout<<maxProfit(s,f,pro,n);
	return 0;
}
