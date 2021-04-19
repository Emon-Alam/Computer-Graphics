#include<windows.h>
#include <stdio.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
# define PI  3.14159265358979323846

GLfloat car_position1 = 0.0f;
GLfloat car_speed1 = 0.03f;
GLfloat car_position2 = 0.0f;
GLfloat car_speed2 = 0.03f;
GLfloat sun_position = 0.0f;
GLfloat sun_speed = 0.02f;
GLfloat plane_position = 0.0f;
GLfloat plane_speed = 0.05f;
GLfloat bird_position = 0.0f;
GLfloat bird_speed = 0.02f;
GLfloat cloud_position = 0.0f;
GLfloat cloud_speed = 0.003f;

GLfloat positioncld = 0.0f;
GLfloat speedcld = 0.002f;
GLfloat positionc1 = 0.0f;
GLfloat positionc2 = 0.0f;
GLfloat speedc1 = 0.015f;
GLfloat speedc2 = 0.0001f;
GLfloat positionship = 0.0f;
GLfloat speedship = 0.0015f;
GLfloat positionbus1 = 0.0f; //right to left
GLfloat positionbus2 = 0.0f; //left to right
GLfloat speedbus = 0.02f;
GLfloat position4 = 0.0f; //rain
GLfloat speed4 = 0.70f;


GLfloat i = 0.0f;      //i in center position


void update_bus1(int value) {  //bus1
    if(positionbus1 <-1.0)
        positionbus1 = 1.0f;  // right to left
    positionbus1 -= speedbus;
	glutPostRedisplay();
	glutTimerFunc(100, update_bus1, 0);
}
void update_bus2(int value) {  //bus2
    if(positionbus2 >1.0)
        positionbus2 = -1.0f;  // left to right
    positionbus2 += speedbus;
	glutPostRedisplay();
	glutTimerFunc(100, update_bus2, 0);
}
void update_ship(int value) {  //ship
    if(positionship <-1.0)
        positionship = 1.0f;  // right to left
    positionship -= speedship;
	glutPostRedisplay();
	glutTimerFunc(100, update_ship, 0);
}

void update_cld(int value) {  //cloud
    if(positioncld >1.0)
        positioncld = -1.0f;  //left to right
    positioncld += speedcld;
	glutPostRedisplay();
	glutTimerFunc(100, update_cld, 0);

}
void update_c1(int value) {  //wave
    if(positionc1 >1.0)
        positionc1 = -1.0f;  //left to right
    positionc1 += speedc1;
	glutPostRedisplay();
	glutTimerFunc(100, update_c1, 0);

}
void update_c2(int value) {  //sunrise
    if(positionc2 <-1.0)
        positionc2 = 0.6f;
    positionc2 += speedc2;
	glutPostRedisplay();
	glutTimerFunc(100, update_c2, 0);

}
void update4(int value) {

    if(position4<-1.0)
        position4 = 1.0f;

    position4 -= speed4;

	glutPostRedisplay();


	glutTimerFunc(100, update4, 0);
}

//day night
void update7(int value){
    if(car_position1 > 1.0)
        car_position1 = -1.0;
    car_position1 += car_speed1;
        glutPostRedisplay();
        glutTimerFunc(100, update7, 0);
}

void update8(int value){
    if(car_position2 < -1.0)
        car_position2 = 1.0;
    car_position2 -= car_speed2;
        glutPostRedisplay();
        glutTimerFunc(100, update8, 0);
}

void update9(int value){
    if(sun_position < -1.0)
        sun_position = 0.1;
//    sun_position -= sun_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update9, 0);
}

void update10(int value){
    if(plane_position > 1.0)
        plane_position = -1.0;
    plane_position += plane_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update10, 0);
}

void update11(int value){
    if(bird_position > 1.0)
        bird_position = -1.0;
    bird_position += bird_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update11, 0);
}

void update12(int value){
    if(cloud_position < -1.0)
        cloud_position = 1.0;
    cloud_position -= cloud_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update12, 0);
}

void sunrise()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

   glBegin(GL_QUADS);
    glColor3ub(176,224,230 ); //sky
    glVertex2f(1.0,0.7);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(-1.0,0.7);
    glEnd();

    glPushMatrix();
    glTranslatef(0.0f,positionc2, 0.0f);

int i;

    glColor3ub(255,215,0 );               // sun
	GLfloat x=0.0f; GLfloat y=0.7f; GLfloat radius =.16f;
	int triangleAmount = 20;

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

glBegin(GL_QUADS);
    glColor3ub(255,228,196 ); //sea soil
    glVertex2f(1.0,0.25);
    glVertex2f(-1.0,0.25);
    glVertex2f(-1.0,0.0);
    glVertex2f(1.0,0.0);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(150, 200, 255 ); //sea
    glVertex2f(1.0,0.7);
    glVertex2f(-1.0,0.7);
    glVertex2f(-1.0,0.25);
    glVertex2f(1.0,0.25);
    glEnd();


//wave circles
glPushMatrix();
    glTranslatef(positionc1,0.0f, 0.0f);



int z;
glColor3ub(150, 200, 255);               //
	GLfloat x20=-0.85f; GLfloat y20=0.48f; GLfloat radius20 =.24f;
	int triangleAmount20 = 20;

	GLfloat twicePi20 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x20, y20);
		for(z = 0; z <= triangleAmount20;z++) {
			glVertex2f(
		            x20 + (radius20 * cos(z *  twicePi20 / triangleAmount20)),
			    y20 + (radius20 * sin(z * twicePi20 / triangleAmount20))
			);
		}
	glEnd();

int w;
glColor3ub(150, 200, 255);               //
	GLfloat x21=-0.68f; GLfloat y21=0.42f; GLfloat radius21 =.18f;
	int triangleAmount21 = 20;

	GLfloat twicePi21 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x21, y21);
		for(w = 0; w<= triangleAmount21;w++) {
			glVertex2f(
		            x21 + (radius21 * cos(w *  twicePi21 / triangleAmount21)),
			    y21 + (radius21 * sin(w * twicePi21 / triangleAmount21))
			);
		}
	glEnd();

int v;
glColor3ub(150, 200, 255);               //
	GLfloat x22=-0.2f; GLfloat y22=0.48f; GLfloat radius22 =.24f;
	int triangleAmount22 = 20;

	GLfloat twicePi22 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x22, y22);
		for(v = 0; v<= triangleAmount22;v++) {
			glVertex2f(
		            x22 + (radius22 * cos(v *  twicePi22 / triangleAmount22)),
			    y22 + (radius22 * sin(v * twicePi22 / triangleAmount22))
			);
		}
	glEnd();
int q;
glColor3ub(150, 200, 255);               //
	GLfloat x27=0.31f; GLfloat y27=0.42f; GLfloat radius27 =.18f;
	int triangleAmount27 = 20;

	GLfloat twicePi27 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x27, y27);
		for(q = 0; q<= triangleAmount27;q++) {
			glVertex2f(
		            x27 + (radius27 * cos(q *  twicePi27 / triangleAmount27)),
			    y27 + (radius27 * sin(q * twicePi27 / triangleAmount27))
			);
		}
	glEnd();

int p;
glColor3ub(150, 200, 255);               //
	GLfloat x28=0.48f; GLfloat y28=0.48f; GLfloat radius28 =.24f;
	int triangleAmount28 = 20;

	GLfloat twicePi28 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x28, y28);
		for(p = 0; p<= triangleAmount28;p++) {
			glVertex2f(
		            x28 + (radius28 * cos(p *  twicePi28 / triangleAmount28)),
			    y28 + (radius28 * sin(p * twicePi28 / triangleAmount28))
			);
		}
	glEnd();

int o;
glColor3ub(150, 200, 255);               //
	GLfloat x29=-0.31f; GLfloat y29=0.42f; GLfloat radius29 =.18f;
	int triangleAmount29 = 20;

	GLfloat twicePi29 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x29, y29);
		for( o= 0; o<= triangleAmount29;o++) {
			glVertex2f(
		            x29 + (radius29 * cos(o *  twicePi29 / triangleAmount29)),
			    y29 + (radius29 * sin(o * twicePi29 / triangleAmount29))
			);
		}
	glEnd();

int n;
glColor3ub(150, 200, 255);               //
	GLfloat x30=-0.48f; GLfloat y30=0.48f; GLfloat radius30 =.24f;
	int triangleAmount30 = 20;

	GLfloat twicePi30 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x28, y28);
		for(n = 0; n<= triangleAmount30;n++) {
			glVertex2f(
		            x30 + (radius30 * cos(n *  twicePi30 / triangleAmount30)),
			    y30 + (radius30 * sin(n * twicePi30 / triangleAmount30))
			);
		}
	glEnd();
int u;
glColor3ub(150, 200, 255);               //
	GLfloat x23=-0.03f; GLfloat y23=0.42f; GLfloat radius23 =.18f;
	int triangleAmount23 = 20;

	GLfloat twicePi23 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x23, y23);
		for(u = 0; u<= triangleAmount23;u++) {
			glVertex2f(
		            x23 + (radius23 * cos(u *  twicePi23 / triangleAmount23)),
			    y23 + (radius23 * sin(u * twicePi23 / triangleAmount23))
			);
		}
	glEnd();

int s;
glColor3ub(150, 200, 255);               //
	GLfloat x24=0.85f; GLfloat y24=0.48f; GLfloat radius24 =.24f;
	int triangleAmount24 = 20;

	GLfloat twicePi24 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x24, y24);
		for(s = 0; s<= triangleAmount24;s++) {
			glVertex2f(
		            x24 + (radius24 * cos(s *  twicePi24 / triangleAmount24)),
			    y24 + (radius24 * sin(s * twicePi24 / triangleAmount24))
			);
		}
	glEnd();
	int t;
glColor3ub(150, 200, 255);               //
	GLfloat x25=0.68f; GLfloat y25=0.42f; GLfloat radius25 =.18f;
	int triangleAmount25 = 20;

	GLfloat twicePi25 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x25, y25);
		for(t = 0; t<= triangleAmount25;t++) {
			glVertex2f(
		            x25 + (radius25 * cos(t *  twicePi25 / triangleAmount25)),
			    y25 + (radius25 * sin(t * twicePi25 / triangleAmount25))
			);
		}
	glEnd();
int r;
glColor3ub(150, 200, 255);               //
	GLfloat x26=0.14f; GLfloat y26=0.48f; GLfloat radius26 =.24f;
	int triangleAmount26 = 20;

	GLfloat twicePi26 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x26, y26);
		for(r = 0; r<= triangleAmount26;r++) {
			glVertex2f(
		            x26 + (radius26 * cos(r *  twicePi26 / triangleAmount26)),
			    y26 + (radius26 * sin(r * twicePi26 / triangleAmount26))
			);
		}
	glEnd();

glPopMatrix();

glPushMatrix();
    glTranslatef(positioncld,0.0f, 0.0f);
//cloud

glBegin(GL_QUADS);
    glColor3ub(255,250,240);
    glVertex2f(-0.7,0.76);
    glVertex2f(-0.4,0.76);
    glVertex2f(-0.4,0.73);
    glVertex2f(-0.7,0.73);
    glEnd();


glColor3ub(255,250,240);                 //cloud 1
    x=-0.68f; y=0.78f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(255,250,240);                 //cloud 1
    x=-0.44f; y=0.78f;  radius =.05f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 1
    x=-0.52f; y=0.78f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 1
    x=-0.6f; y=0.81f;  radius =.065f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//cloud 2
glBegin(GL_QUADS);
    glColor3ub(255,250,240);
    glVertex2f(0.7,0.8);
    glVertex2f(0.4,0.8);
    glVertex2f(0.4,0.77);
    glVertex2f(0.7,0.77);
    glEnd();


glColor3ub(255,250,240);                 //cloud 2
    x=0.68f; y=0.82f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(255,250,240);                 //cloud 1
    x=0.42f; y=0.82f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 2
    x=0.49f; y=0.82f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 2
    x=0.59f; y=0.85f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();


glPushMatrix();
    glTranslatef(positionship,0.0f, 0.0f);
//ship
glBegin(GL_QUADS);      // ash quad ship
    glColor3ub(128,128,128);
    glVertex2f(0.8,0.5);
    glVertex2f(0.8,0.62);
    glVertex2f(0.45,0.62);
    glVertex2f(0.45,0.5);
    glEnd();
glBegin(GL_QUADS);      //black quad ship
    glColor3ub(0,0,0);
    glVertex2f(0.8,0.48);
    glVertex2f(0.83,0.55);
    glVertex2f(0.4,0.55);
    glVertex2f(0.45,0.48);
    glEnd();
//window
glBegin(GL_QUADS);
    glColor3ub(211,211,211);  //
    glVertex2f(0.78,0.58);
    glVertex2f(0.78,0.6);
    glVertex2f(0.75,0.6);
    glVertex2f(0.75,0.58);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(211,211,211);  //
    glVertex2f(0.73,0.58);
    glVertex2f(0.73,0.6);
    glVertex2f(0.70,0.6);
    glVertex2f(0.70,0.58);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(0.68,0.58);
    glVertex2f(0.68,0.6);
    glVertex2f(0.65,0.6);
    glVertex2f(0.65,0.58);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(0.63,0.58);
    glVertex2f(0.63,0.6);
    glVertex2f(0.60,0.6);
    glVertex2f(0.60,0.58);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(165,42,42 ); //brown quad
    glVertex2f(0.5,0.6);
    glVertex2f(0.5,0.56);
    glVertex2f(0.52,0.56);
    glVertex2f(0.52,0.6);
    glEnd();
glBegin(GL_QUADS);      // ash quad2 ship
    glColor3ub(128,128,128);
    glVertex2f(0.8,0.62);
    glVertex2f(0.8,0.68);
    glVertex2f(0.6,0.68);
    glVertex2f(0.6,0.62);
    glEnd();
//windows
glBegin(GL_QUADS);
    glColor3ub(211,211,211);  //
    glVertex2f(0.78,0.64);
    glVertex2f(0.78,0.66);
    glVertex2f(0.75,0.66);
    glVertex2f(0.75,0.64);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(211,211,211);  //
    glVertex2f(0.73,0.64);
    glVertex2f(0.73,0.66);
    glVertex2f(0.70,0.66);
    glVertex2f(0.70,0.64);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(0.68,0.64);
    glVertex2f(0.68,0.66);
    glVertex2f(0.65,0.66);
    glVertex2f(0.65,0.64);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(0.63,0.64);
    glVertex2f(0.63,0.66);
    glVertex2f(0.60,0.66);
    glVertex2f(0.60,0.64);
    glEnd();
// top air quad
glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(0.56,0.62);
    glVertex2f(0.56,0.68);
    glVertex2f(0.54,0.68);
    glVertex2f(0.54,0.62);
    glEnd();



glColor3ub(105,105,105);                 //mini box
    x=0.55f; y=0.69f;  radius =.007f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(105,105,105);                 //mini box
    x=0.57f; y=0.71f;  radius =.0065f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(105,105,105);                 //mini box
    x=0.59f; y=0.715f;  radius =.0065f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(0.53,0.62);
    glVertex2f(0.53,0.68);
    glVertex2f(0.51,0.68);
    glVertex2f(0.51,0.62);
    glEnd();

glColor3ub(105,105,105);                 //mini box
    x=0.525f; y=0.7f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(105,105,105);                 //mini box
    x=0.51f; y=0.69f;  radius =.007f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3ub(105,105,105);                 //mini box
    x=0.545f; y=0.712f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//flag
glBegin(GL_QUADS);
    glColor3ub(188,143,143);
    glVertex2f(0.43,0.55);
    glVertex2f(0.43,0.65);
    glVertex2f(0.42,0.65);
    glVertex2f(0.42,0.55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245,245,245);
    glVertex2f(0.42,0.65);
     glVertex2f(0.38,0.635);
     glVertex2f(0.42,0.62);
     glEnd();
//bottom window
glBegin(GL_QUADS);
    glColor3ub(240,248,255);
    glVertex2f(0.47,0.525);
    glVertex2f(0.47,0.54);
    glVertex2f(0.43,0.54);
    glVertex2f(0.43,0.525);
    glEnd();

glPopMatrix();

//green
glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(1.0,0.0);
     glVertex2f(1.0,0.08);
     glVertex2f(0.3,0.0);
     glEnd();

glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-1.0,0.0);
     glVertex2f(-0.2,0.05);
     glVertex2f(-1.0,0.1);
     glEnd();
glColor3ub(255,228,196);                 //circle
    x=-0.25f; y=0.05f;  radius =.1f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,228,196);                 //circle
    x=-0.4f; y=0.05f;  radius =.1f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glBegin(GL_QUADS);
    glColor3ub(0,100,0); //green
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glEnd();

    glBegin(GL_QUADS);     //whole - axis
    glColor3ub(100,113,135);
    glVertex2f(1.0,-0.68);
    glVertex2f(-1.0,-0.68);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glEnd();

//house 6
glBegin(GL_QUADS);
    glColor3ub(255,228,196); //down
    glVertex2f(-0.8,-0.1);
    glVertex2f(-0.95,-0.1);
    glVertex2f(-0.95,-0.2);
    glVertex2f(-0.8,-0.2);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,69,0);  //up
    glVertex2f(-0.75,-0.13);
    glVertex2f(-1.0,-0.13);
    glVertex2f(-0.95,-0.08);
    glVertex2f(-0.8,-0.08);
    glEnd();

//house 7
glBegin(GL_QUADS);
    glColor3ub(255,228,196); //down
    glVertex2f(-0.7,-0.1);
    glVertex2f(-0.55,-0.1);
    glVertex2f(-0.55,-0.2);
    glVertex2f(-0.7,-0.2);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,69,0 );  //up
    glVertex2f(-0.5,-0.13);
    glVertex2f(-0.55,-0.08);
    glVertex2f(-0.7,-0.08);
    glVertex2f(-0.75,-0.13);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(138,43,226);  //window
    glVertex2f(-0.57,-0.18);
    glVertex2f(-0.57,-0.14);
    glVertex2f(-0.61,-0.14);
    glVertex2f(-0.61,-0.18);
    glEnd();
//house 1
glBegin(GL_QUADS);
    glColor3ub(219,112,147); //down
    glVertex2f(-1.0,-0.5);
    glVertex2f(-0.6,-0.5);
    glVertex2f(-0.6,-0.3);
    glVertex2f(-1.0,-0.3);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(176,196,222);  //up
    glVertex2f(-1.0,-0.3);
    glVertex2f(-0.55,-0.3);
    glVertex2f(-0.65,-0.15);
    glVertex2f(-1.0,-0.15);
    glEnd();

//house 2
glBegin(GL_QUADS);
    glColor3ub(139,69,19); //down
    glVertex2f(-1.0,-0.6);
    glVertex2f(-0.7,-0.6);
    glVertex2f(-0.7,-0.3);
    glVertex2f(-1.0,-0.3);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(112,128,144);  //up
    glVertex2f(-1.0,-0.4);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.73,-0.26);
    glVertex2f(-1.0,-0.26);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(170, 120, 70);  //door
    glVertex2f(-0.89,-0.6);
    glVertex2f(-0.81,-0.6);
    glVertex2f(-0.81,-0.45);
    glVertex2f(-0.89,-0.45);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,182,193);  //window
    glVertex2f(-0.73,-0.54);
    glVertex2f(-0.73,-0.49);
    glVertex2f(-0.785,-0.49);
    glVertex2f(-0.785,-0.54);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,182,193);  //window
    glVertex2f(-0.975,-0.54);
    glVertex2f(-0.975,-0.49);
    glVertex2f(-0.925,-0.49);
    glVertex2f(-0.925,-0.54);
    glEnd();



//house 3
glBegin(GL_QUADS);
    glColor3ub(192,192,192); //down
    glVertex2f(0.3,-0.2);
    glVertex2f(0.7,-0.2);
    glVertex2f(0.7,-0.3);
    glVertex2f(0.3,-0.3);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(219,112,147);  //up
    glVertex2f(0.25,-0.23);
    glVertex2f(0.75,-0.23);
    glVertex2f(0.7,-0.18);
    glVertex2f(0.3,-0.18);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //door
    glVertex2f(0.46,-0.25);
    glVertex2f(0.54,-0.25);
    glVertex2f(0.54,-0.3);
    glVertex2f(0.46,-0.3);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.6,-0.25);
    glVertex2f(0.65,-0.25);
    glVertex2f(0.65,-0.29);
    glVertex2f(0.6,-0.29);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.35,-0.25);
    glVertex2f(0.4,-0.25);
    glVertex2f(0.4,-0.29);
    glVertex2f(0.35,-0.29);
    glEnd();
//house 4
glBegin(GL_QUADS);
    glColor3ub(192,192,192); //down
    glVertex2f(0.8,-0.4);
    glVertex2f(0.95,-0.4);
    glVertex2f(0.95,-0.5);
    glVertex2f(0.8,-0.5);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(244,164,96 );  //up
    glVertex2f(0.75,-0.43);
    glVertex2f(1.0,-0.43);
    glVertex2f(0.95,-0.38);
    glVertex2f(0.8,-0.38);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //door
    glVertex2f(0.86,-0.445);
    glVertex2f(0.88,-0.445);
    glVertex2f(0.88,-0.5);
    glVertex2f(0.86,-0.5);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.90,-0.46);
    glVertex2f(0.93,-0.46);
    glVertex2f(0.93,-0.49);
    glVertex2f(0.90,-0.49);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.82,-0.46);
    glVertex2f(0.85,-0.46);
    glVertex2f(0.85,-0.49);
    glVertex2f(0.82,-0.49);
    glEnd();

//house 5
glBegin(GL_QUADS);
    glColor3ub(192,192,192); //down
    glVertex2f(0.8,-0.2);
    glVertex2f(0.95,-0.2);
    glVertex2f(0.95,-0.3);
    glVertex2f(0.8,-0.3);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(64,224,208);  //up
    glVertex2f(0.75,-0.23);
    glVertex2f(1.0,-0.23);
    glVertex2f(0.95,-0.18);
    glVertex2f(0.8,-0.18);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //door
    glVertex2f(0.86,-0.245);
    glVertex2f(0.88,-0.245);
    glVertex2f(0.88,-0.3);
    glVertex2f(0.86,-0.3);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.90,-0.26);
    glVertex2f(0.93,-0.26);
    glVertex2f(0.93,-0.29);
    glVertex2f(0.90,-0.29);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.82,-0.26);
    glVertex2f(0.85,-0.26);
    glVertex2f(0.85,-0.29);
    glVertex2f(0.82,-0.29);
    glEnd();

//ground
glBegin(GL_QUADS);
    glColor3ub(210, 170, 120);
    glVertex2f(0.4,-0.15);
    glVertex2f(0.7,-0.15);
    glVertex2f(0.7,0.0);
    glVertex2f(0.4,0.0);
    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.55,0.0);
    glVertex2f(0.55,-0.15);


glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.7,-0.05);
    glVertex2f(0.67,-0.05);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.67,-0.05);
    glVertex2f(0.67,-0.10);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.67,-0.10);
    glVertex2f(0.7,-0.10);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.4,-0.05);
    glVertex2f(0.43,-0.05);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.43,-0.05);
    glVertex2f(0.43,-0.10);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.43,-0.10);
    glVertex2f(0.4,-0.10);
    glEnd();



	GLfloat x40=0.55f; GLfloat y40=-0.07f; GLfloat radius40 =.03f; //center of field
	int k;
	int lineAmount40 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi40 = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
		for(k = 0; k <= lineAmount40;k++) {
			glVertex2f(
			    x40 + (radius40 * cos(k *  twicePi40 / lineAmount40)),
			    y40 + (radius40* sin(k * twicePi40 / lineAmount40))
			);
		}
	glEnd();

