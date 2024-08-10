/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:49:21 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 03:49:23 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

long	ft_atoi_ps(char *str)
{
	int		i;
	long	nbr;
	long	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (21474836478);
		nbr = nbr * 10 + (str[i++] - '0');
	}
	if (nbr * sign > INT_MAX || nbr * sign < INT_MIN)
		return (21474836478);
	return (nbr * sign);
}

void	free_tab(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print == 1)
		write(1, "ss\n", 3);
}
