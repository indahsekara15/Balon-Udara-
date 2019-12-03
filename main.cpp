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
double rotate_y = 0;
double rotate_x = 0;
int w=1024, h=720;
int skalaX=0, skalaY=0;

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
    //awan 1
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
    //awan 2
    glPushMatrix();
    glTranslatef(45,25.5,1);
    glutSolidSphere(0.75, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(46,26,1);
    glutSolidSphere(1.25, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(47,25.5,1);
    glutSolidSphere(0.75, 20, 20);
    glPopMatrix();
    //awan 3
    glPushMatrix();
    glTranslatef(50,27.5,1);
    glutSolidSphere(1.25, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(52,28.5,1);
    glutSolidSphere(2.20, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(54,27.5,1);
    glutSolidSphere(1.25, 20, 20);
    glPopMatrix();
    //awan 4
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
    //awan 5
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
    //awan 6
    glPushMatrix();
    glTranslatef(-65,27.5,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-62,28,1);
    glutSolidSphere(2.5, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-60,27,1);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();
}

void pohon(void){
    //batang
    GLUquadricObj *pObj;
    pObj =gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3ub(104,70,14);
    glRotatef(270,1,0,0);
    gluCylinder(pObj, 4, 0.7, 30, 25, 25);
    glPopMatrix();
}

void ranting(void){
    GLUquadricObj *pObj;
    pObj =gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glPushMatrix();
    glColor3ub(104,70,14);
    glTranslatef(0,27,0);
    glRotatef(330,1,0,0);
    gluCylinder(pObj, 0.6, 0.1, 15, 25, 25);
    glPopMatrix();

    //daun
    glPushMatrix();
    glColor3ub(18,118,13);
    glScaled(5, 5, 5);
    glTranslatef(0,7,3);
    glutSolidDodecahedron();
    glPopMatrix();
}

void balon(){
    glLoadIdentity();

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    gluLookAt(0.0,12.0,3.0,0.0,0.0,0.0,0.0,2.0,0.0);

    glTranslatef(0,_z,0);
    glRotatef(sudut,_x,_y,_z);

    //Balon
    glPushMatrix();
    glutSolidSphere(2.0,20,50);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f); //ring
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,2.9);
    glScalef(1,1,0.5);
    glutSolidTorus(0.19,0.20,20,50);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//kerucut
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,1);
    glutSolidCone(1.734,2,20,50);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red  list box
    glPopMatrix();

    //Kotak dibawah balon
    glPushMatrix();
    glTranslatef(0,0,3.2);
    glScalef(1,1,0.25);
    glutSolidTorus(0.19,0.20,20,50);
    glColor4f(1.0f,0.5f,0.0f,0.0f); // box
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,3.43);
    glScalef(1,1,0.6);
    glutSolidCube(0.6);
    glColor4f(0.0f,1.0f,1.0f,1.0f); //kotak
    glPopMatrix();
}

void alas(){
    //Menggambar Tanah
    glColor3f(0, 3, 0);
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

void reshape(int w, int h){
    glViewport(0, 0 , (GLsizei) w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
    balon();
    glPopMatrix();

	glPushMatrix();
    alas();
    glPopMatrix();

    //pohon 1
    glPushMatrix();
        glTranslatef(-15,4,5);
        glScalef(0.2, 0.2, 0.2);
        glRotatef(90,0,1,0);
        pohon();

        //ranting1
        ranting();

        //ranting2
        glPushMatrix();
        glScalef(1.5, 1.5, 1.5);
        glTranslatef(0,25,25);
        glRotatef(250,1,0,0);
        ranting();
        glPopMatrix();

        //ranting3
        glPushMatrix();
        glScalef(1.8, 1.8, 1.8);
        glTranslatef(0,-6,21.5);
        glRotatef(-55,1,0,0);
        ranting();
        glPopMatrix();
    glPopMatrix();

    //pohon 2
    glPushMatrix();
        glTranslatef(-21,4,5);
        glScalef(0.1, 0.1, 0.1);
        glRotatef(90,0,1,0);
        pohon();

        //ranting1
        ranting();

        //ranting2
        glPushMatrix();
        glScalef(1.5, 1.5, 1.5);
        glTranslatef(0,25,25);
        glRotatef(250,1,0,0);
        ranting();
        glPopMatrix();

        //ranting3
        glPushMatrix();
        glScalef(1.8, 1.8, 1.8);
        glTranslatef(0,-6,21.5);
        glRotatef(-55,1,0,0);
        ranting();
        glPopMatrix();
    glPopMatrix();

    //pohon 3
    glPushMatrix();
        glTranslatef(18,4,9);
        glScalef(0.15, 0.15, 0.15);
        glRotatef(90,0,1,0);
        pohon();

        //ranting1
        ranting();

        //ranting2
        glPushMatrix();
        glScalef(1.5, 1.5, 1.5);
        glTranslatef(0,25,25);
        glRotatef(250,1,0,0);
        ranting();
        glPopMatrix();

        //ranting3
        glPushMatrix();
        glScalef(1.8, 1.8, 1.8);
        glTranslatef(0,-6,21.5);
        glRotatef(-55,1,0,0);
        ranting();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    awan();
    glPopMatrix();

	//Menggambar Halaman
	glColor3f(0, 2.5, 0);
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

void keyboard (unsigned char key, int x, int y) {
    if (key == 'x')
    {
        _x=1;
        _y=0;
        _z=0;
        sudut+=10;
    }
    if (key == 'y')
    {
        _y=1;
        _x=0;
        _z=0;
        sudut+=10;
    }
    if (key == 'z')
    {
        _y=0;
        _x=0;
        _z=1;
        sudut+=10;
    }
}
void inputKey(int key, int x, int y) {
    	switch (key) {
		case GLUT_KEY_END :
			angle -= 0.05f;
			orientMe(angle);break;
		case GLUT_KEY_HOME :
			angle +=0.05f;
			orientMe(angle);break;
		case GLUT_KEY_PAGE_UP :
             moveMeFlat(5);break;
		case GLUT_KEY_PAGE_DOWN :
		     moveMeFlat(-5);break;
        case GLUT_KEY_UP:
            rotate_x += 5;break;
        case GLUT_KEY_DOWN:
            rotate_x -= 5;break;
        case GLUT_KEY_LEFT:
            rotate_y += 5;break;
        case GLUT_KEY_RIGHT:
            rotate_y -= 5;break;
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
    glutKeyboardFunc (keyboard);
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