glColor3ub(50,50,50  );                 //players
    x=0.46f; y=-0.07f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.5f; y=-0.10f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.67f; y=-0.02f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.53f; y=-0.012f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.64f; y=-0.09f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.6f; y=-0.05f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



// bench 1
glBegin(GL_QUADS);
    glColor3ub(100,149,237 );
    glVertex2f(0.5,-0.36);
    glVertex2f(0.5,-0.4);
    glVertex2f(0.3,-0.4);
    glVertex2f(0.3,-0.36);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(50,50,50 );  //legs
    glVertex2f(0.45,-0.4);
    glVertex2f(0.45,-0.44);
    glVertex2f(0.47,-0.44);
    glVertex2f(0.47,-0.4);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(50,50,50 );  //legs
    glVertex2f(0.35,-0.4);
    glVertex2f(0.35,-0.44);
    glVertex2f(0.33,-0.44);
    glVertex2f(0.33,-0.4);
    glEnd();

// bench 2
glBegin(GL_QUADS);
    glColor3ub(100,149,237 );
    glVertex2f(0.75,-0.46);
    glVertex2f(0.75,-0.5);
    glVertex2f(0.55,-0.5);
    glVertex2f(0.55,-0.46);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(50,50,50 );  //legs
    glVertex2f(0.7,-0.5);
    glVertex2f(0.7,-0.54);
    glVertex2f(0.72,-0.54);
    glVertex2f(0.72,-0.5);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(50,50,50 );  //legs
    glVertex2f(0.6,-0.5);
    glVertex2f(0.6,-0.54);
    glVertex2f(0.58,-0.54);
    glVertex2f(0.58,-0.5);
    glEnd();
//road quad
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(0.8,-0.86);
    glVertex2f(0.8,-0.82);
    glVertex2f(0.6,-0.82);
    glVertex2f(0.6,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(0.4,-0.86);
    glVertex2f(0.4,-0.82);
    glVertex2f(0.2,-0.82);
    glVertex2f(0.2,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(0.0,-0.86);
    glVertex2f(0.0,-0.82);
    glVertex2f(-0.2,-0.82);
    glVertex2f(-0.2,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(-0.4,-0.86);
    glVertex2f(-0.4,-0.82);
    glVertex2f(-0.6,-0.82);
    glVertex2f(-0.6,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(-0.8,-0.86);
    glVertex2f(-0.8,-0.82);
    glVertex2f(-0.99,-0.82);
    glVertex2f(-0.99,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(0.98,-0.86);
    glVertex2f(0.98,-0.82);
    glVertex2f(1.0,-0.82);
    glVertex2f(1.0,-0.86);
    glEnd();


//bus2
glPushMatrix();
    glTranslatef(positionbus2,0.0f, 0.0f);
glColor3ub(238,130,238 );
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.87);
	glVertex2f(-0.35,-0.97);
	glVertex2f(-0.7,-0.97);
	glVertex2f(-0.7,-0.87);
	glEnd();
glColor3ub(50,50,50 ); //front
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.87);
	glVertex2f(-0.35,-0.93);
	glVertex2f(-0.4,-0.93);
	glVertex2f(-0.4,-0.87);
	glEnd();
glColor3ub(238,130,238 ); //front2
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.88);
	glVertex2f(-0.35,-0.90);
	glVertex2f(-0.37,-0.90);
	glVertex2f(-0.37,-0.88);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(-0.44,-0.89);
	glVertex2f(-0.44,-0.92);
	glVertex2f(-0.48,-0.92);
	glVertex2f(-0.48,-0.89);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(-0.52,-0.89);
	glVertex2f(-0.52,-0.92);
	glVertex2f(-0.56,-0.92);
	glVertex2f(-0.56,-0.89);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(-0.6,-0.89);
	glVertex2f(-0.6,-0.92);
	glVertex2f(-0.64,-0.92);
	glVertex2f(-0.64,-0.89);
	glEnd();


glColor3ub(50,50,50  );                 //tire
    x=-0.45f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=-0.41f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=-0.64f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(50,50,50  );                 //tire
    x=-0.6f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();


//bus1
glPushMatrix();
    glTranslatef(positionbus1,0.0f, 0.0f);
glColor3ub(238,130,238 );
	glBegin(GL_QUADS);
	glVertex2f(0.35,-0.71);
	glVertex2f(0.35,-0.81);
	glVertex2f(0.7,-0.81);
	glVertex2f(0.7,-0.71);
	glEnd();
glColor3ub(50,50,50 ); //front
	glBegin(GL_QUADS);
	glVertex2f(0.35,-0.71);
	glVertex2f(0.35,-0.78);
	glVertex2f(0.4,-0.78);
	glVertex2f(0.4,-0.71);
	glEnd();
glColor3ub(238,130,238 ); //front2
	glBegin(GL_QUADS);
	glVertex2f(0.35,-0.72);
	glVertex2f(0.35,-0.74);
	glVertex2f(0.37,-0.74);
	glVertex2f(0.37,-0.72);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(0.44,-0.73);
	glVertex2f(0.44,-0.77);
	glVertex2f(0.48,-0.77);
	glVertex2f(0.48,-0.73);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(0.52,-0.73);
	glVertex2f(0.52,-0.77);
	glVertex2f(0.56,-0.77);
	glVertex2f(0.56,-0.73);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(0.6,-0.73);
	glVertex2f(0.6,-0.77);
	glVertex2f(0.64,-0.77);
	glVertex2f(0.64,-0.73);
	glEnd();


glColor3ub(50,50,50  );                 //tire
    x=0.45f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=0.41f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=0.64f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(50,50,50  );                 //tire
    x=0.6f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

//tree1

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.5);
	glVertex2f(-0.35,-0.65);
	glVertex2f(-0.4,-0.65);
	glVertex2f(-0.4,-0.5);
	glEnd();
glColor3ub(10,150,10);
    x=-0.38f; y=-0.45f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=-0.34f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=-0.42f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree2

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(0.15,-0.5);
	glVertex2f(0.15,-0.65);
	glVertex2f(0.2,-0.65);
	glVertex2f(0.2,-0.5);
	glEnd();
glColor3ub(10,150,10);
    x=0.18f; y=-0.45f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.22f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.14f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree3

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(0.15,-0.15);
	glVertex2f(0.15,-0.3);
	glVertex2f(0.2,-0.3);
	glVertex2f(0.2,-0.15);
	glEnd();
glColor3ub(10,150,10);
    x=0.18f; y=-0.1f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.22f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.14f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree1

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.15);
	glVertex2f(-0.35,-0.3);
	glVertex2f(-0.4,-0.3);
	glVertex2f(-0.4,-0.15);
	glEnd();
glColor3ub(10,150,10);
    x=-0.38f; y=-0.10f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=-0.34f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=-0.42f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree5

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(0.9,-0.05);
	glVertex2f(0.9,-0.1);
	glVertex2f(0.95,-0.1);
	glVertex2f(0.95,-0.05);
	glEnd();
glColor3ub(10,150,10);
    x=0.92f; y=-0.02f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.91f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.94f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
//tree6

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(0.8,-0.05);
	glVertex2f(0.8,-0.1);
	glVertex2f(0.85,-0.1);
	glVertex2f(0.85,-0.05);
	glEnd();
glColor3ub(10,150,10);
    x=0.82f; y=-0.02f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.81f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.84f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



// swimming tire
glColor3ub(128,0,0);
    x=-0.6f; y=0.15f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,228,196);
    x=-0.6f; y=0.15f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//3rd
glColor3ub(0,0,128 );
    x=-0.7f; y=0.12f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,228,196);
    x=-0.7f; y=0.12f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//2nd
glColor3ub(255,165,0 );
    x=-0.65f; y=0.2f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,228,196);
    x=-0.65f; y=0.2f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
//4 on the sea
glColor3ub(128,0,0);
    x=-0.35f; y=0.35f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(150, 200, 255);
    x=-0.35f; y=0.35f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//human1
glColor3ub(0,0,0);
    x=-0.35f; y=0.37f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.38,0.35);
	glVertex2f(-0.38,0.305);
	glVertex2f(-0.32,0.305);
	glVertex2f(-0.32,0.35);
	glEnd();
glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.27,0.35);
	glVertex2f(-0.27,0.32);
	glVertex2f(-0.32,0.32);
	glVertex2f(-0.32,0.35);
	glEnd();
glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.38,0.35);
	glVertex2f(-0.38,0.32);
	glVertex2f(-0.43,0.32);
	glVertex2f(-0.43,0.35);
	glEnd();

//5 on the sea
glColor3ub(255,69,0);
    x=-0.85f; y=0.35f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(150, 200, 255);
    x=-0.85f; y=0.35f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//human2

glColor3ub(0,0,0);
    x=-0.85f; y=0.37f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.88,0.35);
	glVertex2f(-0.88,0.305);
	glVertex2f(-0.82,0.305);
	glVertex2f(-0.82,0.35);
	glEnd();
glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.77,0.35);
	glVertex2f(-0.77,0.32);
	glVertex2f(-0.82,0.32);
	glVertex2f(-0.82,0.35);
	glEnd();
glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.88,0.35);
	glVertex2f(-0.88,0.32);
	glVertex2f(-0.93,0.32);
	glVertex2f(-0.93,0.35);
	glEnd();



//beach

glColor3ub(72,209,204   );
	glBegin(GL_QUADS);
	glVertex2f(-0.2,0.05);
	glVertex2f(-0.2,0.2);
	glVertex2f(-0.1,0.2);
	glVertex2f(-0.1,0.05);
	glEnd();
glColor3ub(250,250,250  );
	glBegin(GL_QUADS);
	glVertex2f(-0.12,0.05);
	glVertex2f(-0.12,0.2);
	glVertex2f(-0.14,0.2);
	glVertex2f(-0.14,0.05);
	glEnd();
glColor3ub(250,250,250   );
	glBegin(GL_QUADS);
	glVertex2f(-0.16,0.05);
	glVertex2f(-0.16,0.2);
	glVertex2f(-0.18,0.2);
	glVertex2f(-0.18,0.05);
	glEnd();
//2
glColor3ub(199,21,133   );
	glBegin(GL_QUADS);
	glVertex2f(0.0,0.05);
	glVertex2f(0.0,0.2);
	glVertex2f(-0.1,0.2);
	glVertex2f(-0.1,0.05);
	glEnd();
glColor3ub(250,250,250  );
	glBegin(GL_QUADS);
	glVertex2f(-0.02,0.05);
	glVertex2f(-0.02,0.2);
	glVertex2f(-0.04,0.2);
	glVertex2f(-0.04,0.05);
	glEnd();
glColor3ub(250,250,250   );
	glBegin(GL_QUADS);
	glVertex2f(-0.06,0.05);
	glVertex2f(-0.06,0.2);
	glVertex2f(-0.08,0.2);
	glVertex2f(-0.08,0.05);
	glEnd();

//3

glColor3ub(199,21,133   );
	glBegin(GL_QUADS);
	glVertex2f(0.7,0.25);
	glVertex2f(0.7,0.15);
	glVertex2f(0.9,0.15);
	glVertex2f(0.9,0.25);
	glEnd();

glColor3ub(250,250,250  );
	glBegin(GL_QUADS);
	glVertex2f(0.7,0.19);
	glVertex2f(0.7,0.17);
	glVertex2f(0.9,0.17);
	glVertex2f(0.9,0.19);
	glEnd();
glColor3ub(250,250,250   );
    glBegin(GL_QUADS);
	glVertex2f(0.7,0.22);
	glVertex2f(0.7,0.24);
	glVertex2f(0.9,0.24);
	glVertex2f(0.9,0.22);
	glEnd();

//4

glColor3ub(255,105,180  );
	glBegin(GL_QUADS);
	glVertex2f(0.3,0.05);
	glVertex2f(0.3,0.2);
	glVertex2f(0.2,0.2);
	glVertex2f(0.2,0.05);
	glEnd();
glColor3ub(250,250,250  );
	glBegin(GL_QUADS);
	glVertex2f(0.22,0.05);
	glVertex2f(0.22,0.2);
	glVertex2f(0.24,0.2);
	glVertex2f(0.24,0.05);
	glEnd();
glColor3ub(250,250,250   );
	glBegin(GL_QUADS);
	glVertex2f(0.26,0.05);
	glVertex2f(0.26,0.2);
	glVertex2f(0.28,0.2);
	glVertex2f(0.28,0.05);
	glEnd();


   glFlush();
    }

void beach_night()
{
     glClearColor(0.0,0.0,0.0,1.0);
   glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();

   glBegin(GL_QUADS);
    glColor3ub(30,30,150  ); //sky
    glVertex2f(1.0,0.7);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(-1.0,0.7);
    glEnd();

//glPushMatrix();
  //  glTranslatef(0.0f,positionc2, 0.0f);
int i;

    glColor3ub(220,220,220);               // moon
	GLfloat x=0.8f; GLfloat y=0.85f; GLfloat radius =.11f;
	int triangleAmount = 20;

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
//glPopMatrix();

//stars
glColor3ub(255,235,205);
    x=-0.9f; y=0.85f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.15f; y=0.8f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.5f; y=0.75f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.7f; y=0.75f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.77f; y=0.9f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.35f; y=0.9f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.8f; y=0.84f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,235,205);
    x=0.1f; y=0.85f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,235,205);
    x=0.47f; y=0.78f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.55f; y=0.55f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


glColor3ub(255,235,205);
    x=0.75f; y=0.87f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();




glBegin(GL_QUADS);
    glColor3ub(130, 130, 110); //sea soil
    glVertex2f(1.0,0.25);
    glVertex2f(-1.0,0.25);
    glVertex2f(-1.0,0.0);
    glVertex2f(1.0,0.0);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(15, 15, 100 ); //sea
    glVertex2f(1.0,0.7);
    glVertex2f(-1.0,0.7);
    glVertex2f(-1.0,0.25);
    glVertex2f(1.0,0.25);
    glEnd();


//wave circles
glPushMatrix();
    glTranslatef(positionc1,0.0f, 0.0f);



int z;
glColor3ub(15, 15, 100);               //
	GLfloat x20=-0.85f; GLfloat y20=0.48f; GLfloat radius20 =.24f;
	int triangleAmount20 = 20;

	GLfloat twicePi20 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x20, y20);
		for(z = 0; z <= triangleAmount20;z++) {
			glVertex2f(
		            x20 + (radius20 * cos(z *  twicePi20 / triangleAmount20)),
			    y20 + (radius20 * sin(z * twicePi20 / triangleAmount20))
			);
		}
	glEnd();

int w;
glColor3ub(15, 15, 100);               //
	GLfloat x21=-0.68f; GLfloat y21=0.42f; GLfloat radius21 =.18f;
	int triangleAmount21 = 20;

	GLfloat twicePi21 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x21, y21);
		for(w = 0; w<= triangleAmount21;w++) {
			glVertex2f(
		            x21 + (radius21 * cos(w *  twicePi21 / triangleAmount21)),
			    y21 + (radius21 * sin(w * twicePi21 / triangleAmount21))
			);
		}
	glEnd();

int v;
glColor3ub(15, 15, 100);               //
	GLfloat x22=-0.2f; GLfloat y22=0.48f; GLfloat radius22 =.24f;
	int triangleAmount22 = 20;

	GLfloat twicePi22 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x22, y22);
		for(v = 0; v<= triangleAmount22;v++) {
			glVertex2f(
		            x22 + (radius22 * cos(v *  twicePi22 / triangleAmount22)),
			    y22 + (radius22 * sin(v * twicePi22 / triangleAmount22))
			);
		}
	glEnd();
int q;
glColor3ub(15, 15, 100);               //
	GLfloat x27=0.31f; GLfloat y27=0.42f; GLfloat radius27 =.18f;
	int triangleAmount27 = 20;

	GLfloat twicePi27 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x27, y27);
		for(q = 0; q<= triangleAmount27;q++) {
			glVertex2f(
		            x27 + (radius27 * cos(q *  twicePi27 / triangleAmount27)),
			    y27 + (radius27 * sin(q * twicePi27 / triangleAmount27))
			);
		}
	glEnd();

int p;
glColor3ub(15, 15, 100);               //
	GLfloat x28=0.48f; GLfloat y28=0.48f; GLfloat radius28 =.24f;
	int triangleAmount28 = 20;

	GLfloat twicePi28 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x28, y28);
		for(p = 0; p<= triangleAmount28;p++) {
			glVertex2f(
		            x28 + (radius28 * cos(p *  twicePi28 / triangleAmount28)),
			    y28 + (radius28 * sin(p * twicePi28 / triangleAmount28))
			);
		}
	glEnd();

int o;
glColor3ub(15, 15, 100);               //
	GLfloat x29=-0.31f; GLfloat y29=0.42f; GLfloat radius29 =.18f;
	int triangleAmount29 = 20;

	GLfloat twicePi29 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x29, y29);
		for( o= 0; o<= triangleAmount29;o++) {
			glVertex2f(
		            x29 + (radius29 * cos(o *  twicePi29 / triangleAmount29)),
			    y29 + (radius29 * sin(o * twicePi29 / triangleAmount29))
			);
		}
	glEnd();

int n;
glColor3ub(15, 15, 100);               //
	GLfloat x30=-0.48f; GLfloat y30=0.48f; GLfloat radius30 =.24f;
	int triangleAmount30 = 20;

	GLfloat twicePi30 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x28, y28);
		for(n = 0; n<= triangleAmount30;n++) {
			glVertex2f(
		            x30 + (radius30 * cos(n *  twicePi30 / triangleAmount30)),
			    y30 + (radius30 * sin(n * twicePi30 / triangleAmount30))
			);
		}
	glEnd();
int u;
glColor3ub(15, 15, 100);               //
	GLfloat x23=-0.03f; GLfloat y23=0.42f; GLfloat radius23 =.18f;
	int triangleAmount23 = 20;

	GLfloat twicePi23 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x23, y23);
		for(u = 0; u<= triangleAmount23;u++) {
			glVertex2f(
		            x23 + (radius23 * cos(u *  twicePi23 / triangleAmount23)),
			    y23 + (radius23 * sin(u * twicePi23 / triangleAmount23))
			);
		}
	glEnd();

int s;
glColor3ub(15, 15, 100);               //
	GLfloat x24=0.85f; GLfloat y24=0.48f; GLfloat radius24 =.24f;
	int triangleAmount24 = 20;

	GLfloat twicePi24 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x24, y24);
		for(s = 0; s<= triangleAmount24;s++) {
			glVertex2f(
		            x24 + (radius24 * cos(s *  twicePi24 / triangleAmount24)),
			    y24 + (radius24 * sin(s * twicePi24 / triangleAmount24))
			);
		}
	glEnd();
	int t;
glColor3ub(15, 15, 100);               //
	GLfloat x25=0.68f; GLfloat y25=0.42f; GLfloat radius25 =.18f;
	int triangleAmount25 = 20;

	GLfloat twicePi25 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x25, y25);
		for(t = 0; t<= triangleAmount25;t++) {
			glVertex2f(
		            x25 + (radius25 * cos(t *  twicePi25 / triangleAmount25)),
			    y25 + (radius25 * sin(t * twicePi25 / triangleAmount25))
			);
		}
	glEnd();
int r;
glColor3ub(15, 15, 100);               //
	GLfloat x26=0.14f; GLfloat y26=0.48f; GLfloat radius26 =.24f;
	int triangleAmount26 = 20;

	GLfloat twicePi26 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x26, y26);
		for(r = 0; r<= triangleAmount26;r++) {
			glVertex2f(
		            x26 + (radius26 * cos(r *  twicePi26 / triangleAmount26)),
			    y26 + (radius26 * sin(r * twicePi26 / triangleAmount26))
			);
		}
	glEnd();

glPopMatrix();

glPushMatrix();
    glTranslatef(positioncld,0.0f, 0.0f);
//cloud

glBegin(GL_QUADS);
    glColor3ub(190,190,190);
    glVertex2f(-0.7,0.76);
    glVertex2f(-0.4,0.76);
    glVertex2f(-0.4,0.73);
    glVertex2f(-0.7,0.73);
    glEnd();


glColor3ub(190,190,190);                 //cloud 1
    x=-0.68f; y=0.78f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(190,190,190);                 //cloud 1
    x=-0.44f; y=0.78f;  radius =.05f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(190,190,190);                 //cloud 1
    x=-0.52f; y=0.78f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(190,190,190);                 //cloud 1
    x=-0.6f; y=0.81f;  radius =.065f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//cloud 2
glBegin(GL_QUADS);
    glColor3ub(190,190,190);
    glVertex2f(0.7,0.8);
    glVertex2f(0.4,0.8);
    glVertex2f(0.4,0.77);
    glVertex2f(0.7,0.77);
    glEnd();


glColor3ub(190,190,190);                 //cloud 2
    x=0.68f; y=0.82f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(190,190,190);                 //cloud 1
    x=0.42f; y=0.82f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(190,190,190);                 //cloud 2
    x=0.49f; y=0.82f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(190,190,190);                 //cloud 2
    x=0.59f; y=0.85f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();


glPushMatrix();
    glTranslatef(positionship,0.0f, 0.0f);
//ship
glBegin(GL_QUADS);      // ash quad ship
    glColor3ub(100,100,100);
    glVertex2f(0.8,0.5);
    glVertex2f(0.8,0.62);
    glVertex2f(0.45,0.62);
    glVertex2f(0.45,0.5);
    glEnd();
glBegin(GL_QUADS);      //black quad ship
    glColor3ub(0,0,0);
    glVertex2f(0.8,0.48);
    glVertex2f(0.83,0.55);
    glVertex2f(0.4,0.55);
    glVertex2f(0.45,0.48);
    glEnd();
//window
glBegin(GL_QUADS);
    glColor3ub(255,215,0 );  //
    glVertex2f(0.78,0.58);
    glVertex2f(0.78,0.6);
    glVertex2f(0.75,0.6);
    glVertex2f(0.75,0.58);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0 );  //
    glVertex2f(0.73,0.58);
    glVertex2f(0.73,0.6);
    glVertex2f(0.70,0.6);
    glVertex2f(0.70,0.58);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(255,215,0 );
    glVertex2f(0.68,0.58);
    glVertex2f(0.68,0.6);
    glVertex2f(0.65,0.6);
    glVertex2f(0.65,0.58);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0 );
    glVertex2f(0.63,0.58);
    glVertex2f(0.63,0.6);
    glVertex2f(0.60,0.6);
    glVertex2f(0.60,0.58);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(165,42,42 ); //brown quad
    glVertex2f(0.5,0.6);
    glVertex2f(0.5,0.56);
    glVertex2f(0.52,0.56);
    glVertex2f(0.52,0.6);
    glEnd();
glBegin(GL_QUADS);      // ash quad2 ship
    glColor3ub(100,100,100);
    glVertex2f(0.8,0.62);
    glVertex2f(0.8,0.68);
    glVertex2f(0.6,0.68);
    glVertex2f(0.6,0.62);
    glEnd();
//windows
glBegin(GL_QUADS);
    glColor3ub(255,215,0 );  //
    glVertex2f(0.78,0.64);
    glVertex2f(0.78,0.66);
    glVertex2f(0.75,0.66);
    glVertex2f(0.75,0.64);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0 );  //
    glVertex2f(0.73,0.64);
    glVertex2f(0.73,0.66);
    glVertex2f(0.70,0.66);
    glVertex2f(0.70,0.64);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(255,215,0 );
    glVertex2f(0.68,0.64);
    glVertex2f(0.68,0.66);
    glVertex2f(0.65,0.66);
    glVertex2f(0.65,0.64);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0 );
    glVertex2f(0.63,0.64);
    glVertex2f(0.63,0.66);
    glVertex2f(0.60,0.66);
    glVertex2f(0.60,0.64);
    glEnd();
