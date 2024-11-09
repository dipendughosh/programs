FLAGS = -m32 -g -fno-stack-protector -O0 -no-pie -static

EXES = lab_1

all: clean $(EXES)


$(EXES):
	gcc $(FLAGS) $@.c -o $@

clean:
	rm -f $(EXES)
