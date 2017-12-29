# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2017/12/29 22:45:09 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := printf

#directories
SRCS_DIR	:=	./srcs
INC_DIR		:=	./includes \
				./libft/includes
OBJ_DIR		:=	./obj
LIB_DIR		:=	./libft



# sources
SRCS	:=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/ft_printf.c
SRCS	+=	$(SRC_DIR)/parsing/flags.c \
			$(SRC_DIR)/parsing/parsing.c \
			$(SRC_DIR)/parsing/length.c \
			$(SRC_DIR)/parsing/precision.c \
			$(SRC_DIR)/parsing/specifiers.c \
			$(SRC_DIR)/parsing/width.c
SRCS	+=	$(SRC_DIR)/printing/printing.c \
			$(SRC_DIR)/printing/nums_common.c \
			$(SRC_DIR)/printing/nums_base.c \
			$(SRC_DIR)/printing/nums_integers.c \
			$(SRC_DIR)/printing/strings_unicode.c \
			$(SRC_DIR)/printing/strings.c
SRCS	+=	$(SRC_DIR)/test/print_test.c
SRCS	+=	$(SRC_DIR)/utilities/utils_common.c
# object files
OBJECTS	:= $(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
# objects dependencies
DEPS       = $(OBJECTS:.o:.d)
DEPS_FLAGS = -MD -MP

# # compiler and flags
CC		:= gcc
CFLAGS	:= -ggdb -Wall -Wextra -Werror
IFLAGS += $(foreach d, $(INC_DIR), -I$d)

# # libraries
LIBS		:= ft
LIB_FLAGS	:= -L$(LIB_DIR) -l$(LIBS)

# echo output colours
CYAN	= \e[1;36m
RED		= \033[1;31m
WHITE	= \033[1;37m
NC		= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTS_PARSING) $(OBJECTS_PRINTING)
	@make -C $(LIB_DIR)/
	@echo "[Building ${RED}executable${NC}]"
	@$(CC) $(CFLAGS) $(OBJECTS) $(IFLAGS) $(LIB_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/printing
	@mkdir -p $(OBJ_DIR)/test
	@mkdir -p $(OBJ_DIR)/utilities
	@echo "[Building $@...]"
	@$(CC) $(CFLAGS) $(IFLAGS) $(DEPS_FLAGS)  -o $@ -c $<

clean:
	@echo "[Cleaning ${RED}executable${NC} objects]"
	@make clean -C $(LIB_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo  "[Cleaning ${RED}executable${NC}]"
	@make fclean -C $(LIB_DIR)
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)
