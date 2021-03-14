CC := clang
CFLAGS := -g -Wall -Werror

all: ngram

clean:
	@echo "Removing build output"
	@rm -f ngram ngram.zip

ngram: ngram.c
	$(CC) $(CFLAGS) -o ngram ngram.c

zip:
	@echo "Generating ngram.zip file..."
	@zip -q -r ngram.zip . -x .git/\* .vscode/\* .clang-format .gitignore ngram
	@echo "Done. Download ngram.zip."

.PHONY: all clean zip
