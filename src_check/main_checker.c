/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:10:05 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/29 17:10:09 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		take_all_in_a(t_data *d, char **av)
{
	int		i;

	i = 0;
	d->tab_a = (int *)malloc((d->ac - 1) * sizeof(int *));
	d->tab_b = (int *)malloc((d->ac - 1) * sizeof(int *));
	d->len_a = d->ac - 1;
	d->len_b = 0;
	while (i + 1 < d->ac)
	{
		if (valid_arg(av[i + 1]))
			return (0);
		d->tab_a[i] = ft_atoi(av[i + 1]);
		if (is_here(d, i))
			return (0);
		i++;
	}
	return (1);
}

int		get_cmd(t_data *d)
{
	char	*s;

	d->cmd = ft_strnew(0);
	s = NULL;
	while (get_next_line(0, &s))
	{
		!ft_strcmp(s, "sa") ? d->cmd = ft_strjoin_free(d->cmd, "a") : 0;
		!ft_strcmp(s, "sb") ? d->cmd = ft_strjoin_free(d->cmd, "b") : 0;
		!ft_strcmp(s, "ss") ? d->cmd = ft_strjoin_free(d->cmd, "c") : 0;
		!ft_strcmp(s, "pa") ? d->cmd = ft_strjoin_free(d->cmd, "d") : 0;
		!ft_strcmp(s, "pb") ? d->cmd = ft_strjoin_free(d->cmd, "e") : 0;
		!ft_strcmp(s, "ra") ? d->cmd = ft_strjoin_free(d->cmd, "f") : 0;
		!ft_strcmp(s, "rb") ? d->cmd = ft_strjoin_free(d->cmd, "g") : 0;
		!ft_strcmp(s, "rr") ? d->cmd = ft_strjoin_free(d->cmd, "h") : 0;
		!ft_strcmp(s, "rra") ? d->cmd = ft_strjoin_free(d->cmd, "i") : 0;
		!ft_strcmp(s, "rrb") ? d->cmd = ft_strjoin_free(d->cmd, "j") : 0;
		!ft_strcmp(s, "rrr") ? d->cmd = ft_strjoin_free(d->cmd, "k") : 0;
		if (ft_strcmp(s, "sa") && ft_strcmp(s, "sb") && ft_strcmp(s, "ss") &&
			ft_strcmp(s, "pa") && ft_strcmp(s, "pb") && ft_strcmp(s, "ra") &&
			ft_strcmp(s, "rb") && ft_strcmp(s, "rr") && ft_strcmp(s, "rra") &&
			ft_strcmp(s, "rrb") && ft_strcmp(s, "rrr"))
			inv_cmd(d, s);
		free(s);
	}
	return (1);
}

void	do_cmd(t_data *d, int i)
{
	while (d->cmd[++i])
	{
		d->cmd[i] == 'a' ? sa(d) : 0;
		d->cmd[i] == 'b' ? sb(d) : 0;
		d->cmd[i] == 'c' ? ss(d) : 0;
		d->cmd[i] == 'd' ? pa(d) : 0;
		d->cmd[i] == 'e' ? pb(d) : 0;
		d->cmd[i] == 'f' ? ra(d) : 0;
		d->cmd[i] == 'g' ? rb(d) : 0;
		d->cmd[i] == 'h' ? rr(d) : 0;
		d->cmd[i] == 'i' ? rra(d) : 0;
		d->cmd[i] == 'j' ? rrb(d) : 0;
		d->cmd[i] == 'k' ? rrr(d) : 0;
	}
}

int		its_sort(t_data *d)
{
	int		i;

	i = 0;
	if (d->len_a == 0)
		return (0);
	while (i < d->len_a - 1)
	{
		if (d->tab_a[i] > d->tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_data	*d;

	if (ac > 1)
	{
		d = NULL;
		if (!(d = (t_data *)malloc(sizeof(t_data))))
			return (-1);
		d->tab_a = NULL;
		d->tab_b = NULL;
		d->ac = ac;
		if (!take_all_in_a(d, av) || !get_cmd(d))
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		do_cmd(d, -1);
		if (!its_sort(d) || d->len_b != 0)
			ft_putstr("KO\n");
		else
			ft_putstr("OK\n");
		free_all(d);
	}
	sleep(10);
	return (0);
}
