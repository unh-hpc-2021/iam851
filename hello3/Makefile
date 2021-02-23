CXX = g++
CXXFLAGS = -Wall

hello: hello.o greeting.o factorial.o
	$(CXX) hello.o greeting.o factorial.o -o hello

hello.o: hello.cxx
	$(CXX) $(CXXFLAGS) -c hello.cxx

greeting.o: greeting.cxx
	$(CXX) $(CXXFLAGS) -c greeting.cxx

factorial.o: factorial.cxx
	$(CXX) $(CXXFLAGS) -c factorial.cxx

