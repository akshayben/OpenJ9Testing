#include <stdlib.h>
#include <stdio.h>

typedef unsigned long int UDATA;

typedef struct JVMImage {
    int timeStamp;
    void (*subAllocateMemory)(struct JVMImage *image, unsigned long int size);
    void (*writeImageToFile)(struct JVMImage *image, char *fileName);
    void (*readImageToFile)(struct JVMImage *image, char *fileName);
} JVMImage;


void subAllocateMemory(struct JVMImage *image, unsigned long int size) {

}

void readImageToFile(struct JVMImage *image, char *fileName) {

}

void writeImageToFile (struct JVMImage *image, char* fileName) {

}


int main() {
    JVMImage *image = malloc(sizeof(JVMImage));
    image
    free(image);
    return 0;
}