// top air quad
glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(0.56,0.62);
    glVertex2f(0.56,0.68);
    glVertex2f(0.54,0.68);
    glVertex2f(0.54,0.62);
    glEnd();



glColor3ub(105,105,105);                 //mini box
    x=0.55f; y=0.69f;  radius =.007f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


glColor3ub(105,105,105);                 //mini box
    x=0.57f; y=0.71f;  radius =.0065f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(105,105,105);                 //mini box
    x=0.59f; y=0.715f;  radius =.0065f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(0.53,0.62);
    glVertex2f(0.53,0.68);
    glVertex2f(0.51,0.68);
    glVertex2f(0.51,0.62);
    glEnd();

glColor3ub(105,105,105);                 //mini box
    x=0.525f; y=0.7f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(105,105,105);                 //mini box
    x=0.51f; y=0.69f;  radius =.007f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3ub(105,105,105);                 //mini box
    x=0.545f; y=0.712f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//flag
glBegin(GL_QUADS);
    glColor3ub(188,143,143);
    glVertex2f(0.43,0.55);
    glVertex2f(0.43,0.65);
    glVertex2f(0.42,0.65);
    glVertex2f(0.42,0.55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245,245,245);
    glVertex2f(0.42,0.65);
     glVertex2f(0.38,0.635);
     glVertex2f(0.42,0.62);
     glEnd();
//bottom window
glBegin(GL_QUADS);
    glColor3ub(240,248,255);
    glVertex2f(0.47,0.525);
    glVertex2f(0.47,0.54);
    glVertex2f(0.43,0.54);
    glVertex2f(0.43,0.525);
    glEnd();

glPopMatrix();

//green
glBegin(GL_TRIANGLES);
    glColor3ub(0, 60, 0);
    glVertex2f(1.0,0.0);
     glVertex2f(1.0,0.08);
     glVertex2f(0.3,0.0);
     glEnd();

glBegin(GL_TRIANGLES);
    glColor3ub(0,60,0);
    glVertex2f(-1.0,0.0);
     glVertex2f(-0.2,0.05);
     glVertex2f(-1.0,0.1);
     glEnd();


glColor3ub(130, 130, 110);                 //circle
    x=-0.25f; y=0.05f;  radius =.1f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(130, 130, 110);                 //circle
    x=-0.4f; y=0.05f;  radius =.1f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glBegin(GL_QUADS);
    glColor3ub(0,60,0); //green
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glEnd();

    glBegin(GL_QUADS);     //whole - axis
    glColor3ub(70,70,70);
    glVertex2f(1.0,-0.68);
    glVertex2f(-1.0,-0.68);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glEnd();

//house 6
glBegin(GL_QUADS);
    glColor3ub(180, 180, 130); //down
    glVertex2f(-0.8,-0.1);
    glVertex2f(-0.95,-0.1);
    glVertex2f(-0.95,-0.2);
    glVertex2f(-0.8,-0.2);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(150, 50, 0);  //up
    glVertex2f(-0.75,-0.13);
    glVertex2f(-1.0,-0.13);
    glVertex2f(-0.95,-0.08);
    glVertex2f(-0.8,-0.08);
    glEnd();

//house 7
glBegin(GL_QUADS);
    glColor3ub(180, 180, 130); //down
    glVertex2f(-0.7,-0.1);
    glVertex2f(-0.55,-0.1);
    glVertex2f(-0.55,-0.2);
    glVertex2f(-0.7,-0.2);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(150, 50, 0 );  //up
    glVertex2f(-0.5,-0.13);
    glVertex2f(-0.55,-0.08);
    glVertex2f(-0.7,-0.08);
    glVertex2f(-0.75,-0.13);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0);  //window
    glVertex2f(-0.57,-0.18);
    glVertex2f(-0.57,-0.14);
    glVertex2f(-0.61,-0.14);
    glVertex2f(-0.61,-0.18);
    glEnd();
//house 1
glBegin(GL_QUADS);
    glColor3ub(150, 70, 80); //down
    glVertex2f(-1.0,-0.5);
    glVertex2f(-0.6,-0.5);
    glVertex2f(-0.6,-0.3);
    glVertex2f(-1.0,-0.3);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(120, 140, 170);  //up
    glVertex2f(-1.0,-0.3);
    glVertex2f(-0.55,-0.3);
    glVertex2f(-0.65,-0.15);
    glVertex2f(-1.0,-0.15);
    glEnd();

//house 2
glBegin(GL_QUADS);
    glColor3ub(100, 50, 0); //down
    glVertex2f(-1.0,-0.6);
    glVertex2f(-0.7,-0.6);
    glVertex2f(-0.7,-0.3);
    glVertex2f(-1.0,-0.3);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(90, 90, 110);  //up
    glVertex2f(-1.0,-0.4);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.73,-0.26);
    glVertex2f(-1.0,-0.26);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(130, 80, 30);  //door
    glVertex2f(-0.89,-0.6);
    glVertex2f(-0.81,-0.6);
    glVertex2f(-0.81,-0.45);
    glVertex2f(-0.89,-0.45);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0);  //window
    glVertex2f(-0.73,-0.54);
    glVertex2f(-0.73,-0.49);
    glVertex2f(-0.785,-0.49);
    glVertex2f(-0.785,-0.54);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0);  //window
    glVertex2f(-0.975,-0.54);
    glVertex2f(-0.975,-0.49);
    glVertex2f(-0.925,-0.49);
    glVertex2f(-0.925,-0.54);
    glEnd();



//house 3
glBegin(GL_QUADS);
    glColor3ub(130, 130, 130); //down
    glVertex2f(0.3,-0.2);
    glVertex2f(0.7,-0.2);
    glVertex2f(0.7,-0.3);
    glVertex2f(0.3,-0.3);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(170, 80, 100);  //up
    glVertex2f(0.25,-0.23);
    glVertex2f(0.75,-0.23);
    glVertex2f(0.7,-0.18);
    glVertex2f(0.3,-0.18);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(70, 31, 110); //door
    glVertex2f(0.46,-0.25);
    glVertex2f(0.54,-0.25);
    glVertex2f(0.54,-0.3);
    glVertex2f(0.46,-0.3);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(255,215,0); //windows
    glVertex2f(0.6,-0.25);
    glVertex2f(0.65,-0.25);
    glVertex2f(0.65,-0.29);
    glVertex2f(0.6,-0.29);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0); //windows
    glVertex2f(0.35,-0.25);
    glVertex2f(0.4,-0.25);
    glVertex2f(0.4,-0.29);
    glVertex2f(0.35,-0.29);
    glEnd();
//house 4
glBegin(GL_QUADS);
    glColor3ub(130, 130, 130); //down
    glVertex2f(0.8,-0.4);
    glVertex2f(0.95,-0.4);
    glVertex2f(0.95,-0.5);
    glVertex2f(0.8,-0.5);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(184, 104, 36 );  //up
    glVertex2f(0.75,-0.43);
    glVertex2f(1.0,-0.43);
    glVertex2f(0.95,-0.38);
    glVertex2f(0.8,-0.38);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(70, 31, 110); //door
    glVertex2f(0.86,-0.445);
    glVertex2f(0.88,-0.445);
    glVertex2f(0.88,-0.5);
    glVertex2f(0.86,-0.5);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0); //windows
    glVertex2f(0.90,-0.46);
    glVertex2f(0.93,-0.46);
    glVertex2f(0.93,-0.49);
    glVertex2f(0.90,-0.49);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0); //windows
    glVertex2f(0.82,-0.46);
    glVertex2f(0.85,-0.46);
    glVertex2f(0.85,-0.49);
    glVertex2f(0.82,-0.49);
    glEnd();

//house 5
glBegin(GL_QUADS);
    glColor3ub(130, 130, 130); //down
    glVertex2f(0.8,-0.2);
    glVertex2f(0.95,-0.2);
    glVertex2f(0.95,-0.3);
    glVertex2f(0.8,-0.3);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(14, 154, 148);  //up
    glVertex2f(0.75,-0.23);
    glVertex2f(1.0,-0.23);
    glVertex2f(0.95,-0.18);
    glVertex2f(0.8,-0.18);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(70, 31, 110); //door
    glVertex2f(0.86,-0.245);
    glVertex2f(0.88,-0.245);
    glVertex2f(0.88,-0.3);
    glVertex2f(0.86,-0.3);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0); //windows
    glVertex2f(0.90,-0.26);
    glVertex2f(0.93,-0.26);
    glVertex2f(0.93,-0.29);
    glVertex2f(0.90,-0.29);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,215,0); //windows
    glVertex2f(0.82,-0.26);
    glVertex2f(0.85,-0.26);
    glVertex2f(0.85,-0.29);
    glVertex2f(0.82,-0.29);
    glEnd();

//ground
glBegin(GL_QUADS);
    glColor3ub(150, 150, 120);
    glVertex2f(0.4,-0.15);
    glVertex2f(0.7,-0.15);
    glVertex2f(0.7,0.0);
    glVertex2f(0.4,0.0);
    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.55,0.0);
    glVertex2f(0.55,-0.15);


glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.7,-0.05);
    glVertex2f(0.67,-0.05);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.67,-0.05);
    glVertex2f(0.67,-0.10);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.67,-0.10);
    glVertex2f(0.7,-0.10);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.4,-0.05);
    glVertex2f(0.43,-0.05);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.43,-0.05);
    glVertex2f(0.43,-0.10);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.43,-0.10);
    glVertex2f(0.4,-0.10);
    glEnd();



	GLfloat x40=0.55f; GLfloat y40=-0.07f; GLfloat radius40 =.03f;
	int k;
	int lineAmount40 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi40 = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
		for(k = 0; k <= lineAmount40;k++) {
			glVertex2f(
			    x40 + (radius40 * cos(k *  twicePi40 / lineAmount40)),
			    y40 + (radius40* sin(k * twicePi40 / lineAmount40))
			);
		}
	glEnd();



// bench 1
glBegin(GL_QUADS);
    glColor3ub(50, 100, 160 );
    glVertex2f(0.5,-0.36);
    glVertex2f(0.5,-0.4);
    glVertex2f(0.3,-0.4);
    glVertex2f(0.3,-0.36);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);  //legs
    glVertex2f(0.45,-0.4);
    glVertex2f(0.45,-0.44);
    glVertex2f(0.47,-0.44);
    glVertex2f(0.47,-0.4);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(110, 110, 110 );  //legs
    glVertex2f(0.35,-0.4);
    glVertex2f(0.35,-0.44);
    glVertex2f(0.33,-0.44);
    glVertex2f(0.33,-0.4);
    glEnd();

// bench 2
glBegin(GL_QUADS);
    glColor3ub(50, 100, 160);
    glVertex2f(0.75,-0.46);
    glVertex2f(0.75,-0.5);
    glVertex2f(0.55,-0.5);
    glVertex2f(0.55,-0.46);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);  //legs
    glVertex2f(0.7,-0.5);
    glVertex2f(0.7,-0.54);
    glVertex2f(0.72,-0.54);
    glVertex2f(0.72,-0.5);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);  //legs
    glVertex2f(0.6,-0.5);
    glVertex2f(0.6,-0.54);
    glVertex2f(0.58,-0.54);
    glVertex2f(0.58,-0.5);
    glEnd();
//road quad
glBegin(GL_QUADS);
    glColor3ub( 220, 220, 220);
    glVertex2f(0.8,-0.86);
    glVertex2f(0.8,-0.82);
    glVertex2f(0.6,-0.82);
    glVertex2f(0.6,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 220, 220, 220);
    glVertex2f(0.4,-0.86);
    glVertex2f(0.4,-0.82);
    glVertex2f(0.2,-0.82);
    glVertex2f(0.2,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 220, 220, 220);
    glVertex2f(0.0,-0.86);
    glVertex2f(0.0,-0.82);
    glVertex2f(-0.2,-0.82);
    glVertex2f(-0.2,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 220, 220, 220);
    glVertex2f(-0.4,-0.86);
    glVertex2f(-0.4,-0.82);
    glVertex2f(-0.6,-0.82);
    glVertex2f(-0.6,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 220, 220, 220);
    glVertex2f(-0.8,-0.86);
    glVertex2f(-0.8,-0.82);
    glVertex2f(-0.99,-0.82);
    glVertex2f(-0.99,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 220, 220, 220);
    glVertex2f(0.98,-0.86);
    glVertex2f(0.98,-0.82);
    glVertex2f(1.0,-0.82);
    glVertex2f(1.0,-0.86);
    glEnd();


//bus2
glPushMatrix();
    glTranslatef(positionbus2,0.0f, 0.0f);
glColor3ub(160, 60, 160 );
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.87);
	glVertex2f(-0.35,-0.97);
	glVertex2f(-0.7,-0.97);
	glVertex2f(-0.7,-0.87);
	glEnd();
glColor3ub(50,50,50 ); //front
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.87);
	glVertex2f(-0.35,-0.93);
	glVertex2f(-0.4,-0.93);
	glVertex2f(-0.4,-0.87);
	glEnd();
glColor3ub(160, 60, 160 ); //front2
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.88);
	glVertex2f(-0.35,-0.90);
	glVertex2f(-0.37,-0.90);
	glVertex2f(-0.37,-0.88);
	glEnd();
glColor3ub(255,215,0 ); //window
	glBegin(GL_QUADS);
	glVertex2f(-0.44,-0.89);
	glVertex2f(-0.44,-0.92);
	glVertex2f(-0.48,-0.92);
	glVertex2f(-0.48,-0.89);
	glEnd();
glColor3ub(255,215,0); //window
	glBegin(GL_QUADS);
	glVertex2f(-0.52,-0.89);
	glVertex2f(-0.52,-0.92);
	glVertex2f(-0.56,-0.92);
	glVertex2f(-0.56,-0.89);
	glEnd();
glColor3ub(255,215,0); //window
	glBegin(GL_QUADS);
	glVertex2f(-0.6,-0.89);
	glVertex2f(-0.6,-0.92);
	glVertex2f(-0.64,-0.92);
	glVertex2f(-0.64,-0.89);
	glEnd();


glColor3ub(50,50,50  );                 //tire
    x=-0.45f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=-0.41f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=-0.64f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(50,50,50  );                 //tire
    x=-0.6f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();


//bus1
glPushMatrix();
    glTranslatef(positionbus1,0.0f, 0.0f);
glColor3ub(160, 60, 160 );
	glBegin(GL_QUADS);
	glVertex2f(0.35,-0.71);
	glVertex2f(0.35,-0.81);
	glVertex2f(0.7,-0.81);
	glVertex2f(0.7,-0.71);
	glEnd();
glColor3ub(50,50,50 ); //front
	glBegin(GL_QUADS);
	glVertex2f(0.35,-0.71);
	glVertex2f(0.35,-0.78);
	glVertex2f(0.4,-0.78);
	glVertex2f(0.4,-0.71);
	glEnd();
glColor3ub(160, 60, 160); //front2
	glBegin(GL_QUADS);
	glVertex2f(0.35,-0.72);
	glVertex2f(0.35,-0.74);
	glVertex2f(0.37,-0.74);
	glVertex2f(0.37,-0.72);
	glEnd();
glColor3ub(255,215,0); //window
	glBegin(GL_QUADS);
	glVertex2f(0.44,-0.73);
	glVertex2f(0.44,-0.77);
	glVertex2f(0.48,-0.77);
	glVertex2f(0.48,-0.73);
	glEnd();
glColor3ub(255,215,0); //window
	glBegin(GL_QUADS);
	glVertex2f(0.52,-0.73);
	glVertex2f(0.52,-0.77);
	glVertex2f(0.56,-0.77);
	glVertex2f(0.56,-0.73);
	glEnd();
glColor3ub(255,215,0 ); //window
	glBegin(GL_QUADS);
	glVertex2f(0.6,-0.73);
	glVertex2f(0.6,-0.77);
	glVertex2f(0.64,-0.77);
	glVertex2f(0.64,-0.73);
	glEnd();


glColor3ub(50,50,50  );                 //tire
    x=0.45f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=0.41f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=0.64f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(50,50,50  );                 //tire
    x=0.6f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

//tree1

glColor3ub(120, 20, 10  );
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.5);
	glVertex2f(-0.35,-0.65);
	glVertex2f(-0.4,-0.65);
	glVertex2f(-0.4,-0.5);
	glEnd();
glColor3ub(10, 100, 10);
    x=-0.38f; y=-0.45f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10, 100, 10);
    x=-0.34f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=-0.42f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree2

glColor3ub(120, 20, 10 );
	glBegin(GL_QUADS);
	glVertex2f(0.15,-0.5);
	glVertex2f(0.15,-0.65);
	glVertex2f(0.2,-0.65);
	glVertex2f(0.2,-0.5);
	glEnd();
glColor3ub(10,100,10);
    x=0.18f; y=-0.45f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=0.22f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=0.14f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree3

glColor3ub(120, 20, 10);
	glBegin(GL_QUADS);
	glVertex2f(0.15,-0.15);
	glVertex2f(0.15,-0.3);
	glVertex2f(0.2,-0.3);
	glVertex2f(0.2,-0.15);
	glEnd();
glColor3ub(10,100,10);
    x=0.18f; y=-0.1f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=0.22f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=0.14f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree1

glColor3ub(120, 20, 10 );
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.15);
	glVertex2f(-0.35,-0.3);
	glVertex2f(-0.4,-0.3);
	glVertex2f(-0.4,-0.15);
	glEnd();
glColor3ub(10,100,10);
    x=-0.38f; y=-0.10f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=-0.34f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=-0.42f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree5

glColor3ub(120, 20, 10 );
	glBegin(GL_QUADS);
	glVertex2f(0.9,-0.05);
	glVertex2f(0.9,-0.1);
	glVertex2f(0.95,-0.1);
	glVertex2f(0.95,-0.05);
	glEnd();
glColor3ub(10,100,10);
    x=0.92f; y=-0.02f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=0.91f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=0.94f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
//tree6

glColor3ub(120, 20, 10 );
	glBegin(GL_QUADS);
	glVertex2f(0.8,-0.05);
	glVertex2f(0.8,-0.1);
	glVertex2f(0.85,-0.1);
	glVertex2f(0.85,-0.05);
	glEnd();
glColor3ub(10,100,10);
    x=0.82f; y=-0.02f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=0.81f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,100,10);
    x=0.84f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



// swimming tire
glColor3ub(108, 0, 0);
    x=-0.6f; y=0.15f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(150, 150, 120);
    x=-0.6f; y=0.15f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//3rd
glColor3ub(0,0,108 );
    x=-0.7f; y=0.12f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(150, 150, 120);
    x=-0.7f; y=0.12f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//2nd
glColor3ub(225,135,0 );
    x=-0.65f; y=0.2f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(150, 150, 120);
    x=-0.65f; y=0.2f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//human1
glColor3ub(0,0,0);
    x=-0.35f; y=0.3f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3ub(200, 160, 110  );  //neck
	glBegin(GL_QUADS);
	glVertex2f(-0.365,0.25);
	glVertex2f(-0.365,0.27);
	glVertex2f(-0.325,0.27);
	glVertex2f(-0.325,0.25);
	glEnd();
glColor3ub(205,92,92  );  // upper body
	glBegin(GL_QUADS);
	glVertex2f(-0.39,0.25);
	glVertex2f(-0.39,0.20);
	glVertex2f(-0.30,0.20);
	glVertex2f(-0.30,0.25);
	glEnd();
glColor3ub(200, 160, 110  ); //left hand
	glBegin(GL_QUADS);
	glVertex2f(-0.39,0.23);
	glVertex2f(-0.39,0.26);
	glVertex2f(-0.43,0.20);
	glVertex2f(-0.42,0.17);
	glEnd();
glColor3ub(200, 160, 110  ); //right hand
	glBegin(GL_QUADS);
	glVertex2f(-0.30,0.25);
	glVertex2f(-0.30,0.22);
	glVertex2f(-0.24,0.23);
	glVertex2f(-0.24,0.24);
	glEnd();

glColor3ub(90,90,90  ); // lower body
	glBegin(GL_QUADS);
	glVertex2f(-0.385,0.20);
	glVertex2f(-0.385,0.16);
	glVertex2f(-0.305,0.16);
	glVertex2f(-0.305,0.20);
	glEnd();
glColor3ub(200, 160, 110  ); //legs
	glBegin(GL_QUADS);
	glVertex2f(-0.33,0.16);
	glVertex2f(-0.33,0.12);
	glVertex2f(-0.32,0.12);
	glVertex2f(-0.32,0.16);
	glEnd();
glColor3ub(200, 160, 110  );  //legs
	glBegin(GL_QUADS);
	glVertex2f(-0.37,0.16);
	glVertex2f(-0.37,0.12);
	glVertex2f(-0.36,0.12);
	glVertex2f(-0.36,0.16);
	glEnd();

// child

glColor3ub(0,0,0);
    x=-0.48f; y=0.22f;  radius =.025f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(200, 160, 110  );  //neck
	glBegin(GL_QUADS);
	glVertex2f(-0.49,0.20);
	glVertex2f(-0.49,0.19);
	glVertex2f(-0.46,0.19);
	glVertex2f(-0.46,0.20);
	glEnd();

    glColor3ub(173,216,230  );  // upper body
	glBegin(GL_QUADS);
	glVertex2f(-0.51,0.19);
	glVertex2f(-0.51,0.17);
	glVertex2f(-0.44,0.17);
	glVertex2f(-0.44,0.19);
	glEnd();
glColor3ub(200, 160, 110  ); //right hand
	glBegin(GL_QUADS);
	glVertex2f(-0.44,0.19);
	glVertex2f(-0.44,0.18);
	glVertex2f(-0.42,0.17);
	glVertex2f(-0.43,0.20);
	glEnd();
glColor3ub(200, 160, 110  ); //left hand
	glBegin(GL_QUADS);
	glVertex2f(-0.51,0.19);
	glVertex2f(-0.51,0.17);
	glVertex2f(-0.55,0.17);
	glVertex2f(-0.55,0.19);
	glEnd();

glColor3ub(50,50,50 ); // lower body
	glBegin(GL_QUADS);
	glVertex2f(-0.50,0.17);
	glVertex2f(-0.50,0.145);
	glVertex2f(-0.45,0.145);
	glVertex2f(-0.45,0.17);
	glEnd();
glColor3ub(200, 160, 110  ); //legs
	glBegin(GL_QUADS);
	glVertex2f(-0.49,0.145);
	glVertex2f(-0.49,0.12);
	glVertex2f(-0.48,0.12);
	glVertex2f(-0.48,0.145);
	glEnd();
glColor3ub(200, 160, 110  );  //legs
	glBegin(GL_QUADS);
	glVertex2f(-0.47,0.145);
	glVertex2f(-0.47,0.12);
	glVertex2f(-0.46,0.12);
	glVertex2f(-0.46,0.145);
	glEnd();




//beach

glColor3ub(32, 150, 150  );
	glBegin(GL_QUADS);
	glVertex2f(-0.2,0.05);
	glVertex2f(-0.2,0.2);
	glVertex2f(-0.1,0.2);
	glVertex2f(-0.1,0.05);
	glEnd();
glColor3ub(200, 200, 200  );
	glBegin(GL_QUADS);
	glVertex2f(-0.12,0.05);
	glVertex2f(-0.12,0.2);
	glVertex2f(-0.14,0.2);
	glVertex2f(-0.14,0.05);
	glEnd();
