# MudopDB_v1

Small experimental C++ project demonstrating a tiny database-style app with a modular layout.

## Repo layout

- `include/` : public headers (api, helper)
- `src/` : implementation and `main.cpp`
- `src/api` : driver/connection/statement implementations
- `src/helper` : small helpers
- `Dockerfile.debian` : Debian-based multi-stage Dockerfile to build and run the project
- `Dockerfile` : Ubuntu-based multi-stage Dockerfile

## Build (local, out-of-source)

```bash
# from repo root
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --parallel

# run
./src/mudopdb
```

## Run in Docker (Debian)

```bash
# build image
docker build -t mudopdb:debian -f Dockerfile.debian .

# run (interactive)
docker run --rm -it mudopdb:debian

# or pipe a connection string
echo "connection-string" | docker run --rm -i mudopdb:debian
```

## Notes & next steps
- The project uses CMake and builds a static helper library plus an executable.
- For development, prefer out-of-source builds and keep `build/` excluded from Docker context (`.dockerignore` included).
- I can add CI (GitHub Actions) to run builds on push and run unit tests.
