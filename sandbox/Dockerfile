FROM ubuntu:jammy

RUN apt-get update \
    && apt-get install -y \
        gcc \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

ADD https://github.com/tttmmmyyyy/fixlang/releases/download/v0.1.0/fix_x86_64-linux-gnu \
    /usr/local/bin/fix

RUN chmod 0755 /usr/local/bin/fix