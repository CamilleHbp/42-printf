# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2017/12/14 14:11:04 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  := printf

#directories
SRCS_DIR  := ./srcs/
INC_DIR   := ./srcs/
BUILD_DIR := ./build
LIB_DIR   := ./libft

# src / obj files
SRCS    :=	main.c \
			ft_printf.c \
			format_parsing.c
OBJECTS := $(patsubst %,$(BUILD_DIR)/%,$(SRCS:.c=.o))
# objects dependencies
DEPS       = $(OBJECTS:.o:.d)
DEPS_FLAGS = -MD -MP

# # compiler and flags
CC     := gcc
CFLAGS := -g  -Wall -Wextra -Werror

# # libraries
LIBS := ft
LIB_FLAGS := -L$(LIB_DIR) -l$(LIBS)

# echo output colours
CYAN = \e[1;36m
RED  = \033[1;31m
WHITE  = \033[1;37m
NC   = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIB_DIR)/
	@echo "[Building ${RED}executable${NC}]"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_FLAGS) -o $(NAME)

$(BUILD_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
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
