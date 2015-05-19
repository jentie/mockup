#
#	mockup - run Arduino sketch on PC
#
# 	Linux version of Makefile
# 


# todo - name source sketch once at the beginning


mockup: AnalogInOutSerial/AnalogInOutSerial.ino mockup.c mockup.h
	ln -f -s AnalogInOutSerial/AnalogInOutSerial.ino ./analog.c
	gcc -o mockup analog.c mockup.c
clean: 
	rm -f mockup
	rm -f *~

