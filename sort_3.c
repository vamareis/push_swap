/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:50:04 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 04:10:46 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_a(t_stack **a)
{
	if (!order_check_a(*a))
	{
		if (stack_min(*a) == (*a)->nbr)
		{
			rra(a, 1);
			sa(a, 1);
		}
		else if (stack_min(*a) == (*a)->next->nbr && stack_max(*a) == (*a)->nbr)
			ra(a, 1);
		else if (stack_min(*a) == (*a)->next->next->nbr
			&& stack_max(*a) == (*a)->nbr)
		{
			ra(a, 1);
			sa(a, 1);
		}
		else if (stack_min(*a) == (*a)->next->nbr
			&& stack_max(*a) == (*a)->next->next->nbr)
			sa(a, 1);
		else if (stack_min(*a) == (*a)->next->next->nbr
			&& stack_max(*a) == (*a)->next->nbr)
			rra(a, 1);
	}
}

int	stack_min(t_stack *stack)
{
	t_stack	*current;
	int		min;

	current = stack;
	min = current->nbr;
	while (current)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

int	stack_max(t_stack *stack)
{
	t_stack	*current;
	int		max;

	current = stack;
	max = current->nbr;
	while (current)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}
