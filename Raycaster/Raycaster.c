#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

typedef struct
{
	int w,a,d,s; //button state on off
}ButtonKeys; ButtonKeys Keys;

//---Textures---

int All_Textures[]=               //all 32x32 textures
{
 //Checkerboard
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,1,1,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,1,1,1,1,1,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,1,1,1,1,1,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,1,1,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,

 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0,

 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1,

 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0, 
 //Brick
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,

 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,

 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,

 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
 //Window
 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,    
       
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 
 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 

 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,   
       
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,  
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 
 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 
 //Door
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,    
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,    
 0,0,0,1,1,1,1,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,1,1,1,1,0,0,0,  
 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,  
 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,   
 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,     

 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,  
 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,    
 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,    
 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,   
 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,  
 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,  
 0,0,0,1,0,0,0,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,  
 0,0,0,1,1,1,1,1, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 1,1,1,1,1,0,0,0,  

 0,0,0,0,0,0,0,0, 0,0,0,0,0,1,0,1, 1,0,1,0,0,0,0,0, 0,0,0,0,0,0,0,0,  
 0,0,0,0,0,0,0,0, 0,0,1,1,1,1,0,1, 1,0,1,1,1,1,0,0, 0,0,0,0,0,0,0,0,   
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,    
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,    
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,   
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0, 
 
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,     
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,   
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,   
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,   
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,  
 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,   
 0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,         
};


#define PI 3.1415926535
#define P2 PI/2
#define P3 3*PI/2
#define DR 0.0174533 //one degree in radians

//---Map---

#define mapX 8	//map width
#define mapY 8	//map height
#define mapS 64	//cube size

int mapW[]=		//walls
{
	1,1,1,1,1,1,2,1,
	1,0,0,1,0,0,0,1,
	1,0,0,4,0,1,0,1,
	1,1,4,1,0,0,0,1,
	1,0,0,0,0,2,0,1,
	1,0,1,0,0,2,0,3,
	1,0,0,0,0,0,0,1,
	1,1,3,1,3,1,1,1,	
};

int mapF[]=		//floors	
{
	0,0,0,0,0,0,0,0,
 	0,0,0,0,1,1,0,0,
 	0,0,0,0,2,0,0,0,
 	0,0,0,0,0,0,0,0,
 	0,0,2,0,0,0,0,0,
 	0,0,0,0,0,0,0,0,
 	0,1,1,1,1,0,0,0,
 	0,0,0,0,0,0,0,0,	
};

int mapC[]=		//ceiling
{
 	0,0,0,0,0,0,0,0,
 	0,0,0,0,0,0,0,0,
 	0,0,0,0,0,0,0,0,
 	0,0,0,0,0,0,1,0,
 	0,1,3,1,0,0,0,0,
 	0,0,0,0,0,0,0,0,
 	0,0,0,0,0,0,0,0,
 	0,0,0,0,0,0,0,0,	
};

float degToRad(float a){ return a*M_PI/180.0;}
float FixAng(float a){ if(a>359){ a-=359;} if(a<0){ a+=360;} return a;}

float px, py, pdx, pdy, pa; //player position

void drawPlayer()
{
	glColor3f(1,1,0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(px, py);
	glEnd();
	
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2i(px,py);
	glVertex2i(px+pdx*5,py+pdy*5);
	glEnd();
}

void drawMap2D()
{
	int x, y, xo, yo;
	for(y = 0; y < mapY; y++){
		for(x = 0; x < mapX; x++){
			if(mapW[y*mapX+x]>0){ glColor3f(1,1,1);}
			else{glColor3f(0,0,0);}
			xo=x*mapS;
			yo=y*mapS;
			glBegin(GL_QUADS);
			glVertex2i(xo+1,yo+1);
			glVertex2i(xo+1,yo+mapS-1);
			glVertex2i(xo+mapS-1,yo+mapS-1);
			glVertex2i(xo+mapS-1,yo+1);
			glEnd();
		}
	}
}

float dist(float ax, float ay, float bx, float by, float ang)
{
	return (sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)));
}

