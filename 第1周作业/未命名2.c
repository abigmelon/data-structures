#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char str[1000];

int pd(char a, char b)
{
	if((islower(a) && islower(b)) || (isupper(a) && isupper(b)) || (isdigit(a) && isdigit(b)))
	{
        return 1;
    }
    return 0;
}

int main()
{
	int i = 0;
	fgets(str, sizeof(str), stdin);
	while(str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == '-' && i > 0 && str[i+1] != '\0' && str[i+1] != '\n')
		{
			char a1 = str[i - 1];
			char a2 = str[i + 1];
			if(pd(a1, a2) && a2 > a1)
			{
				for(char s = a1 + 1; s <= a2; s++)
				{
					printf("%c", s);
				}
				i++;
			}
			else
			{
				printf("-");
			}
		}
		else
		{
			printf("%c", str[i]);
		}
		i++;
	}
	return 0;
}
