#
TOPDIR = ../../..
#
include $(TOPDIR)/make.inc

#
INCS = -I"$(TOPDIR)/inc"
LIBS = -L"$(TOPDIR)/lib"
CFLAGS +=
CXXFLAGS += $(INCS)
LDFLAGS += $(LIBS)

#
OBJ = test_search.o
BIN = test_search.exe
RC  =
RES = ${RC:.rc=.res}
#
HEADER = $(INCDIR)/adt/uadt.h    \
         $(INCDIR)/adt/usearch.h \

#
all: $(BIN)

#
$(BIN) : $(OBJ) $(RES)
	$(CXX) -o $(BIN) $^ $(LIBS) $(RES)

#
%.o : %.cpp $(HEADER)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCS)

#
.PHONY : test
test:
	$(WINE) ./$(BIN)

.PHONY : clean
clean :
	${RM} ${OBJ} ${BIN} $(RES)
