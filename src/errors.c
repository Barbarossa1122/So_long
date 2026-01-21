#include "so_long.h"
#include <errno.h>

void	sl_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void	sl_perror(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	exit(1);
}

void	sl_free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	sl_free_game(t_game *g)
{
	sl_free_map(&g->map);
	/* Qui in futuro aggiungerai mlx_destroy_image se necessario */
}

int	sl_exit_game(t_game *g)
{
	sl_free_game(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(0);
	return (0);
}
