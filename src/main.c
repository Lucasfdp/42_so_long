/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:32:52 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/17 05:26:17 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

int count_lines(int fd)
{
	int count = 0;
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	return count;
}
void    print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", 
		map[i]);
		i++;
	}
}

void    show_struct(t_map map)
{
	if (map.map)
		print_map(map.map);
	ft_printf("\n");
	if (map.c_count)
		ft_printf("Collectibles:%d\n", map.c_count);
	if (map.e_count)
		ft_printf("Exits:%d\n", map.e_count);
	if (map.p_count)
		ft_printf("Players:%d\n", map.p_count);
	if (map.width)
		ft_printf("Width:%d\n", map.width);
	if (map.height)
		ft_printf("Height:%d\n", map.height);
}

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

// int main(int ac, char *av[])
// {
// 	(void)ac;
// 	t_map   map;
	
// 	if (handle_ber(av[1]))
// 	{
// 		if (!prep_map(av, &map))
// 		{
// 			ft_printf("Error\nFailed prep");
// 			return (0);
// 		}
// 		if (parse_map(&map))
// 			show_struct(map);
// 		free_array(map.map, map.height);
// 	}
// 	else
// 		ft_printf("Error\nTry using a .ber file");
// 	// void *mlx;
// 	// void *win;
// 	// void *img;

// 	// mlx = mlx_init();
// 	// win = mlx_new_window(mlx, 800, 600, "It's my game");
// 	// img = mlx_xpm_file_to_image(mlx, "textures/SnowTiles.xpm", &map.width, &map.height);
// 	// if (!img)
// 	// {
// 	//     ft_printf("lol failed");
// 	//     return (1);
// 	// }
// 	// printf("Image loaded: %dx%d\n", map.width, map.height);
// 	// // Put image at position (x=100, y=50)
// 	// mlx_put_image_to_window(mlx, win, img, 300, 100);

// 	// mlx_loop(mlx);
// 	return (0);
// }

int main(int ac, char **av)
{
    t_game	game;

	(void)ac;
    if (!handle_ber(av[1]))
    {
        ft_printf("Error\nTry using a .ber file\n");
        return (1);
    }

    if (!prep_map(av, &game))
    {
        ft_printf("Error\nFailed prep\n");
        return (1);
    }
    if (!parse_and_prep(&game))
    {
	    return (1);
	}
	count_collectibles(&game);
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_printf("Error\nFailed to initialize mlx\n");
        return (1);
    }

    game.window = mlx_new_window(game.mlx, game.map.width * 128,
					 game.map.height * 128, "so_long");
    if (!game.window)
    {
        ft_printf("Error\nFailed to create window\n");
        return (1);
    }

    load_images(&game);

    if (!game.imgs.wall || !game.imgs.floor || !game.imgs.player || !game.imgs.exit || !game.imgs.collect)
    {
        ft_printf("Error loading images\n");
        return (1);
    }

    draw_map(&game);

    //mlx_key_hook(game.window, handle_key, NULL);
	mlx_hook(game.window, 2, 1L<<0, handle_key, &game);


    mlx_loop(game.mlx);

    return (0);
}

