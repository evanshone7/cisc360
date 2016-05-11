CC := gcc
CFLAGS := -std=gnu99 -MMD -Wall -Wextra -Werror
# LOADLIBES := -L/usr/local/lib
LDLIBS := -lrt

TARGET := driver-O0
ifdef DEBUG
  CFLAGS += -g
endif
ifdef OPTLEVEL
  CFLAGS += -O$(OPTLEVEL)
  TARGET := driver-O$(OPTLEVEL)
endif
ifdef OPENMP
  CFLAGS += -fopenmp
endif
ifdef CILK
  LDLIBS += -lcilk_plus
endif

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

.PHONY: clean veryclean all

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@
#	-rm -vf $(OBJS)
veryclean : clean
	-rm -vf $(DEPS)

clean :
	-rm -vf $(OBJS) $(wildcard driver-*)

-include $(DEPS)
