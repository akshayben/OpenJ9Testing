#include <stdlib.h>
#include <stdio.h>

const char *FILENAME = "test.bin";

typedef unsigned long int UDATA;

typedef struct JVMImage {
    int timeStamp;
    FILE *fptr;
    const char *fileName;
    int isAlreadyCached;
    void (*init)(struct JVMImage *image, const char *fileName);
    void (*subAllocateMemory)(struct JVMImage *image, unsigned long int size);
    void (*writeImageToFile)(struct JVMImage *image);
    void (*readImageFromFile)(struct JVMImage *image);
    void (*destroy)(struct JVMImage *image);
} JVMImage;

int fileExists(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}

void init(struct JVMImage *image, const char *fileName) {
    image->fileName = fileName;
    image->fptr = fopen(FILENAME, "ab+");
}

void subAllocateMemory(struct JVMImage *image, UDATA size) {

}

void readImageFromFile(struct JVMImage *image) {
    char *test = NULL;
    printf("%p\n", test);
    fread(&test, sizeof(char *), 1, image->fptr);
    printf("%p\n", test);
    printf("%s\n", test);
}

void writeImageToFile(struct JVMImage *image) {
    char *test = malloc(sizeof(char) * 5);
    test = "test";
    printf("%p\n", test);
    printf("%s\n", test);
    fwrite(&test, sizeof(char *), 1, image->fptr);
}

void destroy(struct JVMImage *image) {
    fclose(image->fptr);
}

struct JVMImage *initializeJVMImage() {
    struct JVMImage *image = (struct JVMImage *)malloc(sizeof(struct JVMImage));
    image->isAlreadyCached = fileExists(FILENAME);
    image->init = init;
    image->subAllocateMemory = subAllocateMemory;
    image->readImageFromFile = readImageFromFile;    
    image->writeImageToFile = writeImageToFile;
    image->destroy = destroy;
    image->init(image, FILENAME);
    return image;
}

void destroyJVMImage(struct JVMImage *image) {
    image->destroy(image);
    free(image);
}

int main() {
    struct JVMImage *image = initializeJVMImage();
    if (image->isAlreadyCached) {
        image->readImageFromFile(image);
    }
    else {
        image->writeImageToFile(image);
    }
    destroyJVMImage(image);
    return 0;
}