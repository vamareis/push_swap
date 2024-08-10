/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:47:22 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 03:47:23 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_till_3(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*a) > 3 && !order_check_a(*a))
	{
		tmp = *a;
		i = rotate_type_ab(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*a, *b, tmp->nbr))
				i = apply_rarb(a, b, tmp->nbr);
			else if (i == ft_case_rrarrb(*a, *b, tmp->nbr))
				i = apply_rrarrb(a, b, tmp->nbr);
			else if (i == ft_case_rarrb(*a, *b, tmp->nbr))
				i = apply_rarrb(a, b, tmp->nbr);
			else if (i == ft_case_rrarb(*a, *b, tmp->nbr))
				i = apply_rrarb(a, b, tmp->nbr);
			else
				tmp = tmp->next;
		}
	}
}

void	sort_b(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 3 && !order_check_a(*a))
		pb(a, b, 1);
	if (ft_lstsize(*a) > 3 && !order_check_a(*a))
		pb(a, b, 1);
	if (ft_lstsize(*a) > 3 && !order_check_a(*a))
		sort_b_till_3(a, b);
	if (!order_check_a(*a))
		sort_3_a(a);
}

void	sort_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	while (*b)
	{
		tmp = *b;
		i = rotate_type_ba(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_rbra(*a, *b, tmp->nbr))
				i = apply_rbra(a, b, tmp->nbr);
			if (i == ft_case_rrbrra(*a, *b, tmp->nbr))
				i = apply_rrbrra(a, b, tmp->nbr);
			if (i == ft_case_rbrra(*a, *b, tmp->nbr))
				i = apply_rbrra(a, b, tmp->nbr);
			if (i == ft_case_rrbra(*a, *b, tmp->nbr))
				i = apply_rrbra(a, b, tmp->nbr);
			else
				tmp = tmp->next;
		}
	}
}

void	algorithm(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	sort_b(a, b);
	sort_a(a, b);
	i = ft_find_index(*a, stack_min(*a));
	if (i <= ft_lstsize(*a) / 2)
	{
		while ((*a)->nbr != stack_min(*a))
			ra(a, 1);
	}
	else
	{
		while ((*a)->nbr != stack_min(*a))
			rra(a, 1);
	}
}
