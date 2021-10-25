#	Auteur       : Bourennane Amine
#	Creation     : 14-12-2020
#	Modification : 14-12-2020


#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc
CFLAGS  =	-ansi -pedantic -Wall
EXEC	=	larger_file

INC_PATH=	includes/
SRC		=	Main.c \
			Mystrdup.c \
			File.c \
			
SRC_PATH= 	$(shell find src -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
OBJ_PATH=	obj/
OBJ		=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))
MMAX_FD	=	MAX_FD=$(shell ulimit -n)

#  Compilation
$(EXEC)				:	$(OBJ)
	@echo "${purple}Compilation $@ ...${neutral}\c"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo " ${green}END${neutral}"

$(OBJ_PATH)Main.o		:	$(INC_PATH)File.h

$(OBJ_PATH)File.o		:	$(INC_PATH)File.h $(INC_PATH)Mystrdup.h

$(OBJ_PATH)Mystrdup.o	:	$(INC_PATH)Mystrdup.h

$(OBJ_PATH)%.o		:	%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${cyan}Compilation $@ ...${neutral}\c"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH) -D$(MMAX_FD)
	@echo " ${green}END${neutral}"

#  Rules
all			:	$(EXEC)

clean		:
	@echo "${red}Deleting objects ...${neutral}\c"
	@/bin/rm -rf $(OBJ)
	@echo " ${green}END${neutral}"

mrproper	:	clean
	@echo "${red}Uninstall project ...${neutral}\c"
	@/bin/rm -rf $(EXEC) $(OBJ_PATH)
	@echo " ${green}END${neutral}"

re			:	mrproper all
