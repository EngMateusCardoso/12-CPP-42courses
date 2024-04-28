NAME		= identify

SRC			= main.cpp	\
			Base.cpp

INC			= Base.hpp

OBJ_PATH	= obj/
OBJ			= $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -rf

CY		= \033[36;1m
GR		= \033[32;1m
RE		= \033[31;1m
RC		= \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@printf "$(CY)Generating $(NAME)...$(RC)\n"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@printf "$(GR)Done!$(RC)\n"

$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ) $(OBJ_PATH)
	@printf "$(RE)Objects removed!$(RC)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RE)$(NAME) removed!$(RC)\n"

re: fclean all

.PHONY: all clean fclean re
