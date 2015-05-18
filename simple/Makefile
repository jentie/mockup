#
#	mockup - run Arduino sketch on PC
#
# 	Linux version of Makefile
# 

mockup: Blink/Blink.ino mockup.c
	ln -f -s Blink/Blink.ino ./blink.c
	gcc -o mockup blink.c mockup.c
clean: 
	rm -f mockup
