/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:19:48 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/15 11:17:32 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_check_a(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_find_position_a(t_stack *a, int nbr)
{
	int		i;
	t_stack	*current;

	i = 1;
	current = a;
	if (nbr < a->nbr && nbr > ft_lstlast(a)->nbr)
		i = 0;
	else if (nbr > stack_max(a) || nbr < stack_min(a))
		i = ft_find_index(a, stack_min(a));
	else
	{
		while (current->next)
		{
			if (nbr > current->nbr && nbr < current->next->nbr)
				return (i);
			i++;
			current = current->next;
		}
	}
	return (i);
}

int	ft_find_position_b(t_stack *b, int nbr)
{
	int		i;
	t_stack	*current;

	i = 1;
	current = b;
	if (nbr > b->nbr && nbr < ft_lstlast(b)->nbr)
		i = 0;
	else if (nbr > stack_max(b) || nbr < stack_min(b))
		i = ft_find_index(b, stack_max(b));
	else
	{
		while (current->next)
		{
			if (nbr < current->nbr && nbr > current->next->nbr)
				return (i);
			i++;
			current = current->next;
		}
	}
	return (i);
}

int	ft_find_index(t_stack *stack, int nbr)
{
	t_stack	*current;
	int		i;

	current = stack;
	i = 0;
	while (current)
	{
		if (current->nbr == nbr)
			return (i);
		i++;
		current = current->next;
	}
	return (i);
}

int	check_args(int argc, char **argv)
{
	char	**args;

	args = NULL;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '\0')
		ft_error();
	else if (argc == 2)
		args = ft_split(argv[1], 32);
	else if (argc > 2)
		args = argv + 1;
	if (!check_alpha(args) || !check_consecutive_signs(args))
		ft_error();
	if (!check_nbr(args) || !check_dup_arg(args))
		ft_error();
	if (argc == 2)
		free_tab(args);
	return (1);
}
