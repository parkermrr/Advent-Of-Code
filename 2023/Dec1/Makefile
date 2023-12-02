all:
	clang main.c -o prob1
	./prob1 in.txt
clean:
	rm prob1
	rm prob1debug
debug:
	clang main.c -o prob1db -g
	lldb prob1db test.txt

