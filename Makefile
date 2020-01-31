CC = g++
CFLAGS = -c --std=c++17
LFLAGS = -Wall
OBJS = main.o 
TEST_OBJS = test_default.o security_staff.o test_security_staff.o

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main 

test : $(TEST_OBJS)
	$(CC) $(LFLAGS) $(TEST_OBJS) -o test

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp 

security_staff.o : security_staff.cpp security_staff.hpp
	$(CC) $(CFLAGS) security_staff.cpp


#-----------UNIT TESTS----------------------------------------
test_default.o : test_default.cpp
	$(CC) $(CFLAGS) test_default.cpp 

test_security_staff.o : test_security_staff.cpp security_staff.hpp
	$(CC) $(CFLAGS) test_security_staff.cpp



#--------------------------------------------------------------

run :
	./main

run_test:
	./test


clean :
	rm *.o main

clean_test:
	rm *.o test
	

