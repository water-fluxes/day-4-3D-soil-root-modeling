include Makefile.defs

LIBS = $(LIBRSWMS)
ifeq ($(PARTRACE),1)
	LIBS += $(LIBPARTRACE)
	CPPFLAGS += -DWITH_PARTRACE
endif

.SUFFIXES: .f90 .o .c

all: $(BUILDDIR) $(LIBSPARSKIT) $(PROGRAM)

$(BUILDDIR):
	mkdir -p $@

$(BUILDDIR)/%.o: %.f90
	@echo "compiling f90 file" $<
	cd $(BUILDDIR); $(CPP) $(CPPFLAGS) ../$< ./pp_$< ; $(F90C) $(F90FLAGS) -I../ -c ./pp_$< -o $(@F)

$(PROGRAM): $(BUILDDIR)/Main.o $(LIBS) 
	cd $(BUILDDIR); $(LD) $(LDFLAGS) -o ../$@ $(^F) $(LDLIBS)

$(LIBRSWMS): $(SRC_RSWMS)/*.f90 $(SRC_RSWMS)/*.c $(SRC_RSWMS)/*.h
	cd $(SRC_RSWMS) ; make

$(LIBPARTRACE): $(SRC_PARTRACE)/*.cpp $(SRC_PARTRACE)/*.hpp
	cd $(SRC_PARTRACE) ; make

$(LIBSPARSKIT):
	cd $(SPARSKIT) ; make

run:
	./rswms

.PHONY: clean
clean:
	rm -rf $(BUILDDIR) $(PROGRAM) 

.PHONY: clean_rswms
clean_rswms:
	cd $(SRC_RSWMS) ; make clean

$(BUILDDIR)/Main.o:  $(LIBS)
