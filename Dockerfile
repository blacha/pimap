
# Build piMap in a container
FROM ubuntu:20.04 as build
RUN apt-get update \
    && apt-get install --no-install-recommends --no-install-suggests -y \
    mingw-w64

RUN mkdir -p /build/src
COPY ./src /build/src
COPY ./build.mapgen.sh /build

WORKDIR /build
RUN ./build.mapgen.sh

# Make a run environment with nodejs and wine
FROM suchja/wine
USER root
RUN apt-get update -yq \
    && apt-get install curl gnupg -yq \
    && curl -sL https://deb.nodesource.com/setup_10.x | bash \
    && apt-get install nodejs -yq

COPY --from=build /build/bin/pimap.exe /app/bin/pimap.exe

VOLUME [ "/app/game" ]

RUN chown xclient:xusers -R /app

USER xclient
WORKDIR /app
ADD package.json /app/package.json
RUN npm i --production

ADD assets /app/assets
ADD build /app/build/

CMD ["node", "build/mapserver/index.js"]
