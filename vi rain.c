#include<stdio.h> 
#include<math.h> 
#include<glut.h> 
#include<string.h> 
 
char str3[30]="Help:-"; 
char str4[50]="Press 'q' or 'Q' or 'ESC' to Exit"; 
char str5[50]="Press 's' or 'S' to Create House"; 
char str6[50]="press 'r' or 'R' to Rain"; 
char str7[50]="TURBINE"; 
char str8[50]="WATER STORAGE"; 
char str1[30]="CHARCOAL"; 
char str2[20]="CHLORINE CONTAINER"; 
 
 
#define radian 3.14159/180.0 
static GLfloat spin=0.0; 
float theta=0.0; 
GLfloat x,y; 
GLint i; 
 
int l; 
 
void flow2(); 
void flow3(); 
void flow4(); 
void flow5(); 
void flow6(); 
void flow7(); 
void flow8(); 
void flow9(); 
void flow10(); 
void flow11(); 
void flow12(); 
void disprectangle(); 
void disprectangle1(); 
void disprectangle2(); 
void drawhouse(); 
void drawconts(); 
void drawpump(); 
void drawtank(); 
void square(); 
void rain1(); 
void circle_draw(GLint,GLint,GLint); 
typedef float points[2]; 
GLfloat count=0; 
GLfloat count1=0; 
GLfloat house1[10][2]={{-625,255},{-700,400},{-500,375}}; 

GLfloat house[3][15]={{-700,-700,-550,-550,-550,-400,-400,-675,-675,-625,-625,-700,-550,-400,-550},{-50,150,150,-50,300,300,100,-50,25,25,-50,175,325,325,175},{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}}; 

GLfloat conts[3][17]={{-540,-520,-520,-425,-425,-375,-375,-250,-250,-5,-5,10,10,-390,-390,-535,-535},{185,185,-100,-100,-235,-235,-275,-275,-435,-435,-50,-50,-450,-450,-250,-250,165},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}; 

