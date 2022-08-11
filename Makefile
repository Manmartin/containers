NAME = tests

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INC = -I .
NSPACE = ft


SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -D NAMESPACE=$(NSPACE) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) -D NAMESPACE=$(NSPACE) $^ -o $@

std: NSPACE = std
std: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) -D NAMESPACE=$(NSPACE)  $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf std

re: fclean all
	
.PHONY: all clean fclean re
