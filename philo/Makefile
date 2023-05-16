# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 10:06:53 by ohalim            #+#    #+#              #
#    Updated: 2023/05/16 05:22:39 by ohalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colours
COLOUR_GREEN	=		\033[0;1;3;36m
COLOUR_RED		=		\033[0;1;3;91m
COLOUR_BLUE		=		\033[0;34m
COLOUR_YELLOW 	=		\033[0;33m
COLOUR_GREY		=		\033[0;1;3;90m
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

SRCS			=		philo.c	parsing_utils.c	parsing.c	init_utils.c	\
						init.c	main_thread_utils.c

OBJS			=		$(addprefix srcs/,$(SRCS:.c=.o))

all				:		$(NAME)

%.o				:		%.c
						$(CC) $(CFLAGS) -c $< -o $@
						@printf $(UP)$(CUT)
						@printf "$(COLOUR_GREY)~ Compiling...[$<]$(COLOUR_END)"
						@echo
						@printf "⌛"
						@sleep 0.3
						@printf ⏳
						@sleep 0.2

$(NAME)			:		$(OBJS)
						@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
						@echo
						@printf $(UP)$(CUT)
						@echo
						@echo "$(COLOUR_GREEN)~ Finished...[$(NAME)] ✅$(COLOUR_END)"

clean			:
						@$(RM) $(OBJS) 
						@echo "$(COLOUR_RED)~ Deleted...[$(OBJS)] 🗑️♻️$(COLOUR_END)"

fclean			:		
						@$(RM) $(OBJS) 
						@echo "$(COLOUR_RED)- Deleted...[$(OBJS)] 🗑️♻️$(COLOUR_END)"
						@echo
						@echo "$(COLOUR_RED)- Deleted...[$(NAME)] 🗑️♻️$(COLOUR_END)"
						@$(RM) $(NAME)

re				:		fclean	all

.PHONY			: 		all		clean		fclean		re
