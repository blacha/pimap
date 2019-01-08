FROM ubuntu:18.04
RUN apt-get update \
    && apt-get install --no-install-recommends --no-install-suggests -y \
    mingw-w64

RUN mkdir -p /build/src
COPY ./src /build/src
COPY ./build.sh /build

WORKDIR /build
RUN ./build.sh
