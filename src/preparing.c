/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:49:22 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/16 07:45:08 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    find_player(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
            }
            x++;
        }
        y++;
    }
}

int prep_map(char **av, t_game *game)
{
    int fd;
    int i;
    int lines;
    game->map.map = NULL;

    i = 0;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (0);
    lines = count_lines(fd);
    close(fd);
    game->map.map = (char **)malloc(sizeof(char *) * (lines + 1));
    if (!game->map.map)
        return (0);
    fd = open(av[1], O_RDONLY);
    while ((game->map.map[i] = get_next_line(fd)) != NULL)
        i++;
    game->map.map[i] = NULL;
    nwl_for_null(game);
    game->map.height = i;
    game->map.width = ft_int_strlen(game->map.map[0]);
    close(fd);
    find_player(game);
    game->steps = 0;
    return (1);
}
