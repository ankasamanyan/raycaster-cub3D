# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasamanian <akasamanian@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:53:09 by jkaczmar          #+#    #+#              #
#    Updated: 2024/05/28 18:01:25 by akasamanian      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = 
CC = gcc
GNL	= ./srcs/get_next_line/
SRCS = 			./srcs/ft_memmove.c \
				./srcs/ft_strjoin.c \
				./srcs/ft_isalnum.c \
				./srcs/ft_isdigit.c \
				./srcs/ft_substr.c \
				./srcs/ft_memchr.c \
				./srcs/ft_itoa.c \
				./srcs/ft_isspace.c \
				./srcs/ft_memcmp.c \
				./srcs/ft_strchr.c \
				./srcs/ft_strlcat.c \
				./srcs/ft_calloc.c \
				./srcs/ft_putstr_fd.c \
				./srcs/ft_intlen.c \
				./srcs/ft_strtrim.c \
				./srcs/ft_tolower.c \
				./srcs/ft_memcpy.c \
				./srcs/ft_putendl_fd.c \
				./srcs/ft_strnstr.c \
				./srcs/ft_putchar_fd.c \
				./srcs/ft_toupper.c \
				./srcs/ft_memset.c \
				./srcs/ft_strncmp.c \
				./srcs/ft_strcmp.c \
				./srcs/ft_striteri.c \
				./srcs/ft_realloc.c \
				./srcs/ft_isprint.c \
				./srcs/ft_isalpha.c \
				./srcs/ft_pow.c \
				./srcs/ft_strdup.c \
				./srcs/ft_putnbr_fd.c \
				./srcs/ft_bzero.c \
				./srcs/ft_atoi.c \
				./srcs/ft_wcount.c \
				./srcs/ft_strrchr.c \
				./srcs/ft_strmapi.c \
				./srcs/ft_isascii.c \
				./srcs/ft_strlcpy.c \
				./srcs/ft_abs.c \
				./srcs/ft_split.c \
				./srcs/ft_strlen.c \
				./srcs/ft_atoll.c \
				./srcs/print_2d_fd.c \
				./srcs/free_2d_guard.c \
				./srcs/free_2d.c \
				./srcs/ft_hex_fd.c \
				./srcs/ft_uphex_fd.c \
				./srcs/ft_uputnbr_fd.c \
				./srcs/ft_putmem_fd.c \
				./srcs/ft_printf.c \
				./srcs/getncount.c \
				./srcs/ft_strlen_ignore.c \
				./srcs/pos_char_start.c \
				./srcs/pos_char_end.c \
				./srcs/ft_realloc_n.c \
				./srcs/get_next_line/get_next_line.c \
				./srcs/get_next_line/get_next_line_utils.c \
				./srcs/ft_strjoin_free.c \
				./srcs/ft_strjoins.c \
				./srcs/ft_strjoin_str2.c \
				./srcs/error_line.c \
				./srcs/ft_strccpy.c \
				./srcs/ft_strclen.c \
				./srcs/ft_subcstr.c \
				./srcs/ft_2darrlen.c

BONUS_SRCS = 	./bonus/ft_lstadd_back.c \
				./bonus/ft_lstdelone.c \
				./bonus/ft_lstclear.c \
				./bonus/ft_lstnew.c \
				./bonus/ft_lstsize.c \
				./bonus/lstsize.c \
				./bonus/ft_lstadd_front.c \
				./bonus/ft_lstmap.c \
				./bonus/ft_lstlast.c \
				./bonus/ft_lstiter.c \
				./bonus/ft_lstprint.c

NC			:= \033[0m
B_RED		:= \033[1;31m
RED 		:= \033[0;31m
B_GREEN		:= \033[1;32m
GREEN 		:= \033[0;32m
B_BLUE 		:= \033[1;34m
BLUE 		:= \033[0;34m
PURPLE		:= \033[0;35m
B_PURPLE	:= \033[1;35m

OBJS = $(SRCS:.c=.o)
GNL_OBJS = 		./srcs/get_next_line/get_next_line.o \
				./srcs/get_next_line/get_next_line_utils.o
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: gnl $(NAME)

%.o: %.c
# @echo "$(B_GREEN)Compiling: $(GREEN)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;36m•\033[0m\c"


gnl:
	@$(MAKE) -C $(GNL)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(GNL_OBJS)

bonus : $(BONUS_OBJS) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
# @echo "$(B_RED)🧹 Cleaning: $(RED) libft object files $(NC)"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(GNL) fclean
	@echo "\033[0;33m•\033[0;33m\c"

fclean: clean
# @echo "$(B_RED)🧹 Cleaning: $(RED) $(NAME) $(NC)"
	@rm -f $(NAME)
	@echo "\033[0;33m•\033[0;33m\c"


re: fclean all

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
# 	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re bonus