GLfloat pump[3][15]={{-325,-275,-275,-325,-175,-125,-125,-175,-50,30,30,-25,-25,-50,0},{225,225,0,0,225,225,0,0,25,25,-50,-50,-25,-25,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}; 

GLfloat tank[3][18]={{-400,-365,-365,-350,-350,-115,-115,-75,-75,-50,-50,-90,-90,-100,-100,-350,-350,-400},{200,200,240,240,360,360,375,375,10,10,-5,-5,360,360,225,225,185,185},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}; 
 
 /* flow function points */ 
points waterpoint[]={{-535.0,175.0},{-527.0,175.0}}; 

points waterpoint2[]={{-527.0,180.0},{-527.0,170.0},{-527.0,160.0},{-527.0,150.0},{-527.0,140.0},{-527.0,130.0},{-527.0,120.0},{-527.0,110.0},{-527.0,100.0},{-527.0,90.0},{-527.0,80.0},{-527.0,70.0},{-527.0,60.0},{-527.0,50.0},{-527.0,40.0},{-527.0,30.0},{-527.0,20.0},{-527.0,10.0},{-527.0,0.0},{-527.0,-10.0},{-527.0,-20.0},{-527.0,-30.0},{-527.0,-40.0},{-527.0,-50.0},{-527.0,-60.0},{-527.0,-70.0},{-527.0,-80.0},{-527.0,-90.0},{-527.0,-100.0},{-527.0,-110.0},{-527.0,-120.0},{-527.0,-130.0},{-527.0,-140.0},{-527.0,-150.0},{-527.0,-160.0},{-527.0,-170.0}}; 

points waterpoint3[]={{-435.0,-243.0},{-425.0,-243.0},{-415.0,-243.0},{-405.0,-243.0},{-395.0,-243.0},{-385.0,-243.0}}; 

points waterpoint4[]={{-383.0,-440.0},{-383.0,-430.0},{-383.0,-420.0},{-383.0,-410.0},{-383.0,-400.0},{-383.0,-390.0},{-383.0,-380.0},{-383.0,-370.0},{-383.0,-360.0},{-383.0,-350.0},{-383.0,-340.0},{-383.0,-330.0},{-383.0,-320.0},{-383.0,-310.0},{-383.0,-300.0},{-383.0,-290.0},{-383.0,-280.0},{-383.0,-270.0},{-383.0,-260.0},{-383.0,-250.0}}; 

points waterpoint5[]={{-250.0,-443.0},{-240.0,-443.0},{-230.0,-443.0},{-220.0,-443.0},{-210.0,-443.0},{-200.0,-443.0},{-190.0,-443.0},{-180.0,-443.0},{-170.0,-443.0},{-160.0,-443.0},{-150.0,-443.0},{-140.0,-443.0},{-130.0,-443.0},{-120.0,-443.0},{-110.0,-443.0},{-100.0,-443.0},{-90.0,-443.0},{-80.0,-443.0},{-70.0,-443.0},{-60.0,-443.0},{-50.0,-443.0},{-40.0,-443.0},{-30.0,-443.0},{-20.0,-443.0},{-10.0,-443.0},{-0.0,-443.0}}; 

points waterpoint6[]={{3.0,-440.0},{3.0,-430.0},{3.0,-420.0},{3.0,-410.0},{3.0,-400.0},{3.0,-390.0},{3.0,-380.0},{3.0,-370.0},{3.0,-360.0},{3.0,-350.0},{3.0,-340.0},{3.0,-330.0},{3.0,-320.0},{3.0,-310.0},{3.0,-300.0},{3.0,-290.0},{3.0,-280.0},{3.0,-270.0},{3.0,-260.0},{3.0,-250.0},{3.0,-240.0},{3.0,-230.0},{3.0,-220.0},{3.0,-210.0},{3.0,-200.0},{3.0,-190.0},{3.0,-180.0},{3.0,-170.0},{3.0,-160.0},{3.0,-150.0},{3.0,-140.0},{3.0,-130.0},{3.0,-120.0},{3.0,-110.0},{3.0,-100.0},{3.0,-90.0},{3.0,-80.0},{3.0,-70.0},{3.0,-60.0},{3.0,-50.0}}; 

points waterpoint7[]={{-55.0,3.0},{-63.0,3.0},{-70.0,3.0},{-77.0,3.0},}; 

points waterpoint8[]={{-83.0,10.0},{-83.0,20.0},{-83.0,30.0},{-83.0,40.0},{-83.0,50.0},{-83.0,60.0},{-83.0,70.0},{-83.0,80.0},{-83.0,90.0},{-83.0,100.0},{-83.0,110.0},{-83.0,120.0},{-83.0,130.0},{-83.0,140.0},{-83.0,150.0},{-83.0,160.0},{-83.0,170.0},{-83.0,180.0},{-83.0,190.0},{-83.0,200.0},{-83.0,210.0},{-83.0,220.0},{-83.0,230.0},{-83.0,240.0},{-83.0,250.0},{-83.0,260.0},{-83.0,270.0},{-83.0,280.0},{-83.0,290.0},{-83.0,300.0},{-83.0,310.0},{-83.0,320.0},{-83.0,330.0},{-83.0,340.0},{-83.0,350.0},{-83.0,360.0},}; 

points waterpoint9[]={{-85.0,367.0},{-95.0,367.0},{-105.0,367.0}}; 

points waterpoint10[]={{-107.0,370.0},{-107.0,360.0},{-107.0,350.0},{-107.0,340.0},{-107.0,330.0},{-107.0,320.0},{-107.0,310.0},{-107.0,300.0},{-107.0,290.0},{-107.0,280.0},{-107.0,270.0},{-107.0,260.0},{-107.0,250.0},{-107.0,240.0},{-107.0,230.0}}; 

points waterpoint11[]={{-110.0,230.0},{-120.0,230.0},{-130.0,230.0},{-140.0,230.0},{-150.0,230.0},{-160.0,230.0},{-170.0,230.0},{-180.0,230.0},{-190.0,230.0},{-200.0,230.0},{-210.0,230.0},{-220.0,230.0},{-230.0,230.0},{-240.0,230.0},{-250.0,230.0},{-260.0,230.0},{-270.0,230.0},{-280.0,230.0},{-290.0,230.0},{-300.0,230.0},{-310.0,230.0},{-320.0,230.0},{-330.0,230.0},{-340.0,230.0}}; 

points waterpoint12[]={{-357.0,225.0},{-357.0,215.0},{-357.0,205.0},{-357.0,195.0}}; 
points rectangle[]={{-390.0,-450.0},{-250.0,-450.0},{-250.0,-440.0},{-390.0,-440.0}}; 
points rectangle1[]={{-350.0,225.0},{-100.0,225.0},{-100.0,235.0},{-350.0,235.0}}; 
points rectangle2[]={{-535.0,-165.0},{-425.0,-165.0},{-425.0,-170.0},{-535.0,-170.0}}; 
 
/*flow functions*/ 
 void flow1() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=1;k>=0;k--) 
    { 
        if(waterpoint[k][0]==-527.0) 
        { 
            waterpoint[k][0]=-535.0; 
        } 
    } 
    for(i=1;i>=0;i--) 
    { 
 
        waterpoint[i][0]=waterpoint[i][0]+0.5; 
    } 
    for( l=1;l>=0;l--) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint[l]); 
        glEnd(); 
    } 
}
--------------------------------- 
void flow2() 
{ 
     
    int k,l; 
    glPointSize(4.0); 
    for( k=35;k>=0;k--) 
    { 
        if(waterpoint2[k][1]==-170.0) 
        { 
            waterpoint2[k][1]=175.0; 
        } 
    } 
    for(i=35;i>=0;i--) 
    { 
 
        waterpoint2[i][1]=waterpoint2[i][1]-0.5; 
    } 
    for( l=0;l<=35;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint[l]); 
        glEnd(); 
    } 
     
} 
--------------------------------- 
void flow3() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=5;k>=0;k--) 
    { 
        if(waterpoint3[k][0]==-385.0) 
        { 
            waterpoint3[k][0]=-435.0; 
        } 
    } 
    for(i=5;i>=0;i--) 
    { 
 
        waterpoint3[i][0]=waterpoint3[i][0]+0.5; 
    } 
    for( l=5;l>=0;l--) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint3[l]); 
        glEnd(); 
    } 
     
} 
void flow4() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=20;k>=0;k--) 
    { 
        if(waterpoint4[k][1]==-440.0) 
        { 
            waterpoint4[k][1]=-250.0; 
        } 
    } 
    for(i=20;i>=0;i--) 
    { 
 
        waterpoint4[i][1]=waterpoint4[i][1]-0.5; 
    } 
    for( l=0;l<=19;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint4[l]); 
        glEnd(); 
    } 
     
} 
void flow5() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=26;k>=0;k--) 
    { 
        if(waterpoint5[k][0]==0.0) 
        { 
            waterpoint5[k][0]=-250.0; 
        } 
    } 
    for(i=0;i<=26;i++) 
    { 
 
        waterpoint5[i][0]=waterpoint5[i][0]+0.5; 
    } 
    for( l=1;l<=25;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint5[l]); 
        glEnd(); 
    } 
     
} 
void flow6() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=40;k>=0;k--) 
    { 
        if(waterpoint6[k][1]==-50.0) 
        { 
            waterpoint6[k][1]=-440.0; 
        } 
    } 
     
    for( l=1;l<=39;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint6[l]); 
        glEnd(); 
    } 
    for(i=39;i>=0;i--) 
    { 
 
        waterpoint6[i][1]=waterpoint6[i][1]+0.5; 
    } 
     
} 
void flow7() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=4;k>=0;k--) 
    { 
        if(waterpoint7[k][0]==-77.0) 
        { 
            waterpoint7[k][0]=-55.0; 
        } 
    } 
     
    for( l=3;l>=0;l--) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint7[l]); 
        glEnd(); 
    } 
    for(i=4;i>=0;i--) 
    { 
 
        waterpoint7[i][0]=waterpoint7[i][0]-0.5; 
    } 
     
} 
void flow8() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=36;k>=0;k--) 
    { 
        if(waterpoint8[k][1]==360.0) 
        { 
            waterpoint8[k][1]=10.0; 
        } 
    } 
     
    for( l=1;l<=36;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint8[l]); 
        glEnd(); 
    } 
    for(i=35;i>=0;i--) 
    { 
 
        waterpoint8[i][1]=waterpoint8[i][1]+0.5; 
    } 
     
} 
void flow9() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( l=3;l>=1;l--) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint9[l]); 
        glEnd(); 
    } 
    for( k=3;k>=0;k--) 
    { 
        if(waterpoint9[k][0]==-105.0) 
        { 
            waterpoint9[k][0]=-85.0; 
        } 
    } 
    for(i=2;i>=0;i--) 
    { 
 
        waterpoint9[i][0]=waterpoint9[i][0]-0.5; 
    } 
     
} 
void flow10() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=15;k>=0;k--) 
    { 
        if(waterpoint10[k][1]==230.0) 
        { 
            waterpoint10[k][1]=370.0; 
        } 
    } 
     
    for( l=1;l<=15;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint10[l]); 
        glEnd(); 
    } 
    for(i=14;i>=0;i--) 
    { 
 
        waterpoint10[i][1]=waterpoint10[i][1]-0.5; 
    } 
    if(count>1730) 
        flow11(); 
} 
void flow11() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( l=24;l>=0;l--) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint11[l]); 
        glEnd(); 
    } 
    for(k=24;k>=0;k--) 
    { 
        if(waterpoint11[k][0]==-340.0) 
        { 
            waterpoint11[k][0]=-110.0; 
        } 
    } 
    for(i=23;i>=0;i--) 
    { 
 
        waterpoint11[i][0]=waterpoint11[i][0]-0.5; 
    } 
    if(count>1760) 
    flow12(); 
} 
void flow12() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=4;k>=0;k--) 
    { 
        if(waterpoint12[k][1]==190.0) 
        { 
            waterpoint12[k][1]=225.0; 
        } 
    } 
     
    for( l=1;l<=4;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.25,1.0); 
        glVertex2fv(waterpoint12[l]); 
        glEnd(); 
    } 
    for(i=3;i>=0;i--) 
    { 
 
        waterpoint12[i][1]=waterpoint12[i][1]-0.5; 
    } 
     
} 
----------------------------------------------------     
void disprectangle1() 
{ 
    int l; 
    glColor3f(0.0,0.25,1.0); 
    glBegin(GL_POLYGON); 
    glVertex2f(-400.0,185.0); 
    glVertex2f(-350.0,185.0); 
    glVertex2f(-350.0,200.0); 
    glVertex2f(-400.0,200.0); 
    glEnd(); 
    glBegin(GL_POLYGON); 
    glVertex2f(-350.0,200.0); 
    glVertex2f(-350.0,240.0); 
    glVertex2f(-365.0,240.0); 
    glVertex2f(-365.0,200.0); 
    glEnd(); 
     
    glBegin(GL_POLYGON); 
    for( l=0;l<=3;l++) 
    { 
    glVertex2fv(rectangle1[l]); 
    } 
    glEnd(); 
    if(count>1730 && count<4500) 
    { 
        rectangle1[2][1]=rectangle1[2][1]+0.04; 
        rectangle1[3][1]=rectangle1[3][1]+0.04; 
    } 
} 
 
