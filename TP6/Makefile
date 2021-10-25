#  Auteur       : Bourennane Amine
#  Creation     : 10-11-2020
#  Modification : 21-11-2020 


#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc
CFLAGS  =	-ansi -pedantic -Wall -fpic
LBFLAGS	=	-shared -g
LDFLAGS =	-lm -O2 -g
EXEC	=	lib_img.so
LIB_PATH=	lib/

SRC		=	$(EXEC:.so=.c) \
			
SRC_PATH= $(shell find src -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
OBJ_PATH=	obj/
OBJ		=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))
LIB		=	$(LIB_PATH)$(EXEC)

#  Compilation
$(LIB)	:	$(OBJ)
	@mkdir -p $(LIB_PATH)
	@echo "${purple}Compilation $@ ...${neutral}\c"
	@$(CC) $(LBFLAGS) -o $@ $<
	@echo " ${green}END${neutral}"

$(OBJ)				:	$(SRC)

$(OBJ_PATH)%.o		:	%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${cyan}Compilation $@ ...${neutral}\c"
	@$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	@echo " ${green}END${neutral}"


#  Rules
all			:	$(LIB)

clean		:
	@echo "${red}Deleting objects...${neutral}"
	@/bin/rm -rf $(OBJ_PATH) 
	@echo "${green}END${neutral}"

mrproper	:	clean
	@echo "${red}Uninstall library...${neutral}"
	@/bin/rm -rf $(LIB)
	@echo "${green}END${neutral}"

re			:	mrproper all
