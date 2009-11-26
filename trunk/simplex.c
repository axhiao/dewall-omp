#include "simplex.h"
#include <stdlib.h>
#include <string.h>

/* face list handling */

int equal_face(void *vf1, void *vf2)  {
  	face *f1 = (face *) vf1;
	face *f2 = (face *) vf2;  
    
    if (f1->point[0] != f2->point[0] && 
		f1->point[0] != f2->point[1])
		return 0;
		
	if (f1->point[1] != f2->point[0] && 
		f1->point[1] != f2->point[1])
		return 0;
	
	return 1;
}

int hash_face(void *vf) {
  face *f = (face *) vf;
  return (int)((long)(f->point[0]) ^ (long)(f->point[1]));
}

int insert_face(face *f, face_list *AFL) {
	return insert_list(AFL, f);
}
int extract_face(face **f, face_list *AFL) {
	return extract_list(AFL, f);
}
int update_face(face *f, face_list *AFL) {
	if (member_list(AFL, f)){
		delete_list(AFL, f);
      printf("\nDeleting face: (%f, %f)(%f, %f)", 
                  f->point[0]->x, f->point[0]->y,
                  f->point[1]->x, f->point[1]->y);
   }
	else 
		insert_list(AFL, f);
}
void initialize_face_list(face_list *AFL, int size) {
	initialize_list(AFL,sizeof(face *),equal_face);
    hash_list(AFL, size, hash_face);
}

/* simplex list handling */

int hash_simplex(void *vs) {
  simplex *s = (simplex *) vs;
  return (hash_face(&(s->face[0])) ^ hash_face(&(s->face[1])) ^ 
		hash_face(&(s->face[2])));
}

void initialize_simplex_list(simplex_list *sl, int size) {
	// Not gonna use the equal function
	initialize_list(sl,sizeof(char *),NULL);
}

int insert_simplex(simplex *s, simplex_list *sl, point_set *P) {	
   int index[3];  
   char simp_temp[100];
   char *simp;
   
   index[0] = s->face[0]->point[0] - P->point;
   index[1] = s->face[0]->point[1] - P->point;

   if ((s->face[1]->point[0] - P->point) != index[0] && (s->face[1]->point[0] - P->point) != index[1])
      index[2] = s->face[1]->point[0] - P->point;
   else 
      index[2] = s->face[1]->point[1] - P->point;
   //free s
   snprintf(simp_temp,100,"(%.3f, %.3f)(%.3f, %.3f)(%.3f, %.3f)",
       P->point[index[0]].x, P->point[index[0]].y,
       P->point[index[1]].x, P->point[index[1]].y,
       P->point[index[2]].x, P->point[index[2]].y);

   simp = (char *)malloc(sizeof(char)*strlen(simp_temp));
   if (!simp)
      return 0;

   simp[0] = 0;
   strncpy(simp, simp_temp, strlen(simp_temp));      
   return insert_list(sl, simp);
}

int extract_simplex(char **s, simplex_list *sl) {
	return extract_list(sl, s);   
}

int build_simplex(simplex **s, face *f, point *p) {
	*s = (simplex *)malloc(sizeof(simplex));
	
	if (!(*s))
		return 0;
		
	(*s)->face[0] = (*s)->face[1] = (*s)->face[2] = NULL;
	
	(*s)->face[0] = (face *)malloc(sizeof(face));
	(*s)->face[1] = (face *)malloc(sizeof(face));
	(*s)->face[2] = (face *)malloc(sizeof(face));

	if(!((*s)->face[0] && (*s)->face[1] && (*s)->face[2]))
		return 0;

	(*s)->face[0]->point[0] = f->point[0];
	(*s)->face[0]->point[1] = f->point[1];

	(*s)->face[1]->point[0] = f->point[0];
	(*s)->face[1]->point[1] = p;
 
	(*s)->face[2]->point[0] = p;
	(*s)->face[2]->point[1] = f->point[1];	
	
	return 1;
}

void revert_face(face *f){
   point *p;
   p = f->point[0];
   f->point[0] = f->point[1];
   f->point[1] = p;   
}
