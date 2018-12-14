control: control.o
	gcc -o control control.o
main: write_story.o
	gcc -o write_story write_story.o
control.o: control.c
	gcc -c control.c
main.o: write_story.c
	gcc -c write_story.c
clean:
	rm -f *out *~ *o
