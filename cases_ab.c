/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:47:32 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 03:47:33 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_rarb(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = ft_find_position_b(b, nbr);
	if (i < ft_find_index(a, nbr))
		i = ft_find_index(a, nbr);
	return (i);
}

int	ft_case_rrarrb(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_position_b(b, nbr))
		i = ft_lstsize(b) - ft_find_position_b(b, nbr);
	if (i < (ft_lstsize(a) - ft_find_index(a, nbr)) && ft_find_index(a, nbr))
		i = ft_lstsize(a) - ft_find_index(a, nbr);
	return (i);
}

int	ft_case_rarrb(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_position_b(b, nbr))
		i = ft_lstsize(b) - ft_find_position_b(b, nbr);
	i = ft_find_index(a, nbr) + i;
	return (i);
}

int	ft_case_rrarb(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_index(a, nbr))
		i = ft_lstsize(a) - ft_find_index(a, nbr);
	i = ft_find_position_b(b, nbr) + i;
	return (i);
}
