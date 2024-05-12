build:
	g++ src/main.cpp -o main

format:
	find . -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i
