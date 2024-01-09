FROM ubuntu:jammy

RUN apt-get update \
    && apt-get install -y \
        gcc make \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

AdD .local/fix /usr/local/bin/fix

RUN chmod 0755 /usr/local/bin/fix

CMD [ "/bin/bash" ]
