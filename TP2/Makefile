#  Auteur       : Bourennane Amine
#  Creation     : 06-10-2020
#  Modification : 06-10-2020


# Variable
CC 			=	gcc
CFLAGS		=	-ansi -pedantic -Wall

ifneq (clean, $(firstword $(MAKECMDGOALS)))
    ifneq (all, $(firstword $(MAKECMDGOALS)))
        EXEC := $(wordlist 1, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
    endif
endif

SRC			:=	$(EXEC).c
OBJ			=	$(SRC:.c=.o)

# Compilation
$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)  : $(SRC)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

# Rule
all		:
	@make ex1 
	@make ex2
	@make mirroir
	@make blasay
	@make ex5

clean :
	/bin/rm -f *.o
