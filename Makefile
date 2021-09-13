driver: 
	g++ driver.cpp logger.cpp -o driver

clean:
	rm driver.o driver logger.o savelog.txt
