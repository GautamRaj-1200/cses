### makefile

```makefile
# Build rule
%: %.cpp
	g++ -std=c++17 -O2 $< -o $@

# Run rule: `make run file=hello`
run:
	./$(file)
```

### To Build

```bash
make hello # filename without extension
```

### To Run

```bash
./hello
```
