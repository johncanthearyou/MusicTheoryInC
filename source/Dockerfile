FROM gcc:latest
WORKDIR /workspace
COPY ** /workspace
RUN gcc *.h *.c -o program
CMD ["./program"]

# To build and run the Docker container, use the following commands:
# docker image build . -t latest
# docker run --rm -it latest