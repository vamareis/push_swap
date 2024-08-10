/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:48:44 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/12 03:48:54 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacker(char **args)
{
	int		i;
	long	nbr;
	t_stack	*new_node;
	t_stack	*a;

	a = NULL;
	i = 0;
	while (args[i])
	{
		nbr = ft_atoi_ps(args[i]);
		new_node = ft_lstnew(nbr);
		ft_lstadd_back(&a, new_node);
		if (nbr == 21474836478)
		{
			free_lst(&a);
			free_tab(args);
			ft_error();
		}
		i++;
	}
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	char	**args;
	t_stack	*a;

	if (argc == 2)
	{
		args = ft_split(argv[1], 32);
		a = ft_stacker(args);
		free_tab(args);
	}
	else if (argc > 2)
		a = ft_stacker(argv + 1);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	if (!check_alpha(argv + 1) || !check_consecutive_signs(argv + 1))
		ft_error();
	if (argc > 2 && !check_nbr(argv + 1))
		ft_error();
	a = ft_process(argc, argv);
	if (!a || !check_dup(a))
	{
		free_lst(&a);
		ft_error();
	}
	if (ft_lstsize(a) <= 3)
		sort_3_a(&a);
	else if (!order_check_a(a))
		algorithm(&a, &b);
	free_lst(&a);
	free_lst(&b);
}