/*rainwater points*/ 
void rain1(); 
void rain3(); 
void rain5(); 
void rain7(); 
void rain9(); 
void rain11(); 
void rain13(); 
void rain15(); 
void rain17(); 
void rain19(); 
void rain21(); 
void rain23(); 
void rain25(); 
void rain27(); 
void rain29(); 
void rain31(); 
void rain33(); 
void rain35(); 
 
 
points rainpoint1[]={{-745.0,400.0},{-745.0,380.0},{-745.0,360.0},{-745.0,340.0},{-745.0,320.0},{-745.0,300.0},{-745.0,280.0},{-745.0,260.0},{-745.0,240.0},{-745.0,220.0},{-745.0,200.0},{-745.0,180.0},{-745.0,160.0},{-745.0,140.0},{-745.0,120.0},{-745.0,100.0},{-745.0,80.0},{-745.0,60.0},{-745.0,40.0},{-745.0,20.0},{-745.0,0.0},{-745.0,-20.0},{-745.0,-40.0},{-745.0,-60.0}}; 

points rainpoint3[]={{-705.0,400.0},{-705.0,380.0},{-705.0,360.0},{-705.0,340.0},{-705.0,320.0},{-705.0,300.0},{-705.0,280.0},{-705.0,260.0},{-705.0,240.0},{-705.0,220.0},{-705.0,200.0},{-705.0,180.0},{-705.0,160.0},{-705.0,140.0},{-705.0,120.0},{-705.0,100.0},{-705.0,80.0},{-705.0,60.0},{-705.0,40.0},{-705.0,20.0},{-705.0,0.0},{-705.0,-20.0},{-705.0,-40.0},{-705.0,-60.0}}; 

