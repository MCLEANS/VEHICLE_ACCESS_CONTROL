CC = g++
CFLAGS = -c --std=c++14
LFLAGS = -Wall
INFLAGS = -I/usr/include/cppcon
LIBFLAGS = -L/usr/lib/x86_64-linux-gnu -lmysqlcppconn

OBJS += main.o  
OBJS += security_staff.o
OBJS += vehicle_records.o
OBJS += db_connection.o
OBJS += access_logs.o

TEST_OBJS += test_default.o 
TEST_OBJS += security_staff.o 
TEST_OBJS += vehicle_records.o 
TEST_OBJS += db_connection.o
TEST_OBJS += access_logs.o
TEST_OBJS += test_security_staff.o
TEST_OBJS += test_vehicle_records.o
TEST_OBJS += test_db_connection.o
TEST_OBJS += test_access_logs.o



all : $(OBJS)
	@echo "---------------linking---------------------"
	$(CC) $(LFLAGS) $(OBJS) -o main $(LIBFLAGS)

test : $(TEST_OBJS)
	@echo "---------------linking tests---------------------"
	$(CC) $(LFLAGS) $(TEST_OBJS) -o test $(LIBFLAGS)

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp 

security_staff.o : security_staff.cpp security_staff.hpp
	$(CC) $(CFLAGS) $(INFLAGS) security_staff.cpp

vehicle_records.o : vehicle_records.cpp vehicle_records.hpp
	$(CC) $(CFLAGS) $(INFLAGS) vehicle_records.cpp

db_connection.o : db_connection.cpp db_connection.hpp
	$(CC) $(CFLAGS) $(INFLAGS) db_connection.cpp

access_logs.o : access_logs.cpp access_logs.hpp
	$(CC) $(CFLAGS) $(INFLAGS) access_logs.cpp

#-----------UNIT TESTS----------------------------------------

test_default.o : test_default.cpp
	@echo "--------compiling required source files------------"
	$(CC) $(CFLAGS) test_default.cpp 

test_security_staff.o : test_security_staff.cpp security_staff.hpp
	$(CC) $(CFLAGS) test_security_staff.cpp

test_vehicle_records.o : test_vehicle_records.cpp vehicle_records.hpp
	$(CC) $(CFLAGS) test_vehicle_records.cpp

test_db_connection.o : test_db_connection.cpp db_connection.hpp
	$(CC) $(CFLAGS) test_db_connection.cpp

test_access_logs.o : test_access_logs.cpp access_logs.hpp
	$(CC) $(CFLAGS) test_access_logs.cpp



#--------------------------------------------------------------

run :
	./main

run_test:
	./test


clean :
	@echo "-----------------cleaning--------------"
	rm *.o main

clean_test:
	@echo "-----------------cleaning test build files--------------"
	rm *.o test
	

