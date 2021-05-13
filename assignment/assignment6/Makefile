SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -g -std=c++2a -pedantic $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

# rule for main
main: mainexe
	$(RM) *.o

mainexe: main.o functions.o
	$(CXX) -o main $^ $(LDFLAGS)
	
