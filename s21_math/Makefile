CC = gcc
VALGRIND = valgrind --leak-check=full --quiet

REPORT = report
NULL = /dev/null
GCOV = *.gcov *.info

CFLAGS = -std=c11 -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
OBJFLAGS = 

INC= -I inc
UNITLIBS = -lcheck -lm -lsubunit

SRC = $(wildcard src/*.c)
UNISRC = $(wildcard unit_test/*.c)
LIBSRC = $(filter-out $(MAIN), $(SRC))
HEADERS = $(filter-out $(wildcard inc/check_*.h), $(wildcard inc/*.h))


OBJDIR = out
OBJ = $(patsubst src/%.c, $(OBJDIR)/%.o, $(filter-out $(LIBSRC), $(SRC)))
UNIOBJ = $(patsubst unit_test/%.c, $(OBJDIR)/%.o, $(filter unit_test/%.c, $(UNISRC)))
LIBSOBJ = $(patsubst src/%.c, $(OBJDIR)/%.o, $(LIBSRC))
UNIHEADERS = $(wildcard inc/check_*.h)

LIBSDIR = libs
LIBNAME = s21_math
LIBS = $(LIBSDIR)/$(LIBNAME).a
LIBLINK = $(patsubst $(LIBSDIR)/lib%.a, -l%, $(LIBS))

BUILD = 
UNITARGET = $(BUILD)unit_tests.exe

.PHONY: gcov
gcov:
	$(MAKE) clean
	$(MAKE) coverage
	./$(UNITARGET) > $(NULL) 2> $(NULL)
	lcov -t "$(LIBNAME)" -c -d $(OBJDIR) -o $(LIBNAME).info > $(NULL) 2> $(NULL)
	genhtml -o $(REPORT) $(LIBNAME).info > $(NULL) 2> $(NULL)

.PHONY: coverage
coverage: CFLAGS += --coverage
coverage: $(UNITARGET)

.PHONY: build
build: $(UNITARGET)

.PHONY: release
release: CFLAGS += -O3
release: $(UNITARGET)

.PHONY: debug
debug: CFLAGS += -g
debug: CFLAGS += -O0
debug: $(UNITARGET)

.PHONY: unit
unit: $(UNITARGET)
	./$(UNITARGET)

.PHONY: debug_unit
debug_unit: CFLAGS += -g
debug_unit: $(UNITARGET)
	$(VALGRIND) ./$(UNITARGET)

.PHONY: clean
clean:
	$(RM) ./*.exe $(GCOV) -r $(OBJDIR) $(LIBSDIR)

.PHONY: del_rep
del_report:
	$(RM) -r $(REPORT)

.PHONY: stat_lib
stat_lib: dirs $(LIBS)

.PHONY: dirs
dirs: $(OBJDIR) $(LIBSDIR)

$(UNITARGET): dirs $(filter-out $(LIBSOBJ), $(UNIOBJ)) $(LIBS)
	$(CC) $(INC) $(filter-out $(LIBSOBJ), $(UNIOBJ)) $(LIBS) -o $@ $(CFLAGS) $(UNITLIBS)

$(OBJDIR):
	mkdir -p $@

$(LIBSDIR):
	mkdir -p $@

$(LIBS): $(LIBSOBJ)
	ar rc $@ $^
	ranlib $@

$(OBJDIR)/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) $(OBJFLAGS) -c $< -o $@

$(OBJDIR)/%.o: unit_test/%.c $(UNIHEADERS)
	$(CC) $(INC) -c $< -o $@ $(CFLAGS)