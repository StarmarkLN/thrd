a.out: main.cpp
	g++ -std=c++17 -O2 -Wall -pedantic -pthread  main.cpp && ./a.out

clean :
	rm *.out

