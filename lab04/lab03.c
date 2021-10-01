/*
 * template.c
 *
 * An OpenGL source code template.
 */


#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <stdio.h>
#include <math.h>
#include "/home/qirui/Desktop/lab3/src/mylib/initShader.h"
#include "/home/qirui/Desktop/lab3/src/mylib/linear_alg.h"


#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

vec4 vertices[360];
int num_vertices=360;
vec4 colors[360];
const float rad=(M_PI)/180;
void cone(){
    int v_index=0;
    for (float i = -180; i <= 180.0; i+=10.0)
    {
        /* code */
        float i1=i*rad;
        float i2=(i+10)*rad;
        vertices[v_index].x=0;
        vertices[v_index].y=0;
        vertices[v_index].z=0;
        vertices[v_index].w=1.0;
        v_index++;

        vertices[v_index].x=0.45*cos(i1);
        vertices[v_index].y=0;
        vertices[v_index].z=0.45*sin(i1);
        vertices[v_index].w=1.0;
        v_index++;

        vertices[v_index].x=0.45*cos(i2);
        vertices[v_index].y=0;
        vertices[v_index].z=0.45*sin(i2);
        vertices[v_index].w=1.0;
        v_index++;

        vertices[v_index].x=0;
        vertices[v_index].y=0.9;
        vertices[v_index].z=0;
        vertices[v_index].w=1.0;
        v_index++;

         vertices[v_index].x=0.45*cos(i1);
        vertices[v_index].y=0;
        vertices[v_index].z=0.45*sin(i1);
        vertices[v_index].w=1.0;
        v_index++;

        vertices[v_index].x=0.45*cos(i2);
        vertices[v_index].y=0;
        vertices[v_index].z=0.45*sin(i2);
        vertices[v_index].w=1.0;
        v_index++;
    }
    
}
void color(){
    for (int i = 0; i < 360; i+=3)
    {
        colors[i].x=colors[i+1].x=colors[i+2].x=rand()/(float)RAND_MAX;
        /* code */
        colors[i].y=colors[i+1].y=colors[i+2].y=rand()/(float)RAND_MAX;
        colors[i].z=colors[i+1].z=colors[i+2].z=rand()/(float)RAND_MAX;
        colors[i].w=1.0;
    }
    
}
void init(void)
{
    GLuint program = initShader("vshader.glsl", "fshader.glsl");
    glUseProgram(program);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    GLuint vColor = glGetAttribLocation(program, "vColor");
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *) sizeof(vertices));

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glDepthRange(1,0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, num_vertices);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int mousex, int mousey)
{
    if(key == 'q')
    	glutLeaveMainLoop();

    //glutPostRedisplay();
}

void reshape(int width, int height)
{
    glViewport(0, 0, 512, 512);
}

int main(int argc, char **argv)
{   
    cone();
    color();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Template");
    glewInit();
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
