# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 20:07:00 by rnugroho          #+#    #+#              #
#    Updated: 2018/03/21 21:29:59 by rnugroho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= asm
NAME_CW:= corewar
FILE_A:= ft_asm
FILE_CW:= ft_corewar 
FILES:= 

# ----- Libft ------
LFTDIR:=./libft
# ==================

# ------------------
COMPILER:=clang
LINKER:=ar rc
SRCPATH:=src/
HDRPATH:=include/
CCHPATH:=obj/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
CFLAGS:=-Wall -Wextra $(IFLAGS)
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
SRC_CW:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_CW)))
SRC_A:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_A)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
OBJ_A:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILE_A)))
OBJ_CW:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILE_CW)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_A)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRCPATH)$(FILE_A).c -o $(NAME)
	@echo $(GREEN) " - OK" $(EOC)

$(NAME_CW): $(OBJ) $(OBJ_CW)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRC_CW) -o $(NAME_CW)
	@echo $(GREEN) " - OK" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_CW)
	@rm -rf $(NAME).dSYM/
	@rm -rf $(NAME_CW).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

debug: $(NAME) $(NAME_CW)
	@$(COMPILER) -g $(IFLAGS) $(SRC_A) $(SRC) $(LFLAGS) -o checker
	@$(COMPILER) -g $(IFLAGS) $(SRC_CW) $(SRC) $(LFLAGS) -o push_swap

norm:
	@norminette $(SRC) $(HDRPATH) | grep -v	Norme -B1 || true
	@cd $(LFTDIR) && $(MAKE) norm

norm2:
	@sh ./norm/norm.sh

.PHONY: all clean fclean re test norme test_ch test_pw debug check
