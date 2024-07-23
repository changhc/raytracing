BUILDDIR=build

clean:
	if [ -d "${BUILDDIR}" ]; then \
		rm -r ${BUILDDIR}; \
	fi \

build:
	mkdir $(BUILDDIR) && cd $(BUILDDIR) && cmake .. && cmake --build .

format:
	find . -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

run: build
	rm img.ppm || true
	./$(BUILDDIR)/src/main

test: build
	cd $(BUILDDIR) && ctest
