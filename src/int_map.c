/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:00:36 by ovirchen          #+#    #+#             */
/*   Updated: 2018/03/05 16:00:37 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	push_num(t_map **all, int i, int j, int n)
{
	int count;

	count = 0;
	if (i - 1 >= 0 && (*all)->i_map[i - 1][j] == -1 && count++)
		(*all)->i_map[i - 1][j] = n + 1;
	if (i - 1 >= 0 && j - 1 >= 0 && (*all)->i_map[i - 1][j - 1] == -1
		&& count++)
		(*all)->i_map[i - 1][j - 1] = n + 1;
	if (i - 1 >= 0 && j + 1 < (*all)->y_m && (*all)->i_map[i - 1][j + 1] == -1
		&& count++)
		(*all)->i_map[i - 1][j + 1] = n + 1;
	if (j - 1 >= 0 && (*all)->i_map[i][j - 1] == -1 && count++)
		(*all)->i_map[i][j - 1] = n + 1;
	if (j + 1 < (*all)->y_m && (*all)->i_map[i][j + 1] == -1 && count++)
		(*all)->i_map[i][j + 1] = n + 1;
	if (i + 1 < (*all)->x_m && (*all)->i_map[i + 1][j] == -1 && count++)
		(*all)->i_map[i + 1][j] = n + 1;
	if (i + 1 < (*all)->x_m && j - 1 >= 0 && (*all)->i_map[i + 1][j - 1] == -1
		&& count++)
		(*all)->i_map[i + 1][j - 1] = n + 1;
	if (i + 1 < (*all)->x_m && j + 1 < (*all)->y_m &&
		(*all)->i_map[i + 1][j + 1] == -1 && count++)
		(*all)->i_map[i + 1][j + 1] = n + 1;
	return (count);
}

static int	count_map(int n, t_map **all)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < (*all)->x_m && count == 0 && (j = -1))
	{
		while (++j < (*all)->y_m && count == 0)
			if ((*all)->i_map[i][j] == -1)
				count = 1;
	}
	if (count == 0)
		return (1);
	count = 0;
	i = -1;
	while (++i < (*all)->x_m && (j = -1))
		while (++j < (*all)->y_m)
			if ((*all)->i_map[i][j] == n)
				count += push_num(all, i, j, n);
	if (count == 0)
		return (0);
	return (count_map(++n, all));
}

int			make_i_map(t_map *all)
{
	int i;
	int j;

	all->i_map = (int**)malloc(sizeof(int*) * (all->x_m));
	i = -1;
	while (++i < all->x_m)
	{
		j = -1;
		all->i_map[i] = (int*)malloc(sizeof(int) * (all->y_m));
		while (++j < all->y_m)
		{
			if (all->map[i][j] == '.')
				all->i_map[i][j] = -1;
			else if (all->map[i][j] == (all->lett - 32))
				all->i_map[i][j] = -2;
			else
				all->i_map[i][j] = 0;
		}
	}
	count_map(0, &all);
	return (1);
}
