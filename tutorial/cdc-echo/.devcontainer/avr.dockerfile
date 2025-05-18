FROM ubuntu:24.04

RUN apt-get update && apt-get --yes --no-install-recommends install \
        avr-libc \
        binutils-avr \
        clang-format \
        gcc-avr \
        make \
    && rm -rf /var/lib/apt/lists/*
