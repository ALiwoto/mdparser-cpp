
CFLAGS := -Wall -Wextra -O2 -ggdb3 -I../src
CXXFLAGS := -Wall -Wextra -O2 -ggdb3 -I../src

CXX_TESTS := \
	static_helpers

all: $(CXX_TESTS:=.test)

runtests: $(CXX_TESTS:=__do_test)

$(CXX_TESTS:=.o): $(CXX_TESTS:=.cpp)
	$(CXX) $(CXXFLAGS) $(^) -c -o $(@)

$(CXX_TESTS:=.test): $(CXX_TESTS:=.o)
	$(CXX) $(CXXFLAGS) $(^) -o $(@)

$(CXX_TESTS:=__do_test): $(CXX_TESTS:=.test)
	./$(@:%__do_test=%.test)

clean:
	@rm -vf $(CXX_TESTS:=.test) $(CXX_TESTS:=.o)

.PHONY: $(CXX_TESTS:=__do_test)
