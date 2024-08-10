/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:24:49 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 04:24:55 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print)
{
	t_stack	*temp;

	if (*a && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
		if (print == 1)
			write(1, "sa\n", 3);
	}
}

void	ra(t_stack **a, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!a || !(*a) || !((*a)->next))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	last = ft_lstlast(*a);
	last->next = temp;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rra(t_stack **a, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	last = *a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
	{
		last->next = *a;
		*a = last;
		second_last->next = NULL;
	}
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print == 1)
		write(1, "rr\n", 3);
}

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (print == 1)
		write(1, "pa\n", 3);
}
