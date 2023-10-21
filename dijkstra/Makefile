run: target
	@./$^

target: main.cpp
	@g++ $^ -g -o $@

clean:
	@rm -rf target

.PHONY: clean run