points rainpoint5[]={{-665.0,400.0},{-665.0,380.0},{-665.0,360.0},{-665.0,340.0},{-665.0,320.0},{-665.0,300.0},{-665.0,280.0},{-665.0,260.0},{-665.0,240.0},{-665.0,220.0},{-665.0,200.0},{-665.0,180.0}}; 

points rainpoint7[]={{-625.0,400.0},{-625.0,380.0},{-625.0,360.0},{-625.0,340.0},{-625.0,320.0},{-625.0,300.0},{-625.0,280.0},{-625.0,260.0},{-625.0,240.0},{-625.0,220.0},{-625.0,200.0},{-625.0,180.0}}; 

points rainpoint9[]={{-585.0,400.0},{-585.0,380.0},{-585.0,360.0},{-585.0,340.0},{-585.0,320.0},{-585.0,300.0},{-585.0,280.0},{-585.0,260.0},{-585.0,240.0},{-585.0,220.0},{-585.0,200.0},{-585.0,180.0}}; 

points rainpoint11[]={{-545.0,400.0},{-545.0,380.0},{-545.0,360.0},{-545.0,340.0},{-545.0,320.0},{-545.0,300.0},{-545.0,280.0},{-545.0,260.0},{-545.0,240.0},{-545.0,220.0},{-545.0,200.0},{-545.0,180.0}}; 

points rainpoint13[]={{-505.0,400.0},{-505.0,380.0},{-505.0,360.0},{-505.0,340.0},{-505.0,320.0},{-505.0,300.0},{-505.0,280.0},{-505.0,260.0},{-505.0,240.0},{-505.0,220.0},{-505.0,200.0},{-505.0,180.0},{-505.0,160.0},{-505.0,140.0},{-505.0,120.0},{-505.0,100.0},{-505.0,80.0},{-505.0,60.0},{-505.0,40.0},{-505.0,20.0},{-505.0,0.0},{-505.0,-20.0},{-505.0,-40.0},{-505.0,-60.0}}; 

points rainpoint15[]={{-465.0,400.0},{-465.0,380.0},{-465.0,360.0},{-465.0,340.0},{-465.0,320.0},{-465.0,300.0},{-465.0,280.0},{-465.0,260.0},{-465.0,240.0},{-465.0,220.0},{-465.0,200.0},{-465.0,180.0},{-465.0,160.0},{-465.0,140.0},{-465.0,120.0},{-465.0,100.0},{-465.0,80.0},{-465.0,60.0},{-465.0,40.0},{-465.0,20.0},{-465.0,0.0},{-465.0,-20.0},{-465.0,-40.0},{-465.0,-60.0}}; 

points rainpoint17[]={{-425.0,400.0},{-425.0,380.0},{-425.0,360.0},{-425.0,340.0},{-425.0,320.0},{-425.0,300.0},{-425.0,280.0},{-425.0,260.0},{-425.0,240.0},{-425.0,220.0},{-425.0,200.0},{-425.0,180.0},{-425.0,160.0},{-425.0,140.0},{-425.0,120.0},{-425.0,100.0},{-425.0,80.0},{-425.0,60.0},{-425.0,40.0},{-425.0,20.0},{-425.0,0.0},{-425.0,-20.0},{-425.0,-40.0},{-425.0,-60.0}}; 

points rainpoint19[]={{-385.0,400.0},{-385.0,380.0},{-385.0,360.0},{-385.0,340.0},{-385.0,320.0},{-385.0,300.0},{-385.0,280.0},{-385.0,260.0},{-385.0,240.0},{-385.0,220.0},{-385.0,200.0},{-385.0,180.0},{-385.0,160.0},{-385.0,140.0},{-385.0,120.0},{-385.0,100.0},{-385.0,80.0},{-385.0,60.0},{-385.0,40.0},{-385.0,20.0},{-385.0,0.0},{-385.0,-20.0},{-385.0,-40.0},{-385.0,-60.0}}; 

points rainpoint21[]={{-555.0,400.0},{-555.0,380.0},{-555.0,360.0},{-555.0,340.0},{-555.0,320.0},{-555.0,300.0},{-555.0,280.0}}; 
points rainpoint23[]={{-515.0,400.0},{-515.0,380.0},{-515.0,360.0},{-515.0,340.0},{-515.0,320.0},{-515.0,300.0},{-515.0,280.0}}; 
points rainpoint25[]={{-475.0,400.0},{-475.0,380.0},{-475.0,360.0},{-475.0,340.0},{-475.0,320.0},{-475.0,300.0},{-475.0,280.0}}; 
points rainpoint27[]={{-435.0,400.0},{-435.0,380.0},{-435.0,360.0},{-435.0,340.0},{-435.0,320.0},{-435.0,300.0},{-435.0,280.0}}; 

points rainpoint29[]={{-695.0,400.0},{-695.0,380.0},{-695.0,360.0},{-695.0,340.0},{-695.0,320.0},{-695.0,300.0},{-695.0,280.0},{-695.0,260.0},{-695.0,240.0},{-695.0,220.0},{-695.0,200.0},{-695.0,180.0}}; 

