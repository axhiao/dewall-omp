MYFLAGS = 
CFLAGS = -lm 

all: dewall test

dewall: 
	 $(CC) $(CFLAGS) $(MYFLAGS) simplexio.c simplex.c geometry.c hashlist.c dewall.c  main.c -o dewall

test: test_simplexio test_geometry test_hashlist

test_simplexio: 
	 $(CC) $(CFLAGS) $(MYFLAGS) ./test/simplexio/test_simplexio.c simplex.c geometry.c hashlist.c simplexio.c -o ./test/simplexio/test_simplexio

test_geometry: 
	 $(CC) $(CFLAGS) $(MYFLAGS) ./test/geometry/test_geometry.c geometry.c hashlist.c simplexio.c simplex.c -o ./test/geometry/test_geometry

test_hashlist:  
	 $(CC) $(CFLAGS) $(MYFLAGS) ./test/hashlist/test_hashlist.c simplex.c simplexio.c geometry.c hashlist.c -o ./test/hashlist/test_hashlist
	 	 
clean:  
	- rm -rf *.o dewall
