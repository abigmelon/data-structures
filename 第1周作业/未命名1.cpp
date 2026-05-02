#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int cnt[26]; 

int main()
{
	char a;
	while((a = getchar()) != EOF)
	{
		if(a >= 'a' && a <= 'z')
		{
			cnt[a - 'a']++;
		}
	}
	int max = 0;
	for(int i = 0; i < 26; i++)
	{
		if(cnt[i] > max) max = cnt[i];
	}
	for(int i = max; i > 0; i--)
	{
		for(int j = 0; j < 26; j++)
		{
			if(cnt[j] >= i) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i = 0; i < 26; i++)
	{
		printf("%c", 'a' + i);
	}
	return 0;
} 
