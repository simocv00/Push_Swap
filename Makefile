NAME       = push_swap
BONUS_EXE  = checker

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

SRC = push_swap.c get_last_stack.c ra.c rra.c sa.c sort_three.c finde_min.c finde_max.c \
      give_value.c ft_lstsize.c give_target.c pa.c pb.c give_rank.c free_stack.c give_index.c \
      sort_me.c rrb.c rb.c find_less.c rrr.c rr.c is_sorted.c ft_strdup.c handel_error.c sort_five.c \
      split.c count_tokens.c free_tokens.c has_number.c extract_all_tokens.c

OBJ = $(SRC:.c=.o)

BSRC = push_swap_Bonus/mini_push_swap.c \
       push_swap_Bonus/ra.c \
       push_swap_Bonus/rra.c \
       push_swap_Bonus/sa.c \
       push_swap_Bonus/give_value.c \
       push_swap_Bonus/pa.c \
       push_swap_Bonus/pb.c \
       push_swap_Bonus/free_stack.c \
       push_swap_Bonus/rrb.c \
       push_swap_Bonus/rb.c \
       push_swap_Bonus/rrr.c \
       push_swap_Bonus/rr.c \
       push_swap_Bonus/is_sorted.c \
       push_swap_Bonus/ft_strdup.c \
       push_swap_Bonus/handel_error.c \
       push_swap_Bonus/split.c \
       push_swap_Bonus/count_tokens.c \
       push_swap_Bonus/free_tokens.c \
       push_swap_Bonus/has_number.c \
       push_swap_Bonus/extract_all_tokens.c \
       push_swap_Bonus/commond_handel.c \
       push_swap_Bonus/ft_strcmp.c \
       push_swap_Bonus/sb.c \
       push_swap_Bonus/ss.c \
       push_swap_Bonus/ft_lstsize.c \
       push_swap_Bonus/get_next_line/get_next_line.c \
       push_swap_Bonus/get_next_line/get_next_line_utils.c \
       push_swap_Bonus/get_last_stack.c

BOBJ = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS_EXE): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(BONUS_EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

push_swap_Bonus/%.o: push_swap_Bonus/%.c
	$(CC) $(CFLAGS) -Ipush_swap_Bonus -c $< -o $@

push_swap_Bonus/get_next_line/%.o: push_swap_Bonus/get_next_line/%.c
	$(CC) $(CFLAGS) -Ipush_swap_Bonus -Ipush_swap_Bonus/get_next_line -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_EXE)

re: fclean all

.PHONY: all Bonus clean fclean re

Bonus:
	$(MAKE) $(BONUS_EXE)
