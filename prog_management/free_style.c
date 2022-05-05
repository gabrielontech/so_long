#include "../so_long.h"

void	free_double_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[++i]);
	free(str);
}