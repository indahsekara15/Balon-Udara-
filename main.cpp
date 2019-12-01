#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>


float angle2=0.0;    // Variable sudut pada saat animasi
float red=1.0, blue=0.3, green=0.5;
float sudut=0.0;
float asd=0.0, fgh=0.0;
float _x=0,_y=0,_z=0;
float ert=0.0, yui=0.0;

//Variable untuk manipulasi sudut pandang
static float angle=0.0,ratio;            //Sudut perputaran kamera (terhadap sumbu y)
static float x=0.0f,y=10.75f,z=55.0f;      //Posisi Kamera
static float lx=0.0f,ly=0.0f,lz=-1.0f;   //Vektor sudut pandang


void garis_xy(){


     glPushMatrix();

glTranslated(_x,_y,_z);



     float i;

            glColor3f( 1.0, 1.0, 1.0);
  	        glBegin( GL_LINES);

            for (i=-20; i<20; i=i+1) {

                   glVertex3f( -20, i, 0);
                  glVertex3f( 20, i, 0);
                   glVertex3f( i,-20, 0);
                  glVertex3f( i,20, 0);
                  }


           glEnd();
            glPopMatrix();

          glutSwapBuffers();
           }

void awan(){
glPushMatrix();
    glColor3ub(153, 223, 255);
    glTranslatef(25,25,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(27,26,1);
    glutSolidSphere(2.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(29,25,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-25,27,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-23,28,1);
    glutSolidSphere(2.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-21,27,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-33,24.5,1);
    glutSolidSphere(0.75, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-32,25,1);
    glutSolidSphere(1.25, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-31,24.5,1);
    glutSolidSphere(0.75, 20, 20);
    glPopMatrix();
}

void burung(){

}

void alas(){
     //Menggambar Tanah
     glColor3f(0.2, 4.5, 2.2);
	glBegin(GL_POLYGON);
           glTexCoord2f(0.0f,0.0f);
           glVertex3f(-2000.0f,0.0f,2000.0f);
           glTexCoord2f(5.0f,0.0f);
           glVertex3f(2000.0f,0.0f,2000.0f);
           glTexCoord2f(5.0f,5.0f);
           glVertex3f(2000.0f,0.0f,-2000.0f);
           glTexCoord2f(0.0f,5.0f);
           glVertex3f(-2000.0f,0.0f,-2000.0f);

        glEnd();
     glPopMatrix();
     }

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
                   alas();
    glPopMatrix();

   //awan
    glPushMatrix();
    glColor3ub(153, 223, 255);
    glTranslatef(25,25,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(27,26,1);
    glutSolidSphere(2.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(29,25,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-25,27,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-23,28,1);
    glutSolidSphere(2.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-21,27,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-33,24.5,1);
    glutSolidSphere(0.75, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-32,25,1);
    glutSolidSphere(1.25, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-31,24.5,1);
    glutSolidSphere(0.75, 20, 20);
    glPopMatrix();

	//Menggambar Halaman
	glColor3f(0, 3, 0);
	glBegin(GL_QUADS);
		glVertex3f(-40.0, 0.1, -40.0);
		glVertex3f(-40.0, 0.1,  40.0);
		glVertex3f( 40.0, 0.1,  40.0);
		glVertex3f( 40.0, 0.1, -40.0);
	glEnd();


    glutSwapBuffers();
}


// Fungsi untuk menyesuaikan perspektif ketika window dirubah ukurannya
void changeSize(int w, int h) {

	// Menghindari pembagian oleh 0.
	if(h == 0)
		h = 1;

    // Rasio antara lebar dengan tinggi layar
	float ratio = 1.0* w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION); //Matrik diset : Matrik Proyeksi
	glLoadIdentity();            //Meload matrik identitas

	// Set the viewport to be the entire window (titik pusat ruang pandang)
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000); //Parameter perspektif (sudut di sumbu yz, rasio lebar/tinggi,
                                     //near clipping planes, far clipping plane)
	glMatrixMode(GL_MODELVIEW);      //Set matrix ke GL_MODELVIEW
	glLoadIdentity();                //Load identity matrix

    //gluLookAt
    gluLookAt(x     , y    , z,
              x + lx,y + ly,z + lz,
		      0.0f  ,1.0f  ,0.0f);

}

void orientMe(float ang) {

	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}

void moveMeFlat(int direction) {
	x = x + direction*(lx)*0.1;
	z = z + direction*(lz)*0.1;

	glLoadIdentity();
	gluLookAt(x, y, z,
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}


void inputKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.05f;
			orientMe(angle);break;
		case GLUT_KEY_RIGHT :
			angle +=0.05f;
			orientMe(angle);break;
		//case GLUT_KEY_UP :
		//	     moveMeFlat(5);break;
		//case GLUT_KEY_DOWN :
			//     moveMeFlat(-5);break;
	}
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


//Fungsi utama
int main(int argc, char **argv) {
     //argc -> a pointer to the unmodified argc variable from the main function
     //argv -> a pointer to the unmodified argv variable from the main function
     glutInit(&argc, argv);

     glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

     //Parameter posisi window (x,y)
     glutInitWindowPosition(100,100);

     //Parameter ukuran window (panjang,lebar)
	 glutInitWindowSize(640,360);

     //Membuat windows Latihan
	 glutCreateWindow("kelompok 9");

     glClearColor( 0.1, 0.5, 1, 0);
     //Fungsi utama untuk menampilkan objek
     glutDisplayFunc(renderScene);

     //Fungsi yang dijalankan dalam keadaan idle
     glutIdleFunc(renderScene);

     //Fungsi untuk mengatur perspektif.
     //Untuk mempertahankan ukuran objek saat jendela dirubah ukurannya
     glutReshapeFunc(changeSize);

     glutSpecialFunc(inputKey);

     //Mengaktifkan depth testing
     glEnable(GL_DEPTH_TEST);
    //Mengatur Pencahayaan
    glDepthFunc(GL_LESS);

   glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


     //Never ending loop, agar layar tidak langsung tertutup
 	 glutMainLoop();

}
