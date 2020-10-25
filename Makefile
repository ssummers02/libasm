NAME=libasm.a

OBJECTS = $(SRCS:.s=.o)

INCLUDES=./
ACC = @nasm -f macho64

FILES = $(wildcard $(INCLUDES)/*.s)
FILES.O = $(addprefix $(INCLUDES)/, $(FILES:.s=.o))


.PHONY : all clean fclean re bonus test

all: $(NAME) $(FILES.O)

$(NAME): $(FILES.O)
		ar rcs $(NAME) $?

$(FILES.O): $(INCLUDES)/%.o: %.s libasm.h
	$(ACC)  $< -o $@

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: all
	 gcc -Wall -Wextra -Werror main.c -I test1.c -I libasm.h libasm.a -o test
	./test
test_clean: fclean
	rm test
	rm write.txt