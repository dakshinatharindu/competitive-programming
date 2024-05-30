CC = g++
TARGETS = code

$(TARGETS):
ifdef toto
		$(CC) -o $@ $(toto)
else
		@echo 'path not found'
endif

clean:
	rm -f $(TARGETS)