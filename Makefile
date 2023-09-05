IDIR=include
CC=g++
CFLAGS= -Wshadow -Winit-self -Wredundant-decls \
		-Wcast-align -Wundef -Wfloat-equal \
		-Winline -Wunreachable-code -Wmissing-declarations \
		-Wmissing-include-dirs -Wswitch-enum -Wswitch-default \
		-Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions \
		-Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body \
		-Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
		-Wmissing-field-initializers -Wnon-virtual-dtor \
		-Woverloaded-virtual -Wpointer-arith -Wsign-promo \
		-Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel \
		-Wtype-limits -Wwrite-strings -D_DEBUG \
		-D_EJUDGE_CLIENT_SIDE -D_EJC -I$(IDIR)	

SDIR=src
ODIR=obj

LIBS=-lm

_DEPS = qsolver.h test.h color_constants.h math_utils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ_M = main.o solver.o math_utils.o
OBJ_M = $(patsubst %,$(ODIR)/%,$(_OBJ_M))

_OBJ_T = test.o solver.o math_utils.o
OBJ_T = $(patsubst %,$(ODIR)/%,$(_OBJ_T))

all: test prog

.PHONY: all clean

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ_T)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

prog: $(OBJ_M)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	

clean:
	rm -f $(ODIR)/*.o $(SDIR)/*~ $(IDIR)/*~