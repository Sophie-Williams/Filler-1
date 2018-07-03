/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:14:32 by ovirchen          #+#    #+#             */
/*   Updated: 2018/03/04 15:14:34 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_p_num(t_map *all)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) <= 0)
		return (ft_error());
	tmp = ft_strchr(line, 'p');
	if (ft_atoi(++tmp) == 1)
		all->lett = 'o';
	else
		all->lett = 'x';
	free(line);
	return (1);
}

static int	part_read_piece(t_map **all)
{
	char	*line;
	int		i;
	int		j;

	if (!((*all)->pie = (char**)malloc(sizeof(char*) * ((*all)->x_p + 1))))
		return (ft_error());
	i = -1;
	(*all)->num_stars = 0;
	while (++i < (*all)->x_p && get_next_line(0, &line) > 0)
	{
		if (!((*all)->pie[i] = (char*)malloc(sizeof(char) *
			((*all)->y_p + 1))))
			return (ft_error());
		j = -1;
		while (++j < (*all)->y_p && line[j])
		{
			if (line[j] == '*')
				(*all)->num_stars++;
			(*all)->pie[i][j] = line[j];
		}
		(*all)->pie[i][j] = '\0';
		free(line);
	}
	(*all)->pie[i] = 0;
	return (1);
}

int			read_piece(t_map *all)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) <= 0)
		return (ft_error());
	tmp = ft_strchr(line, ' ');
	all->x_p = ft_atoi(++tmp);
	tmp = ft_strchr(tmp, ' ');
	all->y_p = ft_atoi(++tmp);
	free(line);
	if (part_read_piece(&all) == 0)
		return (0);
	return (1);
}

static int	part_read_map(t_map **all)
{
	int		i;
	int		j;
	char	*line;
	char	*tmp;

	if (!((*all)->map = (char**)malloc(sizeof(char*) * ((*all)->x_m + 1))))
		return (ft_error());
	i = -1;
	while (++i < (*all)->x_m && get_next_line(0, &line) > 0)
	{
		tmp = ft_strchr(line, ' ');
		free(line);
		if (!((*all)->map[i] = (char*)malloc(sizeof(char) * ((*all)->y_m + 1))))
			return (ft_error());
		j = -1;
		while (++j < (*all)->y_m && *(++tmp))
			(*all)->map[i][j] = *tmp;
		(*all)->map[i][j] = '\0';
	}
	(*all)->map[i] = 0;
	return (1);
}

int			read_map(t_map *all)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) <= 0 || !ft_strchr(line, ' '))
		return (ft_error());
	tmp = ft_strchr(line, ' ');
	all->x_m = ft_atoi(++tmp);
	tmp = ft_strchr(tmp, ' ');
	all->y_m = ft_atoi(++tmp);
	free(line);
	if (all->x_m < 1 || all->y_m < 1 || get_next_line(0, &line) == -1)
		return (ft_error());
	free(line);
	if (part_read_map(&all) == 0)
		return (0);
	return (read_piece(all));
}
