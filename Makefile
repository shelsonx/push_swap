SRCS_FILES			= 	linked_list_funcs.c init.c swap_operations.c push_operations.c  \
						rotate_up_operations.c reverse_rotate_operations.c exit.c push_swap_utils.c \
						sort_small.c validate.c quick_sort.c sort_large.c sort_large_utils.c positions.c \
						adjust_stack.c costs.c main.c

SRCS_FILES_BONUS	= 	linked_list_funcs.c init.c swap_operations.c push_operations.c  \
						rotate_up_operations.c reverse_rotate_operations.c exit.c push_swap_utils.c \
						validate.c quick_sort.c positions.c checker.c

SRCS_DIR			= src

SRCS_DIR_BONUS		= src_bonus

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

SRCS_BONUS			= $(addprefix $(SRCS_DIR_BONUS)/, $(SRCS_FILES_BONUS))

OBJS				= $(SRCS:.c=.o)

OBJS_BONUS			= $(SRCS_BONUS:.c=.o)

LIBFT_DIR			= ./libs/libft

LIBFT				= ./libs/libft/libft.a

RM 					= rm -f

CC					= cc

CFLAGS 				= -Wall -Wextra -Werror -g

NAME				= push_swap
NAME_BONUS			= checker

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(LIBFT) $(OBJS)
					$(CC)  $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(OBJS_BONUS)
					$(CC)  $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):			
					$(MAKE) -C $(LIBFT_DIR)
					$(MAKE) bonus -C $(LIBFT_DIR)
					
clean:
					$(MAKE) clean -C $(LIBFT_DIR)
					$(RM) $(OBJS)
					$(RM) $(OBJS_BONUS)

fclean:				clean
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re libft bonus

test3:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					./push_swap $(ARG) | wc -l

test5:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-500 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					./push_swap $(ARG) | wc -l

test100:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-1000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					./push_swap $(ARG) | wc -l

test500:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-2000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					./push_swap $(ARG) | wc -l