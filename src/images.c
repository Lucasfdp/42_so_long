/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:35:22 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/16 07:15:17 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

void    load_images(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    game->imgs.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &i, &j);
    game->imgs.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &i, &j);
    game->imgs.player = mlx_xpm_file_to_image(game->mlx, "textures/duck2.xpm", &i, &j);
    game->imgs.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &i, &j);
    game->imgs.collect = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &i, &j);
}

void	put_tile(t_game *game, int y, int x)
{
	int px = x * 128;
	int py = y * 128;
    char    tile;

    tile = game->map.map[y][x];
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.wall, px, py);
	else if (tile == '0')
        mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
	else if (tile == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.player, px, py);
	}
	else if (tile == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
        //mlx_put_image_to_window(game->mlx, game->window, game->imgs.collect, px, py);
	}
	else if (tile == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs.floor, px, py);
        //mlx_put_image_to_window(game->mlx, game->window, game->imgs.exit, px, py);
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
