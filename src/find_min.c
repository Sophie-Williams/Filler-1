/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:38:37 by ovirchen          #+#    #+#             */
/*   Updated: 2018/03/05 13:38:38 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	loop(t_map **all, int *count, int *sum)
{
	int i;
	int j;
	int col;
	int row;

	i = -1;
	while (++i < (*all)->x_p && (*count) < (*all)->num_stars && (j = -1))
		while (++j < (*all)->y_p && (*count) < (*all)->num_stars)
		{
			if (i == (*all)->i_p && j == (*all)->j_p)
				(*count) += 1;
			else if ((*all)->pie[i][j] == '*')
			{
				row = (*all)->i_m + i - (*all)->i_p;
				col = (*all)->j_m + j - (*all)->j_p;
				if (row < (*all)->x_m && row >= 0 && col < (*all)->y_m &&
					col >= 0 && (*all)->map[row][col] == '.')
				{
					(*sum) += (*all)->i_map[row][col];
					(*count) += 1;
				}
				else
					(*count) += (*all)->num_stars + 10;
			}
		}
}

static int	check_push(t_map **all, int row, int col)
{
	int count;
	int sum;

	(*all)->i_p = row;
	(*all)->j_p = col;
	count = 0;
	sum = 0;
	loop(all, &count, &sum);
	if (count == (*all)->num_stars)
	{
		if ((*all)->min_sum == -1 || sum < (*all)->min_sum)
		{
			(*all)->min_sum = sum;
			(*all)->x = (*all)->i_m - (*all)->i_p;
			(*all)->y = (*all)->j_m - (*all)->j_p;
		}
		return (1);
	}
	return (0);
}

static int	push_piece(t_map **all, int i, int j)
{
	int row;
	int col;
	int count;

	count = 0;
	row = -1;
	(*all)->i_m = i;
	(*all)->j_m = j;
	while (++row < (*all)->x_p)
	{
		col = -1;
		while (++col < (*all)->y_p)
		{
			if ((*all)->pie[row][col] == '*')
				if (check_push(all, row, col) == 1)
					count++;
		}
	}
	return (1);
}

int			find_place(t_map *all)
{
	int i;
	int j;

	i = -1;
	all->min_sum = -1;
	while (++i < all->x_m)
	{
		j = -1;
		while (++j < all->y_m)
		{
			if (all->map[i][j] == all->lett - 32)
				push_piece(&all, i, j);
		}
	}
	return (1);
}
