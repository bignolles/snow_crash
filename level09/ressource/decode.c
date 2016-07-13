#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, char **argv)
{
	size_t	i = 0;
	size_t	len;
	char	*str;

	if (argc == 2)
	{
		len = strlen(argv[1]);
		str = malloc(len + 1);
		str[len] = '\0';
		while (i < len)
		{
			str[i] = argv[1][i] - (char)i;	
			++i;
		}
		printf("decoded string : [%s]\n", str);
	}
	else
		printf("Wrong usage\n");
}