glColor3ub(200,200,200   );
	glBegin(GL_QUADS);
	glVertex2f(-0.16,0.05);
	glVertex2f(-0.16,0.2);
	glVertex2f(-0.18,0.2);
	glVertex2f(-0.18,0.05);
	glEnd();
//2
glColor3ub(140, 11, 93   );
	glBegin(GL_QUADS);
	glVertex2f(0.0,0.05);
	glVertex2f(0.0,0.2);
	glVertex2f(-0.1,0.2);
	glVertex2f(-0.1,0.05);
	glEnd();
glColor3ub(200,200,200  );
	glBegin(GL_QUADS);
	glVertex2f(-0.02,0.05);
	glVertex2f(-0.02,0.2);
	glVertex2f(-0.04,0.2);
	glVertex2f(-0.04,0.05);
	glEnd();
glColor3ub(200,200,200   );
	glBegin(GL_QUADS);
	glVertex2f(-0.06,0.05);
	glVertex2f(-0.06,0.2);
	glVertex2f(-0.08,0.2);
	glVertex2f(-0.08,0.05);
	glEnd();

//3

glColor3ub(140, 11, 93   );
	glBegin(GL_QUADS);
	glVertex2f(0.7,0.25);
	glVertex2f(0.7,0.15);
	glVertex2f(0.9,0.15);
	glVertex2f(0.9,0.25);
	glEnd();

glColor3ub(200,200,200  );
	glBegin(GL_QUADS);
	glVertex2f(0.7,0.19);
	glVertex2f(0.7,0.17);
	glVertex2f(0.9,0.17);
	glVertex2f(0.9,0.19);
	glEnd();
glColor3ub(200,200,200   );
    glBegin(GL_QUADS);
	glVertex2f(0.7,0.22);
	glVertex2f(0.7,0.24);
	glVertex2f(0.9,0.24);
	glVertex2f(0.9,0.22);
	glEnd();

//4

glColor3ub(235,85,150  );
	glBegin(GL_QUADS);
	glVertex2f(0.3,0.05);
	glVertex2f(0.3,0.2);
	glVertex2f(0.2,0.2);
	glVertex2f(0.2,0.05);
	glEnd();
glColor3ub(200,200,200  );
	glBegin(GL_QUADS);
	glVertex2f(0.22,0.05);
	glVertex2f(0.22,0.2);
	glVertex2f(0.24,0.2);
	glVertex2f(0.24,0.05);
	glEnd();
glColor3ub(200,200,200   );
	glBegin(GL_QUADS);
	glVertex2f(0.26,0.05);
	glVertex2f(0.26,0.2);
	glVertex2f(0.28,0.2);
	glVertex2f(0.28,0.05);
	glEnd();


   glFlush();

}

void beach_rain()
{

    glClearColor(1.0,1.0,1.0,1.0);
   glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();

   glBegin(GL_QUADS);
    glColor3ub(176,224,230 ); //sky
    glVertex2f(1.0,0.7);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(-1.0,0.7);
    glEnd();


glBegin(GL_QUADS);
    glColor3ub(255,228,196 ); //sea soil
    glVertex2f(1.0,0.25);
    glVertex2f(-1.0,0.25);
    glVertex2f(-1.0,0.0);
    glVertex2f(1.0,0.0);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(150, 200, 255 ); //sea
    glVertex2f(1.0,0.7);
    glVertex2f(-1.0,0.7);
    glVertex2f(-1.0,0.25);
    glVertex2f(1.0,0.25);
    glEnd();


//wave circles
glPushMatrix();
    glTranslatef(positionc1,0.0f, 0.0f);



int z;
glColor3ub(150, 200, 255);               //
	GLfloat x20=-0.85f; GLfloat y20=0.48f; GLfloat radius20 =.24f;
	int triangleAmount20 = 20;

	GLfloat twicePi20 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x20, y20);
		for(z = 0; z <= triangleAmount20;z++) {
			glVertex2f(
		            x20 + (radius20 * cos(z *  twicePi20 / triangleAmount20)),
			    y20 + (radius20 * sin(z * twicePi20 / triangleAmount20))
			);
		}
	glEnd();

int w;
glColor3ub(150, 200, 255);               //
	GLfloat x21=-0.68f; GLfloat y21=0.42f; GLfloat radius21 =.18f;
	int triangleAmount21 = 20;

	GLfloat twicePi21 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x21, y21);
		for(w = 0; w<= triangleAmount21;w++) {
			glVertex2f(
		            x21 + (radius21 * cos(w *  twicePi21 / triangleAmount21)),
			    y21 + (radius21 * sin(w * twicePi21 / triangleAmount21))
			);
		}
	glEnd();

int v;
glColor3ub(150, 200, 255);               //
	GLfloat x22=-0.2f; GLfloat y22=0.48f; GLfloat radius22 =.24f;
	int triangleAmount22 = 20;

	GLfloat twicePi22 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x22, y22);
		for(v = 0; v<= triangleAmount22;v++) {
			glVertex2f(
		            x22 + (radius22 * cos(v *  twicePi22 / triangleAmount22)),
			    y22 + (radius22 * sin(v * twicePi22 / triangleAmount22))
			);
		}
	glEnd();
int q;
glColor3ub(150, 200, 255);               //
	GLfloat x27=0.31f; GLfloat y27=0.42f; GLfloat radius27 =.18f;
	int triangleAmount27 = 20;

	GLfloat twicePi27 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x27, y27);
		for(q = 0; q<= triangleAmount27;q++) {
			glVertex2f(
		            x27 + (radius27 * cos(q *  twicePi27 / triangleAmount27)),
			    y27 + (radius27 * sin(q * twicePi27 / triangleAmount27))
			);
		}
	glEnd();

int p;
glColor3ub(150, 200, 255);               //
	GLfloat x28=0.48f; GLfloat y28=0.48f; GLfloat radius28 =.24f;
	int triangleAmount28 = 20;

	GLfloat twicePi28 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x28, y28);
		for(p = 0; p<= triangleAmount28;p++) {
			glVertex2f(
		            x28 + (radius28 * cos(p *  twicePi28 / triangleAmount28)),
			    y28 + (radius28 * sin(p * twicePi28 / triangleAmount28))
			);
		}
	glEnd();

int o;
glColor3ub(150, 200, 255);               //
	GLfloat x29=-0.31f; GLfloat y29=0.42f; GLfloat radius29 =.18f;
	int triangleAmount29 = 20;

	GLfloat twicePi29 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x29, y29);
		for( o= 0; o<= triangleAmount29;o++) {
			glVertex2f(
		            x29 + (radius29 * cos(o *  twicePi29 / triangleAmount29)),
			    y29 + (radius29 * sin(o * twicePi29 / triangleAmount29))
			);
		}
	glEnd();

int n;
glColor3ub(150, 200, 255);               //
	GLfloat x30=-0.48f; GLfloat y30=0.48f; GLfloat radius30 =.24f;
	int triangleAmount30 = 20;

	GLfloat twicePi30 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x28, y28);
		for(n = 0; n<= triangleAmount30;n++) {
			glVertex2f(
		            x30 + (radius30 * cos(n *  twicePi30 / triangleAmount30)),
			    y30 + (radius30 * sin(n * twicePi30 / triangleAmount30))
			);
		}
	glEnd();
int u;
glColor3ub(150, 200, 255);               //
	GLfloat x23=-0.03f; GLfloat y23=0.42f; GLfloat radius23 =.18f;
	int triangleAmount23 = 20;

	GLfloat twicePi23 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x23, y23);
		for(u = 0; u<= triangleAmount23;u++) {
			glVertex2f(
		            x23 + (radius23 * cos(u *  twicePi23 / triangleAmount23)),
			    y23 + (radius23 * sin(u * twicePi23 / triangleAmount23))
			);
		}
	glEnd();

int s;
glColor3ub(150, 200, 255);               //
	GLfloat x24=0.85f; GLfloat y24=0.48f; GLfloat radius24 =.24f;
	int triangleAmount24 = 20;

	GLfloat twicePi24 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x24, y24);
		for(s = 0; s<= triangleAmount24;s++) {
			glVertex2f(
		            x24 + (radius24 * cos(s *  twicePi24 / triangleAmount24)),
			    y24 + (radius24 * sin(s * twicePi24 / triangleAmount24))
			);
		}
	glEnd();
	int t;
glColor3ub(150, 200, 255);               //
	GLfloat x25=0.68f; GLfloat y25=0.42f; GLfloat radius25 =.18f;
	int triangleAmount25 = 20;

	GLfloat twicePi25 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x25, y25);
		for(t = 0; t<= triangleAmount25;t++) {
			glVertex2f(
		            x25 + (radius25 * cos(t *  twicePi25 / triangleAmount25)),
			    y25 + (radius25 * sin(t * twicePi25 / triangleAmount25))
			);
		}
	glEnd();
int r;
glColor3ub(150, 200, 255);               //
	GLfloat x26=0.14f; GLfloat y26=0.48f; GLfloat radius26 =.24f;
	int triangleAmount26 = 20;

	GLfloat twicePi26 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x26, y26);
		for(r = 0; r<= triangleAmount26;r++) {
			glVertex2f(
		            x26 + (radius26 * cos(r *  twicePi26 / triangleAmount26)),
			    y26 + (radius26 * sin(r * twicePi26 / triangleAmount26))
			);
		}
	glEnd();

glPopMatrix();

//glPushMatrix();
   // glTranslatef(positioncld,0.0f, 0.0f);
//cloud

glBegin(GL_QUADS);
    glColor3ub(255,250,240);
    glVertex2f(-0.7,0.76);
    glVertex2f(-0.4,0.76);
    glVertex2f(-0.4,0.73);
    glVertex2f(-0.7,0.73);
    glEnd();


glColor3ub(255,250,240);                 //cloud 1
   GLfloat x=-0.68f; GLfloat y=0.78f; GLfloat radius =.045f;

    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <=  triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(255,250,240);                 //cloud 1
    x=-0.44f; y=0.78f;  radius =.05f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 1
    x=-0.52f; y=0.78f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 1
    x=-0.6f; y=0.81f;  radius =.065f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//cloud 2
glBegin(GL_QUADS);
    glColor3ub(255,250,240);
    glVertex2f(0.7,0.8);
    glVertex2f(0.4,0.8);
    glVertex2f(0.4,0.77);
    glVertex2f(0.7,0.77);
    glEnd();


glColor3ub(255,250,240);                 //cloud 2
    x=0.68f; y=0.82f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(255,250,240);                 //cloud 1
    x=0.42f; y=0.82f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 2
    x=0.49f; y=0.82f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 2
    x=0.59f; y=0.85f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
//glPopMatrix();


glPushMatrix();
    glTranslatef(positionship,0.0f, 0.0f);
//ship
glBegin(GL_QUADS);      // ash quad ship
    glColor3ub(128,128,128);
    glVertex2f(0.8,0.5);
    glVertex2f(0.8,0.62);
    glVertex2f(0.45,0.62);
    glVertex2f(0.45,0.5);
    glEnd();
glBegin(GL_QUADS);      //black quad ship
    glColor3ub(0,0,0);
    glVertex2f(0.8,0.48);
    glVertex2f(0.83,0.55);
    glVertex2f(0.4,0.55);
    glVertex2f(0.45,0.48);
    glEnd();
//window
glBegin(GL_QUADS);
    glColor3ub(211,211,211);  //
    glVertex2f(0.78,0.58);
    glVertex2f(0.78,0.6);
    glVertex2f(0.75,0.6);
    glVertex2f(0.75,0.58);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(211,211,211);  //
    glVertex2f(0.73,0.58);
    glVertex2f(0.73,0.6);
    glVertex2f(0.70,0.6);
    glVertex2f(0.70,0.58);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(0.68,0.58);
    glVertex2f(0.68,0.6);
    glVertex2f(0.65,0.6);
    glVertex2f(0.65,0.58);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(0.63,0.58);
    glVertex2f(0.63,0.6);
    glVertex2f(0.60,0.6);
    glVertex2f(0.60,0.58);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(165,42,42 ); //brown quad
    glVertex2f(0.5,0.6);
    glVertex2f(0.5,0.56);
    glVertex2f(0.52,0.56);
    glVertex2f(0.52,0.6);
    glEnd();
glBegin(GL_QUADS);      // ash quad2 ship
    glColor3ub(128,128,128);
    glVertex2f(0.8,0.62);
    glVertex2f(0.8,0.68);
    glVertex2f(0.6,0.68);
    glVertex2f(0.6,0.62);
    glEnd();
//windows
glBegin(GL_QUADS);
    glColor3ub(211,211,211);  //
    glVertex2f(0.78,0.64);
    glVertex2f(0.78,0.66);
    glVertex2f(0.75,0.66);
    glVertex2f(0.75,0.64);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(211,211,211);  //
    glVertex2f(0.73,0.64);
    glVertex2f(0.73,0.66);
    glVertex2f(0.70,0.66);
    glVertex2f(0.70,0.64);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(0.68,0.64);
    glVertex2f(0.68,0.66);
    glVertex2f(0.65,0.66);
    glVertex2f(0.65,0.64);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(0.63,0.64);
    glVertex2f(0.63,0.66);
    glVertex2f(0.60,0.66);
    glVertex2f(0.60,0.64);
    glEnd();
// top air quad
glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(0.56,0.62);
    glVertex2f(0.56,0.68);
    glVertex2f(0.54,0.68);
    glVertex2f(0.54,0.62);
    glEnd();



glColor3ub(105,105,105);                 //mini box
    x=0.55f; y=0.69f;  radius =.007f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(105,105,105);                 //mini box
    x=0.57f; y=0.71f;  radius =.0065f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(105,105,105);                 //mini box
    x=0.59f; y=0.715f;  radius =.0065f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(0.53,0.62);
    glVertex2f(0.53,0.68);
    glVertex2f(0.51,0.68);
    glVertex2f(0.51,0.62);
    glEnd();

glColor3ub(105,105,105);                 //mini box
    x=0.525f; y=0.7f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(105,105,105);                 //mini box
    x=0.51f; y=0.69f;  radius =.007f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3ub(105,105,105);                 //mini box
    x=0.545f; y=0.712f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//flag
glBegin(GL_QUADS);
    glColor3ub(188,143,143);
    glVertex2f(0.43,0.55);
    glVertex2f(0.43,0.65);
    glVertex2f(0.42,0.65);
    glVertex2f(0.42,0.55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245,245,245);
    glVertex2f(0.42,0.65);
     glVertex2f(0.38,0.635);
     glVertex2f(0.42,0.62);
     glEnd();
//bottom window
glBegin(GL_QUADS);
    glColor3ub(240,248,255);
    glVertex2f(0.47,0.525);
    glVertex2f(0.47,0.54);
    glVertex2f(0.43,0.54);
    glVertex2f(0.43,0.525);
    glEnd();

glPopMatrix();

//green
glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(1.0,0.0);
     glVertex2f(1.0,0.08);
     glVertex2f(0.3,0.0);
     glEnd();

glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-1.0,0.0);
     glVertex2f(-0.2,0.05);
     glVertex2f(-1.0,0.1);
     glEnd();
glColor3ub(255,228,196);                 //circle
    x=-0.25f; y=0.05f;  radius =.1f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,228,196);                 //circle
    x=-0.4f; y=0.05f;  radius =.1f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glBegin(GL_QUADS);
    glColor3ub(0,100,0); //green
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glEnd();

    glBegin(GL_QUADS);     //whole - axis
    glColor3ub(100,113,135);
    glVertex2f(1.0,-0.68);
    glVertex2f(-1.0,-0.68);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glEnd();

//house 6
glBegin(GL_QUADS);
    glColor3ub(255,228,196); //down
    glVertex2f(-0.8,-0.1);
    glVertex2f(-0.95,-0.1);
    glVertex2f(-0.95,-0.2);
    glVertex2f(-0.8,-0.2);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,69,0);  //up
    glVertex2f(-0.75,-0.13);
    glVertex2f(-1.0,-0.13);
    glVertex2f(-0.95,-0.08);
    glVertex2f(-0.8,-0.08);
    glEnd();

//house 7
glBegin(GL_QUADS);
    glColor3ub(255,228,196); //down
    glVertex2f(-0.7,-0.1);
    glVertex2f(-0.55,-0.1);
    glVertex2f(-0.55,-0.2);
    glVertex2f(-0.7,-0.2);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,69,0 );  //up
    glVertex2f(-0.5,-0.13);
    glVertex2f(-0.55,-0.08);
    glVertex2f(-0.7,-0.08);
    glVertex2f(-0.75,-0.13);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(138,43,226);  //window
    glVertex2f(-0.57,-0.18);
    glVertex2f(-0.57,-0.14);
    glVertex2f(-0.61,-0.14);
    glVertex2f(-0.61,-0.18);
    glEnd();
//house 1
glBegin(GL_QUADS);
    glColor3ub(219,112,147); //down
    glVertex2f(-1.0,-0.5);
    glVertex2f(-0.6,-0.5);
    glVertex2f(-0.6,-0.3);
    glVertex2f(-1.0,-0.3);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(176,196,222);  //up
    glVertex2f(-1.0,-0.3);
    glVertex2f(-0.55,-0.3);
    glVertex2f(-0.65,-0.15);
    glVertex2f(-1.0,-0.15);
    glEnd();

//house 2
glBegin(GL_QUADS);
    glColor3ub(139,69,19); //down
    glVertex2f(-1.0,-0.6);
    glVertex2f(-0.7,-0.6);
    glVertex2f(-0.7,-0.3);
    glVertex2f(-1.0,-0.3);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(112,128,144);  //up
    glVertex2f(-1.0,-0.4);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.73,-0.26);
    glVertex2f(-1.0,-0.26);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(170, 120, 70);  //door
    glVertex2f(-0.89,-0.6);
    glVertex2f(-0.81,-0.6);
    glVertex2f(-0.81,-0.45);
    glVertex2f(-0.89,-0.45);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,182,193);  //window
    glVertex2f(-0.73,-0.54);
    glVertex2f(-0.73,-0.49);
    glVertex2f(-0.785,-0.49);
    glVertex2f(-0.785,-0.54);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(255,182,193);  //window
    glVertex2f(-0.975,-0.54);
    glVertex2f(-0.975,-0.49);
    glVertex2f(-0.925,-0.49);
    glVertex2f(-0.925,-0.54);
    glEnd();



//house 3
glBegin(GL_QUADS);
    glColor3ub(192,192,192); //down
    glVertex2f(0.3,-0.2);
    glVertex2f(0.7,-0.2);
    glVertex2f(0.7,-0.3);
    glVertex2f(0.3,-0.3);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(219,112,147);  //up
    glVertex2f(0.25,-0.23);
    glVertex2f(0.75,-0.23);
    glVertex2f(0.7,-0.18);
    glVertex2f(0.3,-0.18);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //door
    glVertex2f(0.46,-0.25);
    glVertex2f(0.54,-0.25);
    glVertex2f(0.54,-0.3);
    glVertex2f(0.46,-0.3);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.6,-0.25);
    glVertex2f(0.65,-0.25);
    glVertex2f(0.65,-0.29);
    glVertex2f(0.6,-0.29);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.35,-0.25);
    glVertex2f(0.4,-0.25);
    glVertex2f(0.4,-0.29);
    glVertex2f(0.35,-0.29);
    glEnd();
//house 4
glBegin(GL_QUADS);
    glColor3ub(192,192,192); //down
    glVertex2f(0.8,-0.4);
    glVertex2f(0.95,-0.4);
    glVertex2f(0.95,-0.5);
    glVertex2f(0.8,-0.5);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(244,164,96 );  //up
    glVertex2f(0.75,-0.43);
    glVertex2f(1.0,-0.43);
    glVertex2f(0.95,-0.38);
    glVertex2f(0.8,-0.38);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //door
    glVertex2f(0.86,-0.445);
    glVertex2f(0.88,-0.445);
    glVertex2f(0.88,-0.5);
    glVertex2f(0.86,-0.5);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.90,-0.46);
    glVertex2f(0.93,-0.46);
    glVertex2f(0.93,-0.49);
    glVertex2f(0.90,-0.49);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.82,-0.46);
    glVertex2f(0.85,-0.46);
    glVertex2f(0.85,-0.49);
    glVertex2f(0.82,-0.49);
    glEnd();

//house 5
glBegin(GL_QUADS);
    glColor3ub(192,192,192); //down
    glVertex2f(0.8,-0.2);
    glVertex2f(0.95,-0.2);
    glVertex2f(0.95,-0.3);
    glVertex2f(0.8,-0.3);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(64,224,208);  //up
    glVertex2f(0.75,-0.23);
    glVertex2f(1.0,-0.23);
    glVertex2f(0.95,-0.18);
    glVertex2f(0.8,-0.18);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //door
    glVertex2f(0.86,-0.245);
    glVertex2f(0.88,-0.245);
    glVertex2f(0.88,-0.3);
    glVertex2f(0.86,-0.3);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.90,-0.26);
    glVertex2f(0.93,-0.26);
    glVertex2f(0.93,-0.29);
    glVertex2f(0.90,-0.29);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(102,51,153); //windows
    glVertex2f(0.82,-0.26);
    glVertex2f(0.85,-0.26);
    glVertex2f(0.85,-0.29);
    glVertex2f(0.82,-0.29);
    glEnd();

//ground
glBegin(GL_QUADS);
    glColor3ub(210, 170, 120);
    glVertex2f(0.4,-0.15);
    glVertex2f(0.7,-0.15);
    glVertex2f(0.7,0.0);
    glVertex2f(0.4,0.0);
    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.55,0.0);
    glVertex2f(0.55,-0.15);


glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.7,-0.05);
    glVertex2f(0.67,-0.05);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.67,-0.05);
    glVertex2f(0.67,-0.10);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.67,-0.10);
    glVertex2f(0.7,-0.10);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.4,-0.05);
    glVertex2f(0.43,-0.05);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.43,-0.05);
    glVertex2f(0.43,-0.10);

    glEnd();
glBegin(GL_LINES);   // lines
    glColor3ub(50,50,50);
    glVertex2f(0.43,-0.10);
    glVertex2f(0.4,-0.10);
    glEnd();



	GLfloat x40=0.55f; GLfloat y40=-0.07f; GLfloat radius40 =.03f; //center of field
	int k;
	int lineAmount40 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi40 = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
		for(k = 0; k <= lineAmount40;k++) {
			glVertex2f(
			    x40 + (radius40 * cos(k *  twicePi40 / lineAmount40)),
			    y40 + (radius40* sin(k * twicePi40 / lineAmount40))
			);
		}
	glEnd();

glColor3ub(50,50,50  );                 //players
    x=0.46f; y=-0.07f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.5f; y=-0.10f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.67f; y=-0.02f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.53f; y=-0.012f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.64f; y=-0.09f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //players
    x=0.6f; y=-0.05f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



// bench 1
glBegin(GL_QUADS);
    glColor3ub(100,149,237 );
    glVertex2f(0.5,-0.36);
    glVertex2f(0.5,-0.4);
    glVertex2f(0.3,-0.4);
    glVertex2f(0.3,-0.36);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(50,50,50 );  //legs
    glVertex2f(0.45,-0.4);
    glVertex2f(0.45,-0.44);
    glVertex2f(0.47,-0.44);
    glVertex2f(0.47,-0.4);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(50,50,50 );  //legs
    glVertex2f(0.35,-0.4);
    glVertex2f(0.35,-0.44);
    glVertex2f(0.33,-0.44);
    glVertex2f(0.33,-0.4);
    glEnd();

