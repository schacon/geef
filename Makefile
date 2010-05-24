OTPROOT=/Users/schacon/otp_src_R13B03
INCLUDES = -I$(OTPROOT)/erts/emulator/beam/

# OS X flags.
GCCFLAGS = -O3 -fPIC -bundle -flat_namespace -undefined suppress -fno-common -Wall -m32

# Linux Flags
#GCCFLAGS = -O3 -fPIC -shared -fno-common -Wall

CFLAGS = $(GCCFLAGS) $(INCLUDES)
LDFLAGS = $(GCCFLAGS) $(LIBS)

OBJECTS = geef.o

DRIVER = geef.so
BEAM = geef.beam

all: $(DRIVER) $(BEAM)

clean: 
	rm -f *.o *.beam $(DRIVER)
	
$(DRIVER): $(OBJECTS)
	gcc -o $@ $^ $(LDFLAGS)
	
$(BEAM): geef.erl
	erlc $^

