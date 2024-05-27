CC=g++ --std=c++17
_MODEL = vec3
_MAIN = main
ODIR=obj
SDIR=src
MODELOBJ = $(patsubst %, $(ODIR)/lib/%.o, $(_MODEL))
MAINOBJ  = $(patsubst %, $(ODIR)/%.o, $(_MAIN))
CFLAGS=-I$(src) -Wall
TEST = $(patsubst %, ./tests/test_%.cpp, $(_MODEL))

build:
	$(CC) src/main.cpp -o main $(CFLAGS)

format:
	find . -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

run: build
	rm img.ppm || true
	./main

code.o: $(MAINOBJ) $(MODELOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(MODELOBJ): $(ODIR)/lib/%.o: $(SDIR)/lib/%.cpp $(MODELDEP)| obj/lib/
	$(CC) -c -o $@ $< $(CFLAGS)


$(MAINOBJ): $(ODIR)/%.o: $(SDIR)/%.cpp $(MAINDEP)| obj/
	$(CC) -c -o $@ $< $(CFLAGS)

test: code.o
	$(CC) -I/tmp/doctest -o ./tests/tests.o $(MODELOBJ) $(TEST) $(CFLAGS)
	./tests/tests.o --success

obj/:
	mkdir -p obj

obj/lib/:
	mkdir -p obj/lib
