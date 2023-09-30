#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

float posX = 0.0, posY = 0.0;

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5);
    glBegin(GL_POINTS);

        glColor3f(0.0, 0.0 , 1.0);
        glVertex2f(posX, posY);

    glEnd();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        posX = (2 * ((float) x / (float) glutGet(GLUT_WINDOW_WIDTH))) - 1;
        posY = 1 - (2 * ((float) y / (float) glutGet(GLUT_WINDOW_HEIGHT)));

    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {

    int init_width = 640, init_height = 480;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(init_width, init_height);

    glutCreateWindow("Exercicio 1");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
 }