#ifndef SHAPES_H
#define SHAPES_H

// Array of shapes to draw

const char *shapes[] = {
    "rectangle",
    "circle",
    "triangle",
    "bezier curve"
    // Add more shapes as needed
};


#define NUM_SHAPES (sizeof(shapes) / sizeof(shapes[0]))

#endif // SHAPES_H
