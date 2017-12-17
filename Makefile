# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2017/12/17 20:46:45 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := printf

#directories
SRCS_DIR			:=	./srcs
INC_DIR				:=	./srcs \
						./srcs/parsing \
						./srcs/printing \
						./srcs/test \
						./libft/srcs
BUILD_DIR			:=	./build
LIB_DIR				:=	./libft



# sources
SRCS	:=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/ft_printf.c
SRCS	+=	$(SRC_DIR)/parsing/flags.c \
			$(SRC_DIR)/parsing/format_parsing.c \
			$(SRC_DIR)/parsing/length.c \
			$(SRC_DIR)/parsing/precision.c \
			$(SRC_DIR)/parsing/specifiers.c \
			$(SRC_DIR)/parsing/width.c
SRCS	+=	$(SRC_DIR)/printing/arg_print.c
SRCS	+=	$(SRC_DIR)/test/print_test.c
# object files
OBJECTS	:= $(patsubst %,$(BUILD_DIR)/%,$(SRCS:.c=.o))
# objects dependencies
DEPS       = $(OBJECTS:.o:.d)
DEPS_FLAGS = -MD -MP

# # compiler and flags
CC		:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror
CFLAGS += $(foreach d, $(INC_DIR), -I$d)

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
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_FLAGS) -o $(NAME)

$(BUILD_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/parsing
	@mkdir -p $(BUILD_DIR)/printing
	@mkdir -p $(BUILD_DIR)/test
	@echo "[Building $@...]"
	@$(CC) $(CFLAGS) $(DEPS_FLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@echo "[Cleaning ${RED}executable${NC} objects]"
	@make clean -C $(LIB_DIR)
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo  "[Cleaning ${RED}executable${NC}]"
	@make fclean -C $(LIB_DIR)
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)
