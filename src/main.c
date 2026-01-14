#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		sl_error("Usage: ./so_long <map.ber>");
	sl_parse_map(&g.map, argv[1]);
	sl_check_map(&g.map);
	sl_init_mlx(&g);
	sl_create_window(&g);
	sl_load_all_textures(&g);
	sl_find_player_position(&g);
	sl_render_map(&g);
	sl_install_hooks(&g);
	sl_start_loop(&g);
	return (0);
}