// bench 2
glBegin(GL_QUADS);
    glColor3ub(100,149,237 );
    glVertex2f(0.75,-0.46);
    glVertex2f(0.75,-0.5);
    glVertex2f(0.55,-0.5);
    glVertex2f(0.55,-0.46);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(50,50,50 );  //legs
    glVertex2f(0.7,-0.5);
    glVertex2f(0.7,-0.54);
    glVertex2f(0.72,-0.54);
    glVertex2f(0.72,-0.5);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub(50,50,50 );  //legs
    glVertex2f(0.6,-0.5);
    glVertex2f(0.6,-0.54);
    glVertex2f(0.58,-0.54);
    glVertex2f(0.58,-0.5);
    glEnd();
//road quad
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(0.8,-0.86);
    glVertex2f(0.8,-0.82);
    glVertex2f(0.6,-0.82);
    glVertex2f(0.6,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(0.4,-0.86);
    glVertex2f(0.4,-0.82);
    glVertex2f(0.2,-0.82);
    glVertex2f(0.2,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(0.0,-0.86);
    glVertex2f(0.0,-0.82);
    glVertex2f(-0.2,-0.82);
    glVertex2f(-0.2,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(-0.4,-0.86);
    glVertex2f(-0.4,-0.82);
    glVertex2f(-0.6,-0.82);
    glVertex2f(-0.6,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(-0.8,-0.86);
    glVertex2f(-0.8,-0.82);
    glVertex2f(-0.99,-0.82);
    glVertex2f(-0.99,-0.86);
    glEnd();
glBegin(GL_QUADS);
    glColor3ub( 250,250,250);
    glVertex2f(0.98,-0.86);
    glVertex2f(0.98,-0.82);
    glVertex2f(1.0,-0.82);
    glVertex2f(1.0,-0.86);
    glEnd();


//bus2
glPushMatrix();
    glTranslatef(positionbus2,0.0f, 0.0f);
glColor3ub(238,130,238 );
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.87);
	glVertex2f(-0.35,-0.97);
	glVertex2f(-0.7,-0.97);
	glVertex2f(-0.7,-0.87);
	glEnd();
glColor3ub(50,50,50 ); //front
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.87);
	glVertex2f(-0.35,-0.93);
	glVertex2f(-0.4,-0.93);
	glVertex2f(-0.4,-0.87);
	glEnd();
glColor3ub(238,130,238 ); //front2
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.88);
	glVertex2f(-0.35,-0.90);
	glVertex2f(-0.37,-0.90);
	glVertex2f(-0.37,-0.88);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(-0.44,-0.89);
	glVertex2f(-0.44,-0.92);
	glVertex2f(-0.48,-0.92);
	glVertex2f(-0.48,-0.89);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(-0.52,-0.89);
	glVertex2f(-0.52,-0.92);
	glVertex2f(-0.56,-0.92);
	glVertex2f(-0.56,-0.89);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(-0.6,-0.89);
	glVertex2f(-0.6,-0.92);
	glVertex2f(-0.64,-0.92);
	glVertex2f(-0.64,-0.89);
	glEnd();


glColor3ub(50,50,50  );                 //tire
    x=-0.45f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=-0.41f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=-0.64f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(50,50,50  );                 //tire
    x=-0.6f; y=-0.98f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();


//bus1
glPushMatrix();
    glTranslatef(positionbus1,0.0f, 0.0f);
glColor3ub(238,130,238 );
	glBegin(GL_QUADS);
	glVertex2f(0.35,-0.71);
	glVertex2f(0.35,-0.81);
	glVertex2f(0.7,-0.81);
	glVertex2f(0.7,-0.71);
	glEnd();
glColor3ub(50,50,50 ); //front
	glBegin(GL_QUADS);
	glVertex2f(0.35,-0.71);
	glVertex2f(0.35,-0.78);
	glVertex2f(0.4,-0.78);
	glVertex2f(0.4,-0.71);
	glEnd();
glColor3ub(238,130,238 ); //front2
	glBegin(GL_QUADS);
	glVertex2f(0.35,-0.72);
	glVertex2f(0.35,-0.74);
	glVertex2f(0.37,-0.74);
	glVertex2f(0.37,-0.72);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(0.44,-0.73);
	glVertex2f(0.44,-0.77);
	glVertex2f(0.48,-0.77);
	glVertex2f(0.48,-0.73);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(0.52,-0.73);
	glVertex2f(0.52,-0.77);
	glVertex2f(0.56,-0.77);
	glVertex2f(0.56,-0.73);
	glEnd();
glColor3ub(0,0,205 ); //window
	glBegin(GL_QUADS);
	glVertex2f(0.6,-0.73);
	glVertex2f(0.6,-0.77);
	glVertex2f(0.64,-0.77);
	glVertex2f(0.64,-0.73);
	glEnd();


glColor3ub(50,50,50  );                 //tire
    x=0.45f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=0.41f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(50,50,50  );                 //tire
    x=0.64f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(50,50,50  );                 //tire
    x=0.6f; y=-0.82f;  radius =.02f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

//tree1

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.5);
	glVertex2f(-0.35,-0.65);
	glVertex2f(-0.4,-0.65);
	glVertex2f(-0.4,-0.5);
	glEnd();
glColor3ub(10,150,10);
    x=-0.38f; y=-0.45f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=-0.34f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=-0.42f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree2

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(0.15,-0.5);
	glVertex2f(0.15,-0.65);
	glVertex2f(0.2,-0.65);
	glVertex2f(0.2,-0.5);
	glEnd();
glColor3ub(10,150,10);
    x=0.18f; y=-0.45f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.22f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.14f; y=-0.48f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree3

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(0.15,-0.15);
	glVertex2f(0.15,-0.3);
	glVertex2f(0.2,-0.3);
	glVertex2f(0.2,-0.15);
	glEnd();
glColor3ub(10,150,10);
    x=0.18f; y=-0.1f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.22f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.14f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree1

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(-0.35,-0.15);
	glVertex2f(-0.35,-0.3);
	glVertex2f(-0.4,-0.3);
	glVertex2f(-0.4,-0.15);
	glEnd();
glColor3ub(10,150,10);
    x=-0.38f; y=-0.10f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=-0.34f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=-0.42f; y=-0.13f;  radius =.07f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//tree5

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(0.9,-0.05);
	glVertex2f(0.9,-0.1);
	glVertex2f(0.95,-0.1);
	glVertex2f(0.95,-0.05);
	glEnd();
glColor3ub(10,150,10);
    x=0.92f; y=-0.02f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.91f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.94f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
//tree6

glColor3ub(170,70,30  );
	glBegin(GL_QUADS);
	glVertex2f(0.8,-0.05);
	glVertex2f(0.8,-0.1);
	glVertex2f(0.85,-0.1);
	glVertex2f(0.85,-0.05);
	glEnd();
glColor3ub(10,150,10);
    x=0.82f; y=-0.02f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.81f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(10,150,10);
    x=0.84f; y=-0.035f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



// swimming tire
glColor3ub(128,0,0);
    x=-0.6f; y=0.15f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,228,196);
    x=-0.6f; y=0.15f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//3rd
glColor3ub(0,0,128 );
    x=-0.7f; y=0.12f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,228,196);
    x=-0.7f; y=0.12f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//2nd
glColor3ub(255,165,0 );
    x=-0.65f; y=0.2f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,228,196);
    x=-0.65f; y=0.2f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
//4 on the sea
glColor3ub(128,0,0);
    x=-0.35f; y=0.35f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(150, 200, 255);
    x=-0.35f; y=0.35f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//human1
glColor3ub(0,0,0);
    x=-0.35f; y=0.37f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.38,0.35);
	glVertex2f(-0.38,0.305);
	glVertex2f(-0.32,0.305);
	glVertex2f(-0.32,0.35);
	glEnd();
glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.27,0.35);
	glVertex2f(-0.27,0.32);
	glVertex2f(-0.32,0.32);
	glVertex2f(-0.32,0.35);
	glEnd();
glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.38,0.35);
	glVertex2f(-0.38,0.32);
	glVertex2f(-0.43,0.32);
	glVertex2f(-0.43,0.35);
	glEnd();

//5 on the sea
glColor3ub(255,69,0);
    x=-0.85f; y=0.35f;  radius =.08f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(150, 200, 255);
    x=-0.85f; y=0.35f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//human2

glColor3ub(0,0,0);
    x=-0.85f; y=0.37f;  radius =.03f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.88,0.35);
	glVertex2f(-0.88,0.305);
	glVertex2f(-0.82,0.305);
	glVertex2f(-0.82,0.35);
	glEnd();
glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.77,0.35);
	glVertex2f(-0.77,0.32);
	glVertex2f(-0.82,0.32);
	glVertex2f(-0.82,0.35);
	glEnd();
glColor3ub(200, 160, 110  );
	glBegin(GL_QUADS);
	glVertex2f(-0.88,0.35);
	glVertex2f(-0.88,0.32);
	glVertex2f(-0.93,0.32);
	glVertex2f(-0.93,0.35);
	glEnd();



//beach

glColor3ub(72,209,204   );
	glBegin(GL_QUADS);
	glVertex2f(-0.2,0.05);
	glVertex2f(-0.2,0.2);
	glVertex2f(-0.1,0.2);
	glVertex2f(-0.1,0.05);
	glEnd();
glColor3ub(250,250,250  );
	glBegin(GL_QUADS);
	glVertex2f(-0.12,0.05);
	glVertex2f(-0.12,0.2);
	glVertex2f(-0.14,0.2);
	glVertex2f(-0.14,0.05);
	glEnd();
glColor3ub(250,250,250   );
	glBegin(GL_QUADS);
	glVertex2f(-0.16,0.05);
	glVertex2f(-0.16,0.2);
	glVertex2f(-0.18,0.2);
	glVertex2f(-0.18,0.05);
	glEnd();
//2
glColor3ub(199,21,133   );
	glBegin(GL_QUADS);
	glVertex2f(0.0,0.05);
	glVertex2f(0.0,0.2);
	glVertex2f(-0.1,0.2);
	glVertex2f(-0.1,0.05);
	glEnd();
glColor3ub(250,250,250  );
	glBegin(GL_QUADS);
	glVertex2f(-0.02,0.05);
	glVertex2f(-0.02,0.2);
	glVertex2f(-0.04,0.2);
	glVertex2f(-0.04,0.05);
	glEnd();
glColor3ub(250,250,250   );
	glBegin(GL_QUADS);
	glVertex2f(-0.06,0.05);
	glVertex2f(-0.06,0.2);
	glVertex2f(-0.08,0.2);
	glVertex2f(-0.08,0.05);
	glEnd();

//3

glColor3ub(199,21,133   );
	glBegin(GL_QUADS);
	glVertex2f(0.7,0.25);
	glVertex2f(0.7,0.15);
	glVertex2f(0.9,0.15);
	glVertex2f(0.9,0.25);
	glEnd();

glColor3ub(250,250,250  );
	glBegin(GL_QUADS);
	glVertex2f(0.7,0.19);
	glVertex2f(0.7,0.17);
	glVertex2f(0.9,0.17);
	glVertex2f(0.9,0.19);
	glEnd();
glColor3ub(250,250,250   );
    glBegin(GL_QUADS);
	glVertex2f(0.7,0.22);
	glVertex2f(0.7,0.24);
	glVertex2f(0.9,0.24);
	glVertex2f(0.9,0.22);
	glEnd();

//4

glColor3ub(255,105,180  );
	glBegin(GL_QUADS);
	glVertex2f(0.3,0.05);
	glVertex2f(0.3,0.2);
	glVertex2f(0.2,0.2);
	glVertex2f(0.2,0.05);
	glEnd();
glColor3ub(250,250,250  );
	glBegin(GL_QUADS);
	glVertex2f(0.22,0.05);
	glVertex2f(0.22,0.2);
	glVertex2f(0.24,0.2);
	glVertex2f(0.24,0.05);
	glEnd();
glColor3ub(250,250,250   );
	glBegin(GL_QUADS);
	glVertex2f(0.26,0.05);
	glVertex2f(0.26,0.2);
	glVertex2f(0.28,0.2);
	glVertex2f(0.28,0.05);
	glEnd();

	//rain
	glPushMatrix();