points rainpoint31[]={{-655.0,400.0},{-655.0,380.0},{-655.0,360.0},{-655.0,340.0},{-655.0,320.0},{-655.0,300.0},{-655.0,280.0},{-655.0,260.0},{-655.0,240.0},{-655.0,220.0},{-655.0,200.0}}; 

points rainpoint33[]={{-615.0,400.0},{-615.0,380.0},{-615.0,360.0},{-615.0,340.0},{-615.0,320.0},{-615.0,300.0},{-615.0,280.0},{-615.0,260.0},{-615.0,240.0}}; 
points rainpoint35[]={{-575.0,400.0},{-575.0,380.0},{-575.0,360.0},{-575.0,340.0},{-575.0,320.0},{-575.0,300.0},{-575.0,280.0},{-575.0,260.0}}; 
 
/*rain function*/ 
 void rain1() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=24;k>=0;k--) 
    { 
        if(rainpoint1[k][1]==-60.0) 
        { 
            rainpoint1[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=24;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint1[l]); 
        glEnd(); 
    } 
    for(i=23;i>=0;i--) 
    { 
 
        rainpoint1[i][1]=rainpoint1[i][1]-2; 
    } 
    rain3(); 
} 
 
void rain3() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=24;k>=0;k--) 
    { 
        if(rainpoint3[k][1]==-60.0) 
        { 
            rainpoint3[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=24;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint3[l]); 
        glEnd(); 
    } 
    for(i=23;i>=0;i--) 
    { 
 
        rainpoint3[i][1]=rainpoint3[i][1]-2; 
    } 
    rain5(); 
} 
void rain5() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=12;k>=0;k--) 
    { 
        if(rainpoint5[k][1]==160.0) 
        { 
            rainpoint5[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=12;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint5[l]); 
        glEnd(); 
    } 
    for(i=11;i>=0;i--) 
    { 
 
        rainpoint5[i][1]=rainpoint5[i][1]-2; 
    } 
    rain7(); 
} 
 
void rain7() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=12;k>=0;k--) 
    { 
        if(rainpoint7[k][1]==160.0) 
        { 
            rainpoint7[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=12;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint7[l]); 
        glEnd(); 
    } 
    for(i=11;i>=0;i--) 
    { 
 
        rainpoint7[i][1]=rainpoint7[i][1]-2; 
    } 
    rain9(); 
} 
 
void rain9() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=12;k>=0;k--) 
    { 
        if(rainpoint9[k][1]==160.0) 
        { 
            rainpoint9[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=12;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint9[l]); 
        glEnd(); 
    } 
    for(i=11;i>=0;i--) 
    { 
 
        rainpoint9[i][1]=rainpoint9[i][1]-1; 
    } 
rain11(); 
} 
 
void rain11() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=12;k>=0;k--) 
    { 
        if(rainpoint11[k][1]==160.0) 
        { 
            rainpoint11[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=12;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint11[l]); 
        glEnd(); 
    } 
    for(i=11;i>=0;i--) 
    { 
 
        rainpoint11[i][1]=rainpoint11[i][1]-1; 
    } 
    rain13(); 
} 
 
 
void rain13() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=11;k>=0;k--) 
    { 
        if(rainpoint13[k][1]==200.0) 
        { 
            rainpoint13[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=11;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint13[l]); 
        glEnd(); 
    } 
    for(i=13;i>=0;i--) 
    { 
 
        rainpoint13[i][1]=rainpoint13[i][1]-2; 
    } 
 
    rain15(); 
} 
void rain15() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=8;k>=0;k--) 
    { 
        if(rainpoint15[k][1]==240.0) 
        { 
            rainpoint15[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=8;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint15[l]); 
        glEnd(); 
    } 
    for(i=23;i>=0;i--) 
    { 
 
        rainpoint15[i][1]=rainpoint15[i][1]-1; 
    } 
    rain17(); 
} 
 
void rain17() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=6;k>=0;k--) 
    { 
        if(rainpoint17[k][1]==300.0) 
        { 
            rainpoint17[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=6;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint17[l]); 
        glEnd(); 
    } 
    for(i=23;i>=0;i--) 
    { 
 
        rainpoint17[i][1]=rainpoint17[i][1]-1; 
    } 
     
    rain19(); 
} 
 
void rain19() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=24;k>=0;k--) 
    { 
        if(rainpoint19[k][1]==-60.0) 
        { 
            rainpoint19[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=24;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint19[l]); 
        glEnd(); 
    } 
    for(i=23;i>=0;i--) 
    { 
 
        rainpoint19[i][1]=rainpoint19[i][1]-1; 
    } 
    rain21(); 
} 
 
void rain21() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=7;k>=0;k--) 
    { 
        if(rainpoint21[k][1]==280.0) 
        { 
            rainpoint21[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=7;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint21[l]); 
        glEnd(); 
    } 
    for(i=11;i>=0;i--) 
    { 
 
        rainpoint21[i][1]=rainpoint21[i][1]-2; 
    } 
    rain23(); 
} 
 
void rain23() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=7;k>=0;k--) 
    { 
        if(rainpoint23[k][1]==280.0) 
        { 
            rainpoint23[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=7;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint23[l]); 
        glEnd(); 
    } 
    for(i=6;i>=0;i--) 
    { 
 
        rainpoint23[i][1]=rainpoint23[i][1]-2; 
    } 
    rain25(); 
} 
 
void rain25() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=7;k>=0;k--) 
    { 
        if(rainpoint25[k][1]==280.0) 
        { 
            rainpoint25[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=7;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint25[l]); 
        glEnd(); 
    } 
    for(i=6;i>=0;i--) 
    { 
 
        rainpoint25[i][1]=rainpoint25[i][1]-2; 
    } 
    rain27(); 
} 
 
