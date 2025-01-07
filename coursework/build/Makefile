CC=gcc
CCFLAGS=-Wall
LOG_FLAGS=-DLOG_ON -DLOG_W 
# -Dимя_макроса
DEBUG_FLAGS=-g -O0 
# -g включить отладочную информацию -O0 минимальная оптимизация
CLEAN=rm -f
PROGRAMM_NAME=sensor
OBJECT_FILES=*.o
SOURCE_DIR=../src/
SOURCE_FILES=$(SOURCE_DIR)sensor.c \
	$(SOURCE_DIR)menu.c \
	$(SOURCE_DIR)temp_functions.c

all: clean $(PROGRAMM_NAME)

$(PROGRAMM_NAME): $(OBJECT_FILES)
	$(CC) $(CCFLAGS) $(LOG_FLAGS) $(DEBUG_FLAGS) $^ -o $@ 
# $@ - текущая цель $^ - список её зависимостей

$(OBJECT_FILES): $(SOURCE_FILES)
	$(CC) $(CCFLAGS) $(LOG_FLAGS) $(DEBUG_FLAGS) -c $^

clean:
	$(CLEAN) *.o $(PROGRAMM_NAME)
