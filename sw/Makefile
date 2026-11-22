SRCS := src/first_run.cpp
LIB_MOTEUS := ./third_party/moteus

build/first_run.out: $(SRCS)
	g++ src/first_run.cpp -I $(LIB_MOTEUS) -o $@

copy-all:
	./scripts/copy_all.sh

copy-build:
	./scripts/copy_build.sh

connect:
	./scripts/connect_rpi.sh

