/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:35:36 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/16 06:23:47 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_rectangle(t_game *game)
{
    int len;
    int i;

    len = ft_int_strlen(game->map.map[0]);
    i = 1;
    while (i < game->map.height)
    {
        if ((ft_int_strlen(game->map.map[i]) != len))
            return (0);
        i++;
    }
    return (1);
}

int check_walls(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < game->map.width)
    {
        if (game->map.map[0][j] != '1' || game->map.map[game->map.height - 1][j] != '1')
            return (0);
        j++;
    }
    while (i < game->map.height)
    {
        if (game->map.map[i][0] != '1' || game->map.map[i][game->map.width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_valid_chars(t_game *game)
{
    int i;
    int j;
    int len;

    i = 0;
    len = ft_int_strlen(game->map.map[0]);
    while (i < game->map.height)
    {
        j = 0;
        while (j < len)
        {
            if (game->map.map[i][j] != '1' && game->map.map[i][j] != '0' &&
                game->map.map[i][j] != 'P' && game->map.map[i][j] != 'C' &&
                game->map.map[i][j] != 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void count_chars(t_game *game)
{
    int i;
    int j;

    i = 0;
    game->map.p_count = 0;
    game->map.e_count = 0;
    game->map.c_count = 0;
    while (i < game->map.height)
    {
        j = 0;
        while (j < game->map.width)
        {
            if (game->map.map[i][j] == 'P')
            game->map.p_count += 1;
            else if (game->map.map[i][j] == 'C')
            game->map.c_count += 1;
            else if (game->map.map[i][j] == 'E')
                game->map.e_count += 1;
            j++;
        }
        i++;
    }
}

int check_char_count(t_game *game)
{
    count_chars(game);

    if (game->map.c_count < 1 || game->map.p_count != 1 || game->map.e_count != 1)
        return (0);
    return (1);
}