void rain27() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=7;k>=0;k--) 
    { 
        if(rainpoint27[k][1]==280.0) 
        { 
            rainpoint27[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=7;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint27[l]); 
        glEnd(); 
    } 
    for(i=6;i>=0;i--) 
    { 
 
        rainpoint27[i][1]=rainpoint27[i][1]-1; 
    } 
    rain29(); 
} 
 
void rain29() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=12;k>=0;k--) 
    { 
        if(rainpoint29[k][1]==200.0) 
        { 
            rainpoint29[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=12;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint29[l]); 
        glEnd(); 
    } 
    for(i=11;i>=0;i--) 
    { 
 
        rainpoint29[i][1]=rainpoint29[i][1]-1; 
    } 
    rain31(); 
} 
 
void rain31() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=11;k>=0;k--) 
    { 
        if(rainpoint31[k][1]==200.0) 
        { 
            rainpoint31[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=11;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint31[l]); 
        glEnd(); 
    } 
    for(i=10;i>=0;i--) 
    { 
 
        rainpoint31[i][1]=rainpoint31[i][1]-1; 
    } 
    rain33(); 
} 
 
void rain33() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=11;k>=0;k--) 
    { 
        if(rainpoint33[k][1]==180.0) 
        { 
            rainpoint33[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=11;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint33[l]); 
        glEnd(); 
    } 
    for(i=7;i>=0;i--) 
    { 
 
        rainpoint33[i][1]=rainpoint33[i][1]-1; 
    } 
    rain35(); 
} 
 
