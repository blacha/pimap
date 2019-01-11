FROM ubuntu:18.04 as build
# FROM portown/alpine-mingw-w64
RUN apt-get update \
    && apt-get install --no-install-recommends --no-install-suggests -y \
    mingw-w64

RUN mkdir -p /build/src
COPY ./src /build/src
COPY ./build.mapgen.sh /build

WORKDIR /build
RUN ./build.mapgen.sh


FROM alpine:latest
RUN apk add --update --no-cache wine libpng ncurses bash freetype

COPY --from=build /build/bin/pimap.exe /app

# ENV WINEARCH win32
# ENV DISPLAY :0

# FROM ubuntu:18.04

# RUN apt-get update && apt-get install wine -y
