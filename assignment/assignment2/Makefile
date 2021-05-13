SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -g -std=c++17 -pedantic $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

# rule for both main and check
all: mainexe checkexe
	$(RM) *.o

# rule for main
main: mainexe
	$(RM) *.o

# rule for check
check: checkexe
	$(RM) *.o

mainexe: main.o functions.o
	$(CXX) -o main $^ $(LDFLAGS)
	
checkexe: check.o functions.o
	$(CXX) -o check $^ $(LDFLAGS)


	
