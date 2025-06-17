/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:35:22 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/17 05:33:55 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

// void    load_images(t_game *game)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     game->imgs.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &i, &j);
//     game->imgs.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &i, &j);
//     game->imgs.player = mlx_xpm_file_to_image(game->mlx, "textures/duck.xpm", &i, &j);
//     game->imgs.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &i, &j);
//     game->imgs.collect = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &i, &j);
// }

// void	put_tile(t_game *game, int y, int x)
// {
// 	int px = x * 128;
// 	int py = y * 128;
//     char    tile;

//     tile = game->map.map[y][x];
// 	if (tile == '1')
// 		mlx_put_image_to_window(game->mlx, game->window, game->imgs.wall, px, py);
// 	else if (tile == '0')
//         mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
// 	else if (tile == 'P')
// 	{
// 		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
// 		mlx_put_image_to_window(game->mlx, game->window, game->imgs.player, px, py);
// 	}
// 	else if (tile == 'C')
// 	{
// 		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
//         //mlx_put_image_to_window(game->mlx, game->window, game->imgs.collect, px, py);
// 	}
// 	else if (tile == 'E')
// 	{
// 		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
//         //mlx_put_image_to_window(game->mlx, game->window, game->imgs.exit, px, py);
// 	}
// }

// void load_images(t_game *game)
// {
//     int tmp_w;
//     int tmp_h;

//     game->imgs.tile_size = 128;

//     game->imgs.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &tmp_w, &tmp_h);
//     game->imgs.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &tmp_w, &tmp_h);

//     game->imgs.player = mlx_xpm_file_to_image(game->mlx, "textures/duck.xpm",
//         &game->imgs.player_w, &game->imgs.player_h);

//     game->imgs.collect = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm",
//         &game->imgs.collect_w, &game->imgs.collect_h);

//     game->imgs.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
//         &game->imgs.exit_w, &game->imgs.exit_h);
// }

void load_images(t_game *game)
{
    int tmp_w;
    int tmp_h;

    game->imgs.tile_size = 128;

    game->imgs.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &tmp_w, &tmp_h);
    printf("Wall:       %p\n", game->imgs.wall);

    game->imgs.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &tmp_w, &tmp_h);
    printf("Floor:      %p\n", game->imgs.floor);

    game->imgs.player = mlx_xpm_file_to_image(game->mlx, "textures/duck.xpm", &game->imgs.player_w, &game->imgs.player_h);
    printf("Player:     %p\n", game->imgs.player);

    game->imgs.collect = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &game->imgs.collect_w, &game->imgs.collect_h);
    printf("Collectible:%p\n", game->imgs.collect);

    game->imgs.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->imgs.exit_w, &game->imgs.exit_h);
    printf("Exit:       %p\n", game->imgs.exit);
}

void	put_tile(t_game *game, int y, int x)
{
	int px = x * game->imgs.tile_size;
	int py = y * game->imgs.tile_size;
	char tile = game->map.map[y][x];

	if (tile == '1' && game->imgs.wall)
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.wall, px, py);
	else if (tile == '0' && game->imgs.floor)
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
	else if (tile == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
		if (game->imgs.player)
        {
            int offset_x = (game->imgs.tile_size - game->imgs.player_w) / 2;
		    int offset_y = (game->imgs.tile_size - game->imgs.player_h) / 2;
		    mlx_put_image_to_window(game->mlx, game->window,
			game->imgs.player, px + offset_x, py + offset_y);}
	}
	else if (tile == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
		if (game->imgs.collect)
        {
            int offset_x = (game->imgs.tile_size - game->imgs.collect_w) / 2;
	    	int offset_y = (game->imgs.tile_size - game->imgs.collect_h) / 2;
		    mlx_put_image_to_window(game->mlx, game->window,
			game->imgs.collect, px + offset_x, py + offset_y);
        }
	}
	else if (tile == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
		if (game->imgs.exit)
        {
            int offset_x = (game->imgs.tile_size - game->imgs.exit_w) / 2;
    		int offset_y = (game->imgs.tile_size - game->imgs.exit_h) / 2;
	    	mlx_put_image_to_window(game->mlx, game->window,
			game->imgs.exit, px + offset_x, py + offset_y);
        }
	}
}

void draw_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            put_tile(game, y, x);
            x++;
        }
        y++;
    }
}
