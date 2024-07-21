# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeum <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 07:46:47 by dgeum             #+#    #+#              #
#    Updated: 2024/07/16 08:03:08 by dgeum            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes

LIBNAME = libft.a

SRCDIR = srcs
OBJDIR = $(SRCDIR)

SRC =	$(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c \
	$(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c

OBJ = $(SRC:.c=.o)

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	ranlib $(LIBNAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
