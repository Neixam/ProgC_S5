#  Auteur       : Bourennane Amine
#  Creation     : 30-09-2020
#  Modification : 30-09-2020

# Variable
CC 			=	gcc
CFLAGS		=	-ansi -pedantic -Wall -pg

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
	@make mytee
	@make pascal
	@make ppcm

clean :
	/bin/rm -f *.o
