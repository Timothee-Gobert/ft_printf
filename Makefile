# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 08:20:04 by tgobert           #+#    #+#              #
#    Updated: 2025/11/14 08:54:00 by tgobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINT_SRCS	=	ft_printf.c \
				ft_printf_pxX.c \
				ft_printf_scuid.c \
				ft_put_fd.c

PRINT_OBJS	=	$(PRINT_SRCS:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
NAME	=	libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(PRINT_OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(PRINT_OBJS)
	
	@echo "███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗"
	@echo "██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝"
	@echo "█████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  "
	@echo "██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  "
	@echo "██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     "
	@echo "╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     "

	@echo "Compiled $(NAME) successfully!"

clean:
	$(RM) $(PRINT_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all
