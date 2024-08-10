/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push_ab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:49:34 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 03:49:36 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rarb(t_stack **a, t_stack **b, int nbr)
{
	{
		while ((*a)->nbr != nbr && ft_find_position_b(*b, nbr))
			rr(a, b, 1);
		while ((*a)->nbr != nbr)
			ra(a, 1);
		while (ft_find_position_b(*b, nbr))
			rb(b, 1);
	}
	pb(a, b, 1);
	return (-1);
}

int	apply_rrarrb(t_stack **a, t_stack **b, int nbr)
{
	{
		while ((*a)->nbr != nbr && ft_find_position_b(*b, nbr))
			rrr(a, b, 1);
		while ((*a)->nbr != nbr)
			rra(a, 1);
		while (ft_find_position_b(*b, nbr))
			rrb(b, 1);
	}
	pb(a, b, 1);
	return (-1);
}

int	apply_rarrb(t_stack **a, t_stack **b, int nbr)
{
	{
		while ((*a)->nbr != nbr)
			ra(a, 1);
		while (ft_find_position_b(*b, nbr))
			rrb(b, 1);
	}
	pb(a, b, 1);
	return (-1);
}

int	apply_rrarb(t_stack **a, t_stack **b, int nbr)
{
	{
		while ((*a)->nbr != nbr)
			rra(a, 1);
		while (ft_find_position_b(*b, nbr))
			rb(b, 1);
	}
	pb(a, b, 1);
	return (-1);
}
