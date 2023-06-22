#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

//With ( -> ) Arrow operator using pointer as well as dot representation.


float calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

float calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width +
                boxPtr->length * boxPtr->height +
                boxPtr->width * boxPtr->height);
}

//With (*) asterisk or indirection operator and (.) dot operator.

float calVolume(struct Box* boxPtr) {
    return (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
}
float calSurfaceArea(struct Box* boxPtr) {
    return 2 * ((*boxPtr).length * (*boxPtr).width +(*boxPtr).length * (*boxPtr).height +(*boxPtr).width * (*boxPtr).height);
}
int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox;

    // Prompt user to enter dimensions
    printf("Enter the length of the box: ");
    scanf("%f", &myBox.length);

    printf("Enter the width of the box: ");
    scanf("%f", &myBox.width);

    printf("Enter the height of the box: ");
    scanf("%f", &myBox.height);

    // Access members using indirection operator (*) and dot operator (.)
    printf("Using indirection operator (*) and dot operator (.)\n");
    printf("Volume: %.2f\n", calVolume(boxPtr));
    printf("Surface Area: %.2f\n", calSurfaceArea(boxPtr));

    // Access members using arrow operator (->)
    printf("\nUsing arrow operator (->)\n");
    printf("Volume: %.2f\n", boxPtr->length * boxPtr->width * boxPtr->height);
    printf("Surface Area: %.2f\n", calculateSurfaceArea(boxPtr));

    return 0;
}
