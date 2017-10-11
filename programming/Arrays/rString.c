#include<stdio.h>
#include<string.h>
void swap(char *c1,char *c2)
{
	char temp;
	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}
int isChar(char a)
{
	if((a>='a' && a<='z') || (a>='A' && a<='Z'))
	return 1;
	
	return 0;
} 
void reverse(char *str,int len)
{
	if(len<=1)
		return;
		
	
	
	if(isChar(str[0]) && isChar(str[len-1]))
	{
		reverse(str+1,len-2);
		swap(&str[0],&str[len-1]);
	}
	
	if(!isChar(str[0]) && isChar(str[len-1]))
	{
		reverse(str+1,len-1);
	}
	
	if(isChar(str[0]) && !isChar(str[len-1]))
	{
		reverse(str,len-2);
	}
	
	if(!isChar(str[0]) && !isChar(str[len-1]))
	{
		reverse(str+1,len-2);
	}
	
	
}

int main()
{
	char str[32];
	scanf("%s",str);
	reverse(str,strlen(str));
	printf("%s",str);
	return 0;
}
