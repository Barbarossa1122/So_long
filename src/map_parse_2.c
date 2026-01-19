#include "so_long.h"

void	sl_strip_cr(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\r')
		line[len - 1] = '\0';
}
