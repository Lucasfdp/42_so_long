/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:35:40 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/16 07:42:36 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int handle_ber(char *str)
{
    int len;

    len = ft_int_strlen(str);
    if (len < 5)
        return (0);
    return (ft_strncmp((str + len - 4), ".ber", 4) == 0);
}

void    nwl_for_null(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (game->map.map[i])
    {
        j = 0;
        while (game->map.map[i][j])
        {
            if (game->map.map[i][j] == '\n')
                game->map.map[i][j] = '\0';
            j++;
        }
        i++;
    }
}

int parse_and_prep(t_game *game)
{
    if (!check_rectangle(game) || !check_valid_chars(game)
        || !check_char_count(game) || !validate_pathing(game) 
        || !check_walls(game))
    {
        ft_printf("Error\nUnplayable map");
        return (0);
    }
    // game->collectibles_found = 0;
    // game->collectibles_total = game->map.c_count;
    // game->steps = 0;
    return (1);
}
