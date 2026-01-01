

CC=gcc
CFLAGS=-Wall -g
LIB=libwordsgenerator
BINS=$(LIB).so $(LIB).a test

all: $(BINS)

%: %.c $(LIB).a
	$(CC) $(CFLAGS) $< -o $@ $(LIB).a

%.o: %.c
	$(CC) $(CFLASG) -c $<

lib%.a: %.o
	ar -cvrs $@ $<

lib%.so: %.c
	$(CC) $(CFLAGS) -shared -fPIC $< -o $@

clean:
	rm -rf *.dSYM *.so *.a *.o $(BINS)