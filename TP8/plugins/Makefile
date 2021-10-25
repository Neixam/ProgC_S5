#  Auteur       : Bourennane Amine
#  Creation     : 04-01-2021
#  Modification : 04-01-2021

#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc
CFLAGS  =	-ansi -pedantic -Wall -fpic
LBFLAGS	=	-shared -g

SRC		=	Add.c \
			Sub.c \
			Div.c \
			Mul.c \
			Mod.c \
			Exp.c \
            Factorial.c \

LIB_PATH=	libs/
EXEC	=	$(addprefix $(LIB_PATH), $(SRC:.c=.so))
			
SRC_PATH= 	$(shell find src -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
OBJ_PATH=	obj/
OBJ		=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

#  Compilation
$(EXEC)			:	$(OBJ)

$(OBJ_PATH)%.o	:	%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${cyan}Compilation $@ ...${neutral}\c"
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo " ${green}END${neutral}"

$(LIB_PATH)%.so	:	$(OBJ_PATH)%.o
	@mkdir -p $(LIB_PATH)
	@echo "${purple}Compilation $@ ...${neutral}\c"
	@$(CC) $(LBFLAGS) -o $@ $<
	@echo " ${green}END${neutral}"

#  Rules
all			:	$(EXEC)

clean		:
	@echo "${red}Deleting $(subst libs/,,$(EXEC)) objects ...${neutral}\c"
	@/bin/rm -rf $(OBJ)
	@echo " ${green}END${neutral}"

mrproper	:	clean
	@echo "${red}Uninstall $(subst libs/,,$(EXEC)) ...${neutral}\c"
	@/bin/rm -rf $(EXEC) $(OBJ_PATH)
	@echo " ${green}END${neutral}"

re			:	mrproper all
