#ifndef SHAPES_H
#define SHAPES_H

// Array of shapes to be radonmly picked.
const char *shapes[] = {
    "rectangle",
    "circle",
    "triangle",
    "bezier curve"
};


#define NUM_SHAPES (sizeof(shapes) / sizeof(shapes[0]))

#endif
