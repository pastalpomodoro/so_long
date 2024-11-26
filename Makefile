NAME= so_long

CC= cc
FLAG= -Wall -Werror -Wextra -g3

FILE= player.c so_long.c get_next_line.c get_next_line_utils.c parsing.c
OBJ=$(FILE:.c=.o)

LIBFT_DIR=../../cercle_1/libft
LIBFT_LIB=../../cercle_1/libft/libft.a

MLX_DIR= ../../minilibx-linux
MLX_LIB=$(MLX_DIR)/libmlx.a
LIBS= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all:$(NAME)

$(NAME):$(OBJ) $(LIBFT_LIB)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(MLX_LIB) $(LIBS) $(LIBFT_LIB)
%.o:%.c
	$(CC) $(FLAG) -c $(FILE)
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
fclean:clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
re:fclean all

.PHONY: all clean fclean re