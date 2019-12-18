# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: alidy <alidy@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/28 10:24:13 by alidy        #+#   ##    ##    #+#        #
#    Updated: 2019/12/18 11:46:38 by alidy       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=		libftprintf.a

HEADERS		=		includes/ft_printf.h

SRCS 		=		src/ft_printf.c	  	 	\
					src/ft_itoa_base.c   	\
					src/ft_get_str_format.c \
					src/ft_int_format.c     \
					src/ft_parsing_flags.c  \
					src/ft_str_format.c     \
					src/ft_un_format.c      \
					src/ft_hexa_format.c    \

FLAGS 		= 		-Wall -Wextra -Werror

OBJ			= 		$(SRCS:.c=.o)

LIB 		= 		libft/libft.a

all			: 		$(NAME)

$(LIB)		:
		@make -C libft

$(NAME): $(LIB) $(OBJ)
		@cp libft/libft.a $(NAME)
		@ar rcs $(NAME) $(OBJ) $(LIB)
		@echo "\033[90m[\033[32mft_printf\033[90m]\033[32m Successfully compiled ft_printf.\033[0m"

%.o: %.c
		@$(CC) -I $(HEADERS) -o $@ -c $< $(FLAGS)

clean		:
		@/bin/rm -f $(OBJ)
		@make clean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted *.o\033[0m"

fclean		:		clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted $(NAME)\033[0m"

re			:		fclean all