void drawRays2D()
{
	int r,mx,my,mp,dof;
	float rx,ry,ra,xo,yo,disT;
	ra=pa-DR*30; if(ra<0){ ra+=2*PI;} if(ra>2*PI){ ra-=2*PI;}
	for(r=0;r<60;r++){
		int vmt=0,hmt=0;	//Vertical and horizontal map texture number
		//---Check Horizontal Lines---
		dof=0;
		float disH=1000000,hx=px,hy=py;
		float aTan=-1/tan(ra);
		if(ra>PI){ ry=(((int)py>>6)<<6)-0.0001; rx=(py-ry)*aTan+px; yo=-64; xo=-yo*aTan;}//looking up
		if(ra<PI){ ry=(((int)py>>6)<<6)+64; rx=(py-ry)*aTan+px; yo=64; xo=-yo*aTan;}//looking down
		if(ra==0 || ra==PI){rx=px; ry=py; dof=8;}//looking straight left or right
		int mv=0,mh=0;
		while(dof<8)
		{
			mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
			if(mp>0 && mp<mapX*mapY && mapW[mp]>0){ hmt=mapW[mp]-1; mh=mapW[mp]; hx=rx; hy=ry; disH=dist(px,py,hx,hy,ra); dof=8;}//hit wall
			else{ rx+=xo; ry+=yo; dof+=1;}//next line
		}
		
		//---Check Vertical Lines---
		dof=0;
		float disV=1000000,vx=px,vy=py;
		float nTan=-tan(ra);
		if(ra>P2 && ra<P3){ rx=(((int)px>>6)<<6)-0.0001; ry=(px-rx)*nTan+py; xo=-64; yo=-xo*nTan;}//looking left
		if(ra<P2 || ra>P3){ rx=(((int)px>>6)<<6)+64; ry=(px-rx)*nTan+py; xo=64; yo=-xo*nTan;}//looking right
		if(ra==0 || ra==PI){rx=px; ry=py; dof=8;}//looking straight up or down
		while(dof<8)
		{
			mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
			if(mp>0 && mp<mapX*mapY && mapW[mp]>0){ vmt=mapW[mp]-1; mv=mapW[mp]; vx=rx; vy=ry; disV=dist(px,py,vx,vy,ra); dof=8;}//hit wall
			else{ rx+=xo; ry+=yo; dof+=1;}//next line
		}
		
		float shade=1;
		if(disV<disH){ hmt=vmt; shade=0.5; rx=vx; ry=vy; disT=disV; glColor3f(0,0.9,0);}	//vertical wall hit
		if(disH<disV){ rx=hx; ry=hy; disT=disH; glColor3f(0,0.7,0);}						//horizontal wall hit
		glLineWidth(2); glBegin(GL_LINES); glVertex2i(px,py); glVertex2i(rx,ry); glEnd();
		//---Draw 3D Walls---
		float ca=pa-ra; if(ca<0){ ca+=2*PI;} if(ca>2*PI){ ca-=2*PI;} disT=disT*cos(ca);	//fix fisheye
		float lineH=(mapS*320)/disT;													//line height
		float ty_step=32.0/(float)lineH;
		float ty_off=0;
		if(lineH>320){ ty_off=(lineH-320)/2.0; lineH=320;}
		float lineO=160-lineH/2;														//line offset
		
		//draw walls
		int y;
		float ty=ty_off*ty_step+hmt*32;
		float tx;
		if(shade==1){ tx=(int)(rx/2.0)%32; if(ra>180){ tx=31-tx;}}
		else{ tx=(int)(ry/2.0)%32; if(ra>90 && ra<270){ tx=31-tx;}}
		
		for(y=0;y<lineH;y++)
		{
			float c=All_Textures[(int)(ty)*32+(int)(tx)]*shade;
			if(hmt==0){ glColor3f(c,c/2.0,c/2.0);}	//checkboard red
			if(hmt==1){ glColor3f(c,c,c/2.0);}		//Brick yellow
			if(hmt==2){ glColor3f(c/2.0,c/2.0,c);}	//Window blue
			if(hmt==3){ glColor3f(c/2.0,c,c/2.0);}	//door green
			glPointSize(8); glBegin(GL_POINTS); glVertex2i(r*8+530,y+lineO);glEnd();	//draw vertical wall
			ty+=ty_step;
		}
		
		for(y=lineO+lineH;y<320;y++)
		{
			//draw floors
			float dy=y-(320/2.0), deg=degToRad(ra), raFix=cos(degToRad(FixAng(pa-ra)));
  			tx=px/2 + cos(deg)*158*32/dy/raFix;
  			ty=py/2 - sin(deg)*158*32/dy/raFix;
  			int mp=mapF[(int)(ty/32.0)*mapX+(int)(tx/32.0)]*32*32;
  			float c=All_Textures[((int)(ty)&31)*32 + ((int)(tx)&31)+mp]*0.7;
  			glColor3f(c/1.3,c/1.3,c);glPointSize(1);glBegin(GL_POINTS);glVertex2i(r*8+530,y);glEnd();
  			
  			//draw ceiling
  			mp=mapC[(int)(ty/32.0)*mapX+(int)(tx/32.0)]*32*32;
  			c=All_Textures[((int)(ty)&31)*32 + ((int)(tx)&31)-20+mp]*0.7;
  			glColor3f(c/2.0,c/1.2,c/2.0);glPointSize(1);glBegin(GL_POINTS);glVertex2i(r*8+530,320-y);glEnd();
		}
		
		ra+=DR; if(ra<0){ ra+=2*PI;} if(ra>2*PI){ ra-=2*PI;}
	}
}

