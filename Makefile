SRCS		=	test.cpp

CPP_VERSION	=	-std=c++98

COMPILER	=	clang++

FLAGS		=	-Wextra -Wall -Werror

NAME		=	containers_test

all : $(NAME)

$(NAME) : $(SRC) 
	@$(COMPILER) $(CPP_VERSION) $(FLAGS) $(SRCS) -D MY -o $(NAME)


ft : $(SRC) 
	@$(COMPILER) $(CPP_VERSION) $(FLAGS) $(SRCS) -D MY -o $(NAME) && ./$(NAME) > myout

std : $(SRC)
	@$(COMPILER) $(CPP_VERSION) $(FLAGS) $(SRCS) -o $(NAME) && ./$(NAME) > out

clean :
	@rm -rf $(NAME) myout out *.dSYM .vscode a.out

fclean : clean

re : fclean all

.PHONY: all clean fclean