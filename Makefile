CC = gcc
PROGNAME = Sudoku
HEADERS = programme.h
SOURCES = main.c programme.c
OBJ = $(SOURCES:.c=.o)

$(PROGNAME) : $(OBJ)
	$(CC) $(OBJ) -o $(PROGNAME)

%.o : %.c $(HEADERS)
	$(CC) -c $<

clean : @$(RM) $(OBJ) $(PROGNAME)