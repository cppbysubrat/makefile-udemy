SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=%)
OBJS := $(BINS:%=%.o)


all: $(BINS) $(OBJS)

%: %.o
	@echo "Generating binaries"
	g++ $< -o $@

%.o : %.cpp
	@echo "Generating object files"
	g++ -c $< -o $@

clean:
	rm $(BINS) $(OBJS)