glTranslatef(0.0,position4,0.0);
	glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-1.0,.65);//E
	glVertex2f(-1.0,.60);
	glVertex2f(-1.0,.55);
	glVertex2f(-1.0,.50);
	glVertex2f(-1.0,.45);
	glVertex2f(-1.0,.40);
	glVertex2f(-1.0,.35);
	glVertex2f(-1.0,.30);
	glVertex2f(-1.0,.25);
	glVertex2f(-1.0,.20);
	glVertex2f(-1.0,.15);
	glVertex2f(-1.0,.10);
	glVertex2f(-1.0,.05);
	glVertex2f(-1.0,.00);
	glVertex2f(-1.0,-.05);
	glVertex2f(-1.0,-.10);
	glVertex2f(-1.0,-.15);
	glVertex2f(-1.0,-.20);
	glVertex2f(-1.0,-.25);
	glVertex2f(-1.0,-.30);
	glVertex2f(-1.0,-.35);
	glVertex2f(-1.0,-.40);
	glVertex2f(-1.0,-.45);
	glVertex2f(-1.0,-.50);
	glVertex2f(-1.0,-.55);
	glVertex2f(-1.0,-.60);
	glVertex2f(-1.0,-.65);
	glVertex2f(-1.0,-.70);
	glVertex2f(-1.0,-.75);
	glVertex2f(-1.0,-.80);

	glVertex2f(-.90,.65);//E
	glVertex2f(-.90,.60);
	glVertex2f(-.90,.55);
	glVertex2f(-.90,.50);
	glVertex2f(-.90,.45);
	glVertex2f(-.90,.40);
	glVertex2f(-.90,.35);
	glVertex2f(-.90,.30);
	glVertex2f(-.90,.25);
	glVertex2f(-.90,.20);
	glVertex2f(-.90,.15);
	glVertex2f(-.90,.10);
	glVertex2f(-.90,.05);
	glVertex2f(-.90,.00);
	glVertex2f(-.90,-.05);
	glVertex2f(-.90,-.10);
	glVertex2f(-.90,-.15);
	glVertex2f(-.90,-.20);
	glVertex2f(-.90,-.25);
	glVertex2f(-.90,-.30);
	glVertex2f(-.90,-.35);
	glVertex2f(-.90,-.40);
	glVertex2f(-.90,-.45);
	glVertex2f(-.90,-.50);
	glVertex2f(-.90,-.55);
	glVertex2f(-.90,-.60);
	glVertex2f(-.90,-.65);
	glVertex2f(-.90,-.70);
	glVertex2f(-.90,-.75);
	glVertex2f(-.90,-.80);

	glVertex2f(-.80,.65);//E
	glVertex2f(-.80,.60);
	glVertex2f(-.80,.55);
	glVertex2f(-.80,.50);
	glVertex2f(-.80,.45);
	glVertex2f(-.80,.40);
	glVertex2f(-.80,.35);
	glVertex2f(-.80,.30);
	glVertex2f(-.80,.25);
	glVertex2f(-.80,.20);
	glVertex2f(-.80,.15);
	glVertex2f(-.80,.10);
	glVertex2f(-.80,.05);
	glVertex2f(-.80,.00);
	glVertex2f(-.80,-.05);
	glVertex2f(-.80,-.10);
	glVertex2f(-.80,-.15);
	glVertex2f(-.80,-.20);
	glVertex2f(-.80,-.25);
	glVertex2f(-.80,-.30);
	glVertex2f(-.80,-.35);
	glVertex2f(-.80,-.40);
	glVertex2f(-.80,-.45);
	glVertex2f(-.80,-.50);
	glVertex2f(-.80,-.55);
	glVertex2f(-.80,-.60);
	glVertex2f(-.80,-.65);
	glVertex2f(-.80,-.70);
	glVertex2f(-.80,-.75);
	glVertex2f(-.80,-.80);


	glVertex2f(-.70,.65);//E
	glVertex2f(-.70,.60);
	glVertex2f(-.70,.55);
	glVertex2f(-.70,.50);
	glVertex2f(-.70,.45);
	glVertex2f(-.70,.40);
	glVertex2f(-.70,.35);
	glVertex2f(-.70,.30);
	glVertex2f(-.70,.25);
	glVertex2f(-.70,.20);
	glVertex2f(-.70,.15);
	glVertex2f(-.70,.10);
	glVertex2f(-.70,.05);
	glVertex2f(-.70,.00);
	glVertex2f(-.70,-.05);
	glVertex2f(-.70,-.10);
	glVertex2f(-.70,-.15);
	glVertex2f(-.70,-.20);
	glVertex2f(-.70,-.25);
	glVertex2f(-.70,-.30);
	glVertex2f(-.70,-.35);
	glVertex2f(-.70,-.40);
	glVertex2f(-.70,-.45);
	glVertex2f(-.70,-.50);
	glVertex2f(-.70,-.55);
	glVertex2f(-.70,-.60);
	glVertex2f(-.70,-.65);
	glVertex2f(-.70,-.70);
	glVertex2f(-.70,-.75);
	glVertex2f(-.70,-.80);


	glVertex2f(-.60,.65);//E
	glVertex2f(-.60,.60);
	glVertex2f(-.60,.55);
	glVertex2f(-.60,.50);
	glVertex2f(-.60,.45);
	glVertex2f(-.60,.40);
	glVertex2f(-.60,.35);
	glVertex2f(-.60,.30);
	glVertex2f(-.60,.25);
	glVertex2f(-.60,.20);
	glVertex2f(-.60,.15);
	glVertex2f(-.60,.10);
	glVertex2f(-.60,.05);
	glVertex2f(-.60,.00);
	glVertex2f(-.60,-.05);
	glVertex2f(-.60,-.10);
	glVertex2f(-.60,-.15);
	glVertex2f(-.60,-.20);
	glVertex2f(-.60,-.25);
	glVertex2f(-.60,-.30);
	glVertex2f(-.60,-.35);
	glVertex2f(-.60,-.40);
	glVertex2f(-.60,-.45);
	glVertex2f(-.60,-.50);
	glVertex2f(-.60,-.55);
	glVertex2f(-.60,-.60);
	glVertex2f(-.60,-.65);
	glVertex2f(-.60,-.70);
	glVertex2f(-.60,-.75);
	glVertex2f(-.60,-.80);


	glVertex2f(-.50,.65);//E
	glVertex2f(-.50,.60);
	glVertex2f(-.50,.55);
	glVertex2f(-.50,.50);
	glVertex2f(-.50,.45);
	glVertex2f(-.50,.40);
	glVertex2f(-.50,.35);
	glVertex2f(-.50,.30);
	glVertex2f(-.50,.25);
	glVertex2f(-.50,.20);
	glVertex2f(-.50,.15);
	glVertex2f(-.50,.10);
	glVertex2f(-.50,.05);
	glVertex2f(-.50,.00);
	glVertex2f(-.50,-.05);
	glVertex2f(-.50,-.10);
	glVertex2f(-.50,-.15);
	glVertex2f(-.50,-.20);
	glVertex2f(-.50,-.25);
	glVertex2f(-.50,-.30);
	glVertex2f(-.50,-.35);
	glVertex2f(-.50,-.40);
	glVertex2f(-.50,-.45);
	glVertex2f(-.50,-.50);
	glVertex2f(-.50,-.55);
	glVertex2f(-.50,-.60);
	glVertex2f(-.50,-.65);
	glVertex2f(-.50,-.70);
	glVertex2f(-.50,-.75);
	glVertex2f(-.50,-.80);



	glVertex2f(-.40,.65);//E
	glVertex2f(-.40,.60);
	glVertex2f(-.40,.55);
	glVertex2f(-.40,.50);
	glVertex2f(-.40,.45);
	glVertex2f(-.40,.40);
	glVertex2f(-.40,.35);
	glVertex2f(-.40,.30);
	glVertex2f(-.40,.25);
	glVertex2f(-.40,.20);
	glVertex2f(-.40,.15);
	glVertex2f(-.40,.10);
	glVertex2f(-.40,.05);
	glVertex2f(-.40,.00);
	glVertex2f(-.40,-.05);
	glVertex2f(-.40,-.10);
	glVertex2f(-.40,-.15);
	glVertex2f(-.40,-.20);
	glVertex2f(-.40,-.25);
	glVertex2f(-.40,-.30);
	glVertex2f(-.40,-.35);
	glVertex2f(-.40,-.40);
	glVertex2f(-.40,-.45);
	glVertex2f(-.40,-.50);
	glVertex2f(-.40,-.55);
	glVertex2f(-.40,-.60);
	glVertex2f(-.40,-.65);
	glVertex2f(-.40,-.70);
	glVertex2f(-.40,-.75);
	glVertex2f(-.40,-.80);


	glVertex2f(-.30,.65);//E
	glVertex2f(-.30,.60);
	glVertex2f(-.30,.55);
	glVertex2f(-.30,.50);
	glVertex2f(-.30,.45);
	glVertex2f(-.30,.40);
	glVertex2f(-.30,.35);
	glVertex2f(-.30,.30);
	glVertex2f(-.30,.25);
	glVertex2f(-.30,.20);
	glVertex2f(-.30,.15);
	glVertex2f(-.30,.10);
	glVertex2f(-.30,.05);
	glVertex2f(-.30,.00);
	glVertex2f(-.30,-.05);
	glVertex2f(-.30,-.10);
	glVertex2f(-.30,-.15);
	glVertex2f(-.30,-.20);
	glVertex2f(-.30,-.25);
	glVertex2f(-.30,-.30);
	glVertex2f(-.30,-.35);
	glVertex2f(-.30,-.40);
	glVertex2f(-.30,-.45);
	glVertex2f(-.30,-.50);
	glVertex2f(-.30,-.55);
	glVertex2f(-.30,-.60);
	glVertex2f(-.30,-.65);
	glVertex2f(-.30,-.70);
	glVertex2f(-.30,-.75);
	glVertex2f(-.30,-.80);


	glVertex2f(-.20,.65);//E
	glVertex2f(-.20,.60);
	glVertex2f(-.20,.55);
	glVertex2f(-.20,.50);
	glVertex2f(-.20,.45);
	glVertex2f(-.20,.40);
	glVertex2f(-.20,.35);
	glVertex2f(-.20,.30);
	glVertex2f(-.20,.25);
	glVertex2f(-.20,.20);
	glVertex2f(-.20,.15);
	glVertex2f(-.20,.10);
	glVertex2f(-.20,.05);
	glVertex2f(-.20,.00);
	glVertex2f(-.20,-.05);
	glVertex2f(-.20,-.10);
	glVertex2f(-.20,-.15);
	glVertex2f(-.20,-.20);
	glVertex2f(-.20,-.25);
	glVertex2f(-.20,-.30);
	glVertex2f(-.20,-.35);
	glVertex2f(-.20,-.40);
	glVertex2f(-.20,-.45);
	glVertex2f(-.20,-.50);
	glVertex2f(-.20,-.55);
	glVertex2f(-.20,-.60);
	glVertex2f(-.20,-.65);
	glVertex2f(-.20,-.70);
	glVertex2f(-.20,-.75);
	glVertex2f(-.20,-.80);



	glVertex2f(-.10,.65);//E
	glVertex2f(-.10,.60);
	glVertex2f(-.10,.55);
	glVertex2f(-.10,.50);
	glVertex2f(-.10,.45);
	glVertex2f(-.10,.40);
	glVertex2f(-.10,.35);
	glVertex2f(-.10,.30);
	glVertex2f(-.10,.25);
	glVertex2f(-.10,.20);
	glVertex2f(-.10,.15);
	glVertex2f(-.10,.10);
	glVertex2f(-.10,.05);
	glVertex2f(-.10,.00);
	glVertex2f(-.10,-.05);
	glVertex2f(-.10,-.10);
	glVertex2f(-.10,-.15);
	glVertex2f(-.10,-.20);
	glVertex2f(-.10,-.25);
	glVertex2f(-.10,-.30);
	glVertex2f(-.10,-.35);
	glVertex2f(-.10,-.40);
	glVertex2f(-.10,-.45);
	glVertex2f(-.10,-.50);
	glVertex2f(-.10,-.55);
	glVertex2f(-.10,-.60);
	glVertex2f(-.10,-.65);
	glVertex2f(-.10,-.70);
	glVertex2f(-.10,-.75);
	glVertex2f(-.10,-.80);

	glVertex2f(-.00,.65);//E
	glVertex2f(-.00,.60);
	glVertex2f(-.00,.55);
	glVertex2f(-.00,.50);
	glVertex2f(-.00,.45);
	glVertex2f(-.00,.40);
	glVertex2f(-.00,.35);
	glVertex2f(-.00,.30);
	glVertex2f(-.00,.25);
	glVertex2f(-.00,.20);
	glVertex2f(-.00,.15);
	glVertex2f(-.00,.10);
	glVertex2f(-.00,.05);
	glVertex2f(-.00,.00);
	glVertex2f(-.00,-.05);
	glVertex2f(-.00,-.10);
	glVertex2f(-.00,-.15);
	glVertex2f(-.00,-.20);
	glVertex2f(-.00,-.25);
	glVertex2f(-.00,-.30);
	glVertex2f(-.00,-.35);
	glVertex2f(-.00,-.40);
	glVertex2f(-.00,-.45);
	glVertex2f(-.00,-.50);
	glVertex2f(-.00,-.55);
	glVertex2f(-.00,-.60);
	glVertex2f(-.00,-.65);
	glVertex2f(-.00,-.70);
	glVertex2f(-.00,-.75);
	glVertex2f(-.00,-.80);


	glVertex2f(.10,.65);//E
	glVertex2f(.10,.60);
	glVertex2f(.10,.55);
	glVertex2f(.10,.50);
	glVertex2f(.10,.45);
	glVertex2f(.10,.40);
	glVertex2f(.10,.35);
	glVertex2f(.10,.30);
	glVertex2f(.10,.25);
	glVertex2f(.10,.20);
	glVertex2f(.10,.15);
	glVertex2f(.10,.10);
	glVertex2f(.10,.05);
	glVertex2f(.10,.00);
	glVertex2f(.10,-.05);
	glVertex2f(.10,-.10);
	glVertex2f(.10,-.15);
	glVertex2f(.10,-.20);
	glVertex2f(.10,-.25);
	glVertex2f(.10,-.30);
	glVertex2f(.10,-.35);
	glVertex2f(.10,-.40);
	glVertex2f(.10,-.45);
	glVertex2f(.10,-.50);
	glVertex2f(.10,-.55);
	glVertex2f(.10,-.60);
	glVertex2f(.10,-.65);
	glVertex2f(.10,-.70);
	glVertex2f(.10,-.75);
	glVertex2f(.10,-.80);


	glVertex2f(.20,.65);//E
	glVertex2f(.20,.60);
	glVertex2f(.20,.55);
	glVertex2f(.20,.50);
	glVertex2f(.20,.45);
	glVertex2f(.20,.40);
	glVertex2f(.20,.35);
	glVertex2f(.20,.30);
	glVertex2f(.20,.25);
	glVertex2f(.20,.20);
	glVertex2f(.20,.15);
	glVertex2f(.20,.10);
	glVertex2f(.20,.05);
	glVertex2f(.20,.00);
	glVertex2f(.20,-.05);
	glVertex2f(.20,-.10);
	glVertex2f(.20,-.15);
	glVertex2f(.20,-.20);
	glVertex2f(.20,-.25);
	glVertex2f(.20,-.30);
	glVertex2f(.20,-.35);
	glVertex2f(.20,-.40);
	glVertex2f(.20,-.45);
	glVertex2f(.20,-.50);
	glVertex2f(.20,-.55);
	glVertex2f(.20,-.60);
	glVertex2f(.20,-.65);
	glVertex2f(.20,-.70);
	glVertex2f(.20,-.75);
	glVertex2f(.20,-.80);


	glVertex2f(.30,.65);//E
	glVertex2f(.30,.60);
	glVertex2f(.30,.55);
	glVertex2f(.30,.50);
	glVertex2f(.30,.45);
	glVertex2f(.30,.40);
	glVertex2f(.30,.35);
	glVertex2f(.30,.30);
	glVertex2f(.30,.25);
	glVertex2f(.30,.20);
	glVertex2f(.30,.15);
	glVertex2f(.30,.10);
	glVertex2f(.30,.05);
	glVertex2f(.30,.00);
	glVertex2f(.30,-.05);
	glVertex2f(.30,-.10);
	glVertex2f(.30,-.15);
	glVertex2f(.30,-.20);
	glVertex2f(.30,-.25);
	glVertex2f(.30,-.30);
	glVertex2f(.30,-.35);
	glVertex2f(.30,-.40);
	glVertex2f(.30,-.45);
	glVertex2f(.30,-.50);
	glVertex2f(.30,-.55);
	glVertex2f(.30,-.60);
	glVertex2f(.30,-.65);
	glVertex2f(.30,-.70);
	glVertex2f(.30,-.75);
	glVertex2f(.30,-.80);


	glVertex2f(.40,.65);//E
	glVertex2f(.40,.60);
	glVertex2f(.40,.55);
	glVertex2f(.40,.50);
	glVertex2f(.40,.45);
	glVertex2f(.40,.40);
	glVertex2f(.40,.35);
	glVertex2f(.40,.30);
	glVertex2f(.40,.25);
	glVertex2f(.40,.20);
	glVertex2f(.40,.15);
	glVertex2f(.40,.10);
	glVertex2f(.40,.05);
	glVertex2f(.40,.00);
	glVertex2f(.40,-.05);
	glVertex2f(.40,-.10);
	glVertex2f(.40,-.15);
	glVertex2f(.40,-.20);
	glVertex2f(.40,-.25);
	glVertex2f(.40,-.30);
	glVertex2f(.40,-.35);
	glVertex2f(.40,-.40);
	glVertex2f(.40,-.45);
	glVertex2f(.40,-.50);
	glVertex2f(.40,-.55);
	glVertex2f(.40,-.60);
	glVertex2f(.40,-.65);
	glVertex2f(.40,-.70);
	glVertex2f(.40,-.75);
	glVertex2f(.40,-.80);


	glVertex2f(.50,.65);//E
	glVertex2f(.50,.60);
	glVertex2f(.50,.55);
	glVertex2f(.50,.50);
	glVertex2f(.50,.45);
	glVertex2f(.50,.40);
	glVertex2f(.50,.35);
	glVertex2f(.50,.30);
	glVertex2f(.50,.25);
	glVertex2f(.50,.20);
	glVertex2f(.50,.15);
	glVertex2f(.50,.10);
	glVertex2f(.50,.05);
	glVertex2f(.50,.00);
	glVertex2f(.50,-.05);
	glVertex2f(.50,-.10);
	glVertex2f(.50,-.15);
	glVertex2f(.50,-.20);
	glVertex2f(.50,-.25);
	glVertex2f(.50,-.30);
	glVertex2f(.50,-.35);
	glVertex2f(.50,-.40);
	glVertex2f(.50,-.45);
	glVertex2f(.50,-.50);
	glVertex2f(.50,-.55);
	glVertex2f(.50,-.60);
	glVertex2f(.50,-.65);
	glVertex2f(.50,-.70);
	glVertex2f(.50,-.75);
	glVertex2f(.50,-.80);



	glVertex2f(.60,.65);//E
	glVertex2f(.60,.60);
	glVertex2f(.60,.55);
	glVertex2f(.60,.50);
	glVertex2f(.60,.45);
	glVertex2f(.60,.40);
	glVertex2f(.60,.35);
	glVertex2f(.60,.30);
	glVertex2f(.60,.25);
	glVertex2f(.60,.20);
	glVertex2f(.60,.15);
	glVertex2f(.60,.10);
	glVertex2f(.60,.05);
	glVertex2f(.60,.00);
	glVertex2f(.60,-.05);
	glVertex2f(.60,-.10);
	glVertex2f(.60,-.15);
	glVertex2f(.60,-.20);
	glVertex2f(.60,-.25);
	glVertex2f(.60,-.30);
	glVertex2f(.60,-.35);
	glVertex2f(.60,-.40);
	glVertex2f(.60,-.45);
	glVertex2f(.60,-.50);
	glVertex2f(.60,-.55);
	glVertex2f(.60,-.60);
	glVertex2f(.60,-.65);
	glVertex2f(.60,-.70);
	glVertex2f(.60,-.75);
	glVertex2f(.60,-.80);

	glVertex2f(.70,.65);//E
	glVertex2f(.70,.60);
	glVertex2f(.70,.55);
	glVertex2f(.70,.50);
	glVertex2f(.70,.45);
	glVertex2f(.70,.40);
	glVertex2f(.70,.35);
	glVertex2f(.70,.30);
	glVertex2f(.70,.25);
	glVertex2f(.70,.20);
	glVertex2f(.70,.15);
	glVertex2f(.70,.10);
	glVertex2f(.70,.05);
	glVertex2f(.70,.00);
	glVertex2f(.70,-.05);
	glVertex2f(.70,-.10);
	glVertex2f(.70,-.15);
	glVertex2f(.70,-.20);
	glVertex2f(.70,-.25);
	glVertex2f(.70,-.30);
	glVertex2f(.70,-.35);
	glVertex2f(.70,-.40);
	glVertex2f(.70,-.45);
	glVertex2f(.70,-.50);
	glVertex2f(.70,-.55);
	glVertex2f(.70,-.60);
	glVertex2f(.70,-.65);
	glVertex2f(.70,-.70);
	glVertex2f(.70,-.75);
	glVertex2f(.70,-.80);



	glVertex2f(.80,.65);//E
	glVertex2f(.80,.60);
	glVertex2f(.80,.55);
	glVertex2f(.80,.50);
	glVertex2f(.80,.45);
	glVertex2f(.80,.40);
	glVertex2f(.80,.35);
	glVertex2f(.80,.30);
	glVertex2f(.80,.25);
	glVertex2f(.80,.20);
	glVertex2f(.80,.15);
	glVertex2f(.80,.10);
	glVertex2f(.80,.05);
	glVertex2f(.80,.00);
	glVertex2f(.80,-.05);
	glVertex2f(.80,-.10);
	glVertex2f(.80,-.15);
	glVertex2f(.80,-.20);
	glVertex2f(.80,-.25);
	glVertex2f(.80,-.30);
	glVertex2f(.80,-.35);
	glVertex2f(.80,-.40);
	glVertex2f(.80,-.45);
	glVertex2f(.80,-.50);
	glVertex2f(.80,-.55);
	glVertex2f(.80,-.60);
	glVertex2f(.80,-.65);
	glVertex2f(.80,-.70);
	glVertex2f(.80,-.75);
	glVertex2f(.80,-.80);


	glVertex2f(.90,.65);//E
	glVertex2f(.90,.60);
	glVertex2f(.90,.55);
	glVertex2f(.90,.50);
	glVertex2f(.90,.45);
	glVertex2f(.90,.40);
	glVertex2f(.90,.35);
	glVertex2f(.90,.30);
	glVertex2f(.90,.25);
	glVertex2f(.90,.20);
	glVertex2f(.90,.15);
	glVertex2f(.90,.10);
	glVertex2f(.90,.05);
	glVertex2f(.90,.00);
	glVertex2f(.90,-.05);
	glVertex2f(.90,-.10);
	glVertex2f(.90,-.15);
	glVertex2f(.90,-.20);
	glVertex2f(.90,-.25);
	glVertex2f(.90,-.30);
	glVertex2f(.90,-.35);
	glVertex2f(.90,-.40);
	glVertex2f(.90,-.45);
	glVertex2f(.90,-.50);
	glVertex2f(.90,-.55);
	glVertex2f(.90,-.60);
	glVertex2f(.90,-.65);
	glVertex2f(.90,-.70);
	glVertex2f(.90,-.75);
	glVertex2f(.90,-.80);

	glVertex2f(1.0,.65);//E
	glVertex2f(1.0,.60);
	glVertex2f(1.0,.55);
	glVertex2f(1.0,.50);
	glVertex2f(1.0,.45);
	glVertex2f(1.0,.40);
	glVertex2f(1.0,.35);
	glVertex2f(1.0,.30);
	glVertex2f(1.0,.25);
	glVertex2f(1.0,.20);
	glVertex2f(1.0,.15);
	glVertex2f(1.0,.10);
	glVertex2f(1.0,.05);
	glVertex2f(1.0,.00);
	glVertex2f(1.0,-.05);
	glVertex2f(1.0,-.10);
	glVertex2f(1.0,-.15);
	glVertex2f(1.0,-.20);
	glVertex2f(1.0,-.25);
	glVertex2f(1.0,-.30);
	glVertex2f(1.0,-.35);
	glVertex2f(1.0,-.40);
	glVertex2f(1.0,-.45);
	glVertex2f(1.0,-.50);
	glVertex2f(1.0,-.55);
	glVertex2f(1.0,-.60);
	glVertex2f(1.0,-.65);
	glVertex2f(1.0,-.70);
	glVertex2f(1.0,-.75);
	glVertex2f(1.0,-.80);

	glEnd();
	glPopMatrix();



   glFlush();

}

void night(){
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);// Clear the color buffer (background)
    glLoadIdentity();//Reset the current matrix

    glBegin(GL_QUADS);
    glColor3ub(10,10,122 );      //sky buttom
	glVertex2f(-1, 0.2);
	glVertex2f(1, 0.2);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(5,5,124 );      //sky  centre
	glVertex2f(-1, 0.5);
	glVertex2f(1, 0.5);
	glVertex2f(1, 0.7);
	glVertex2f(-1, 0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,128 );      //sky top
	glVertex2f(-1, 0.7);
	glVertex2f(1, 0.7);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
    glEnd();



    glLoadIdentity();
    int i;                                      //moon
    GLfloat x=0.7f; GLfloat y=0.87f; GLfloat radius =.08f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,235,205);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount; i++) {
			glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//star
    glColor3ub(255,235,205);
    x=-0.9f; y=0.85f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.9f; y=0.8f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.5f; y=0.75f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.7f; y=0.75f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.77f; y=0.9f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.35f; y=0.9f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.8f; y=0.84f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,235,205);
    x=0.1f; y=0.85f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,235,205);
    x=0.47f; y=0.78f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.55f; y=0.55f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.0f; y=0.8f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.2f; y=0.68f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,235,205);
    x=0.76f; y=0.73f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=0.27f; y=0.69f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.15f; y=0.87f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.25f; y=0.65f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


