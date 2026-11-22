BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

CXX_NATIVE = g++
CXX_RPI = aarch64-linux-gnu-g++

GNR_FLAGS = -std=c++17 -Wall -Wextra #general flags

LIB_MOTEUS = ./third_party/moteus
LIB_PI3HAT = ./third_party/pi3hat

vpath %.cpp src $(LIB_PI3HAT)

INCLUDES = \
	-I $(LIB_MOTEUS) \
	-I $(LIB_PI3HAT)

TARGET_NAMES = first_run.out set_stop.out
TARGETS = $(addprefix $(BUILD_DIR)/, $(TARGET_NAMES))

#--------TARGETS--------

$(BUILD_DIR)/first_run.out: $(addprefix $(OBJ_DIR)/, first_run.o pi3hat.o)
	${CXX_RPI} ${GNR_FLAGS} $^ -o $@

$(BUILD_DIR)/set_stop.out: $(addprefix $(OBJ_DIR)/, set_stop.o pi3hat.o)
	${CXX_RPI} ${GNR_FLAGS} $^ -o $@

#------------------------

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)
	${CXX_RPI} ${GNR_FLAGS} $(INCLUDES) -c $^ -o $@

deploy-all: $(TARGETS)
	make copy-build

deploy-%: $(BUILD_DIR)/%.out
	make copy-build

copy-all:
	./scripts/copy_all.sh

copy-build:
	./scripts/copy_build.sh

connect:
	./scripts/connect_rpi.sh

clean:
	rm -rf build

