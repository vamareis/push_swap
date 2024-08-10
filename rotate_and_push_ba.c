/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push_ba.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:49:44 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 03:49:45 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rbra(t_stack **a, t_stack **b, int nbr)
{
	{
		while ((*b)->nbr != nbr && ft_find_position_a(*a, nbr))
			rr(a, b, 1);
		while ((*b)->nbr != nbr)
			rb(b, 1);
		while (ft_find_position_a(*a, nbr))
			ra(a, 1);
	}
	pa(a, b, 1);
	return (-1);
}

int	apply_rrbrra(t_stack **a, t_stack **b, int nbr)
{
	{
		while ((*b)->nbr != nbr && ft_find_position_a(*a, nbr))
			rrr(a, b, 1);
		while ((*b)->nbr != nbr)
			rrb(b, 1);
		while (ft_find_position_a(*a, nbr))
			rra(a, 1);
	}
	pa(a, b, 1);
	return (-1);
}

int	apply_rbrra(t_stack **a, t_stack **b, int nbr)
{
	{
		while ((*b)->nbr != nbr)
			rb(b, 1);
		while (ft_find_position_a(*a, nbr))
			rra(a, 1);
	}
	pa(a, b, 1);
	return (-1);
}

int	apply_rrbra(t_stack **a, t_stack **b, int nbr)
{
	{
		while ((*b)->nbr != nbr)
			rrb(b, 1);
		while (ft_find_position_a(*a, nbr))
			ra(a, 1);
	}
	pa(a, b, 1);
	return (-1);
}
