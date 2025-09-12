# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/12 15:21:06 by vinpache          #+#    #+#              #
#    Updated: 2025/09/12 15:43:18 by vinpache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	= \033[0m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RED		= \033[1;31m

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
SRCS = fractol.c init.c fractol_calc.c fractol_draw.c hooks.c fractol_setup.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ -lmlx -lXext -lX11 -lm
	@echo "$(GREEN)✅ Fractol compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)🔧 Compiling:$(RESET) $<"
	
clean:
	@rm -f $(OBJS)
	@echo "$(RED)✅ Fractol objects fully cleaned!$(RESET)"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✅ Fractol program fully cleaned!$(RESET)"
	
re: fclean all

.PHONY: all clean fclean re