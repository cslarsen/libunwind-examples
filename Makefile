CXXFLAGS := \
	-std=c++14 \
	-O0 -g -Wall \
	-march=native -mtune=native \
	-I/usr/local/opt/libunwind-headers/include

TARGETS := \
	backtrace

all: $(TARGETS)

run: all
	./backtrace

clean:
	rm -rf $(TARGETS) *.dSYM
