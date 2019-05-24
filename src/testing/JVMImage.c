#include <stdlib.h>
#include <stdio.h>

const char *FILENAME = "test.bin";

typedef unsigned long int UDATA;

typedef struct JVMImage {
    int timeStamp;
    FILE *fptr;
    char *fileName;
    void (*init)();
    void (*subAllocateMemory)(JVMImage *image, unsigned long int size);
    void (*writeImageToFile)(JVMImage *image);
    void (*readImageToFile)(JVMImage *image);
    void (*destroy)();
} JVMImage;

JVMImage *initializeJVMImage() {
    JVMImage *image = malloc(sizeof(JVMImage));
    image->init = init;
    image->subAllocateMemory = subAllocateMemory;
    image->readImageToFile = readImageToFile;    
    image->writeImageToFile = writeImageToFile;
    image->destroy = destroy;
    image->init();
    return image;
}

void destroyJVMImage(JVMImage *image) {
    image->destroy(image);
    free(image);
}

void init(JVMImage *image, char *fileName) {
    image->fileName = fileName;
    image->fptr = fopen(image->fileName, "rb+");

}

void subAllocateMemory(JVMImage *image, UDATA size) {

}

void readImageToFile(JVMImage *image) {

}

void writeImageToFile(JVMImage *image) {
    char *test = "data";
    //fwrite(, sizeof(char *), 1, image->fptr)
}

void *fetchData(UDATA id) {

}

void destroy(JVMImage *image) {
    fclose(image->fileName);
}

int main() {
    char *test = "data";
    printf(test);
    JVMImage *image = initializeJVMImage();
    image->writeImageToFile(image);
    destroyJVMImage(image);
    return 0;
}