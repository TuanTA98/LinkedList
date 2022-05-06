# Compiler
#GCC_DIR := E:\Local_Setup\NXP\S32DS.3.4\S32DS\build_tools\gcc_v9.2\gcc-9.2-arm32-eabi

#CC := $(GCC_DIR)/bin/arm-none-eabi-gcc.exe
#LD := $(GCC_DIR)/bin/arm-none-eabi-gcc.exe
#AS := $(GCC_DIR)/bin/arm-none-eabi-gcc.exe

CC := gcc
LD := gcc
AS := gcc

# output
OUT_DIRS := ./output
# include
INC_DIRS := ./include
# src
SRC_DIRS := ./src

INC_FILE += $(foreach DIR,$(INC_DIRS),$(wildcard $(DIR)/*.h))
SRC_FILE += $(foreach DIR,$(SRC_DIRS),$(wildcard $(DIR)/*.c))

LIST_C_FILE := $(notdir $(SRC_FILE))
LIST_H_FILE := $(notdir $(INC_FILE))
LIST_O_FILE := $(subst .c,.o,$(LIST_C_FILE))

OBJ_FILE := $(foreach FILE,$(LIST_O_FILE), $(OUT_DIRS)/$(FILE))

vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
vpath %.o $(OUT_DIRS)

INC_DIRS_OPT := $(foreach DIR,$(INC_DIRS),-I $(DIR))

# Compiler Option
CCOPT := $(INC_DIRS_OPT) \
		 -c \
		 -DTEST_ENABLE=STD_OFF

# Assembler Option
ASOPT := -c \
		 $(INC_DIRS_OPT)

# Linker Option
LDOPT := 

all: $(LIST_O_FILE)

build: $(LIST_O_FILE)
	@echo Building...
	@$(LD) $(LDOPT) $(OBJ_FILE) -o $(OUT_DIRS)/main.exe
	@echo Done!

%.o: %.c $(INC_FILE)
	@$(CC) $(CCOPT) $< -o $(OUT_DIRS)/$@

run:
	@./$(OUT_DIRS)/main.exe

.PHONY:clean
clean:
	@rm $(OUT_DIRS)/*
	@echo Clean done!

print-%:
	@echo $($(subst print-,,$@))