void rain35() 
{ 
    int k,l; 
    glPointSize(4.0); 
    for( k=5;k>=0;k--) 
    { 
        if(rainpoint35[k][1]==300.0) 
        { 
            rainpoint35[k][1]=400.0; 
        } 
    } 
     
    for( l=1;l<=8;l++) 
    { 
        glBegin(GL_POINTS); 
        glColor3f(0.0,0.5,1.0); 
        glVertex2fv(rainpoint35[l]); 
        glEnd(); 
    } 
    for(i=7;i>=0;i--) 
    { 
 
        rainpoint35[i][1]=rainpoint35[i][1]-1; 
    } 
     
} 
 
 /* HOUSE AND OTHERS*/---------------------------------------- 
 void drawconts() 
{ 
    glColor3f(1.0,1.0,1.0); 
    glBegin(GL_LINE_STRIP); 
    for(i=0;i<=16;i++) 
    { 
        glVertex2f(conts[0][i],conts[1][i]); 
    } 
    glEnd(); 
    if(count1>60) 
    drawpump(); 
} 
void drawhouse() 
{ 
     
    count1=count1+1; 
    glColor3f(0.5,0.0,0.0); 
    glBegin(GL_POLYGON); 
    glVertex2f(house[0][0],house[1][0]); 
    glVertex2f(house[0][1],house[1][1]); 
    glVertex2f(house[0][3],house[1][2]); 
    glVertex2f(house[0][3],house[1][3]); 
    glEnd(); 
 
    glColor3f(0.5,1.0,0.5);//door 
    glBegin(GL_POLYGON); 
    glVertex2f(house[0][7],house[1][7]); 
    glVertex2f(house[0][8],house[1][8]); 
    glVertex2f(house[0][9],house[1][9]); 
    glVertex2f(house[0][10],house[1][10]); 
    glEnd(); 
 
 
    glColor3f(1.0,0.0,0.5); 
    glBegin(GL_POLYGON); 
    glVertex2f(house[0][2],house[1][2]); 
    glVertex2f(house[0][5],house[1][5]); 
    glVertex2f(house[0][6],house[1][6]); 
    glVertex2f(house[0][3],house[1][3]); 
    glEnd(); 
 
    glColor3f(1.0,0.5,0.0);//reqd 
    glBegin(GL_POLYGON); 
    glVertex2f(house[0][1],house[1][1]); 
    glVertex2f(house[0][11],house[1][11]); 
    glVertex2f(house[0][14],house[1][14]); 
    glVertex2f(house[0][2],house[1][2]); 
    glEnd(); 
 
    glBegin(GL_POLYGON); 
    glVertex2f(house[0][1],house[1][1]); 
    glVertex2f(house[0][11],house[1][11]); 
    glVertex2f(house[0][12],house[1][12]); 
    glVertex2f(house[0][4],house[1][4]); 
    glEnd(); 
 
 
    glBegin(GL_POLYGON); 
    glVertex2f(house[0][12],house[1][12]); 
    glVertex2f(house[0][13],house[1][13]); 
    glVertex2f(house[0][5],house[1][5]); 
    glVertex2f(house[0][4],house[1][4]); 
    glEnd(); 
 
    glBegin(GL_POLYGON); 
    glVertex2f(house[0][14],house[1][14]); 
    glVertex2f(house[0][13],house[1][13]); 
    glVertex2f(house[0][5],house[1][5]); 
    glVertex2f(house[0][2],house[1][2]); 
    glEnd(); 
    glBegin(GL_POLYGON); 
    glColor3f(1.0,0.0,0.0); 
          glVertex2f(house[0][14],house[1][14]); 
        glVertex2f(house[0][13],house[1][13]); 
        glVertex2f(house1[2][0],house1[2][1]); 
        glVertex2f(house1[0][0],house1[0][1]); 
     
    glEnd(); 
    glColor3f(.5,0.0,.5); 
    glBegin(GL_POLYGON); 
    glVertex2f(house[0][11],house[1][11]); 
    glVertex2f(house[0][14],house[1][14]); 
    glVertex2f(house1[0][0],house1[0][1]); 
    glEnd(); 
    if(count1>30) 
    drawconts(); 
}
------------------------------------------------ 
void drawpump() 
{ 
    glColor3f(.25,0.0,0.0); 
    glBegin(GL_POLYGON); 
    glVertex2f(pump[0][0],pump[1][0]); 
    glVertex2f(pump[0][1],pump[1][1]); 
    glVertex2f(pump[0][2],pump[1][2]); 
    glVertex2f(pump[0][3],pump[1][3]); 
    glEnd(); 
    glBegin(GL_POLYGON); 
    glVertex2f(pump[0][4],pump[1][4]); 
    glVertex2f(pump[0][5],pump[1][5]); 
    glVertex2f(pump[0][6],pump[1][6]); 
    glVertex2f(pump[0][7],pump[1][7]); 
    glEnd(); 
    glColor3f(1.0,1.0,1.0); 
    glBegin(GL_LINE_LOOP); 
    glVertex2f(pump[0][8],pump[1][8]); 
    glVertex2f(pump[0][9],pump[1][9]); 
    glVertex2f(pump[0][10],pump[1][10]); 
    glVertex2f(pump[0][11],pump[1][11]); 
    glVertex2f(pump[0][12],pump[1][12]); 
    glVertex2f(pump[0][13],pump[1][13]); 
    glEnd(); 
    glEnd(); 
    glColor3f(1.0,0.0,0.0); 
    glBegin(GL_POINTS); 
    glVertex2f(pump[0][14],pump[1][14]); 
    glEnd(); 
    if(count1>90) 
    drawtank(); 
} 
------------------------------------------------
void drawtank() 
{ 
    glColor3f(1.0,1.0,1.0); 
    glBegin(GL_LINE_LOOP); 
    for(i=0;i<=17;i++) 
    { 
         glVertex2f(tank[0][i],tank[1][i]); 
    } 
    glEnd(); 
    circle_draw(-525,-240,10); 
    circle_draw(-505,-240,10); 
    circle_draw(-485,-240,10); 
    circle_draw(-465,-240,10); 
    circle_draw(-525,-200,10); 
    circle_draw(-505,-200,10); 
    circle_draw(-485,-200,10); 
    circle_draw(-465,-200,10); 
    circle_draw(-520,-220,10); 
    circle_draw(-500,-220,10); 
    circle_draw(-480,-220,10); 
    circle_draw(-460,-220,10); 
    circle_draw(-520,-180,10); 
    circle_draw(-500,-180,10); 
    circle_draw(-480,-180,10); 
    circle_draw(-460,-180,10); 
    circle_draw(-445,-240,10); 
    circle_draw(-445,-200,10); 
    circle_draw(-440,-220,10); 
    circle_draw(-440,-180,10); 
     
} 
-------------------------------------
void bitmap() 
{ 
    int a,p,b,o; 
    glColor3f(1.0,0.0,0.0); 
    glRasterPos2i(80,350); 
    for( a=0;a<strlen(str3);a++) 
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str3[a]); 
    glColor3f(0.0,1.0,0.0); 
    glRasterPos2i(100,300); 
    for( p=0;p<strlen(str5);p++) 
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str5[p]); 
    glColor3f(0.0,0.0,1.0); 
    glRasterPos2i(100,250); 
    for( b=0;b<strlen(str6);b++) 
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str6[b]); 
    glColor3f(1.0,0.0,1.0); 
    glRasterPos2i(100,200); 
    for( o=0;o<strlen(str4);o++) 
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str4[o]); 
     
}
------------------------------------------------ 
void bitmap1() 
{ 
    int l,z,k,m; 
    glColor3f(1.0,0.0,0.0); 
     
    glRasterPos2i(-350,-150); 
    for( l=0;l<strlen(str1);l++) 
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str1[l]); 
    glRasterPos2i(-190,-200); 
    for( z=0;z<strlen(str2);z++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str2[z]); 
    glRasterPos2i(-190,-100); 
    for( k=0;k<strlen(str7);k++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str7[k]); 
 
    /*glRasterPos2i(-240,250); 
    for( m=0;m<strlen(str8);m++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str8[m]);*/ 
 
 
    glRasterPos2i(-340,-60); 
    for( m=0;m<strlen(str8);m++)         
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str8[m]); 
}
------------------------------------ 
void line() 
{ 
    glColor3f(1.0,0.0,0.0); 
    glBegin(GL_LINES); 
    glVertex2f(-440,-180); 
    glVertex2f(-360,-155); 
    glVertex2f(-280,-310); 
    glVertex2f(-200,-210); 
    glVertex2f(-160,-90); 
    glVertex2f(-50,-30); 
 
    glVertex2f(-290,-40); 
    glVertex2f(-240,250); 
 
    glEnd(); 
}
------------------------------------------ 
void draw_pixel(GLint cx,GLint cy) 
{ 
    glColor3f(0.5,0.5,0.5); 
    glBegin(GL_POINTS); 
    glVertex2i(cx,cy); 
    glEnd(); 
} 
--------------------------------------------
void plotpixels(GLint h,GLint k,GLint x,GLint y) 
{ 
    draw_pixel(x+h,y+k); 
    draw_pixel(-x+h,y+k); 
    draw_pixel(x+h,-y+k); 
    draw_pixel(-x+h,-y+k); 
    draw_pixel(y+h,x+k); 
    draw_pixel(-y+h,x+k); 
    draw_pixel(y+h,-x+k); 
    draw_pixel(-y+h,-x+k); 
} 
-------------------------------------------------
void circle_draw(GLint h,GLint k,GLint r) 
{ 
    GLint d=1-r,x=0,y=r; 
    while(y>x) 
    { 
        plotpixels(h,k,x,y); 
        if(d<0) d+=2*x+3; 
        else 
        { 
            d+=2*(x-y)+5; 
            --y; 
        } 
        ++x; 
    } 
    plotpixels(h,k,x,y); 
} 
-------------------------------------------------------- 
void square() 
{ 
    glColor3f(0.0,1.0,1.0); 
    glBegin(GL_QUADS); 
    glVertex2f(x,y); 
    glVertex2f(-y,x); 
    glVertex2f(-x,-y); 
    glVertex2f(y,-x); 
    glEnd(); 
} 
-------------------------
void disprectangle2() 
{ 
    glColor3f(0.0,0.25,1.0); 
    glBegin(GL_POLYGON); 
    for(l=0;l<=3;l++) 
    { 
    glVertex2fv(rectangle2[l]); 
    } 
    glEnd(); 
    if(count>450 && count<600) 
    { 
        rectangle2[1][1]=rectangle2[1][1]+0.07; 
        rectangle2[0][1]=rectangle2[0][1]+0.07; 
    } 
    if(count>3500&&count<3660) 
    { 
        rectangle2[1][1]=rectangle2[1][1]-0.07; 
        rectangle2[0][1]=rectangle2[0][1]-0.07; 
    } 
     
}
------------------------------------ 
void disprectangle() 
{ 
    glColor3f(0.0,0.25,1.0); 
 
    glBegin(GL_POLYGON); 
    for(l=0;l<=3;l++) 
    { 
    glVertex2fv(rectangle[l]); 
    } 
    glEnd(); 
    if(count>540 && count<1500) 
    { 
        rectangle[2][1]=rectangle[2][1]+0.05; 
        rectangle[3][1]=rectangle[3][1]+0.05; 
    } 
}
------------------------ 
void disprec(); 
void disprec() 
{ 
 
    if(count>3770 && count<4400) 
    { 
        rectangle[2][1]=rectangle[2][1]-0.06; 
        rectangle[3][1]=rectangle[3][1]-0.06; 
    } 
    glColor3f(0.0,0.25,1.0); 
    glBegin(GL_POLYGON); 
    glVertex2fv(rectangle[0]); 
    glVertex2fv(rectangle[1]); 
    glVertex2fv(rectangle[2]); 
    glVertex2fv(rectangle[3]); 
    glEnd(); 
}
---------------------------------- 
void displayd() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    square(); 
    glutSwapBuffers(); 
} 
unsigned char key2; 
------------------------------------------------------- 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glPointSize(2.0); 
    bitmap(); 
    if(key2=='q'||key2=='Q') exit(0); 
    if(key2=='s'||key2=='S') 
    { 
        drawhouse(); 
        if(count1>150) 
        { 
            line(); 
            bitmap1(); 
        } 
    } 
