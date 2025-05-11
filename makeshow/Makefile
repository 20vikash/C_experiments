hello: hello.c
	echo "Hello is successfully executed"
	echo "My name is vikash"
	gcc -o hello hello.c

test: hello.c
	echo "Test got executed"
	gcc -o test hello.c

test2: example
	echo "Hello"
	touch test2

example:
	echo "Hi"

hello.c:
	echo "#include<stdio.h>\n int main() {printf(\"Hello world\");}" > hello.c

hi:
	touch hi

clean:
	rm a.out hello.c
