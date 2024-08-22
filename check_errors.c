/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:14:37 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/22 17:30:30 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nbr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_atoi_ps(arr[i]) == 21474836478)
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(t_stack *a)
{
	t_stack	*current;

	while (a)
	{
		current = a->next;
		while (current)
		{
			if ((a->nbr == current->nbr))
				return (0);
			current = current->next;
		}
		a = a->next;
	}
	return (1);
}

int	check_dup_arg(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi_ps(arr[i]) == ft_atoi_ps(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_alpha(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == '\0')
			return (0);
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
			{
				if (arr[i][j] != '-' && arr[i][j] != '+' && arr[i][j] != ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_consecutive_signs(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-' || arr[i][j] == '+')
			{
				if (!ft_isdigit(arr[i][j + 1]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
