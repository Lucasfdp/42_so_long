/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:08:57 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/17 02:58:53 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

# define TILE_SIZE 64

typedef struct s_map
{
    char    **map;
    int     height;
    int     width;
    int     p_count;
    int     e_count;
    int     c_count;
} t_map;

// typedef struct s_img
// {
//     void    *wall;
//     void    *floor;
//     void    *player;
//     void    *exit;
//     void    *collect;
// } t_img;

typedef struct s_img {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;

	int		player_w;
	int		player_h;
	int		collect_w;
	int		collect_h;
	int		exit_w;
	int		exit_h;
	int		tile_size;
}	t_img;

typedef struct s_game
{
    t_map   map;
    t_img   imgs;
    void    *mlx;
    void    *window;
    int     player_x;
    int     player_y;
    int     steps;
    int     collectibles_total;
    int     collectibles_found;
}   t_game;

//parsing
int handle_ber(char *str);
int check_rectangle(t_game *game);
void    nwl_for_null(t_game *game);
int check_walls(t_game *game);
int check_valid_chars(t_game *game);
int count_lines(int fd);
int prep_map(char **av, t_game *game);
void count_chars(t_game *game);
int check_char_count(t_game *game);
int parse_and_prep(t_game *game);
char **copy_map(t_game *game);
void    find_player(t_game *game);
void    flood_fill(char **map, int y, int x);
int check_ff(char **map, int height, int width);
int validate_pathing(t_game *game);
void	error_exit(const char *msg);

//loading_map
void    load_images(t_game *game);
void	put_tile(t_game *game, int y, int x);
void	draw_map(t_game *game);
void    print_map(char **map);
void count_collectibles(t_game *game);

//key hooks
int handle_key(int keycode, t_game *game);

#endif