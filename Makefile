IDIR = include
CC = g++
CFLAGS = -I$(IDIR)

ODIR = obj
LDIR =../lib

LIBS=-lm -lncurses

_DEPS=Sorting.h BubbleSort.h InsertionSort.h SelectionSort.h MergeSort.h PancakeSort.h StrandSort.h QuickSort.h HeapSort.h ShellSort.h TimSort.h
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o Sorting.o BubbleSort.o InsertionSort.o SelectionSort.o MergeSort.o PancakeSort.o StrandSort.o QuickSort.o HeapSort.o ShellSort.o TimSort.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

run: all
	./all
