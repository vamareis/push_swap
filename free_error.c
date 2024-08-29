/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:33:11 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/29 14:33:18 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error(t_stack **a, t_stack **b, char *line)
{
	if (a)
		free_lst(a);
	if (b)
		free_lst(b);
	if (line)
		free(line);
	write(2, "Error\n", 6);
	exit(1);
}