glColor3ub(255,235,205);
    x=-0.94f; y=0.49f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.48f; y=0.89f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.84f; y=0.57f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glColor3ub(255,235,205);
    x=-0.78f; y=0.98f;  radius =.005f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glPushMatrix();
	glTranslatef(bird_position, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3ub(30,30,30);
    glVertex2f(-0.6f, 0.3f);
     glVertex2f(-0.5f,0.25f);// x, y
     glVertex2f(-0.55f,0.3f);
     glEnd();
glBegin(GL_TRIANGLES);
    glColor3ub(30,30,30);
    glVertex2f(-0.6f, 0.25f);
     glVertex2f(-0.55f,0.25f);// x, y
     glVertex2f(-0.5f,0.3f);

  glEnd();
//birds
glBegin(GL_TRIANGLES);
    glColor3ub(30,30,30);
    glVertex2f(-0.6f, 0.4f);
     glVertex2f(-0.5f,0.35f);// x, y
     glVertex2f(-0.55f,0.4f);
     glEnd();
glBegin(GL_TRIANGLES);
    glColor3ub(30,30,30);
    glVertex2f(-0.6f, 0.35f);
     glVertex2f(-0.55f,0.35f);// x, y
     glVertex2f(-0.5f,0.4f);

  glEnd();

    glPopMatrix();





    //glPopMatrix();

    glLoadIdentity();
    glPushMatrix();
	glTranslatef(plane_position, 0.0f, 0.0f);
    glBegin(GL_QUADS);              //plane up wing
	glColor3ub(53, 143, 112);
	glVertex2f(-0.6, 0.65);
	glVertex2f(-0.5, 0.65);
	glVertex2f(-0.47, 0.75);
	glVertex2f(-0.5, 0.75);
	glEnd();

    glBegin(GL_POLYGON);            //plane body
	glColor3ub(0,0,0);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.73, 0.55);
	glVertex2f(-0.4, 0.55);
	glVertex2f(-0.4, 0.58);
	glVertex2f(-0.43, 0.63);
	glVertex2f(-0.5, 0.68);
	glVertex2f(-0.72, 0.68);
	glEnd();

    glBegin(GL_QUADS);              //plane tail
	glColor3ub(53, 143, 112);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.72, 0.68);
	glVertex2f(-0.79, 0.75);
	glVertex2f(-0.82, 0.75);
	glEnd();

    glBegin(GL_QUADS);              //plane down wing
	glColor3ub(53, 143, 112);
	glVertex2f(-0.75, 0.48);
	glVertex2f(-0.7, 0.48);
	glVertex2f(-0.5, 0.58);
	glVertex2f(-0.65, 0.58);
	glEnd();

    glBegin(GL_QUADS);              //plane front window
	glColor3ub(227, 227, 227);
	glVertex2f(-0.53, 0.63);
	glVertex2f(-0.43, 0.63);
	glVertex2f(-0.5, 0.68);
	glVertex2f(-0.53, 0.65);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //plane window
	glVertex2f(-0.56, 0.63);
	glVertex2f(-0.58, 0.63);
	glVertex2f(-0.58, 0.66);
	glVertex2f(-0.56, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //plane window
	glVertex2f(-0.56, 0.63);
	glVertex2f(-0.58, 0.63);
	glVertex2f(-0.58, 0.66);
	glVertex2f(-0.56, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //plane window
	glVertex2f(-0.6, 0.63);
	glVertex2f(-0.62, 0.63);
	glVertex2f(-0.62, 0.66);
	glVertex2f(-0.6, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //plane window
	glVertex2f(-0.64, 0.63);
	glVertex2f(-0.66, 0.63);
	glVertex2f(-0.66, 0.66);
	glVertex2f(-0.64, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //plane window
	glVertex2f(-0.68, 0.63);
	glVertex2f(-0.7, 0.63);
	glVertex2f(-0.7, 0.66);
	glVertex2f(-0.68, 0.66);
    glEnd();
	glPopMatrix();


    glLoadIdentity();
    int e;                          //moon
GLfloat x5=0.68f; GLfloat y5=0.9f; GLfloat radius5 =.085f;
	int triangleAmount5 = 20;
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,128);
		glVertex2f(x5, y5);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x5 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();



	glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(0,60,0 );      //background
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0.2);
	glVertex2f(-1, 0.2);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //road
	glVertex2f(-1, -0.7);
	glVertex2f(1, -0.7);
	glVertex2f(1, -0.4);
	glVertex2f(-1, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //bottom road
	glVertex2f(-0.17, -1);
	glVertex2f(0.17, -1);
	glVertex2f(0.15, -0.7);
	glVertex2f(-0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //top road
	glVertex2f(-0.14, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(-0.1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-1.1, -0.55);
	glVertex2f(-1, -0.55);
	glVertex2f(-0.95, -0.53);
	glVertex2f(-1.05, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.9, -0.55);
	glVertex2f(-0.8, -0.55);
	glVertex2f(-0.75, -0.53);
	glVertex2f(-0.85, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.7, -0.55);
	glVertex2f(-0.6, -0.55);
	glVertex2f(-0.55, -0.53);
	glVertex2f(-0.65, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.5, -0.55);
	glVertex2f(-0.4, -0.55);
	glVertex2f(-0.35, -0.53);
	glVertex2f(-0.45, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.3, -0.55);
	glVertex2f(-0.2, -0.55);
	glVertex2f(-0.15, -0.53);
	glVertex2f(-0.25, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.15, -0.55);
	glVertex2f(0.25, -0.55);
	glVertex2f(0.3, -0.53);
	glVertex2f(0.2, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.35, -0.55);
	glVertex2f(0.45, -0.55);
	glVertex2f(0.5, -0.53);
	glVertex2f(0.4, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.55, -0.55);
	glVertex2f(0.65, -0.55);
	glVertex2f(0.7, -0.53);
	glVertex2f(0.6, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.75, -0.55);
	glVertex2f(0.85, -0.55);
	glVertex2f(0.9, -0.53);
	glVertex2f(0.8, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.95, -0.55);
	glVertex2f(1, -0.55);
	glVertex2f(1, -0.53);
	glVertex2f(1, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //bottom divider
	glVertex2f(-0.01, -0.8);
	glVertex2f(0.01, -0.8);
	glVertex2f(0.01, -0.7);
	glVertex2f(-0.01, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //bottom divider
	glVertex2f(-0.01, -0.9);
	glVertex2f(0.01, -0.9);
	glVertex2f(0.01, -1);
	glVertex2f(-0.01, -1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, -0.4);
	glVertex2f(0.01, -0.4);
	glVertex2f(0.01, -0.3);
	glVertex2f(-0.01, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, -0.2);
	glVertex2f(0.01, -0.2);
	glVertex2f(0.01, -0.1);
	glVertex2f(-0.01, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, 0.0);
	glVertex2f(0.01, 0.0);
	glVertex2f(0.01, 0.1);
	glVertex2f(-0.01, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom left footpath
	glVertex2f(-1, -0.8);
	glVertex2f(-0.25, -0.8);
	glVertex2f(-0.25, -0.7);
	glVertex2f(-1, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom left footpath
	glVertex2f(-0.28, -1);
	glVertex2f(-0.17, -1);
	glVertex2f(-0.15, -0.7);
	glVertex2f(-0.25, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom right footpath
	glVertex2f(0.2, -0.8);
	glVertex2f(1, -0.8);
	glVertex2f(1, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom right footpath
	glVertex2f(0.17, -1);
	glVertex2f(0.28, -1);
	glVertex2f(0.25, -0.7);
	glVertex2f(0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top left footpath
	glVertex2f(-1, -0.4);
	glVertex2f(-0.2, -0.4);
	glVertex2f(-0.2, -0.3);
	glVertex2f(-1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top left footpath
	glVertex2f(-0.24, -0.4);
	glVertex2f(-0.14, -0.4);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top right footpath
	glVertex2f(1, -0.4);
	glVertex2f(0.2, -0.4);
	glVertex2f(0.2, -0.3);
	glVertex2f(1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top right footpath
	glVertex2f(0.24, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.19, 0.2);
    glEnd();

    //tree

      glBegin(GL_QUADS);
   glColor3ub(102, 34, 0);

     glVertex2f(-.8f, -1.0f);
     glVertex2f(-.8f, -0.9f);// x, y
     glVertex2f(-.77f, -0.9f);
     glVertex2f(-.77f, -1.0f);// x, y

   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(60,179,113);

     glVertex2f(-0.84f, -0.91f);
     glVertex2f(-.785f, -.81f);// x, y
     glVertex2f(-.73f, -0.91f);


   glEnd();


   glBegin(GL_TRIANGLES);
   glColor3ub(60,179,113);

     glVertex2f(-0.84f, -0.95f);
     glVertex2f(-.785f, -.85f);// x, y
     glVertex2f(-.73f, -0.95f);


   glEnd();


      glBegin(GL_QUADS);
   glColor3ub(102, 34, 0);

     glVertex2f(.8f, -1.0f);
     glVertex2f(.8f, -0.9f);// x, y
     glVertex2f(.77f, -0.9f);
     glVertex2f(.77f, -1.0f);// x, y

   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(60,179,113);

     glVertex2f(0.84f, -0.91f);
     glVertex2f(.785f, -.81f);// x, y
     glVertex2f(.73f, -0.91f);


   glEnd();


   glBegin(GL_TRIANGLES);
   glColor3ub(60,179,113);

     glVertex2f(0.84f, -0.95f);
     glVertex2f(.785f, -.85f);// x, y
     glVertex2f(.73f, -0.95f);


   glEnd();



    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //1st building front
	glVertex2f(-0.95, -0.25);
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.95, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //1st building right
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.65, -0.2);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.7, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //1st building top
	glVertex2f(-0.95, 0.35);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.9, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //1st building window
	glVertex2f(-0.9, 0.25);
	glVertex2f(-0.85, 0.25);
	glVertex2f(-0.85, 0.3);
	glVertex2f(-0.9, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //1st building window
	glVertex2f(-0.8, 0.25);
	glVertex2f(-0.75, 0.25);
	glVertex2f(-0.75, 0.3);
	glVertex2f(-0.8, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //1st building window
	glVertex2f(-0.9, 0.15);
	glVertex2f(-0.85, 0.15);
	glVertex2f(-0.85, 0.2);
	glVertex2f(-0.9, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //1st building window
	glVertex2f(-0.8, 0.15);
	glVertex2f(-0.75, 0.15);
	glVertex2f(-0.75, 0.2);
	glVertex2f(-0.8, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //1st building window
	glVertex2f(-0.9, 0.05);
	glVertex2f(-0.85, 0.05);
	glVertex2f(-0.85, 0.1);
	glVertex2f(-0.9, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0);      //1st building window
	glVertex2f(-0.8, 0.05);
	glVertex2f(-0.75, 0.05);
	glVertex2f(-0.75, 0.1);
	glVertex2f(-0.8, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //1st building window
	glVertex2f(-0.9, 0.0);
	glVertex2f(-0.85, 0.0);
	glVertex2f(-0.85, -0.05);
	glVertex2f(-0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //1st building window
	glVertex2f(-0.8, 0.0);
	glVertex2f(-0.75, 0.0);
	glVertex2f(-0.75, -0.05);
	glVertex2f(-0.8, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //1st building window
	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.85, -0.1);
	glVertex2f(-0.85, -0.15);
	glVertex2f(-0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0);      //1st building window
	glVertex2f(-0.8, -0.15);
	glVertex2f(-0.75, -0.15);
	glVertex2f(-0.75, -0.1);
	glVertex2f(-0.8, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //1st building door
	glVertex2f(-0.85, -0.25);
	glVertex2f(-0.8, -0.25);
	glVertex2f(-0.8, -0.18);
	glVertex2f(-0.85, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //2nd building front
	glVertex2f(-0.63, -0.25);
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.63, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //2nd building right
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.28, -0.2);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.33, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //2nd building top
	glVertex2f(-0.63, 0.15);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.58, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //2nd building window
	glVertex2f(-0.58, -0.15);
	glVertex2f(-0.51, -0.15);
	glVertex2f(-0.51, -0.1);
	glVertex2f(-0.58, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //2nd building window
	glVertex2f(-0.45, -0.15);
	glVertex2f(-0.38, -0.15);
	glVertex2f(-0.38, -0.1);
	glVertex2f(-0.45, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //2nd building window
	glVertex2f(-0.58, 0.0);
	glVertex2f(-0.51, 0.0);
	glVertex2f(-0.51, -0.05);
	glVertex2f(-0.58, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //2nd building window
	glVertex2f(-0.45, 0.0);
	glVertex2f(-0.38, 0.0);
	glVertex2f(-0.38, -0.05);
	glVertex2f(-0.45, -0.05);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //2nd building window
	glVertex2f(-0.58, 0.05);
	glVertex2f(-0.51, 0.05);
	glVertex2f(-0.51, 0.1);
	glVertex2f(-0.58, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //2nd building window
	glVertex2f(-0.45, 0.05);
	glVertex2f(-0.38, 0.05);
	glVertex2f(-0.38, 0.1);
	glVertex2f(-0.45, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //2nd building door
	glVertex2f(-0.51, -0.25);
	glVertex2f(-0.45, -0.25);
	glVertex2f(-0.45, -0.18);
	glVertex2f(-0.51, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //3rd building
	glVertex2f(0.3, -0.25);
	glVertex2f(0.55, -0.25);
	glVertex2f(0.55, 0.4);
	glVertex2f(0.3, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //3rd building window
	glVertex2f(0.35, 0.3);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.4, 0.35);
	glVertex2f(0.35, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0  );      //3rd building window
	glVertex2f(0.45, 0.3);
	glVertex2f(0.5, 0.3);
	glVertex2f(0.5, 0.35);
	glVertex2f(0.45, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0  );      //3rd building window
	glVertex2f(0.35, 0.2);
	glVertex2f(0.4, 0.2);
	glVertex2f(0.4, 0.25);
	glVertex2f(0.35, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //3rd building window
	glVertex2f(0.45, 0.2);
	glVertex2f(0.5, 0.2);
	glVertex2f(0.5, 0.25);
	glVertex2f(0.45, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //3rd building window
	glVertex2f(0.35, 0.1);
	glVertex2f(0.4, 0.1);
	glVertex2f(0.4, 0.15);
	glVertex2f(0.35, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0  );      //3rd building window
	glVertex2f(0.45, 0.1);
	glVertex2f(0.5, 0.1);
	glVertex2f(0.5, 0.15);
	glVertex2f(0.45, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0  );      //3rd building window
	glVertex2f(0.35, 0.0);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.4, 0.05);
	glVertex2f(0.35, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0  );      //3rd building window
	glVertex2f(0.45, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, 0.05);
	glVertex2f(0.45, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //3rd building window
	glVertex2f(0.35, -0.1);
	glVertex2f(0.4, -0.1);
	glVertex2f(0.4, -0.05);
	glVertex2f(0.35, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0  );      //3rd building window
	glVertex2f(0.45, -0.1);
	glVertex2f(0.5, -0.1);
	glVertex2f(0.5, -0.05);
	glVertex2f(0.45, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //3rd building window
	glVertex2f(0.35, -0.2);
	glVertex2f(0.4, -0.2);
	glVertex2f(0.4, -0.15);
	glVertex2f(0.35, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0  );      //3rd building window
	glVertex2f(0.45, -0.2);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.5, -0.15);
	glVertex2f(0.45, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //3rd building door
	glVertex2f(0.45, -0.25);
	glVertex2f(0.4, -0.25);
	glVertex2f(0.4, -0.22);
	glVertex2f(0.45, -0.22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //4th building
	glVertex2f(0.6, -0.25);
	glVertex2f(0.95, -0.25);
	glVertex2f(0.95, 0.25);
	glVertex2f(0.6, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //4th building window
	glVertex2f(0.65, 0.2);
	glVertex2f(0.7, 0.2);
	glVertex2f(0.7, 0.15);
	glVertex2f(0.65, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //4th building window
	glVertex2f(0.75, 0.2);
	glVertex2f(0.8, 0.2);
	glVertex2f(0.8, 0.15);
	glVertex2f(0.75, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //4th building window
	glVertex2f(0.9, 0.2);
	glVertex2f(0.85, 0.2);
	glVertex2f(0.85, 0.15);
	glVertex2f(0.9, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //4th building window
	glVertex2f(0.65, 0.1);
	glVertex2f(0.7, 0.1);
	glVertex2f(0.7, 0.05);
	glVertex2f(0.65, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //4th building window
	glVertex2f(0.75, 0.1);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.8, 0.05);
	glVertex2f(0.75, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //4th building window
	glVertex2f(0.9, 0.1);
	glVertex2f(0.85, 0.1);
	glVertex2f(0.85, 0.05);
	glVertex2f(0.9, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //4th building window
	glVertex2f(0.65, 0.0);
	glVertex2f(0.7, 0.0);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.65, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //4th building window
	glVertex2f(0.75, 0.0);
	glVertex2f(0.8, 0.0);
	glVertex2f(0.8, -0.05);
	glVertex2f(0.75, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //4th building window
	glVertex2f(0.9, 0.0);
	glVertex2f(0.85, 0.0);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0 );      //4th building window
	glVertex2f(0.65, -0.1);
	glVertex2f(0.7, -0.1);
	glVertex2f(0.7, -0.15);
	glVertex2f(0.65, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //4th building window
	glVertex2f(0.75, -0.1);
	glVertex2f(0.8, -0.1);
	glVertex2f(0.8, -0.15);
	glVertex2f(0.75, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0 );      //4th building window
	glVertex2f(0.9, -0.1);
	glVertex2f(0.85, -0.1);
	glVertex2f(0.85, -0.15);
	glVertex2f(0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);      //4th building door
	glVertex2f(0.75, -0.25);
	glVertex2f(0.8, -0.25);
	glVertex2f(0.8, -0.18);
	glVertex2f(0.75, -0.18);
    glEnd();

    glPushMatrix();
	glTranslatef(car_position1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(240, 80, 22);      //left car body
	glVertex2f(-0.5, -0.48);
	glVertex2f(-0.2, -0.48);
	glVertex2f(-0.2, -0.46);
	glVertex2f(-0.26, -0.43);
	glVertex2f(-0.3, -0.39);
	glVertex2f(-0.4, -0.39);
	glVertex2f(-0.43, -0.43);
	glVertex2f(-0.5, -0.45);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //left car window
	glVertex2f(-0.42, -0.43);
	glVertex2f(-0.36, -0.43);
	glVertex2f(-0.36, -0.4);
	glVertex2f(-0.39, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //left car window
	glVertex2f(-0.34, -0.43);
	glVertex2f(-0.28, -0.43);
	glVertex2f(-0.31, -0.4);
	glVertex2f(-0.34, -0.4);
    glEnd();

    int a;                          //left car wheel1
    GLfloat x1=-0.41f; GLfloat y1=-0.48f; GLfloat radius1 =.03f;
	int triangleAmount1 = 20;
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x1, y1);
		for(a = 0; a <= triangleAmount1; a++) {
			glVertex2f(
                x1 + (radius1 * cos(a * twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(a * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	int b;                          //left car wheel2
    GLfloat x2=-0.27f; GLfloat y2=-0.48f; GLfloat radius2 =.03f;
	int triangleAmount2 = 20;
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x2, y2);
		for(b = 0; b <= triangleAmount2; b++) {
			glVertex2f(
                x2 + (radius2 * cos(b * twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(b * twicePi2 / triangleAmount2))
			);
		}
	glEnd();


    glPopMatrix();

	glPushMatrix();
	glTranslatef(car_position2, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
    glColor3ub(209, 31, 123);      //right car body
	glVertex2f(0.2, -0.65);
	glVertex2f(0.5, -0.65);
	glVertex2f(0.5, -0.62);
	glVertex2f(0.46, -0.61);
	glVertex2f(0.4, -0.56);
	glVertex2f(0.3, -0.56);
	glVertex2f(0.27, -0.6);
	glVertex2f(0.2, -0.63);
    glEnd();




    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //right car window
	glVertex2f(0.34, -0.6);
	glVertex2f(0.28, -0.6);
	glVertex2f(0.31, -0.57);
	glVertex2f(0.34, -0.57);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //right car window
	glVertex2f(0.42, -0.6);
	glVertex2f(0.36, -0.6);
	glVertex2f(0.36, -0.57);
	glVertex2f(0.39, -0.57);
    glEnd();

    int c;                          //right car wheel
    GLfloat x3=0.29f; GLfloat y3=-0.65f; GLfloat radius3 =.03f;
	int triangleAmount3 = 20;
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x3, y3);
		for(c = 0; c <= triangleAmount3; c++) {
			glVertex2f(
                x3 + (radius3 * cos(c * twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(c * twicePi3 / triangleAmount3))
			);
		}
	glEnd();

	int d;                          //right car wheel
    GLfloat x4=0.42f; GLfloat y4=-0.65f; GLfloat radius4 =.03f;
	int triangleAmount4 = 20;
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x4, y4);
		for(d = 0; d <= triangleAmount4; d++) {
			glVertex2f(
                x4 + (radius4 * cos(d * twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(d * twicePi4 / triangleAmount4))
			);
		}
	glEnd();
    glPopMatrix();


    glBegin(GL_QUADS);
    glColor3ub(148,0,211);              //top car
	glVertex2f(0.03, -0.35);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.1, -0.17);
	glVertex2f(0.03, -0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);              //top car
	glVertex2f(0.03, -0.37);
	glVertex2f(0.1, -0.37);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.03, -0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,139);              //top car window
	glVertex2f(0.04, -0.3);
	glVertex2f(0.09, -0.3);
	glVertex2f(0.085, -0.25);
	glVertex2f(0.045, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148,0,211);              //bottom car
	glVertex2f(-0.1, -0.9);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.03, -0.72);
	glVertex2f(-0.1, -0.72);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);              //bottom car
	glVertex2f(-0.1, -0.92);
	glVertex2f(-0.03, -0.92);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.1, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(211,211,211);              //bottom car window
	glVertex2f(-0.09, -0.8);
	glVertex2f(-0.04, -0.8);
	glVertex2f(-0.04, -0.77);
	glVertex2f(-0.09, -0.77);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom left signal
	glVertex2f(-0.2, -0.8);
	glVertex2f(-0.19, -0.8);
	glVertex2f(-0.19, -0.7);
	glVertex2f(-0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom left signal
	glVertex2f(-0.23, -0.7);
	glVertex2f(-0.16, -0.7);
	glVertex2f(-0.16, -0.54);
	glVertex2f(-0.23, -0.54);
    glEnd();

    GLfloat x26=-0.195f; GLfloat y26=-0.57f;GLfloat radius26 =.025f;          //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x26, y26);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x26 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y26 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x27=-0.195f; GLfloat y27=-0.62f;                                   //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x27, y27);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x27 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y27 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x28=-0.195f; GLfloat y28=-0.67f;                                  //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x28, y28);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x28 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y28 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom right signal
	glVertex2f(0.2, -0.8);
	glVertex2f(0.19, -0.8);
	glVertex2f(0.19, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom right signal
	glVertex2f(0.23, -0.7);
	glVertex2f(0.16, -0.7);
	glVertex2f(0.16, -0.54);
	glVertex2f(0.23, -0.54);
    glEnd();

    GLfloat x29=0.195f; GLfloat y29=-0.57f;GLfloat radius29 =.025f;          //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x29, y29);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x29 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y29 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x30=0.195f; GLfloat y30=-0.62f;                                   //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x30, y30);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x30 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y30 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x31=0.195f; GLfloat y31=-0.67f;                                  //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x31, y31);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x31 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y31 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top left signal
	glVertex2f(-0.2, -0.35);
	glVertex2f(-0.19, -0.35);
	glVertex2f(-0.19, -0.25);
	glVertex2f(-0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top left signal
	glVertex2f(-0.23, -0.25);
	glVertex2f(-0.16, -0.25);
	glVertex2f(-0.16, -0.09);
	glVertex2f(-0.23, -0.09);
    glEnd();

    GLfloat x32=-0.195f; GLfloat y32=-0.12f;GLfloat radius32=.025f;          //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x32, y32);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x32 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y32 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x33=-0.195f; GLfloat y33=-0.17f;                                   //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x33, y33);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x33 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y33 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x34=-0.195f; GLfloat y34=-0.22f;                                  //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x34, y34);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x34 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y34 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top right signal
	glVertex2f(0.2, -0.35);
	glVertex2f(0.19, -0.35);
	glVertex2f(0.19, -0.25);
	glVertex2f(0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top right signal
	glVertex2f(0.23, -0.25);
	glVertex2f(0.16, -0.25);
	glVertex2f(0.16, -0.09);
	glVertex2f(0.23, -0.09);
    glEnd();

    GLfloat x35=0.195f; GLfloat y35=-0.12f;GLfloat radius35=.025f;          //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x35, y35);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x35 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y35 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x36=0.195f; GLfloat y36=-0.17f;                                   //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x36, y36);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x36 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y36 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x37=0.195f; GLfloat y37=-0.22f;                                  //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x37, y37);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x37 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y37 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x14=-0.61f; GLfloat y14=-0.56f;GLfloat radius14 =.04f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x14, y14);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x14 + (radius14 * cos(e * twicePi5 / triangleAmount5)),
			    y14 + (radius14 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x15=-0.71f; GLfloat y15=-0.61f;GLfloat radius15 =.03f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x15, y15);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x15 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y15 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x16=-0.51f; GLfloat y16=-0.61f;                                  //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x16, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x16 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y16 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //bottom right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x17=0.61f; GLfloat y17=-0.56f;GLfloat radius17 =.04f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x17, y17);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x17 + (radius17 * cos(e * twicePi5 / triangleAmount5)),
			    y17 + (radius17 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x18=0.71f; GLfloat y18=-0.61f;GLfloat radius18 =.03f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x18, y18);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x18 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y18 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x19=0.51f; GLfloat y19=-0.61f;                                  //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x19, y19);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x19 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y19 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glScaled(0.6, 0.6, 0);
    glTranslated(0.35, 0.45, 0);
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x20=0.61f; GLfloat y20=-0.56f;GLfloat radius20 =.04f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x20, y20);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x20 + (radius20 * cos(e * twicePi5 / triangleAmount5)),
			    y20 + (radius20 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x21=0.71f; GLfloat y21=-0.61f;GLfloat radius21 =.03f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x21, y21);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x21 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y21 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x22=0.51f; GLfloat y22=-0.61f;                                  //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x22, y22);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x22 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y22 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glTranslated(-0.85, 0.0, 0);
	glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x23=-0.61f; GLfloat y23=-0.56f;GLfloat radius23 =.04f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x23, y23);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x23 + (radius23 * cos(e * twicePi5 / triangleAmount5)),
			    y23 + (radius23 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x24=-0.71f; GLfloat y24=-0.61f;GLfloat radius24 =.03f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x24, y24);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x24 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y24 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x25=-0.51f; GLfloat y25=-0.61f;                                  //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x25, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x25 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y25 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	glFlush();// Render now


}
void day(){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);// Clear the color buffer (background)
    glLoadIdentity();//Reset the current matrix

    glBegin(GL_QUADS);
    glColor3ub(179,230,255);      //sky
	glVertex2f(-1, 0.2);
	glVertex2f(1, 0.2);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(249, 215, 28);      //star
	glVertex2f(0.2, -0.65);
	glVertex2f(0.5, -0.65);
	glVertex2f(0.5, -0.62);
	glVertex2f(0.46, -0.61);
	glVertex2f(0.4, -0.56);
	glVertex2f(0.3, -0.56);
	glVertex2f(0.27, -0.6);
	glVertex2f(0.2, -0.63);
    glEnd();

    glLoadIdentity();
    glPushMatrix();
	glTranslatef(0.0f, sun_position, 0.0f);
    int i;                                      //sun
    GLfloat x=-0.5f; GLfloat y=1.13f; GLfloat radius =.13f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(249, 215, 28);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount; i++) {
			glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glPopMatrix();

    glLoadIdentity();
    glPushMatrix();
	glTranslatef(plane_position, 0.0f, 0.0f);
    glBegin(GL_QUADS);              //plane up wing
	glColor3ub(53, 143, 112);
	glVertex2f(-0.6, 0.65);
	glVertex2f(-0.5, 0.65);
	glVertex2f(-0.47, 0.75);
	glVertex2f(-0.5, 0.75);
	glEnd();

    glBegin(GL_POLYGON);            //plane body
	glColor3ub(0,0,0);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.73, 0.55);
	glVertex2f(-0.4, 0.55);
	glVertex2f(-0.4, 0.58);
	glVertex2f(-0.43, 0.63);
	glVertex2f(-0.5, 0.68);
	glVertex2f(-0.72, 0.68);
	glEnd();

    glBegin(GL_QUADS);              //plane tail
	glColor3ub(53, 143, 112);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.72, 0.68);
	glVertex2f(-0.79, 0.75);
	glVertex2f(-0.82, 0.75);
	glEnd();

    glBegin(GL_QUADS);              //plane down wing
	glColor3ub(53, 143, 112);
	glVertex2f(-0.75, 0.48);
	glVertex2f(-0.7, 0.48);
	glVertex2f(-0.5, 0.58);
	glVertex2f(-0.65, 0.58);
	glEnd();

    glBegin(GL_QUADS);              //plane front window
	glColor3ub(227, 227, 227);
	glVertex2f(-0.53, 0.63);
	glVertex2f(-0.43, 0.63);
	glVertex2f(-0.5, 0.68);
	glVertex2f(-0.53, 0.65);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.56, 0.63);
	glVertex2f(-0.58, 0.63);
	glVertex2f(-0.58, 0.66);
	glVertex2f(-0.56, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.56, 0.63);
	glVertex2f(-0.58, 0.63);
	glVertex2f(-0.58, 0.66);
	glVertex2f(-0.56, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.6, 0.63);
	glVertex2f(-0.62, 0.63);
	glVertex2f(-0.62, 0.66);
	glVertex2f(-0.6, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.64, 0.63);
	glVertex2f(-0.66, 0.63);
	glVertex2f(-0.66, 0.66);
	glVertex2f(-0.64, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.68, 0.63);
	glVertex2f(-0.7, 0.63);
	glVertex2f(-0.7, 0.66);
	glVertex2f(-0.68, 0.66);
    glEnd();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(bird_position, 0.0f, 0.0f);
    glBegin(GL_LINES);              //bird
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.35, 0.45);
    glBegin(GL_LINES);
    glVertex2f(-0.35, 0.45);
    glVertex2f(-0.3, 0.5);
    glEnd();

    glBegin(GL_LINES);              //bird
    glVertex2f(-0.25, 0.5);
    glVertex2f(-0.2, 0.45);
    glBegin(GL_LINES);
    glVertex2f(-0.2, 0.45);
    glVertex2f(-0.15, 0.5);
    glEnd();
    glPopMatrix();

    glLoadIdentity();
    glPushMatrix();
	glTranslatef(cloud_position, 0.0f, 0.0f);
    int e;                          //cloud
GLfloat x5=0.6f; GLfloat y5=0.85f; GLfloat radius5 =.06f;
	int triangleAmount5 = 20;
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,240);
		glVertex2f(x5, y5);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x5 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    GLfloat x6=0.66f; GLfloat y6=0.88f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,240);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x6 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y6 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x7=0.66f; GLfloat y7=0.83f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,240);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x7 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y7 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x8=0.73f; GLfloat y8=0.87f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,240);
		glVertex2f(x8, y8);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x8 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y8 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x9=0.72f; GLfloat y9=0.83f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,240);
		glVertex2f(x9, y9);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x9 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y9 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x10=-0.1f; GLfloat y10=0.88f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,240);
		glVertex2f(x10, y10);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x10 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y10 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x11=-0.05f; GLfloat y11=0.9f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,240);
		glVertex2f(x11, y11);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x11 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y11 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x12=-0.05f; GLfloat y12=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,240);
		glVertex2f(x12, y12);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x12 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y12 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x13=0.0f; GLfloat y13=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,240);
		glVertex2f(x13, y13);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x13 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y13 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();






    //cloud
glBegin(GL_QUADS);
    glColor3ub(255,250,240);
    glVertex2f(-0.7,0.76);
    glVertex2f(-0.5,0.76);
    glVertex2f(-0.5,0.74);
    glVertex2f(-0.7,0.74);
    glEnd();


glColor3ub(255,250,240);                 //cloud 1
    x=-0.68f; y=0.78f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



glColor3ub(255,250,240);                 //cloud 1
    x=-0.6f; y=0.78f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 1
    x=-0.52f; y=0.78f;  radius =.045f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255,250,240);                 //cloud 1
    x=-0.6f; y=0.81f;  radius =.056f;

    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();






	glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(0,100,0 );      //background
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0.2);
	glVertex2f(-1, 0.2);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //road
	glVertex2f(-1, -0.7);
	glVertex2f(1, -0.7);
	glVertex2f(1, -0.4);
	glVertex2f(-1, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //bottom road
	glVertex2f(-0.17, -1);
	glVertex2f(0.17, -1);
	glVertex2f(0.15, -0.7);
	glVertex2f(-0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //top road
	glVertex2f(-0.14, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(-0.1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-1.1, -0.55);
	glVertex2f(-1, -0.55);
	glVertex2f(-0.95, -0.53);
	glVertex2f(-1.05, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.9, -0.55);
	glVertex2f(-0.8, -0.55);
	glVertex2f(-0.75, -0.53);
	glVertex2f(-0.85, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.7, -0.55);
	glVertex2f(-0.6, -0.55);
	glVertex2f(-0.55, -0.53);
	glVertex2f(-0.65, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.5, -0.55);
	glVertex2f(-0.4, -0.55);
	glVertex2f(-0.35, -0.53);
	glVertex2f(-0.45, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.3, -0.55);
	glVertex2f(-0.2, -0.55);
	glVertex2f(-0.15, -0.53);
	glVertex2f(-0.25, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.15, -0.55);
	glVertex2f(0.25, -0.55);
	glVertex2f(0.3, -0.53);
	glVertex2f(0.2, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.35, -0.55);
	glVertex2f(0.45, -0.55);
	glVertex2f(0.5, -0.53);
	glVertex2f(0.4, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.55, -0.55);
	glVertex2f(0.65, -0.55);
	glVertex2f(0.7, -0.53);
	glVertex2f(0.6, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.75, -0.55);
	glVertex2f(0.85, -0.55);
	glVertex2f(0.9, -0.53);
	glVertex2f(0.8, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.95, -0.55);
	glVertex2f(1, -0.55);
	glVertex2f(1, -0.53);
	glVertex2f(1, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //bottom divider
	glVertex2f(-0.01, -0.8);
	glVertex2f(0.01, -0.8);
	glVertex2f(0.01, -0.7);
	glVertex2f(-0.01, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //bottom divider
	glVertex2f(-0.01, -0.9);
	glVertex2f(0.01, -0.9);
	glVertex2f(0.01, -1);
	glVertex2f(-0.01, -1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, -0.4);
	glVertex2f(0.01, -0.4);
	glVertex2f(0.01, -0.3);
	glVertex2f(-0.01, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, -0.2);
	glVertex2f(0.01, -0.2);
	glVertex2f(0.01, -0.1);
	glVertex2f(-0.01, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, 0.0);
	glVertex2f(0.01, 0.0);
	glVertex2f(0.01, 0.1);
	glVertex2f(-0.01, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom left footpath
	glVertex2f(-1, -0.8);
	glVertex2f(-0.25, -0.8);
	glVertex2f(-0.25, -0.7);
	glVertex2f(-1, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom left footpath
	glVertex2f(-0.28, -1);
	glVertex2f(-0.17, -1);
	glVertex2f(-0.15, -0.7);
	glVertex2f(-0.25, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom right footpath
	glVertex2f(0.2, -0.8);
	glVertex2f(1, -0.8);
	glVertex2f(1, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom right footpath
	glVertex2f(0.17, -1);
	glVertex2f(0.28, -1);
	glVertex2f(0.25, -0.7);
	glVertex2f(0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top left footpath
	glVertex2f(-1, -0.4);
	glVertex2f(-0.2, -0.4);
	glVertex2f(-0.2, -0.3);
	glVertex2f(-1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top left footpath
	glVertex2f(-0.24, -0.4);
	glVertex2f(-0.14, -0.4);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top right footpath
	glVertex2f(1, -0.4);
	glVertex2f(0.2, -0.4);
	glVertex2f(0.2, -0.3);
	glVertex2f(1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top right footpath
	glVertex2f(0.24, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.19, 0.2);
    glEnd();

    //tree

      glBegin(GL_QUADS);
   glColor3ub(102, 34, 0);

     glVertex2f(-.8f, -1.0f);
     glVertex2f(-.8f, -0.9f);// x, y
     glVertex2f(-.77f, -0.9f);
     glVertex2f(-.77f, -1.0f);// x, y

   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(60,179,113);

     glVertex2f(-0.84f, -0.91f);
     glVertex2f(-.785f, -.81f);// x, y
     glVertex2f(-.73f, -0.91f);


   glEnd();


   glBegin(GL_TRIANGLES);
   glColor3ub(60,179,113);

     glVertex2f(-0.84f, -0.95f);
     glVertex2f(-.785f, -.85f);// x, y
     glVertex2f(-.73f, -0.95f);


   glEnd();


      glBegin(GL_QUADS);
   glColor3ub(102, 34, 0);

     glVertex2f(.8f, -1.0f);
     glVertex2f(.8f, -0.9f);// x, y
     glVertex2f(.77f, -0.9f);
     glVertex2f(.77f, -1.0f);// x, y

   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(60,179,113);

     glVertex2f(0.84f, -0.91f);
     glVertex2f(.785f, -.81f);// x, y
     glVertex2f(.73f, -0.91f);


   glEnd();


   glBegin(GL_TRIANGLES);
   glColor3ub(60,179,113);

     glVertex2f(0.84f, -0.95f);
     glVertex2f(.785f, -.85f);// x, y
     glVertex2f(.73f, -0.95f);


   glEnd();



    glBegin(GL_QUADS);
    glColor3ub(255,69,0 );      //1st building front
	glVertex2f(-0.95, -0.25);
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.95, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,69,0 );      //1st building right
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.65, -0.2);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.7, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,160,122);      //1st building top
	glVertex2f(-0.95, 0.35);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.9, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.25);
	glVertex2f(-0.85, 0.25);
	glVertex2f(-0.85, 0.3);
	glVertex2f(-0.9, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.25);
	glVertex2f(-0.75, 0.25);
	glVertex2f(-0.75, 0.3);
	glVertex2f(-0.8, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.15);
	glVertex2f(-0.85, 0.15);
	glVertex2f(-0.85, 0.2);
	glVertex2f(-0.9, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.15);
	glVertex2f(-0.75, 0.15);
	glVertex2f(-0.75, 0.2);
	glVertex2f(-0.8, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.05);
	glVertex2f(-0.85, 0.05);
	glVertex2f(-0.85, 0.1);
	glVertex2f(-0.9, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.05);
	glVertex2f(-0.75, 0.05);
	glVertex2f(-0.75, 0.1);
	glVertex2f(-0.8, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.0);
	glVertex2f(-0.85, 0.0);
	glVertex2f(-0.85, -0.05);
	glVertex2f(-0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.0);
	glVertex2f(-0.75, 0.0);
	glVertex2f(-0.75, -0.05);
	glVertex2f(-0.8, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.85, -0.1);
	glVertex2f(-0.85, -0.15);
	glVertex2f(-0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, -0.15);
	glVertex2f(-0.75, -0.15);
	glVertex2f(-0.75, -0.1);
	glVertex2f(-0.8, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building door
	glVertex2f(-0.85, -0.25);
	glVertex2f(-0.8, -0.25);
	glVertex2f(-0.8, -0.18);
	glVertex2f(-0.85, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,128 );      //2nd building front
	glVertex2f(-0.63, -0.25);
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.63, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,128 );      //2nd building right
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.28, -0.2);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.33, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(72, 189, 224);      //2nd building top
	glVertex2f(-0.63, 0.15);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.58, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, -0.15);
	glVertex2f(-0.51, -0.15);
	glVertex2f(-0.51, -0.1);
	glVertex2f(-0.58, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, -0.15);
	glVertex2f(-0.38, -0.15);
	glVertex2f(-0.38, -0.1);
	glVertex2f(-0.45, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, 0.0);
	glVertex2f(-0.51, 0.0);
	glVertex2f(-0.51, -0.05);
	glVertex2f(-0.58, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, 0.0);
	glVertex2f(-0.38, 0.0);
	glVertex2f(-0.38, -0.05);
	glVertex2f(-0.45, -0.05);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, 0.05);
	glVertex2f(-0.51, 0.05);
	glVertex2f(-0.51, 0.1);
	glVertex2f(-0.58, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, 0.05);
	glVertex2f(-0.38, 0.05);
	glVertex2f(-0.38, 0.1);
	glVertex2f(-0.45, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building door
	glVertex2f(-0.51, -0.25);
	glVertex2f(-0.45, -0.25);
	glVertex2f(-0.45, -0.18);
	glVertex2f(-0.51, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(245,222,179 );      //3rd building
	glVertex2f(0.3, -0.25);
	glVertex2f(0.55, -0.25);
	glVertex2f(0.55, 0.4);
	glVertex2f(0.3, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.35, 0.3);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.4, 0.35);
	glVertex2f(0.35, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.45, 0.3);
	glVertex2f(0.5, 0.3);
	glVertex2f(0.5, 0.35);
	glVertex2f(0.45, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.35, 0.2);
	glVertex2f(0.4, 0.2);
	glVertex2f(0.4, 0.25);
	glVertex2f(0.35, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.45, 0.2);
	glVertex2f(0.5, 0.2);
	glVertex2f(0.5, 0.25);
	glVertex2f(0.45, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.35, 0.1);
	glVertex2f(0.4, 0.1);
	glVertex2f(0.4, 0.15);
	glVertex2f(0.35, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.45, 0.1);
	glVertex2f(0.5, 0.1);
	glVertex2f(0.5, 0.15);
	glVertex2f(0.45, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.35, 0.0);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.4, 0.05);
	glVertex2f(0.35, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.45, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, 0.05);
	glVertex2f(0.45, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.35, -0.1);
	glVertex2f(0.4, -0.1);
	glVertex2f(0.4, -0.05);
	glVertex2f(0.35, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.45, -0.1);
	glVertex2f(0.5, -0.1);
	glVertex2f(0.5, -0.05);
	glVertex2f(0.45, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.35, -0.2);
	glVertex2f(0.4, -0.2);
	glVertex2f(0.4, -0.15);
	glVertex2f(0.35, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building window
	glVertex2f(0.45, -0.2);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.5, -0.15);
	glVertex2f(0.45, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205 );      //3rd building door
	glVertex2f(0.45, -0.25);
	glVertex2f(0.4, -0.25);
	glVertex2f(0.4, -0.22);
	glVertex2f(0.45, -0.22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148,0,211);      //4th building
	glVertex2f(0.6, -0.25);
	glVertex2f(0.95, -0.25);
	glVertex2f(0.95, 0.25);
	glVertex2f(0.6, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.2);
	glVertex2f(0.7, 0.2);
	glVertex2f(0.7, 0.15);
	glVertex2f(0.65, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.2);
	glVertex2f(0.8, 0.2);
	glVertex2f(0.8, 0.15);
	glVertex2f(0.75, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.2);
	glVertex2f(0.85, 0.2);
	glVertex2f(0.85, 0.15);
	glVertex2f(0.9, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.1);
	glVertex2f(0.7, 0.1);
	glVertex2f(0.7, 0.05);
	glVertex2f(0.65, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.1);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.8, 0.05);
	glVertex2f(0.75, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.1);
	glVertex2f(0.85, 0.1);
	glVertex2f(0.85, 0.05);
	glVertex2f(0.9, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.0);
	glVertex2f(0.7, 0.0);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.65, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.0);
	glVertex2f(0.8, 0.0);
	glVertex2f(0.8, -0.05);
	glVertex2f(0.75, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.0);
	glVertex2f(0.85, 0.0);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, -0.1);
	glVertex2f(0.7, -0.1);
	glVertex2f(0.7, -0.15);
	glVertex2f(0.65, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, -0.1);
	glVertex2f(0.8, -0.1);
	glVertex2f(0.8, -0.15);
	glVertex2f(0.75, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, -0.1);
	glVertex2f(0.85, -0.1);
	glVertex2f(0.85, -0.15);
	glVertex2f(0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building door
	glVertex2f(0.75, -0.25);
	glVertex2f(0.8, -0.25);
	glVertex2f(0.8, -0.18);
	glVertex2f(0.75, -0.18);
    glEnd();

    glPushMatrix();
	glTranslatef(car_position1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(240, 80, 22);      //left car body
	glVertex2f(-0.5, -0.48);
	glVertex2f(-0.2, -0.48);
	glVertex2f(-0.2, -0.46);
	glVertex2f(-0.26, -0.43);
	glVertex2f(-0.3, -0.39);
	glVertex2f(-0.4, -0.39);
	glVertex2f(-0.43, -0.43);
	glVertex2f(-0.5, -0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //left car window
	glVertex2f(-0.42, -0.43);
	glVertex2f(-0.36, -0.43);
	glVertex2f(-0.36, -0.4);
	glVertex2f(-0.39, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //left car window
	glVertex2f(-0.34, -0.43);
	glVertex2f(-0.28, -0.43);
	glVertex2f(-0.31, -0.4);
	glVertex2f(-0.34, -0.4);
    glEnd();

    int a;                          //left car wheel1
    GLfloat x1=-0.41f; GLfloat y1=-0.48f; GLfloat radius1 =.03f;
	int triangleAmount1 = 20;
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x1, y1);
		for(a = 0; a <= triangleAmount1; a++) {
			glVertex2f(
                x1 + (radius1 * cos(a * twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(a * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	int b;                          //left car wheel2
    GLfloat x2=-0.27f; GLfloat y2=-0.48f; GLfloat radius2 =.03f;
	int triangleAmount2 = 20;
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x2, y2);
		for(b = 0; b <= triangleAmount2; b++) {
			glVertex2f(
                x2 + (radius2 * cos(b * twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(b * twicePi2 / triangleAmount2))
			);
		}
	glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(car_position2, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
    glColor3ub(209, 31, 123);      //right car body
	glVertex2f(0.2, -0.65);
	glVertex2f(0.5, -0.65);
	glVertex2f(0.5, -0.62);
	glVertex2f(0.46, -0.61);
	glVertex2f(0.4, -0.56);
	glVertex2f(0.3, -0.56);
	glVertex2f(0.27, -0.6);
	glVertex2f(0.2, -0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //right car window
	glVertex2f(0.34, -0.6);
	glVertex2f(0.28, -0.6);
	glVertex2f(0.31, -0.57);
	glVertex2f(0.34, -0.57);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //right car window
	glVertex2f(0.42, -0.6);
	glVertex2f(0.36, -0.6);
	glVertex2f(0.36, -0.57);
	glVertex2f(0.39, -0.57);
    glEnd();

    int c;                          //right car wheel
    GLfloat x3=0.29f; GLfloat y3=-0.65f; GLfloat radius3 =.03f;
	int triangleAmount3 = 20;
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x3, y3);
		for(c = 0; c <= triangleAmount3; c++) {
			glVertex2f(
                x3 + (radius3 * cos(c * twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(c * twicePi3 / triangleAmount3))
			);
		}
	glEnd();

	int d;                          //right car wheel
    GLfloat x4=0.42f; GLfloat y4=-0.65f; GLfloat radius4 =.03f;
	int triangleAmount4 = 20;
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x4, y4);
		for(d = 0; d <= triangleAmount4; d++) {
			glVertex2f(
                x4 + (radius4 * cos(d * twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(d * twicePi4 / triangleAmount4))
			);
		}
	glEnd();
    glPopMatrix();


    glBegin(GL_QUADS);
    glColor3ub(148,0,211);              //top car
	glVertex2f(0.03, -0.35);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.1, -0.17);
	glVertex2f(0.03, -0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);              //top car
	glVertex2f(0.03, -0.37);
	glVertex2f(0.1, -0.37);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.03, -0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,139);              //top car window
	glVertex2f(0.04, -0.3);
	glVertex2f(0.09, -0.3);
	glVertex2f(0.085, -0.25);
	glVertex2f(0.045, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148,0,211);              //bottom car
	glVertex2f(-0.1, -0.9);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.03, -0.72);
	glVertex2f(-0.1, -0.72);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);              //bottom car
	glVertex2f(-0.1, -0.92);
	glVertex2f(-0.03, -0.92);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.1, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(211,211,211);              //bottom car window
	glVertex2f(-0.09, -0.8);
	glVertex2f(-0.04, -0.8);
	glVertex2f(-0.04, -0.77);
	glVertex2f(-0.09, -0.77);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom left signal
	glVertex2f(-0.2, -0.8);
	glVertex2f(-0.19, -0.8);
	glVertex2f(-0.19, -0.7);
	glVertex2f(-0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //bottom left signal
	glVertex2f(-0.23, -0.7);
	glVertex2f(-0.16, -0.7);
	glVertex2f(-0.16, -0.54);
	glVertex2f(-0.23, -0.54);
    glEnd();

    GLfloat x26=-0.195f; GLfloat y26=-0.57f;GLfloat radius26 =.025f;          //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x26, y26);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x26 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y26 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x27=-0.195f; GLfloat y27=-0.62f;                                   //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x27, y27);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x27 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y27 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x28=-0.195f; GLfloat y28=-0.67f;                                  //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x28, y28);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x28 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y28 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom right signal
	glVertex2f(0.2, -0.8);
	glVertex2f(0.19, -0.8);
	glVertex2f(0.19, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //bottom right signal
	glVertex2f(0.23, -0.7);
	glVertex2f(0.16, -0.7);
	glVertex2f(0.16, -0.54);
	glVertex2f(0.23, -0.54);
    glEnd();

    GLfloat x29=0.195f; GLfloat y29=-0.57f;GLfloat radius29 =.025f;          //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x29, y29);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x29 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y29 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x30=0.195f; GLfloat y30=-0.62f;                                   //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x30, y30);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x30 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y30 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x31=0.195f; GLfloat y31=-0.67f;                                  //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x31, y31);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x31 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y31 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top left signal
	glVertex2f(-0.2, -0.35);
	glVertex2f(-0.19, -0.35);
	glVertex2f(-0.19, -0.25);
	glVertex2f(-0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //top left signal
	glVertex2f(-0.23, -0.25);
	glVertex2f(-0.16, -0.25);
	glVertex2f(-0.16, -0.09);
	glVertex2f(-0.23, -0.09);
    glEnd();

    GLfloat x32=-0.195f; GLfloat y32=-0.12f;GLfloat radius32=.025f;          //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x32, y32);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x32 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y32 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x33=-0.195f; GLfloat y33=-0.17f;                                   //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x33, y33);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x33 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y33 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x34=-0.195f; GLfloat y34=-0.22f;                                  //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x34, y34);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x34 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y34 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top right signal
	glVertex2f(0.2, -0.35);
	glVertex2f(0.19, -0.35);
	glVertex2f(0.19, -0.25);
	glVertex2f(0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //top right signal
	glVertex2f(0.23, -0.25);
	glVertex2f(0.16, -0.25);
	glVertex2f(0.16, -0.09);
	glVertex2f(0.23, -0.09);
    glEnd();

    GLfloat x35=0.195f; GLfloat y35=-0.12f;GLfloat radius35=.025f;          //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x35, y35);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x35 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y35 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x36=0.195f; GLfloat y36=-0.17f;                                   //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x36, y36);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x36 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y36 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x37=0.195f; GLfloat y37=-0.22f;                                  //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x37, y37);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x37 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y37 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x14=-0.61f; GLfloat y14=-0.56f;GLfloat radius14 =.04f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x14, y14);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x14 + (radius14 * cos(e * twicePi5 / triangleAmount5)),
			    y14 + (radius14 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x15=-0.71f; GLfloat y15=-0.61f;GLfloat radius15 =.03f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x15, y15);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x15 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y15 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x16=-0.51f; GLfloat y16=-0.61f;                                  //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x16, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x16 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y16 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x17=0.61f; GLfloat y17=-0.56f;GLfloat radius17 =.04f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x17, y17);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x17 + (radius17 * cos(e * twicePi5 / triangleAmount5)),
			    y17 + (radius17 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x18=0.71f; GLfloat y18=-0.61f;GLfloat radius18 =.03f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x18, y18);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x18 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y18 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x19=0.51f; GLfloat y19=-0.61f;                                  //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x19, y19);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x19 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y19 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glScaled(0.6, 0.6, 0);
    glTranslated(0.35, 0.45, 0);
    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x20=0.61f; GLfloat y20=-0.56f;GLfloat radius20 =.04f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x20, y20);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x20 + (radius20 * cos(e * twicePi5 / triangleAmount5)),
			    y20 + (radius20 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x21=0.71f; GLfloat y21=-0.61f;GLfloat radius21 =.03f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x21, y21);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x21 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y21 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x22=0.51f; GLfloat y22=-0.61f;                                  //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x22, y22);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x22 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y22 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glTranslated(-0.85, 0.0, 0);
	glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x23=-0.61f; GLfloat y23=-0.56f;GLfloat radius23 =.04f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x23, y23);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x23 + (radius23 * cos(e * twicePi5 / triangleAmount5)),
			    y23 + (radius23 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x24=-0.71f; GLfloat y24=-0.61f;GLfloat radius24 =.03f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x24, y24);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x24 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y24 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x25=-0.51f; GLfloat y25=-0.61f;                                  //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x25, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x25 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y25 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();



	glFlush();// Render now

}

void SpecialInput(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:

            plane_speed = 0.05f;
            speedbus = 0.05f;
            break;
        case GLUT_KEY_DOWN:

            plane_speed = 0.01f;
            speedbus = 0.01f;
            break;
        case GLUT_KEY_RIGHT:

            bird_speed = 0.04f;
            speedship = 0.0055f;
            break;
        case GLUT_KEY_LEFT:

            bird_speed = 0.01;
            speedship = 0.0005f;
            break;
    }
glutPostRedisplay();
}



void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

    case 'a':
    glutDisplayFunc(sunrise);
    glutPostRedisplay();

    break;

    case 's':
    glutDisplayFunc(beach_night);
    glutPostRedisplay();

    break;

     case 'd':
    glutDisplayFunc(beach_rain);
    glutPostRedisplay();

    break;

    case 'f':
     glutDisplayFunc(day);
     glutPostRedisplay();

    break;
    case 'g':
    glutDisplayFunc(night);
    glutPostRedisplay();

    break;

glutPostRedisplay();


	}


}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);

   glutCreateWindow("City And beach view");
    glutDisplayFunc(sunrise);
   glutKeyboardFunc(handleKeypress);

    glutTimerFunc(100, update_c1, 0);
    glutTimerFunc(100, update_c2, 0);
    glutTimerFunc(100, update_cld, 0);
    glutTimerFunc(100, update_ship, 0);
    glutTimerFunc(100, update_bus1, 0);
    glutTimerFunc(100, update_bus2, 0);
    glutTimerFunc(100, update4, 0);
    glutTimerFunc(100, update7, 0);
	glutTimerFunc(100, update8, 0);
	glutTimerFunc(100, update9, 0);
	glutTimerFunc(100, update10, 0);
	glutTimerFunc(100, update11, 0);
	glutTimerFunc(100, update12, 0);

 glutSpecialFunc(SpecialInput);
   glutMainLoop();
   return 0;
}
