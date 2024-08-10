# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Names of the executables
NAME = push_swap
BONUS_NAME = checker

# Source files for get_next_line
GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

# Source and object files for push_swap
# Ensure check_errors.c is included for push_swap
SRCS = $(filter-out checker.c, $(wildcard *.c))
OBJS = $(SRCS:.c=.o)

# Source and object files for checker
# Ensure check_errors.c is included for checker
BONUS_SRCS = $(filter-out push_swap.c, $(wildcard *.c))
BONUS_OBJS = $(BONUS_SRCS:.c=.o) $(GNL_OBJS)

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