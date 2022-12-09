# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:18:12 by jduval            #+#    #+#              #
#    Updated: 2022/12/09 14:03:17 by jduval           ###   ########.fr        #
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

SRCS = 	pushswap.c		ps_utils.c \
		ps_flat.c 		ps_parse.c \
		ps_set_stack.c 	ps_stats.c \
		ps_move.c

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
