# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:18:12 by jduval            #+#    #+#              #
#    Updated: 2022/12/30 18:37:43 by jduval           ###   ########.fr        #
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

ifdef BONUS
BUILD_DIR = .build_bonus
else
BUILD_DIR = .build
endif

SRCS = 			pushswap.c \
				ps_parse.c		ps_flat.c	\
				ps_set_stack.c 	ps_data.c \
				ps_moves.c		ps_double_moves.c \
				ps_algorithm.c  ps_pathern.c \
				ps_data_utils.c	ps_utils.c \

SRCS_BONUS =	ft_checker.c 		ps_set_stack_bonus.c \
				ps_flat_bonus.c		ps_parse_bonus.c \
				ps_utils_bonus.c	ps_moves_a_bonus.c \
				ps_moves_b_bonus.c	ps_double_moves_bonus.c \
				ps_utils2_bonus.c \

ifdef BONUS
OBJS = $(SRCS_BONUS:%.c=$(BUILD_DIR)/%.o)
else
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
endif

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
.PHONY:bonus
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
