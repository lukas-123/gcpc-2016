%.out: src/%.cpp
	clang++ -stdlib=libstdc++ -D_DEBUG -DDEBUG -g -Wall -static -pipe -std=c++11 -o build/$@ $<

clean:
	rm -rf build/*

.PHONY: clean
