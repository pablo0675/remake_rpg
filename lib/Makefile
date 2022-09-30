##
## MY_LIB PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CPPFLAGS = -I include

## ===========================[VAR]===========================

ARRAY 		=		array_gestion/

PRINTF  	=		printf_gestion/

STR 		=		str_gestion/

CONVERTOR 	=		convertor_gestion/

## ===========================[PATH]===========================

## 			array_gestion 		##

ARRAY_SRC		=	$(ARRAY)free_array.c			\
					$(ARRAY)print_array.c			\
					$(ARRAY)array_cat.c				\

##          convertor_gestion 	##

CONVERTOR_SRC	=	$(CONVERTOR)my_atoi.c			\
					$(CONVERTOR)my_str_to_array.c	\

## 			my_printf			##
PRINTF_SRC		=	$(PRINTF)my_print_free.c		\
					$(PRINTF)my_printf.c			\
					$(PRINTF)my_put_nbr.c			\
					$(PRINTF)my_putchar.c			\
					$(PRINTF)my_putstr.c			\

##   		str_gestion			##
STR_SRC			=	$(STR)my_strcat.c				\
					$(STR)my_strcmp.c				\
					$(STR)my_strcpy.c				\
					$(STR)my_strlen.c				\

SRC				=	$(ARRAY_SRC)			\
					$(CONVERTOR_SRC)		\
					$(PRINTF_SRC)			\
					$(STR_SRC)
OBJ	=	$(SRC:.c=.o)

NAME	=	libc.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm $(OBJ)
clean:
	rm -f $(OBJ)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: fclean all clean
