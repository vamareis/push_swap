/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:49:09 by vamachad          #+#    #+#             */
/*   Updated: 2024/07/15 11:17:52 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line/get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_stacker(char **args);
t_stack				*ft_process(int argc, char **argv);
int					ft_find_position_a(t_stack *a, int nbr);
int					ft_find_position_b(t_stack *b, int nbr);
int					ft_find_index(t_stack *a, int nbr);
void				sort_b_till_3(t_stack **a, t_stack **b);
void				algorithm(t_stack **a, t_stack **b);
void				sort_a(t_stack **a, t_stack **b);
void				sort_b(t_stack **a, t_stack **b);
void				sort_3_a(t_stack **a);
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b, int print);
void				ss(t_stack **a, t_stack **b, int print);
void				pa(t_stack **a, t_stack **b, int print);
void				pb(t_stack **a, t_stack **b, int print);
int					stack_min(t_stack *stack);
int					stack_max(t_stack *stack);
void				ft_error(void);
int					ft_isdigit(char c);
long				ft_atoi_ps(char *str);
void				free_tab(char **args);
int					ft_lstsize(t_stack *stack);
t_stack				*ft_lstlast(t_stack *stack);
t_stack				*ft_lstnew(long nbr);
void				ft_lstadd_back(t_stack **a, t_stack *new);
int					order_check_a(t_stack *a);
char				**ft_split(char const *s, char c);
void				print_stacks(t_stack *a, t_stack *b);
int					ft_case_rarb(t_stack *a, t_stack *b, int nbr);
int					ft_case_rrarrb(t_stack *a, t_stack *b, int nbr);
int					ft_case_rarrb(t_stack *a, t_stack *b, int nbr);
int					ft_case_rrarb(t_stack *a, t_stack *b, int nbr);
int					ft_case_rbra(t_stack *a, t_stack *b, int nbr);
int					ft_case_rrbrra(t_stack *a, t_stack *b, int nbr);
int					ft_case_rrbra(t_stack *a, t_stack *b, int nbr);
int					ft_case_rbrra(t_stack *a, t_stack *b, int nbr);
int					rotate_type_ab(t_stack *a, t_stack *b);
int					rotate_type_ba(t_stack *a, t_stack *b);
int					apply_rarb(t_stack **a, t_stack **b, int nbr);
int					apply_rrarrb(t_stack **a, t_stack **b, int nbr);
int					apply_rarrb(t_stack **a, t_stack **b, int nbr);
int					apply_rrarb(t_stack **a, t_stack **b, int nbr);
int					apply_rbra(t_stack **a, t_stack **b, int nbr);
int					apply_rrbrra(t_stack **a, t_stack **b, int nbr);
int					apply_rbrra(t_stack **a, t_stack **b, int nbr);
int					apply_rrbra(t_stack **a, t_stack **b, int nbr);
void				free_lst(t_stack **stack);
int					check_dup(t_stack *a);
int					check_dup_arg(char **arr);
int					check_alpha(char **arr);
int					check_repeat_signs(char *str);
int					check_nbr(char **arr);
int					check_consecutive_signs(char **arr);
int					check_args(int argc, char **argv);

#endif
