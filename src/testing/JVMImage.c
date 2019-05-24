#include <stdlib.h>
#include <stdio.h>

const char *FILENAME = "test.bin";

typedef unsigned long int UDATA;

typedef struct JVMImage {
    int timeStamp;
    FILE *fptr;
    char *fileName;
    void (*init)();
    void (*subAllocateMemory)(struct JVMImage *image, unsigned long int size);
    void (*writeImageToFile)(struct JVMImage *image);
    void (*readImageToFile)(struct JVMImage *image);
    void (*destroy)();
} JVMImage;

struct JVMImage *initializeJVMImage() {
    struct JVMImage *image = malloc(sizeof(JVMImage));
    image->init = init;
    image->subAllocateMemory = subAllocateMemory;
    image->readImageToFile = readImageToFile;    
    image->writeImageToFile = writeImageToFile;
    image->destroy = destroy;
    image->init();
    return image;
}

void destroyJVMImage(struct JVMImage *image) {
    image->destroy(image);
    free(image);
}

void init(struct JVMImage *image, char *fileName) {
    image->fileName = fileName;
    image->fptr = fopen(image->fileName, "rb+");

}

void subAllocateMemory(struct JVMImage *image, UDATA size) {

}

void readImageToFile(struct JVMImage *image) {

}

void writeImageToFile(struct JVMImage *image) {
    char *test = "data";
    //fwrite(, sizeof(char *), 1, image->fptr)
}

void *fetchData(UDATA id) {

}

void destroy(struct JVMImage *image) {
    fclose(image->fileName);
}

int main() {
    char *test = "data";
    printf(test);
    struct JVMImage *image = initializeJVMImage();
    image->writeImageToFile(image);
    destroyJVMImage(image);
    return 0;
}