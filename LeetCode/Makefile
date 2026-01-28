CC = g++
TARGETS = code

run: build
	@./$(TARGETS)

build:
ifdef SOURCE
		@$(CC) -o $(TARGETS) $(SOURCE)
else
		@echo 'path not found'
endif

clean:
	rm -f $(TARGETS)