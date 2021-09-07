driver: driver.o
	g++ driver.o -o driver	

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

driver.cpp:
	driver.cpp

clean:
	rm driver.o driver
