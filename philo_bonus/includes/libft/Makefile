# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 18:08:09 by ohalim            #+#    #+#              #
#    Updated: 2023/02/20 16:04:30 by ohalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colours
COLOUR_GREEN	=		\033[0;32m
COLOUR_RED		=		\033[0;31m
COLOUR_BLUE		=		\033[0;34m
COLOUR_YELLOW	=		\033[0;33m
COLOUR_GREY		=		'\033[2;37m'
COLOUR_END		=		\033[0m

#Fonts
ITALIC			=		'\033[3m'
FONT_END		=		'\033[0m'

#styling
UP				=		"\033[A"
CUT				=		"\033[K"

NAME			=		libft.a

SRCS			=	ft_isalpha.c			ft_toupper.c		ft_isdigit.c	ft_tolower.c	ft_isascii.c        \
					ft_strchr.c				ft_isprint.c		ft_strrchr.c	ft_strlen.c		ft_strncmp.c        \
					ft_memset.c				ft_bzero.c			ft_memchr.c		ft_memcpy.c 	ft_strtrim.c  	    \
					ft_memmove.c 			ft_strlcpy.c 		ft_strlcat.c 	ft_atoi.c      	ft_putnbr_fd.c      \
					ft_calloc.c 			ft_strdup.c 		ft_substr.c 	ft_strjoin.c 	ft_putendl_fd.c     \
					ft_split.c				ft_itoa.c 			ft_strmapi.c 	ft_striteri.c 	ft_putchar_fd.c 	\
					ft_putstr_fd.c 			ft_memcmp.c			ft_strnstr.c	ft_isalnum.c	ft_lstdelone.c		\
					ft_lstnew.c				ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c 	ft_lstadd_back.c 	\
					ft_lstclear.c 			ft_lstiter.c 		ft_lstmap.c		ft_putstr.c		ft_putnbr_u.c		\
					ft_putnbr_hexa.c		get_next_line.c		ft_format.c		ft_printf.c		ft_putchar.c		\
					ft_putnbr.c				ft_hex.c

OBJS			=	$(addprefix srcs/,$(SRCS:.c=.o))

CC				=	cc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

.c.o			:
					$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
					@printf $(UP)$(CUT)
					@echo "$(COLOUR_BLUE)- Compiling...[libft/$<]$(COLOUR_END)"

all				: 	$(NAME)

$(NAME)			:	$(OBJS)
					@echo "$(COLOUR_YELLOW)- Creating...[$(NAME)] ⏳$(COLOUR_END)"
					@ar -rc $(NAME) $(OBJS)
					@echo "$(COLOUR_GREEN)- Finished...[$(NAME)] ✅🥳$(COLOUR_END)"
clean			:
					@$(RM) $(OBJS)
					@echo "$(COLOUR_RED)- Deleted...[$(OBJS)]$(COLOUR_END)"

fclean			: 	clean
					@$(RM) $(NAME)
					@echo "$(COLOUR_RED)- Deleted...[$(NAME)] 🥺$(COLOUR_END)"

re				:	fclean all

.PHONY			: 	all clean fclean re
