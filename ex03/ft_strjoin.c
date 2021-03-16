#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int n;

	while (*str)
	{
		n++;
		str++;
	}
	return (n);
}

void ft_str_sep_cat(char **strs, char *sep, int size, char *strcat)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			*strcat = strs[i][j];
			strcat++;
			j++;
		}
		if (i == size - 1)
			*strcat = '\0';
		else
		{
			k = 0;
			while (sep[k])
			{
				*strcat = sep[k];
				k++;
				strcat++;
			}
		}
		i++;
	}
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	char *strcat;

	if (size == 0)
	{
		strcat = malloc(sizeof(strcat));
		*strcat = 0;
		return (strcat);
	}
	else
	{
		strcat = malloc(sizeof(*strcat) * (50 + size + ft_strlen(sep)));
	}
	ft_str_sep_cat(strs, sep, size, strcat);
	return (strcat);
}

int main(void)
{
	char *str[] = {"je", "suis", "antoine", "yes", "man", "commen", "t", "vas", "tu", "moi", "bien"};
	char *strsep;
	char sep[] = " ";

	strsep = ft_strjoin(11, str, sep);

	printf("%s\n", strsep);

	free(strsep);
	return (0);
}