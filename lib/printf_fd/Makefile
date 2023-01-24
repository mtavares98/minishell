# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 14:39:43 by mtavares          #+#    #+#              #
#    Updated: 2023/01/23 17:40:40 by mtavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(foreach dir,$(SRCS_DIR),$(wildcard $(dir)/*.c))

SRCS_DIR	=	srcs

OBJS		=	$(subst $(SRCS_DIR),$(OBJS_DIR),$(SRCS:.c=.o))

OBJS_DIR	=	objs

NAME		=	libprintf_fd.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

AR			=	ar rcs

all:		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CFLAGS) $() -c $< -o $@

$(NAME):	$(OBJS)
		@$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re