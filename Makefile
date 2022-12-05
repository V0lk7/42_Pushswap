# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:18:12 by jduval            #+#    #+#              #
#    Updated: 2022/12/05 09:35:13 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################

NAME = push_swap

MAKEFLAGS += --no-print-directory

CC = clang

CFLAGS = -Wall -Werror -Wextra -ggdb3

CPPFLAGS = -MMD -MP -I $(INCLUDE)

DIRDUP = mkdir -p $(@D)

###############################################################################

INCLUDE = libft/include/

BUILD_DIR = .build

SRCS = 	pushswap.c		pushswap_utils.c \
		ft_flat_str.c 	ft_parse.c \
		set_stacks.c 	circular_buf_set.c \

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

DEPS = ${OBJS:.o=.d}

###############################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C libft/
	@$(CC) $(CFLAGS) $(CPPFLAGS) $^ libft/libft.a -o $@
	$(info CREATED $@)

$(BUILD_DIR)/%.o : %.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

###############################################################################

clean: 
	@${MAKE} -C libft/ clean
	@rm -rf $(OBJS) $(BUILD_DIR)
.PHONY:clean

fclean: clean 
	@${MAKE} -C libft/ fclean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
