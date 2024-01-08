NAME	= megaphone

SRC		= megaphone.cpp
OBJ		= $(SRC:.cpp=.o)

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

CY		= \033[36;1m
GR		= \033[32;1m
RE		= \033[31;1m
RC		= \033[0m

all: $(NAME)

$(NAME): $(SRC)
	@printf "$(CY)Generating $(NAME)...$(RC)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC)
	@printf "$(GR)Done!$(RC)\n"

clean:
	@printf "$(RE)No files to remove.$(RC)\n"

fclean:
	@rm -f $(NAME)
	@printf "$(RE)$(NAME) removed!$(RC)\n"

re: fclean all

.PHONY: all clean fclean re
