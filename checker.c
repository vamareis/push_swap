/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:19:01 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/22 17:30:41 by vamachad         ###   ########.fr       */
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

	a = NULL;
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

void	do_commands(t_stack **a, t_stack **b, char *ln)
{
	if (ln[0] == 's' && ln[1] == 'a' && ln[2] == '\n')
		sa(a, 0);
	else if (ln[0] == 's' && ln[1] == 'b' && ln[2] == '\n')
		sb(b, 0);
	else if (ln[0] == 'p' && ln[1] == 'a' && ln[2] == '\n')
		pa(a, b, 0);
	else if (ln[0] == 'p' && ln[1] == 'b' && ln[2] == '\n')
		pb(a, b, 0);
	else if (ln[0] == 'r' && ln[1] == 'a' && ln[2] == '\n')
		ra(a, 0);
	else if (ln[0] == 'r' && ln[1] == 'b' && ln[2] == '\n')
		rb(b, 0);
	else if (ln[0] == 'r' && ln[1] == 'r' && ln[2] == 'a' && ln[3] == '\n')
		rra(a, 0);
	else if (ln[0] == 'r' && ln[1] == 'r' && ln[2] == 'b' && ln[3] == '\n')
		rrb(b, 0);
	else if (ln[0] == 's' && ln[1] == 's' && ln[2] == '\n')
		ss(a, b, 0);
	else if (ln[0] == 'r' && ln[1] == 'r' && ln[2] == '\n')
		rr(a, b, 0);
	else if (ln[0] == 'r' && ln[1] == 'r' && ln[2] == 'r' && ln[3] == '\n')
		rrr(a, b, 0);
	else
		ft_error();
}

void	get_commands(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		do_commands(a, b, line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!check_args(argc, argv))
		return (0);
	a = ft_process(argc, argv);
	b = NULL;
	get_commands(&a, &b);
	if (order_check_a(a))
		write(1, "OK\n", 3);
	else if (!order_check_a(a))
		write(1, "KO\n", 3);
	free_lst(&a);
	free_lst(&b);
}

/* void    print_stacks(t_stack *a, t_stack *b)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = a;
	current_b = b;
	printf("\nSTACK A\n\n");
	while (current_a)
	{
		printf("%ld\n", current_a->nbr);
		current_a = current_a->next;
	}
	printf("\n\n");
	printf("STACK B\n\n");
	if (!current_b)
		printf("Empty\n");
	while (current_b)
	{
		printf("%ld\n", current_b->nbr);
		current_b = current_b->next;
	}
	printf("\n\n");
} */
