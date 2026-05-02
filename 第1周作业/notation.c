#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char s[105];
char z[105];
char x[105];
char ss[210];
char s1[210];
char s2[210];

int main()
{
	fgets(s, 105, stdin);
	s[strcspn(s, "\n")] = '\0';
	int e = 0;
	char *p = strchr(s, '.');
	if(p == NULL)
	{
		strcpy(z, s);
	}
	else
	{
		strncpy(z, s, p - s);
		z[p - s] = '\0';
		strcpy(x, p + 1);
	}
	strcpy(ss, z);
	strcat(ss, x);
	int l = strlen(ss);
	int pos = -1;
	for(int i = 0; i < l; i++)
	{
		if(ss[i] != '0')
		{
			pos = i;
			break;
		}
	}
	int lz = strlen(z);
	if(lz == 1 && z[0] == '0')
	{
		e = -((pos - lz) + 1);
	}
	else
	{
		e = lz - 1 - pos;
	}
	s1[0] = ss[pos];
	strcpy(s2, ss + pos + 1);
	if(strlen(s2) > 0)
	{
		strcat(s1, ".");
		strcat(s1, s2);
	}
	printf("%se%d", s1, e);
	return 0;
}
