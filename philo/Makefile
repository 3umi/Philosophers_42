# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 10:06:53 by ohalim            #+#    #+#              #
#    Updated: 2023/05/11 21:42:27 by ohalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colours
COLOUR_GREEN	=		\033[0;32m
COLOUR_RED		=		\033[0;31m
COLOUR_BLUE		=		\033[0;34m
COLOUR_YELLOW 	=		\033[0;33m
COLOUR_GREY		=		'\033[2;37m'
COLOUR_END		=		\033[0m

#Fonts
ITALIC			=		'\033[3m'
FONT_END		=		'\033[0m'

#styling
UP				=		"\033[A"
CUT				=		"\033[K"

NAME			=		philo

CC				=		cc

CFLAGS			=		-Wall -Wextra -Werror
#-fsanitize=thread -g3

RM				=		rm -f

LIBFT_PATH		=		includes/libft/

LIBFT_LIB		=		$(LIBFT_PATH)libft.a

SRCS			=		philo.c	parsing_utils.c parsing.c init_utils.c init.c main_thread_utils.c

OBJS			=		$(addprefix srcs/,$(SRCS:.c=.o))


all				:		MAKE_LIBS $(NAME)

%.o				:		%.c
						$(CC) $(CFLAGS) -c $< -o $@
						@printf $(UP)$(CUT)
						@echo "$(COLOUR_BLUE)- Compiling...[$<]$(COLOUR_END)"

MAKE_LIBS		:
						@make -C $(LIBFT_PATH) all
						@echo

$(NAME)			:		$(OBJS)
						@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
						@echo "$(COLOUR_GREEN)- Finished...[$(NAME)] ✅🥳$(COLOUR_END)"

clean			:
						@make -C $(LIBFT_PATH) clean
						@echo
						@$(RM) $(OBJS) 
						@echo "$(COLOUR_RED)- Deleted...[$(OBJS)]$(COLOUR_END)"

fclean			:		
						@make -C $(LIBFT_PATH) fclean
						@echo
						@$(RM) $(OBJS) 
						@echo "$(COLOUR_RED)- Deleted...[$(OBJS)]$(COLOUR_END)"
						@echo "$(COLOUR_RED)- Deleted...[$(NAME)] 🥺$(COLOUR_END)"
						@$(RM) $(NAME)

re				:		fclean	all

.PHONY			: 		all		clean		fclean		re
