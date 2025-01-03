all: sensor

sensor: sensor.o temp_api.o menu.o
	gcc sensor.o temp_api.o menu.o -o sensor

menu.o: menu.c
	gcc -g3 -c menu.c

sensor.o: sensor.c
	gcc -g3 -c sensor.c

temp_api.o: temp_api.c
	gcc -g3 -c temp_api.c
	
clean:
	rm *.o sensor
