# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 17:29:46 by vamachad          #+#    #+#              #
#    Updated: 2024/08/22 17:29:48 by vamachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Names of the executables
NAME = push_swap
BONUS_NAME = checker

# Source files for get_next_line
GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

# Source files for push_swap
SRCS = push_swap.c algorithm.c cases_ab.c cases_ba.c check_errors.c \
       ft_lst_tools.c ft_split.c operations_1.c operations_2.c \
       push_swap_utils.c push_swap_utils_2.c rotate_and_push_ab.c \
       rotate_and_push_ba.c rotate_type.c sort_3.c
OBJS = $(SRCS:.c=.o)

# Source files for checker
BONUS_SRCS = checker.c algorithm.c cases_ab.c cases_ba.c check_errors.c \
             ft_lst_tools.c ft_split.c operations_1.c operations_2.c \
             push_swap_utils.c push_swap_utils_2.c rotate_and_push_ab.c \
             rotate_and_push_ba.c rotate_type.c sort_3.c $(GNL_SRCS)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Rule to make the push_swap executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to make the checker executable
$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

# Rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets for cleaning up
.PHONY: clean fclean re bonus

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean $(NAME)

# Bonus rule to compile both executables
bonus: $(NAME) $(BONUS_NAME)
