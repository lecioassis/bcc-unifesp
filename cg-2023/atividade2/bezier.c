#include <GL/glut.h>

GLfloat ctrlPoints1[4][3] = {
    {-4.0, -2.0, 0.0},
    {-2.0, 4.0, 0.0},
    {2.0, -4.0, 0.0},
    {4.0, 2.0, 0.0}
};

GLfloat ctrlPoints2[4][3] = {
    {-4.0, 2.0, 0.0},
    {-2.0, -4.0, 0.0},
    {2.0, 4.0, 0.0},
    {4.0, -2.0, 0.0}
};

GLfloat ctrlPoints3[4][3] = {
    {-4.0, 0.0, 2.0},
    {-2.0, 0.0, -2.0},
    {2.0, 0.0, 2.0},
    {4.0, 0.0, -2.0}
};

GLfloat angleX = 0.0;
GLfloat angleY = 0.0;
int currentCurve = 1;

void drawBezierCurve(GLfloat ctrlPoints[4][3]) {
    int i;
    float t;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);

    for (i = 0; i <= 100; i++) {
        t = i / 100.0;
        GLfloat x = ctrlPoints[0][0] * (1 - t) * (1 - t) * (1 - t) +
                    ctrlPoints[1][0] * 3 * t * (1 - t) * (1 - t) +
                    ctrlPoints[2][0] * 3 * t * t * (1 - t) +
                    ctrlPoints[3][0] * t * t * t;

        GLfloat y = ctrlPoints[0][1] * (1 - t) * (1 - t) * (1 - t) +
                    ctrlPoints[1][1] * 3 * t * (1 - t) * (1 - t) +
                    ctrlPoints[2][1] * 3 * t * t * (1 - t) +
                    ctrlPoints[3][1] * t * t * t;

        GLfloat z = ctrlPoints[0][2] * (1 - t) * (1 - t) * (1 - t) +
                    ctrlPoints[1][2] * 3 * t * (1 - t) * (1 - t) +
                    ctrlPoints[2][2] * 3 * t * t * (1 - t) +
                    ctrlPoints[3][2] * t * t * t;

        glVertex3f(x, y, z);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);

    switch (currentCurve) {
        case 1:
            drawBezierCurve(ctrlPoints1);
            break;
        case 2:
            drawBezierCurve(ctrlPoints2);
            break;
        case 3:
            drawBezierCurve(ctrlPoints3);
            break;
    }

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            angleX += 5.0;
            break;
        case GLUT_KEY_DOWN:
            angleX -= 5.0;
            break;
        case GLUT_KEY_LEFT:
            angleY -= 5.0;
            break;
        case GLUT_KEY_RIGHT:
            angleY += 5.0;
            break;
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            currentCurve = 1;
            break;
        case '2':
            currentCurve = 2;
            break;
        case '3':
            currentCurve = 3;
            break;
    }

    glutPostRedisplay();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Bezier Curve");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