if(key2=='r'||key2=='R')  
{ 
    count=count+1; 
    drawhouse(); 
    bitmap(); 
    line(); 
    bitmap1(); 
     
     
    if(count<2500) 
    { 
    rain1(); 
    } 
    if(count>370&&count<3600) 
    flow1(); 
    if(count<3620) 
    { 
       flow2(); 
       if(count>300&&count<4030) 
       { 
           disprectangle2(); 
         
       } 
    } 
    if(count>3770 && count<4200) 
        disprec(); 
    if(count>500&&count<3730) 
    flow3(); 
    if(count>520&&count<3750) 
    flow4(); 
    if(count>540&&count<3770) 
        disprectangle(); 
    if(count>1530&&count<4250) 
        flow5(); 
    if(count>1500&&count<4480) 
    { 
        square(); 
 
    } 
    if(count>1560&&count<4300) 
    flow6(); 
    if(count>1600&&count<4320) 
    flow7(); 
    if(count>1620&&count<4340) 
    flow8(); 
    if(count>1660&&count<4360) 
    flow9(); 
    if(count>1690&&count<4380) 
    flow10(); 
    if(count>1790) disprectangle1(); 
 
} 
    glFlush(); 
    glutSwapBuffers(); 
} 
------------------------------------------------- 
void mykey(unsigned char key,int x,int y) 
{ 
   key2=key; 
    if(key==27) exit(0); 
   if(key=='q'||key=='Q') exit(0); 
   if(key=='s'||key=='S') { 
                            drawhouse(); 
                                bitmap1(); 
                            } 
   if(key=='r'||key=='R')  
   { 
       count=150; 
       drawhouse(); 
       rain1(); 
       rain35(); 
   } 
} 
------------------------------------------------
void myinit() 
{ 
    glClearColor(0.0,0.0,0.0,0.0); 
    glColor3f(1.0,0.0,0.0); 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-750.0,400.0,-500.0,400.0); 
} 
----------------------------------------------
void idle() 
{ 
theta=theta+15.0; 
if(theta>360.0) 
theta=theta-360.0; 
x=18.0*cos(radian*theta); 
y=18.0*sin(radian*theta); 
bitmap(); 
glutPostRedisplay(); 
} 
---------------------------------------------------------- 
void main(int argc,char **argv) 
{ 
    glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB); 
    glutInitWindowPosition(0,0); 
    glutInitWindowSize(1250,750); 
    glutCreateWindow("RAIN WATER HARVESTING"); 
    myinit(); 
    glutDisplayFunc(display); 
    glutIdleFunc(idle); 
    glutKeyboardFunc(mykey); 
    glutMainLoop(); 
}

