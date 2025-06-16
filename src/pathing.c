/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:35:44 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/16 07:06:53 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char **copy_map(t_game *game)
{
	char **map_cpy;
	int i;

	map_cpy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		map_cpy[i] = ft_strdup(game->map.map[i]);
		if (!map_cpy[i])
		{
			free_array(map_cpy, i);
			return (NULL);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}


void flood_fill(char **map, int y, int x)
{
    if (y < 0 || x < 0)
        return ;
    if (map[y] == NULL || x >= (int)ft_strlen(map[y]))
        return ;
    if (map[y][x] == '1' || map[y][x] == 'F')
        return ;
    map[y][x] = 'F';
    flood_fill(map, y, x + 1);
    flood_fill(map, y + 1, x);
    flood_fill(map, y, x - 1);
    flood_fill(map, y - 1, x);
}

int check_ff(char **map, int height, int width)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (map[i][j] == 'E' || map[i][j] == 'C')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int validate_pathing(t_game *game)
{
    char **map_cpy;
    int res;

    map_cpy = copy_map(game);
    flood_fill(map_cpy, game->player_y, game->player_x);
    res = check_ff(map_cpy, game->map.height, game->map.width);
    free_array(map_cpy, game->map.height);
    return (res);
}
