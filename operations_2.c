/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:25:08 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 04:25:11 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, int print)
{
	t_stack	*temp;

	if (*b && (*b)->next)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = (*b)->next;
		(*b)->next = temp;
		if (print == 1)
			write(1, "sb\n", 3);
	}
}

void	rb(t_stack **b, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!b || !(*b) || !((*b)->next))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	last = ft_lstlast(*b);
	last->next = temp;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = NULL;
	last = *b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
	{
		last->next = *b;
		*b = last;
		second_last->next = NULL;
	}
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print == 1)
		write(1, "rrr\n", 4);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (print == 1)
		write(1, "pb\n", 3);
}
