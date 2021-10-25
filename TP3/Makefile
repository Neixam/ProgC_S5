#  Auteur       : Bourennane Amine
#  Creation     : 19-10-2020
#  Modification : 19-10-2020

#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc
CFLAGS  =	-ansi -pedantic -Wall
LDFLAGS =	-lreadline
EXEC	=	rotaluklak

INC_PATH=	includes/
SRC		=	Main.c \
			Parser.c \
			Functionality.c \
			Calc.c \

SRC_PATH= $(shell find src -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
OBJ_PATH=	obj/
OBJ		=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

#  Compilation
$(EXEC)						:	$(OBJ)
	@echo "${purple}Compilation $@ ...${neutral}\c"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo " ${green}END${neutral}"

$(OBJ_PATH)Main.o			:	$(INC_PATH)Parser.h

$(OBJ_PATH)Parser.o			:	$(INC_PATH)Parser.h $(INC_PATH)Functionality.h $(INC_PATH)Calc.h

$(OBJ_PATH)Functionality.o	:	$(INC_PATH)Functionality.h

$(OBJ_PATH)Calc.o			:	$(INC_PATH)Calc.h

$(OBJ_PATH)%.o				:	%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${cyan}Compilation $@ ...${neutral}\c"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH)
	@echo " ${green}END${neutral}"

#  Rules
all			: $(EXEC)

clean		:
	@echo "${red}Deleting objects...${neutral}"
	@/bin/rm -rf $(OBJ_PATH) 
	@echo "${green}END${neutral}"

mrproper	:	clean
	@echo "${red}Uninstall project...${neutral}"
	@/bin/rm -rf $(EXEC)
	@echo "${green}END${neutral}"

re			:	mrproper all
