# export env variables
ifneq (,$(wildcard ./.env))
    include .env
    export
endif

.PHONY: default run

# vars
APP_NAME=orion_airlines

default: run

install:
	@echo "Installing dependencies"

run:
	@echo "Running the application"

build:
	@echo "Building the application"

clean:
	@echo "Cleaning the application"
	@rm -rf bin