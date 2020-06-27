/* * * * * * *
 * Implementation of the Inside Hull algorithm for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2019
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by Dan Wu
 */

//                   WRITE YOUR IMPLEMENTATION HERE
//
// You should fill in the function definitions for orientation() and
// inside_hull() in this file.
//
// Don't be shy to add any extra functions or types you may need.

#include <stdio.h>
#include <stdlib.h>

#include "convex-hull.h"

// Returns the orientation of Point p2 in relation to the line segment p0p1.
// If p2 is to the left of p0p1 then it returns LEFT ('l'), if p2 is to the
// right it returns RIGHT ('r').
// If p0, p1 and p2 are collinear then COLLINEAR ('c') is returned.
char orientation(Point p0, Point p1, Point p2) {
  // TODO: Implement orientation()
  //define the x-coordinate of p0p1 segment at p2 y-coordinate
  double tmpx = (p0.x - p1.x) / (p0.y - p1.y) * (p2.y - p1.y) + p1.x;
  //if x-coordinate of p2 is smaller than tmpx, p2 is to the left of p0p1
  if (tmpx > p2.x)
	  return 'l';
  //if x-coordinate of p2 is greter than tmpx, p2 is to the right of p0p1
  else if (tmpx < p2.x)
  {
	  return 'r';
  }
  //if x-coordinate of p2 is equal to tmpx, p0, p1 and p2 are collinear
  else if (tmpx == p2.x)
  {
	  return 'c';
  }
  else
  {
    fprintf(stderr, "Error: orientation() not implemented\n");
    exit(EXIT_FAILURE);
  }
}

// Takes a polygon (i.e. an array of points) given in counter-clockwise order
// with n points.
//
// Stores the points of the convex hull into the hull array (the last point
// should NOT be the same as the first point), and returns the number of
// points which are in the convex hull.
//
// If three successive points in the polygon are collinear then the algorithm
// should terminate and COLLINEAR_POINTS should be returned.
//
// If an error occurs this function should return INSIDE_HULL_ERROR.
int inside_hull(Point *polygon, int n, Point *hull) {
  // TODO: Implement the InsideHull algorithm
  int x1, y1, x2, y2, x3, y3,num = 0;
	x1 = polygon[0].x;
	y1 = polygon[0].y;
	x2 = x1;
	y2 = y1;
  int i;
	for (i = 1; i < n; i++)
	{
		x3 = polygon[i].x;
		y3 = polygon[i].y;

		if (x3<x1)
		{
			x1 = x3;
			y1 = y3;
		}
		else if (x3>x2)
		{
			x2 = x3;
			y2 = y3;
		}
	}
	hull[0].x = x1;
	hull[0].y = y1;
	hull[1].x = x2;
	hull[1].y = y2;
	getResult(polygon, x1, y1, x2, y2, n, hull, num);
	getResult(polygon, x2, y2, x1, y1, n, hull, num);
    fprintf(stderr, "Error: inside_hull() not implemented\n");
    exit(EXIT_FAILURE);
}


void getResult(Point *polygon, int x1, int y1, int x2, int y2, int n, Point *hull,int num)
{
	int i, t, x3, y3, R, Rmax, tmax;
	Point * Result = malloc(sizeof(&polygon));
	int m = 0;

	x3 = polygon[1].x;
	y3 = polygon[1].y;
	R = x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3;
	Rmax = R;
	tmax = 1;
	//for(i=2;i<=Pack[0][0];i++)//
	for (i = 1; i <= n; i++)
	{
		x3 = polygon[i].x;
		y3 = polygon[i].y;
		R = x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3;
														  /*
														  |x1 y1 1|
														  |x2 y2 1|
														  |x3 y3 1|
														  */
		if (R >= 0)
		{
			t = ++m;
			Result[t].x = x3;
			Result[t].y = y3;
		}
		if (R > Rmax)
		{
			Rmax = R;
			tmax = i;
		}
	}
	if (Rmax <= 0)
	{
		return;
	}
	else
	{
		t = ++num;
		hull[t].x = polygon[tmax].x;
		hull[t].y = polygon[tmax].y;
		if (m==0)
			return ;
	}
	getResult(Result, x1, y1, polygon[tmax].x, polygon[tmax].y,n, hull,num);
	getResult(Result, polygon[tmax].x, polygon[tmax].y, x2, y2,n, hull,num);
}
