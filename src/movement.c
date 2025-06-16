/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:14:08 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/16 07:46:14 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_player(t_game *game, int new_x, int new_y)
{
    // Check boundaries
    if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
        return;

    char target = game->map.map[new_y][new_x];

    // If wall, block movement
    if (target == '1')
        return;

    // If exit
    if (target == 'E')
    {
        if (game->collectibles_found == game->collectibles_total)
        {
            ft_printf("You won! All collectibles gathered.\n");
            exit(0);
        }
        else
        {
            ft_printf("Collect all items before exiting!\n");
            return;
        }
    }

    // If collectible, pick it up
    if (target == 'C')
    {
        game->collectibles_found++;
        ft_printf("Collectibles: %d / %d\n", game->collectibles_found, game->collectibles_total);
    }

    // Update map: remove player from old position
    game->map.map[game->player_y][game->player_x] = '0';

    // Update player position
    game->player_x = new_x;
    game->player_y = new_y;

    // Place player on new tile
    game->map.map[new_y][new_x] = 'P';

    // Redraw the map
    draw_map(game);
}



int handle_key(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC key
        exit(0);

    else if (keycode == 65362 || keycode == 119)
        move_player(game, game->player_x, game->player_y - 1);
    else if (keycode == 65364 || keycode == 115)
        move_player(game, game->player_x, game->player_y + 1);
    else if (keycode == 65361 || keycode == 97)
        move_player(game, game->player_x - 1, game->player_y);
    else if (keycode == 65363 || keycode == 100)
        move_player(game, game->player_x + 1, game->player_y);
    game->steps += 1;
    ft_printf("Moves: %d\n", game->steps);
    return (0);
}

void count_collectibles(t_game *game)
{
    int x, y;

    game->collectibles_total = 0;
    game->collectibles_found = 0;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.map[y][x] == 'C')
                game->collectibles_total++;
            x++;
        }
        y++;
    }
}
