#	Auteur       : Bourennane Amine
#	Creation     : 04-01-2021
#	Modification : 11-01-2021


#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc
CFLAGS  =	-ansi -Wall
LDFLAGS	=	-lreadline -ldl
LBFLAGS	=	-L./libs -lstack
EXEC	=	eap

INC_PATH=	includes/
SRC		=	Main.c \
			Parser.c \
			Plugins.c \
			
SRC_PATH= 	$(shell find src -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
OBJ_PATH=	obj/
OBJ		=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))
LIB		=	libs/libstack.a
LIB_SRC	=	libs/src/Stack.c
LIB_PATH=	libs/includes/
PLUGIN	=	$(subst src,libs,$(foreach plug, $(shell find plugins -name "*.c"), $(plug:.c=.so)))
PLUG_SRC=	$(shell find plugins -name "*.c")

#  Compilation
$(EXEC)				:	$(OBJ) $(PLUGIN) $(LIB)
	@echo "${purple}Compilation $@ ...${neutral}\c"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LBFLAGS) $(LDFLAGS)
	@echo " ${green}END${neutral}"

$(LIB)				:	$(LIB_SRC)
	@make -C libs all

$(PLUGIN)			:	$(PLUG_SRC)
	@make -C plugins all

$(OBJ_PATH)Main.o	:	$(INC_PATH)Plugins.h $(INC_PATH)Parsing.h

$(OBJ_PATH)Parser.o	:	$(INC_PATH)Plugins.h $(INC_PATH)Parsing.h

$(OBJ_PATH)Plugins.o:	$(INC_PATH)Plugins.h

$(OBJ_PATH)%.o		:	%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${cyan}Compilation $@ ...${neutral}\c"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH) -I $(LIB_PATH)
	@echo " ${green}END${neutral}"

#  Rules
all			:	$(EXEC) $(LIB) $(PLUGIN)

clean		:
	@make -C plugins clean
	@make -C libs clean
	@echo "${red}Deleting objects ...${neutral}\c"
	@/bin/rm -rf $(OBJ)
	@echo " ${green}END${neutral}"

mrproper	:	clean
	@make -C plugins mrproper
	@make -C libs mrproper
	@echo "${red}Uninstall project ...${neutral}\c"
	@/bin/rm -rf $(EXEC) $(OBJ_PATH)
	@echo " ${green}END${neutral}"

re			:	mrproper all
