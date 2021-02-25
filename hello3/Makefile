CXX = g++
CXXFLAGS = -Wall

hello: hello.o greeting.o factorial.o
	$(CXX) $^ -o $@

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $<
