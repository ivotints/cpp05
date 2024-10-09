# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 12:41:50 by ivotints          #+#    #+#              #
#    Updated: 2024/09/11 20:50:36 by ivotints         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bureaucrat
SRCS	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp
OBJ_DIR	= obj
OBJS	= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
CFLAGS	= -Wall -Wextra -Werror -std=c++98
CC		= c++
INCLUDE	= includes/
VPATH	= src/


all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) done

$(OBJ_DIR):
	@mkdir -p $@

run: $(NAME)
	@./$(NAME)

vrun: $(NAME)
	@valgrind --leak-check=full --show-error-list=yes ./$(NAME)

clean:
	@rm -rf $(OBJ_DIR)
#@echo removed $(OBJ_DIR) folder

fclean: clean
	@rm -rf $(NAME)
#@echo removed $(NAME)

re: fclean all

.PHONY: all run vrun clean fclean re

