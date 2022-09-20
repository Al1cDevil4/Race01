flags := -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME := part_of_the_matrix

all: $(NAME)

$(NAME): 
	clang $(flags) -I inc  src/*.c -o $(NAME)

uninstall:
	rm -rf $(NAME) 

clean:
	rm -rf $(NAME) 

reinstall:
	make uninstall
	make all
