#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <cmath>

float angle = 2.4f;
float zoom = -6.0f;
float cameraAngleX = 0.0f, cameraAngleY = 0.0f;

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat lightPosition[] = { 2.0f, 5.0f, 5.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void House() {
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(1.0f, 0.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);

        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);

        glVertex3f(1.0f, 0.0f, -1.0f);
        glVertex3f(1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();
}

void Roof() {
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 1.5f, 0.0f);

        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(0.0f, 1.5f, 0.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 1.5f, 0.0f);
        glVertex3f(0.0f, 1.5f, 0.0f);

        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 1.5f, 0.0f);
        glVertex3f(0.0f, 1.5f, 0.0f);
    glEnd();
}

void Door() {
    glColor3f(0.8f, 0.2f, 0.2f);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 1.01f);
    glBegin(GL_QUADS);
        glVertex3f(-0.2f, 0.0f, 0.0f);
        glVertex3f(0.2f, 0.0f, 0.0f);
        glVertex3f(0.2f, 0.6f, 0.0f);
        glVertex3f(-0.2f, 0.6f, 0.0f);
    glEnd();
    glPopMatrix();
}

void Window(float xPos, float yPos, float zPos) {
    glColor3f(0.2f, 0.8f, 0.2f);
    glPushMatrix();
    glTranslatef(xPos, yPos, zPos);

    GLfloat windowEmissive[] = { 0.2f, 1.0f, 0.2f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, windowEmissive);

    glBegin(GL_QUADS);
        glVertex3f(-0.2f, 0.0f, 0.0f);
        glVertex3f(0.2f, 0.0f, 0.0f);
        glVertex3f(0.2f, 0.4f, 0.0f);
        glVertex3f(-0.2f, 0.4f, 0.0f);
    glEnd();

    GLfloat noEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, noEmission);

    glPopMatrix();
}

void WindowPos() {
    Window(-0.7f, 0.5f, 1.01f);
    Window(0.7f, 0.5f, 1.01f);
}

void Chimney() {
    glColor3f(0.5f, 0.0f, 0.5f);
    glBegin(GL_QUADS);
        glVertex3f(0.3f, 1.2f, 0.1f);
        glVertex3f(0.5f, 1.2f, 0.1f);
        glVertex3f(0.5f, 1.5f, 0.1f);
        glVertex3f(0.3f, 1.5f, 0.1f);

        glVertex3f(0.3f, 1.2f, -0.1f);
        glVertex3f(0.5f, 1.2f, -0.1f);
        glVertex3f(0.5f, 1.5f, -0.1f);
        glVertex3f(0.3f, 1.5f, -0.1f);

        glVertex3f(0.3f, 1.2f, -0.1f);
        glVertex3f(0.3f, 1.2f, 0.1f);
        glVertex3f(0.3f, 1.5f, 0.1f);
        glVertex3f(0.3f, 1.5f, -0.1f);

        glVertex3f(0.5f, 1.2f, -0.1f);
        glVertex3f(0.5f, 1.2f, 0.1f);
        glVertex3f(0.5f, 1.5f, 0.1f);
        glVertex3f(0.5f, 1.5f, -0.1f);
    glEnd();
}

void Ground() {
    glColor3f(0.5f, 0.35f, 0.05f);
    glBegin(GL_QUADS);
        glVertex3f(-5.0f, 0.0f, -5.0f);
        glVertex3f(5.0f, 0.0f, -5.0f);
        glVertex3f(5.0f, 0.0f, 5.0f);
        glVertex3f(-5.0f, 0.0f, 5.0f);
    glEnd();
}

void Tree(float x, float z) {
    glColor3f(0.6f, 0.3f, 0.0f);
    glPushMatrix();
    glTranslatef(x, 1.0f, z);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    GLUquadricObj *quad = gluNewQuadric();
    gluCylinder(quad, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glColor3f(0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(x, 1.5f, z);
    glutSolidSphere(0.6, 10, 10);
    glPopMatrix();
}

void Fence() {
    glColor3f(0.96f, 0.79f, 0.33f);
    for (float x = -2.5f; x <= 2.5f; x += 1.0f) {
        glPushMatrix();
        glTranslatef(x, 0.4f, -3.0f);
        GLUquadricObj *quad = gluNewQuadric();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quad, 0.05, 0.05, 0.5, 10, 10);
        glPopMatrix();
    }

    glColor3f(0.22f, 0.12f, 0.02f);
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, -3.0f);
    glScalef(5.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float cameraX = zoom * sin(angle + cameraAngleX);
    float cameraZ = zoom * cos(angle + cameraAngleX);

    gluLookAt(cameraX, 2.0f, cameraZ,
              0.0f, 0.7f, 0.0f,
              0.0f, 1.0f, 0.0f);

    Ground();
    House();
    Roof();
    Chimney();
    Door();
    WindowPos();
    Tree(-3.0f, -2.0f);
    Tree(2.0f, 3.0f);
    Fence();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void controls(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            zoom += 0.2f;
            break;
        case 's':
            zoom -= 0.2f;
            break;
        case 'a':
            cameraAngleX -= 0.1f;
            break;
        case 'd':
            cameraAngleX += 0.1f;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("house scene");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(controls);
    glutMainLoop();
    return 0;
}
