CXX = g++
CXXFLAGS = -Wall

hello: hello.o greeting.o factorial.o
	$(CXX) $^ -o $@

hello.o: hello.cxx
	$(CXX) $(CXXFLAGS) -c $<

greeting.o: greeting.cxx
	$(CXX) $(CXXFLAGS) -c $<

factorial.o: factorial.cxx
	$(CXX) $(CXXFLAGS) -c $<

