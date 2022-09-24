SRCS_FILES			= 	input.c

SRCS_FILES_BONUS	= 	# need to implement

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
NAME_BONUS			= push_swap_bonus

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