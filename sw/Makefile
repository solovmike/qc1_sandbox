SRCS = src/first_run.cpp
LIB_MOTEUS = ./third_party/moteus
CXX_NATIVE = g++
CXX_RPI = aarch64-linux-gnu-g++

build/first_run.out: $(SRCS)
	${CXX_RPI} src/first_run.cpp -I $(LIB_MOTEUS) -o $@

deploy-%: build/%.out
	make copy-build

copy-all:
	./scripts/copy_all.sh

copy-build:
	./scripts/copy_build.sh

connect:
	./scripts/connect_rpi.sh

