SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -g -std=c++17 -pedantic $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

# rule for main
main: mainexe
	$(RM) *.o

mainexe: main.o array.o
	$(CXX) -o main $^ $(LDFLAGS)
	
