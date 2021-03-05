#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

void createImage()
{
  //bottom at 250 50
  //middle at y=300
  //top at y = 375
  screen sc;
  color clr;
  struct matrix *obj;

  clear_screen(sc);
  obj = new_matrix(4, 100);
  clr.red = 0;
  clr.green = 229;
  clr.blue = 238;

  for (int i = 0; i < 500; i++)
  {
    for (int j = 0; j < 500; j++)
    {
      plot(sc, clr, i, j);
    }
  }

  clr.red = 0;
  clr.green = 51;
  clr.blue = 102;

  //outer shape
  add_edge(obj, 250, 50, 0, 400, 300, 0);
  add_edge(obj, 250, 50, 0, 100, 300, 0);
  add_edge(obj, 100, 300, 0, 400, 300, 0);
  add_edge(obj, 100, 300, 0, 150, 375, 0);
  add_edge(obj, 400, 300, 0, 350, 375, 0);
  add_edge(obj, 150, 375, 0, 350, 375, 0);

  //inner triangles

  add_edge(obj, 150, 375, 0, 160, 300, 0);
  add_edge(obj, 350, 375, 0, 340, 300, 0);
  add_edge(obj, 150, 375, 0, 250, 300, 0);
  add_edge(obj, 350, 375, 0, 250, 300, 0);
  add_edge(obj, 160, 300, 0, 250, 50, 0);
  add_edge(obj, 340, 300, 0, 250, 50, 0);
  add_edge(obj, 250, 50, 0, 250, 300, 0);

  draw_lines(obj, sc, clr);

  display(sc);
  save_extension(sc, "test.png");
}

int main()
{

  screen s;
  struct matrix *edges;
  struct matrix *edges2;
  struct matrix *edges3;

  edges = new_matrix(4, 4);

  printf("Testing add_edge. Adding points (10,20,30) and (40,50,60): \n");
  add_edge(edges, 10, 20, 30, 40, 50, 60);
  print_matrix(edges);
  printf("\n");

  printf("Testing add_edge. Adding points (5,10,15) and (20,25,30): \n");
  add_edge(edges, 5, 10, 15, 20, 25, 30);
  print_matrix(edges);
  printf("\n");

  printf("Converting matrix into identity matrix.. \n");
  ident(edges);
  print_matrix(edges);
  printf("\n");

  printf("Initializating second matrix with points (1,2,3) and (4,5,6)\n");
  edges2 = new_matrix(4, 2);
  add_edge(edges2, 1, 2, 3, 4, 5, 6);
  print_matrix(edges2);
  printf("\n");

  printf("Multiplying identity matrix by new matrix\n");
  matrix_mult(edges, edges2);
  print_matrix(edges2);
  printf("\n");

  printf("Initializating third matrix with matrix with points (1,5,6),(7,8,8),(2,4,0),(8,5,3)\n");
  printf("Multiplying third matrix by second matrix with points (1,2,3) and (4,5,6)\n");
  printf("\n");
  edges3 = new_matrix(4, 4);
  add_edge(edges3, 1, 5, 6, 7, 8, 8);
  add_edge(edges3, 2, 4, 0, 8, 5, 3);
  matrix_mult(edges3, edges2);
  print_matrix(edges2);

  free_matrix(edges);
  //free_matrix(edges2);

  createImage();
}
