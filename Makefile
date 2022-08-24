CC = g++
CFLAGS= -std=c++11 -Wall -O2

$(TARGET) : $(OBJS)
	$(CC) -c ${CFLAGS} $(SRC)
	$(CC) -o $@ $(OBJS)
	rm *.o


