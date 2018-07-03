/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:58:58 by ovirchen          #+#    #+#             */
/*   Updated: 2018/03/04 13:58:59 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_error(void)
{
	write(1, "error\n", 6);
	return (0);
}

static void	free_all_malloc(t_map *all)
{
	int i;

	i = -1;
	while (++i < all->x_p)
		free(all->pie[i]);
	free(all->pie);
	i = -1;
	while (++i < all->x_m)
	{
		free(all->map[i]);
		free(all->i_map[i]);
	}
	free(all->map);
	free(all->i_map);
}

int			main(void)
{
	t_map	all;

	if (get_p_num(&all) == 0)
		return (1);
	while (read_map(&all) != 0)
	{
		make_i_map(&all);
		all.x = 0;
		all.y = 0;
		find_place(&all);
		ft_printf("%d %d\n", all.x, all.y);
		free_all_malloc(&all);
	}
	return (0);
}
