#include <cairo.h>

int main() {
    // Create a Cairo surface
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 400, 300);
    
    // Create a Cairo context
    cairo_t *cr = cairo_create(surface);

    // Set the source color for the background (RGB values between 0.0 and 1.0)
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); // Black

    // Draw a filled rectangle to serve as the background
    cairo_rectangle(cr, 0, 0, 400, 300); // Assuming the surface size is 400x300
    cairo_fill(cr);

    // Set the source color for the blue rectangle
    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0); // Blue

    // Draw a rectangle on top of the background
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
* The things that change for steps 3-5 (to create a different shape with a different color)
*  1. 
*
*/

