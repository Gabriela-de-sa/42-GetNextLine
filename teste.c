#include <stdlib.h>

char *before(char *line)
{
	char	*str;
	int		index;
	char	*return_line;

	str = line;
	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\0')
	{
		return_line = (char *) malloc(index + 1);
		if (return_line == NULL)
			return (NULL);
		return_line = ft_strncpy(return_line, str, index);
	}
	else
	{
		return_line = (char *) malloc(index + 2);
		if (return_line == NULL)
			return (NULL);
		return_line = ft_strncpy(return_line, str, index);
	}
	printf("%s", return_line);
	return (return_line);
}

int main()
{
    char c[] = "gabriela\n de sa\n linda maravilhosa";
    before(c);
}
