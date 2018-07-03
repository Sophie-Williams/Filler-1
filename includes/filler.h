/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:47:01 by ovirchen          #+#    #+#             */
/*   Updated: 2018/03/04 14:47:02 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "../libftprintf/libftprintf.h"

typedef struct	s_map
{
	char	lett;
	int		x_m;
	int		y_m;
	int		i_m;
	int		j_m;
	char	**map;
	int		**i_map;
	int		min_sum;
	int		x_p;
	int		y_p;
	int		i_p;
	int		j_p;
	int		num_stars;
	char	**pie;
	int		x;
	int		y;
}				t_map;

int				ft_error(void);
int				get_p_num(t_map *all);
int				read_map(t_map *all);
int				read_piece(t_map *all);
int				find_place(t_map *all);
int				make_i_map(t_map *all);

#endif
