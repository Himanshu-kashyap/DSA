#include<stdio.h>
#include<string.h>
 using namespace std;
int main()
{
	char cho[102];
	fgets(cho,102,stdin);
	//printf("%s",cho);
	int len = strlen(cho);
	for(int i=0;i<=len;i++)
			printf("%c ",cho[len-i]);

}

