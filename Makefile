CXXFLAGS := \
	-O0 -g -Wall \
	-march=native -mtune=native \
	-I/usr/local/opt/libunwind-headers/include

LDFLAGS := -lunwind

TARGETS := \
	backtrace

all: $(TARGETS)

run: all
	./backtrace

clean:
	rm -rf $(TARGETS) *.dSYM
