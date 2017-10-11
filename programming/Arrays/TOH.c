#include<stdio.h>
void TOH(int n, char S, char H, char D)
{
	if(n==0)
		return;
	
	TOH(n-1,S,H,D);
	printf("Moved ped %d from %c to %c\n",n,S,D);
	TOH(n-1,H,D,S);
}

int main()
{
	int t;
	scanf("%d",&t);
	TOH(t,'A','B','C');
	return 0;
}
