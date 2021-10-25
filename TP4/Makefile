# Variable
purple = \033[0;35m
cyan = \033[0;36m
green = \033[0;32m
neutral = \033[0m
red = \033[31m

INC_PATH = includes/
CC = gcc
EXEC = alchemist
CLAGS = -ansi -pedantic -Wall
SRC	=	Player.c \
		Main.c \
		Location.c \
		Display.c \
		Cell.c \
		Board.c \

SRC_PATH = $(shell find src -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

# Compilation
$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_PATH)Main.o : $(INC_PATH)Board.h 

$(OBJ_PATH)Location.o : $(INC_PATH)Location.h 

$(OBJ_PATH)Display.o : $(INC_PATH)Display.h 

$(OBJ_PATH)Cell.o : $(INC_PATH)Cell.h $(INC_PATH)Board.h 

$(OBJ_PATH)Board.o : $(INC_PATH)Board.h $(INC_PATH)Display.h $(INC_PATH)Location.h $(INC_PATH)Player.h $(INC_PATH)Cell.h 

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
