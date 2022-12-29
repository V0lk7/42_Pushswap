# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:18:12 by jduval            #+#    #+#              #
#    Updated: 2022/12/29 13:50:32 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################

ifdef BONUS
NAME = checker
else
NAME = push_swap
endif

MAKEFLAGS += --no-print-directory

CC = clang

CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -MMD -MP -I $(INCLUDE)

DIRDUP = mkdir -p $(@D)

###############################################################################

INCLUDE = libft/include/

BUILD_DIR = .build

SRCS = 	pushswap.c		ps_utils.c	\
		ps_parse.c		ps_flat.c	\
		ps_set_stack.c 	ps_data.c \
		ps_moves.c		ps_moves2.c \
		ps_algorithm.c  ps_pathern.c \
		ps_data_utils.c

SRCS_BONUS = 

ifdef BONUS
SRCS += $(SRCS_BONUS)
endif

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

DEPS = ${OBJS:.o=.d}

###############################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C libft/
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) libft/libft.a -o $@
	$(info CREATED $@)

$(BUILD_DIR)/%.o : %.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS) 

bonus: 
	$(MAKE) BONUS=1 all

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
