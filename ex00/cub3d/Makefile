# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corozco <corozco@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 05:41:03 by corozco           #+#    #+#              #
#    Updated: 2020/02/12 04:15:44 by corozco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D
HEAD := -I./includes/ -I./libft/includes
#HEAD := -I./includes/ -I./minilibx_mms_20191207_beta -I./minilibx_opengl_20191021 -I./libft/includes

CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror

SRC := \
	srcs/main.c \
	srcs/move.c \
	srcs/init_window.c \
	srcs/ft_press.c \
	srcs/gestion_error.c \
	srcs/ft_init_map.c \
	srcs/init_parser.c \
	srcs/conv_map.c \
	srcs/perform_dda.c \
	srcs/raycasting.c \
	srcs/draw.c \
	srcs/sprites_casting.c \
	srcs/open_file.c \
	srcs/bmp.c \

LMLX = -lft -lm -lmlx -framework OpenGL -framework AppKit

OBJS = $(addprefix objs/, $(SRC:.c=.o))

#color
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef



all: $(NAME)

$(NAME): $(OBJS)
	@make -sC ./libft
	@echo ''
	@gcc $(HEAD) $(LMLX) $(OBJS) -o $(NAME) -L./libft -lft
#	@gcc -g3 -fsanitize=address $(HEAD) $(LMLX) $(OBJS) -o $(NAME) -L./libft -lft
	@echo '	 '
	@echo '	......( \_/ ) '
	@echo '	......( o_o ) '
	@echo '	..../""""""""""""\======░ ▒▓▓█D' "$(WARN_COLOR)\t $(NAME)\t$(OK_COLOR)[CREATED]$(NO_COLOR)";
	@echo '	/"""""""""""""""""""\ '
	@echo '	\_@_@_@_@_@_@_@_@_@_/'

objs/%.o: %.c
	@mkdir -p $(dir $@)
	@$(call run_and_test,gcc $(CFLAGS) $(HEAD) -c $< -o $@)

clean:
	@rm -rf $(OBJS) objs
	@make clean -sC libft
	@printf "%b" "$(ERROR_COLOR)\tmake clean\t$(OK_COLOR)[SUCCESS]$(NO_COLOR)\n";
	@make 42

fclean:
	@make fclean -sC libft
	@rm -rf $(NAME) $(OBJS) objs
	@printf "%b" "$(ERROR_COLOR)\tmake fclean\t$(OK_COLOR)[SUCCESS]$(NO_COLOR)\n";

re: fclean all

normi:
	norminette includes
	norminette srcs

quimera:
	@echo '	 _**_**	'
	@echo '	_**___**	'
	@echo '	_**___**_________****	'
	@echo '	_**___**_______**___****	'
	@echo '	_**__**_______*___**___**	'
	@echo '	__**__*______*__**__***__**	'
	@echo '	___**__*____*__**_____**__*	'
	@echo '	____**_**__**_**________**	'
	@echo '	____**___**__**	'
	@echo '	___*___________*	'
	@echo '	__*_____________*	'
	@echo '	_*____0_____0____*	'
	@echo '	_*_______@_______*	'
	@echo '	_*_______________*	'
	@echo '	___*_____v_____*	'
	@echo '	_____**_____** 	Quimera '

42:
	@echo '		© 2020 42corozco'
	@echo '		║▌█║▌│█│║▌║││█║▌║▌║'
