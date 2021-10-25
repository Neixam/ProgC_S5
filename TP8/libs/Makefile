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
CFLAGS  =	-ansi -pedantic -Wall
LIBCC	=	ar rs
EXEC	=	libstack.a

INC_PATH=	includes/
SRC		=	Stack.c \
			
SRC_PATH= 	$(shell find src -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
OBJ_PATH=	obj/
OBJ		=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

#  Compilation
$(EXEC)				:	$(OBJ)
	@echo "${purple}Compilation $@ ...${neutral}"
	@$(LIBCC) $@ $^
	@echo " ${green}END${neutral}"

$(OBJ_PATH)Stack.o	:	$(INC_PATH)Stack.h

$(OBJ_PATH)%.o		:	%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${cyan}Compilation $@ ...${neutral}\c"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH)
	@echo " ${green}END${neutral}"

#  Rules
all			:	$(EXEC)

clean		:
	@echo "${red}Deleting $(EXEC) objects ...${neutral}\c"
	@/bin/rm -rf $(OBJ)
	@echo " ${green}END${neutral}"

mrproper	:	clean
	@echo "${red}Uninstall $(EXEC) ...${neutral}\c"
	@/bin/rm -rf $(EXEC) $(OBJ_PATH)
	@echo " ${green}END${neutral}"

re			:	mrproper all
