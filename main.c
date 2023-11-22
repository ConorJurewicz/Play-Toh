// cc -o exe $(pkg-config --cflags --libs cairo) main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <cairo.h>
#include "shapes.h"

/*
 *TODO: 
 *  1. Implement drawings for triangle
    2. 
 */


int main() {

    short WIDTH = 500;
    short HEIGHT = 500;

    short MIN_SIZE = 1;
    short MAX_SIZE = WIDTH/5;

    srand(time(NULL));

    // Getting amount of shapes to draw
    short shapes_to_draw;
    printf("How many shapes to draw?: ");
    scanf("%hd", &shapes_to_draw);

    // Creating a Cairo surface & context
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cairo_t *cr = cairo_create(surface);

    // Setting background color [RGB, 0.0 - 1.0]
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); // Black
    // Drawing a rectangle to act as the background [x, y, W, H]
    cairo_rectangle(cr, 0, 0, 400, 300); // W,H matches Surface
    // Coloring the rectangle with source RGB
    cairo_fill(cr);

    while(shapes_to_draw){

        // Choosing a shape
        int shape_ind = rand() % NUM_SHAPES;
        const char *selected_shape = shapes[shape_ind];
    
        // Generating random size for shape
        short size_w = rand() % MAX_SIZE;
        short size_h = rand() % MAX_SIZE;
        
        // Generating random coordinates for shape
        short rand_x = rand() % (WIDTH-1);
        short rand_y = rand() % (HEIGHT-1); 

        // Generating random color for shape
        double rand_R = (double)rand() / RAND_MAX;
        double rand_G = (double)rand() / RAND_MAX;
        double rand_B = (double)rand() / RAND_MAX;

        
        cairo_set_source_rgb(cr, rand_R, rand_G, rand_B);


        if(strcmp(selected_shape, "rectangle") == 0){
            printf("Rectangle going to be drawn.\n");
            // Drawing a rectangle on top of background [surface, x, y, W, H]
            cairo_rectangle(cr, rand_x, rand_y, size_w, size_h);
            
            // Fill the rectangle with the source color 
            cairo_fill(cr);
        }

        else if(strcmp(selected_shape, "circle") == 0){
            printf("Circle going to be drawn.\n");
            // Drawing an arc on screen [surface, x, y, radius, angle1, angle2]
            cairo_arc(cr, rand_x, rand_y, rand()%50, rand()%100, rand()%50);
            
            // Filling circle
            cairo_fill(cr);

        }

        else if(strcmp(selected_shape, "triangle") == 0){
            printf("Triangle going to be drawn.\n");
        }

        else if(strcmp(selected_shape, "bezier curve") == 0){
            printf("Beziur curve going to be drawn.\n");

            cairo_curve_to(cr, rand_x, rand_y, 
            rand_x+rand()%100, rand_y+rand()%50,
            rand_x+rand()%50, rand_y+rand()%50);

            cairo_fill(cr);
        }

        shapes_to_draw--;
    }
    // Save the surface to an image file (PNG format in this case)
    cairo_surface_write_to_png(surface, "output.png");

    // Clean up resources
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}
