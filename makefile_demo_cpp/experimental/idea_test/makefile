
SRCS := $(wildcard *.cpp)

BINS := $(SRCS:%.cpp=%)
OBJS := $(SRCS:%.cpp=%.o)


#all: ${BINS} $(OBJS)
#all: ${BINS}
all: myio


myio: $(OBJS)
	g++ $^ -o $@

#%:%.o
#	g++ $< -o $@

%.o: %.cpp
	g++ -c $< -o $@


	


clean:
	-rm  $(BINS) $(OBJS)

