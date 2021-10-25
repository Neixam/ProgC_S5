# Variable
purple = \033[0;35m
cyan = \033[0;36m
green = \033[0;32m
neutral = \033[0m
red = \033[31m

INC_PATH = includes/
CC = gcc
EXEC = porte_clef
CLAGS = -ansi -pedantic -Wall
SRC = main.c \

SRC_PATH = $(shell find src -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

# Compilation
$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_PATH)main.o : $(INC_PATH)code.h 

$(OBJ_PATH)%.o : %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH)

# Rules
all : $(EXEC)

clean :
	@echo "${red}Deleted objects ...${neutral}"
	@/bin/rm -rf $(OBJ_PATH)
	@echo "${green}END${neutral}"

fclean : clean
	@echo "${red}Uninstall project ...${neutral}"
	@/bin/rm -rf $(EXEC)
	@echo "${green}END${neutral}"

re : fclean all
