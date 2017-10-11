#include <bits/stdc++.h>
using namespace std;

void sumClosest(int a[],int n,int sum)
{
	int left=0,right=n-1,min=INT_MAX;
	int x,y;
	while(left < right)
	{
		if(abs(a[left]+a[right]-sum)<min)
		{
			min = abs(a[left]+a[right]-sum);
			x=left;
			y=right;
		}
		else if(a[left]+a[right]>sum)
		{
			right--;
		}
		else
		{
			left++;
		}
		
	}
	cout<<a[x]<<" "<<a[y];
}

int main()
{
	int n,sum;
	cin>>n>>sum;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	sumClosest(a,n,sum);
	return 0;
}