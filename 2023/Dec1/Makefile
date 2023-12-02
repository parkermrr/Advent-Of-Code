all:
	clang main.c -o dec1
	./dec1 in.txt
clean:
	rm dec1
	rm dec1debug
debug:
	clang main.c -o dec1debug -g
	lldb dec1debug test.txt

