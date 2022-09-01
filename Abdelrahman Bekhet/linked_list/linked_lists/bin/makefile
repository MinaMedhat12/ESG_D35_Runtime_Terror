#Rule: dependencies
#Action

C_COMPILER := gcc

C_FILES := ../linked_lists.c
C_FILES += ../Funcs.c

OBJ_FILES := linked_lists.o
OBJ_FILES += Funcs.o

EXE_FILES := main.exe

all: clean linking

build: $(C_FILES)
	@echo "Starting build"
	@$(C_COMPILER) -c $(C_FILES)

linking: build
	@echo "Starting link"
	@$(C_COMPILER) $(OBJ_FILES) -o $(EXE_FILES)
	@echo "exe file generated"

Run: clean linking
	@echo "Starting Run"
	@./$(EXE_FILES)

clean:
#the next line is in git bash format
	@rm -f *.o *.exe