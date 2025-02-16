FROM gcc:latest
COPY . /workspace
WORKDIR /workspace
RUN gcc Main.c -o Main.o
CMD ["./Main.o"]

# To build and run the Docker container, use the following commands:
# docker image build . -t latest
# docker run -it latest