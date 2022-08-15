NAME	=	libftprintf.a

SRCS	=	ft_functions.c		ft_itoa.c		ft_printf.c\
		ft_strdup.c		get_properties.c	handlers.c\
		numbers_handler.c

HEADER	=	libftprintf.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus	: all

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all
