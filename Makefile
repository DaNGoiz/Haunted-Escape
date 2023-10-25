CXX = g++
CXXFLAGS = -std=c++11
LDFLAGS =

SRCS = get_map.cpp set_map.cpp generate_map.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = my_program

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
