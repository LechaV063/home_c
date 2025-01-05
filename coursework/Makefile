all: sensor

sensor: sensor.o temp_functions.o menu.o
	gcc sensor.o temp_functions.o menu.o -o sensor

menu.o: menu.c
	gcc -g3 -c menu.c

sensor.o: sensor.c
	gcc -g3 -c sensor.c

temp_functions.o: temp_functions.c
	gcc -g3 -c temp_functions.c
	
clean:
	rm *.o sensor
