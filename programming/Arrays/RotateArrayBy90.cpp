#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,i,j;
		cin>>n;
	int mat[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	i=0;
	while(i<n)
	{
		for(j=i;j<n;j++)
		{
			swap(mat[i][j],mat[j][i]);
		}
		i++;
	}
	
	for(i=0;i<n/2;i++){
	for(j=0;j<n;j++)
	{
		swap(mat[i][j],mat[n-i-1][j]);
	}
}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
    		{
			cout<<mat[i][j]<<' ';
		}
		cout<<endl;
	}
}
    return 0;
}
