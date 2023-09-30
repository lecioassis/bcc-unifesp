#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float thetaX = 0.0;
float thetaY = 0.0;

void cubo() {
  //cube
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.24,0.24,0.25);
    glVertex3f(0.24,0.24,0.25);
    glVertex3f(0.24,-0.24,0.25);
    glVertex3f(-0.24,-0.24,0.25);
  glEnd();
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.24,0.24,-0.25);
    glVertex3f(0.24,0.24,-0.25);
    glVertex3f(0.24,-0.24,-0.25);
    glVertex3f(-0.24,-0.24,-0.25);
  glEnd();
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(0.25,-0.24,0.24);
    glVertex3f(0.25,0.24,0.24);
    glVertex3f(0.25,0.24,-0.24);
    glVertex3f(0.25,-0.24,-0.24);
  glEnd();
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.25,-0.24,0.24);
    glVertex3f(-0.25,0.24,0.24);
    glVertex3f(-0.25,0.24,-0.24);
    glVertex3f(-0.25,-0.24,-0.24);
  glEnd();
  glColor3f(1.0,0.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.24,0.25,0.24);
    glVertex3f(0.24,0.25,0.24);
    glVertex3f(0.24,0.25,-0.24);
    glVertex3f(-0.24,0.25,-0.24);
  glEnd();
  glColor3f(0.0,1.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.24,-0.25,0.24);
    glVertex3f(0.24,-0.25,0.24);
    glVertex3f(0.24,-0.25,-0.24);
    glVertex3f(-0.24,-0.25,-0.24);
  glEnd();
    
  //outline
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.25,0.25,0.24);
    glVertex3f(0.25,0.25,0.24);
    glVertex3f(0.25,-0.25,0.24);
    glVertex3f(-0.25,-0.25,0.24);
  glEnd();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.25,0.25,-0.24);
    glVertex3f(0.25,0.25,-0.24);
    glVertex3f(0.25,-0.25,-0.24);
    glVertex3f(-0.25,-0.25,-0.24);
  glEnd();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(0.24,-0.25,0.25);
    glVertex3f(0.24,0.25,0.25);
    glVertex3f(0.24,0.25,-0.25);
    glVertex3f(0.24,-0.25,-0.25);
  glEnd();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.24,-0.25,0.25);
    glVertex3f(-0.24,0.25,0.25);
    glVertex3f(-0.24,0.25,-0.25);
    glVertex3f(-0.24,-0.25,-0.25);
  glEnd();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.25,0.24,0.25);
    glVertex3f(0.25,0.24,0.25);
    glVertex3f(0.25,0.24,-0.25);
    glVertex3f(-0.25,0.24,-0.25);
  glEnd();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-0.25,-0.24,0.25);
    glVertex3f(0.25,-0.24,0.25);
    glVertex3f(0.25,-0.24,-0.25);
    glVertex3f(-0.25,-0.24,-0.25);
  glEnd();
}

void desenha() {
  glClearColor(0, 0, 0, 0); // Preto
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPushMatrix();
//Head 
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glScalef(1.0, 1.0, 1.0);
  glTranslatef(0.0,0.75,0.0);
  glScalef(0.5, 0.5, 0.5);
  cubo();
  glPopMatrix();

//Body
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glScalef(1.0, 2.0, 0.5);
  glTranslatef(0.0,0.25,0.0);
  glScalef(0.5, 0.5, 0.5);
  cubo();
  glPopMatrix();

//Left Arm
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glTranslatef(0.25,0.625-0.0625,0.0);
  glScalef(1.0, 0.5, 0.5);
  glScalef(0.5, 0.5, 0.5);
  cubo();
  glPopMatrix();
//Left Forearm
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glTranslatef(0.5,0.625-0.0625,0.0);
  glScalef(1.0, 0.5, 0.5);
  glScalef(0.5, 0.5, 0.5);
  cubo();
  glPopMatrix();
    
//Right Arm
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glTranslatef(-0.25,0.625-0.0625,0.0);
  glScalef(1.0, 0.5, 0.5);
  glScalef(0.5, 0.5, 0.5);
  cubo();
  glPopMatrix();
//Right Forearm
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glTranslatef(-0.5,0.625-0.0625,0.0);
  glScalef(1.0, 0.5, 0.5);
  glScalef(0.5, 0.5, 0.5);
  cubo();
  glPopMatrix();

//Left Leg
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glScalef(0.5, 1.0, 0.5);
  glTranslatef(0.25/2,0.25/2,0.0);
  glScalef(0.5, 0.5, 0.5);  
  cubo();
  glPopMatrix();
//Left Leg
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glScalef(0.5, 1.0, 0.5);
  glTranslatef(0.25/2,-0.25/2,0.0);
  glScalef(0.5, 0.5, 0.5);
  cubo();
  glPopMatrix();
    
//Right Leg
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glScalef(0.5, 1.0, 0.5);
  glTranslatef(-0.25/2,0.25/2,0.0);
  glScalef(0.5, 0.5, 0.5);
  cubo();
  glPopMatrix();
//Right Leg
  glPushMatrix();
  glRotatef(thetaX,1.0,0.0,0.0);
  glRotatef(thetaY,0.0,1.0,0.0);
  glScalef(0.5, 1.0, 0.5);
  glTranslatef(-0.25/2,-0.25/2,0.0);
  glScalef(0.5, 0.5, 0.5);
  cubo();
  glPopMatrix();

  glFlush();
}

void tecladoEspecial(int tecla, int x, int y) {
  switch (tecla) {
  case GLUT_KEY_RIGHT:
    thetaY += 2;
    break;
  case GLUT_KEY_LEFT:
    thetaY -= 2;
    break;
  case GLUT_KEY_UP:
    thetaX += 2;
    break;
  case GLUT_KEY_DOWN:
    thetaX -= 2;
    break;
  default:
    break;
  }
  glutPostRedisplay();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(400,400);
  glutCreateWindow("cubeman");
  glutDisplayFunc(desenha);
  // glutIdleFunc(anima); 
  // // Não consegui implementar a animacao a tempo
  glutSpecialFunc(tecladoEspecial);
  glutMainLoop();
  return 0;
}
