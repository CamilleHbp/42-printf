# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2017/12/31 14:38:38 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC 			= gcc
LIB_CFLAGS	= -Wall -Werror -Wextra

LIB_SRCS =	ft_abs.c \
			ft_absd.c \
			ft_absl.c \
			ft_absld.c \
			ft_absf.c \
			ft_min.c \
			ft_max.c \
			ft_pow.c \
			ft_round.c \
			ft_sqrt.c
LIB_SRCS +=	ft_bzero.c \
			ft_memalloc.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memccpy.c\
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c	\
			ft_realloc.c
LIB_SRCS +=	ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c
LIB_SRCS += ft_atoi.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_islower.c \
			ft_isupper.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbrf.c \
			ft_putnbr_fd.c \
			ft_putnstr.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putstr_padzeroes.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wcharlen.c \
			ft_wputchar.c \
			ft_wputnstr.c \
			ft_wputstr.c \
			ft_wstrlen.c

# sources and objects.
# we use the VPATH variable which causes MAKE to look for sources in all those
# directories
VPATH			:= ./srcs/math:./srcs/memory:./srcs/lists:./srcs/string
LIB_INC_DIR		:= ./includes
LIB_OBJECTS_DIR	:= ./obj
LIB_OBJECTS		= $(patsubst %,$(LIB_OBJECTS_DIR)/%,$(LIB_SRCS:.c=.o))

# echo output colours
RED		= \033[1;31m
PURPLE	= \033[1;35m
NC		= \033[0m

all: $(NAME)

$(NAME): $(LIB_OBJECTS)
	@echo "[Building ${PURPLE}library${NC}]"
	@ar rc $(NAME) $(LIB_OBJECTS)

$(LIB_OBJECTS_DIR)/%.o:%.c
	@mkdir -p $(LIB_OBJECTS_DIR)
	@$(CC) $(LIB_CFLAGS) -I$(LIB_INC_DIR) -o $@ -c $<

clean:
	@echo "[Cleaning ${PURPLE}lib${NC} objects]"
	@/bin/rm -rf $(LIB_OBJECTS_DIR)

fclean: clean
	@echo "[Cleaning ${PURPLE}lib${NC} binary]"
	@/bin/rm -f $(NAME)

re: fclean all
