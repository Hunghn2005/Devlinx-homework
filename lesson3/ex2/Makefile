CC = gcc
TARGET = exec_env

all: $(TARGET)

$(TARGET): exec_env.c
	$(CC) exec_env.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
