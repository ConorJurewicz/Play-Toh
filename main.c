// cc -o exe $(pkg-config --cflags --libs cairo) main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <cairo.h>
#include "shapes.h"

/*
 *TODO: 
    1. Create a randomly generated shape
    2. Choose a radnomly generated color for the randomly generated shape
    3. Have user be able to input how many randomly generated shapes [with randomly generated]
    color to be drawn
 *
 */


int main() {

    srand(time(NULL));

    // Choosing a shape
    int shape_ind = rand() % NUM_SHAPES;
    const char *selected_shape = shapes[shape_ind];
    
    // Creating a Cairo surface
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 400, 300);
    
    // Creating a Cairo context
    cairo_t *cr = cairo_create(surface);

    // Setting background color [RGB, 0.0 - 1.0]
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); // Black

    // Drawing a rectangle to act as the background [x, y, W, H]
    cairo_rectangle(cr, 0, 0, 400, 300); // W,H matches Surface
    
    // Coloring the rectangle with source RGB
    cairo_fill(cr);

    // Setting the color for a new shape to be drawn [RGB, 0.0 - 1.0]
    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0) // Blue

    // Drawing a rectangle on top of background [x, y, W, H]
    cairo_rectangle(cr, 50, 50, 300, 200);
    
    // Fill the rectangle with the source color 
    cairo_fill(cr);

    // Save the surface to an image file (PNG format in this case)
    cairo_surface_write_to_png(surface, "output.png");

    // Clean up resources
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}

/*
*
* There's a pattern of creation for cairo.
* 1. Create a surface
* 2. Create a context
* 3. Choose color for current shape
* 4. Draw shape
* 5. Fill shape with color
* [Repeat steps 3-5]
* [Choose Color, Choose Shape, Fill Chape with Color]
*
*
*/

