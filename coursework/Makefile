all: sensor

sensor: sensor.o temp_api.o
	gcc sensor.o temp_api.o -o sensor

sensor.o: sensor.c
	gcc -c sensor.c

temp_api.o: temp_api.c
	gcc -c temp_api.c
	
clean:
	rm *.o sensor
