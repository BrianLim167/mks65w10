
all: signals.c
	gcc signals.c -o signals
run: all
	./signals
clean:
	rm -f *~
	rm -f *.o
