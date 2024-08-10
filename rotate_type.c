/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:49:54 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 03:49:55 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_type_ab(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = ft_case_rrarrb(a, b, a->nbr);
	while (tmp)
	{
		if (i > ft_case_rarb(a, b, tmp->nbr))
			i = ft_case_rarb(a, b, tmp->nbr);
		if (i > ft_case_rrarrb(a, b, tmp->nbr))
			i = ft_case_rrarrb(a, b, tmp->nbr);
		if (i > ft_case_rarrb(a, b, tmp->nbr))
			i = ft_case_rarrb(a, b, tmp->nbr);
		if (i > ft_case_rrarb(a, b, tmp->nbr))
			i = ft_case_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ba(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		i;

	tmp = b;
	i = ft_case_rrbrra(a, b, b->nbr);
	while (tmp)
	{
		if (i > ft_case_rbra(a, b, tmp->nbr))
			i = ft_case_rbra(a, b, tmp->nbr);
		if (i > ft_case_rrbrra(a, b, tmp->nbr))
			i = ft_case_rrbrra(a, b, tmp->nbr);
		if (i > ft_case_rbrra(a, b, tmp->nbr))
			i = ft_case_rbrra(a, b, tmp->nbr);
		if (i > ft_case_rrbra(a, b, tmp->nbr))
			i = ft_case_rrbra(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
