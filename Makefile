CC = g++
CFLAGS = -c --std=c++14
LFLAGS = -Wall
INFLAGS = -I/usr/include/cppcon
LIBFLAGS = -L/usr/lib/x86_64-linux-gnu -lmysqlcppconn

OBJS += main.o  
OBJS += security_staff.o
OBJS += vehicle_records.o

TEST_OBJS += test_default.o 
TEST_OBJS += security_staff.o 
TEST_OBJS += test_security_staff.o
TEST_OBJS += vehicle_records.o 
TEST_OBJS += test_vehicle_records.o

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main $(LIBFLAGS)

test : $(TEST_OBJS)
	$(CC) $(LFLAGS) $(TEST_OBJS) -o test $(LIBFLAGS)

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp 

security_staff.o : security_staff.cpp security_staff.hpp
	$(CC) $(CFLAGS) $(INFLAGS) security_staff.cpp

vehicle_records.o : vehicle_records.cpp vehicle_records.hpp
	$(CC) $(CFLAGS) $(INFLAGS) vehicle_records.cpp


#-----------UNIT TESTS----------------------------------------

test_default.o : test_default.cpp
	$(CC) $(CFLAGS) test_default.cpp 

test_security_staff.o : test_security_staff.cpp security_staff.hpp
	$(CC) $(CFLAGS) test_security_staff.cpp

test_vehicle_records.o : test_vehicle_records.cpp vehicle_records.hpp
	$(CC) $(CFLAGS) test_vehicle_records.cpp



#--------------------------------------------------------------

run :
	./main

run_test:
	./test


clean :
	rm *.o main

clean_test:
	rm *.o test
	