float frame1, frame2, fps;

void display()
{	
	//frames per second
	frame2=glutGet(GLUT_ELAPSED_TIME); fps=(frame2-frame1); frame1=glutGet(GLUT_ELAPSED_TIME);

	//buttons
	if(Keys.a==1){ pa-=0.05; if(pa<0){ pa+=2*PI;} pdx=cos(pa)*5; pdy=sin(pa)*5;}
	if(Keys.d==1){ pa+=0.05; if(pa>2*PI){pa-=2*PI;} pdx=cos(pa)*5; pdy=sin(pa)*5;}
	
	int xo=0; if(pdx<0){ xo-=20;} else{ xo=20;}
	int yo=0; if(pdy<0){ yo-=20;} else{ yo=20;}
	int ipx=px/64.0, ipx_add_xo=(px+xo)/64.0, ipx_sub_xo=(px-xo)/64.0;
	int ipy=py/64.0, ipy_add_yo=(py+yo)/64.0, ipy_sub_yo=(py-yo)/64.0;
	if(Keys.w==1){
		if(mapW[ipy*mapX+ipx_add_xo]==0){ px+=pdx*0.05*fps;}
		if(mapW[ipy_add_yo*mapY+ipx]==0){ py+=pdy*0.05*fps;}
	}
	if(Keys.s==1){
		if(mapW[ipy*mapX+ipx_sub_xo]==0){ px-=pdx*0.05*fps;}
		if(mapW[ipy_sub_yo*mapY+ipx]==0){ py-=pdy*0.05*fps;}
	}
	
	glutPostRedisplay();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawMap2D();
	drawPlayer();
	drawRays2D();
	glutSwapBuffers();
}

void ButtonDown(unsigned char key, int x, int y)
{
	if(key=='a'){ Keys.a=1;}
	if(key=='d'){ Keys.d=1;}
	if(key=='w'){ Keys.w=1;}
	if(key=='s'){ Keys.s=1;}
	if(key=='e')				//open door
	{
		int xo=0; if(pdx<0){ xo-=25;} else{ xo=25;}
		int yo=0; if(pdy<0){ yo-=25;} else{ yo=25;}
		int ipx=px/64.0, ipx_add_xo=(px+xo)/64.0;
		int ipy=py/64.0, ipy_add_yo=(py+yo)/64.0;
		if(mapW[ipy_add_yo*mapX+ipx_add_xo]==4){ mapW[ipy_add_yo*mapX+ipx_add_xo]=0;}
	}
	glutPostRedisplay();
}

void ButtonUp(unsigned char key, int x, int y)
{
	if(key=='a'){ Keys.a=0;}
	if(key=='d'){ Keys.d=0;}
	if(key=='w'){ Keys.w=0;}
	if(key=='s'){ Keys.s=0;}
	glutPostRedisplay();
}

void init()
{
	glClearColor(0.3,0.3,0.3,0);
	gluOrtho2D(0,1024,512,0);
	px=300; py=300; pdx=cos(pa)*5; pdy=sin(pa)*5;;
	
}

void resize(int w, int h)
{
	glutReshapeWindow(1024,512);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024,510);
	glutInitWindowPosition(400,200);
	glutCreateWindow("Raycaster");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(ButtonDown);
	glutKeyboardUpFunc(ButtonUp);
	glutMainLoop();
}
