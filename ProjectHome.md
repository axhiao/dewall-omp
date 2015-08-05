In mathematics, and computational geometry, a Delaunay triangulation for a set P of points in the plane is a triangulation DT(P) such that no point in P is inside the circumcircle of any triangle in DT(P). Delaunay triangulations maximize the minimum angle of all the angles of the triangles in the triangulation; they tend to avoid skinny triangles. The triangulation was invented by Boris Delaunay in 1934.

source: http://en.wikipedia.org/wiki/Delaunay_triangulation

This is a parallel implementation (using openmp) of the algorithm described in the following paper:

P. Cignoni. DeWall - A fast divide and conquer delaunay triangulation algorithm in ed. Computer-Aided Design, 30(5):333–341, April 1998.

http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.96.438

![http://upload.wikimedia.org/wikipedia/commons/thumb/c/c9/Delaunay_circumcircles.png/280px-Delaunay_circumcircles.png](http://upload.wikimedia.org/wikipedia/commons/thumb/c/c9/Delaunay_circumcircles.png/280px-Delaunay_circumcircles.png)