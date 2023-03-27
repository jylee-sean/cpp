CC = g++
CFLAGS= -std=c++11 -Wall -O2

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^
	rm *.o
$(OBJS) : $(SRC)
	$(CC) -c ${CFLAGS} $^



