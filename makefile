.PHONY: default run build clean

# vars
APP_NAME=orion_airlines

default: run

install:
	@echo "Installing dependencies"
	@sudo apt install build-essential libsqlite3-dev

run:
	@echo "Running the application"
	@./build/$(APP_NAME)

build:
	@echo "Building the application"
	@mkdir -p build
	@cd build && cmake .. && make -j 

clean:
	@echo "Cleaning the application"
	@rm -rf build