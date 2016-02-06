CXXFLAGS := \
	-O0 -g -Wall \
	-march=native -mtune=native \
	-I/usr/local/opt/libunwind-headers/include

ifeq ($(shell uname), Linux)
	LDFLAGS := -lunwind
endif

TARGETS := \
	backtrace

all: $(TARGETS)

run: all
	./backtrace

clean:
	rm -rf $(TARGETS) *.dSYM
