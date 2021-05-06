OBJS = main.o appointment.o calendar.o day.o reminder.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

calendar: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o calendar

main.o: main.o appointment.h calendar.h day.h reminder.h
	$(CC) $(CFLAGS) main.cpp

appointment.o: appointment.cpp appointment.h reminder.h
	$(CC) $(CFLAGS) appointment.cpp

calendar.o: calendar.cpp calendar.h day.h
	$(CC) $(CFLAGS) calendar.cpp

day.o: day.cpp day.h reminder.h
	$(CC) $(CFLAGS) day.cpp

reminder.o: reminder.cpp reminder.h
	$(CC) $(CFLAGS) reminder.cpp

clean:
	rm *.o calendar