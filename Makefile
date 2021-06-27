INCLUDE := $(INCLUDE) /usr/local/opt/libunwind-headers/include

CXXFLAGS := \
	-O0 -g -Wall \
	$(addprefix -I,$(INCLUDE)) \
	$(addprefix -L,$(LIB))

ifeq ($(shell uname), Linux)
	LDLIBS := -lunwind
endif

TARGETS := \
	backtrace

all: $(TARGETS)

run: all
	./backtrace

clean:
	rm -rf $(TARGETS) *.dSYM
