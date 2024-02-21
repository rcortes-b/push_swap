NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEAD = push_swap.h

SRCS = push_swap.c check_all.c instructions.c instructions2.c special_sort.c special_sort2.c algorithm.c steps.c aux_for_B.c sort.c sort2.c algorithm2.c

LIB1_SRCS = libft/libft.a

OBJS = $(SRCS:.c=.o)
#OBJS_explicit = push_swap.o check_all.o instructions.o instructions2.o special_sort.o special_sort2.o algorithm.o steps.o aux_for_B.o sort.o sort2.o algorithm2.o

#DEPS = $(SRCS:.c=.d)

all : $(NAME)

%.o : %.c Makefile push_swap.h
	$(CC) $(FLAGS) -c $< -o $@
#-MMD

#-include $(DEPS)

$(NAME) : $(OBJS) 
	make bonus -C libft
	$(CC) $(FLAGS) $(LIB1_SRCS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re

### Learning ###
#rule : DEPS 
#	terminal commands
#
##push_swap : $(SRCS) Makefile push_swap.h
##	gcc push_swap.c main.c -o push_swap
#
#$(SRCS) : 