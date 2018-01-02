# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2018/01/02 21:12:22 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra


# sources
SRCS_DIR	:=	./srcs
SRCS	:=	$(SRC_DIR)/ft_printf.c
SRCS	+=	$(SRC_DIR)/parsing/flags.c \
			$(SRC_DIR)/parsing/parsing.c \
			$(SRC_DIR)/parsing/length.c \
			$(SRC_DIR)/parsing/precision.c \
			$(SRC_DIR)/parsing/specifiers.c \
			$(SRC_DIR)/parsing/width.c
SRCS	+=	$(SRC_DIR)/printing/printing.c \
			$(SRC_DIR)/printing/nums_base.c \
			$(SRC_DIR)/printing/nums_common.c \
			$(SRC_DIR)/printing/nums_common_floats.c \
			$(SRC_DIR)/printing/nums_floats.c \
			$(SRC_DIR)/printing/nums_integers.c \
			$(SRC_DIR)/printing/pointers.c \
			$(SRC_DIR)/printing/strings_unicode.c \
			$(SRC_DIR)/printing/strings.c
SRCS	+=	$(SRC_DIR)/utilities/utils_common.c
# libft sources
# we use the VPATH variable which causes MAKE to look for sources in all those
# directories
VPATH			:= ./libftprintf/srcs/math:./libftprintf/srcs/memory:./libftprintf/srcs/lists:./libftprintf/srcs/string
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

# object files
OBJ_DIR		:=	./obj
OBJECTS		:= $(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
# object files for libft
LIB_OBJECTS_DIR	:= ./libftprintf/obj
LIB_OBJECTS		= $(patsubst %,$(LIB_OBJECTS_DIR)/%,$(LIB_SRCS:.c=.o))
# objects dependencies
DEPS       = $(OBJECTS:.o:.d)
DEPS_FLAGS = -MD -MP

# includes
INC_DIR		:=	./includes \
				./libftprintf/includes
IFLAGS += $(foreach d, $(INC_DIR), -I$d)

# echo output colours
CYAN	= \e[1;36m
RED		= \033[1;31m
WHITE	= \033[1;37m
PURPLE	= \033[1;35m
NC		= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB_OBJECTS) $(OBJECTS)
	@echo "[Building ${PURPLE}library${NC}]"
	@ar rcs $(NAME) $(LIB_OBJECTS) $(OBJECTS)

$(LIB_OBJECTS_DIR)/%.o:%.c
	@mkdir -p $(LIB_OBJECTS_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/printing
	@mkdir -p $(OBJ_DIR)/test
	@mkdir -p $(OBJ_DIR)/utilities
	@$(CC) $(CFLAGS) $(IFLAGS) $(DEPS_FLAGS) -o $@ -c $<

clean:
	@echo "[Cleaning ${PURPLE}lib${NC} objects]"
	@/bin/rm -rf $(LIB_OBJECTS_DIR)
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[Cleaning ${PURPLE}lib${NC} binary]"
	@/bin/rm -rf $(NAME)

re: fclean all
