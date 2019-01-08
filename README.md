# PiMap - Diablo 2 - Map generation test

_This code is taken completly from Awesom-O_

A Linux based CLI interface to generate maps for diablo 2.


# Building

Using docker

```
docker build -t pimap .
```


# Generating maps

```
docker run pimap -v /path/to/diablo:/game -p 5000:5000

# /map/:seed/:difficulty/:levelCode.json
curl http://localhost:5000/map/0x0000001/Nightmare/1.json
```
