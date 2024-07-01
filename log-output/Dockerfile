# First stage: Build environment
FROM alpine:3.20 AS build

# Install necessary packages for building
RUN apk update && apk add --no-cache \
    build-base \
    cmake \
    ninja

# Set the working directory
WORKDIR /app

# Copy the build files
COPY Makefile .
COPY CMakeLists.txt .
COPY src/ ./src

# Run CMake and build the project
RUN make release

# Second stage: Runtime environment
FROM alpine:3.20

# Install necessary runtime dependencies
RUN apk update && apk add --no-cache libstdc++

# Copy the built executable from the first stage
COPY --from=build /app/build-release/bin/dlog /app/dlog

ENTRYPOINT ["/app/dlog"]