logger: logger.o
	g++ logger.o -o logger

logger.o: logger.cpp
	g++ -c logger.cpp -o logger.o

logger.cpp:
	logger.cpp

driver: driver.o
	g++ driver.o -o driver	

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

driver.cpp: logger
	make logger	

clean:
	rm driver.o driver logger.o logger
