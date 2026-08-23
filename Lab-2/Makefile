CXX = g++
CXXFLAGS = -Wall -std=c++17

OBJS = main.o Calculator.o

calculator: $(OBJS)
	$(CXX) $(OBJS) -o calculator

main.o: main.cpp Calculator.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Calculator.o: Calculator.cpp Calculator.h
	$(CXX) $(CXXFLAGS) -c Calculator.cpp

clean:
	rm -f $(OBJS) calculator