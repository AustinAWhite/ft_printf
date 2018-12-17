NAME	=	libftprintf.a
CFLAGS	=	-Wall -Wextra -Werror
HEADER	=	includes/ft_printf.h
_FILES	=	convert print_out ft_printf handle_alpha handle_numeric out util
_LIBFT	=	ft_atoi ft_bzero ft_isdigit ft_memset ft_putchar \
			ft_strjoin ft_strlen ft_strnew ft_toupper ft_strcmp  ft_tolower ft_strsub ft_strchr
LIBFT	=	$(addprefix libft/, $(_LIBFT))
LIBSRC	=	$(addsuffix .c, $(LIBFT))
FILES	=	$(addprefix srcs/, $(_FILES))
SRC		=	$(addsuffix .c, $(FILES))
OBJ		=	$(addsuffix .o, $(_FILES))
LIBOBJ	=	$(addsuffix .o, $(_LIBFT))	

all: $(NAME)

$(NAME):
	gcc -c -w $(SRC) $(LIBSRC) -I $(HEADER) -I libft/libft.h && ar rc $(NAME) $(OBJ) $(LIBOBJ) && ranlib $(NAME) 
	#gcc -c -w $(SRC) $(LIBSRC) -I $(HEADER) -I libft/libft.h && ar rc $(NAME) $(OBJ) $(LIBOBJ) && ranlib $(NAME) 

clean:
	/bin/rm -f $(OBJ) $(LIBOBJ) 

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all