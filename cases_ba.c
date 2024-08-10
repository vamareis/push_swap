/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_ba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:47:43 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 03:47:45 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_rbra(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = ft_find_position_a(a, nbr);
	if (i < ft_find_index(b, nbr))
		i = ft_find_index(b, nbr);
	return (i);
}

int	ft_case_rrbrra(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_position_a(a, nbr))
		i = ft_lstsize(a) - ft_find_position_a(a, nbr);
	if (i < ft_lstsize(b) - ft_find_index(b, nbr) && ft_find_index(b, nbr))
		i = ft_lstsize(b) - ft_find_index(b, nbr);
	return (i);
}

int	ft_case_rrbra(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_position_a(a, nbr))
		i = ft_find_position_a(a, nbr);
	i = (ft_lstsize(b) - ft_find_index(b, nbr)) + i;
	return (i);
}

int	ft_case_rbrra(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_position_a(a, nbr))
		i = ft_lstsize(a) - ft_find_position_a(a, nbr);
	i = ft_find_index(b, nbr) + i;
	return (i);
}
