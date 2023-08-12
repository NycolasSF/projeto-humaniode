// Definir a macro _STDCALL_SUPPORTED

#include <GL/glut.h> // Incluir a biblioteca GLUT
#include <cstdio>

// Variáveis para controlar as articulações do robô
static int left_shoulder = 0, left_elbow = 0;
static int right_shoulder = 0, right_elbow = 0;
static int turn = 0; // Variável para controlar a rotação do robô

void init(){
    glClearColor(0.0,0.0,0.0,0.0); // Definir a cor de fundo para preto
    glShadeModel(GL_FLAT); // Definir o modo de shading para GL_FLAT
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT); // Limpar o buffer de cores
    glClearColor(0.0,0.0,0.0,0.0); // Definir a cor de fundo novamente para preto
    glColor3f(1.0,0.0,0.0); // Definir a cor do desenho para vermelho

    // Desenhar a parte superior esquerda do robô (braço esquerdo)
    glPushMatrix();
        glRotatef ((GLfloat) turn, 0.0, 1.0, 0.0); // Rotação do robô em torno do eixo y
        glTranslatef(0.5,1.7,0.0); // Translação para a posição do ombro esquerdo
        glRotatef((GLfloat) left_shoulder, 0.0,0.0,1.0); // Rotação do ombro esquerdo em torno do eixo z
        glTranslatef(0.5,0.0,0.0); // Translação para a posição do cotovelo esquerdo
        glPushMatrix();
            glScalef(1.3,0.4,1.0); // Ajustar o tamanho do cubo (parte superior do braço esquerdo)
            glutSolidCube(0.5); // Desenhar o cubo (parte superior do braço esquerdo)
        glPopMatrix();

        // Desenhar a parte inferior esquerda do robô (antebraço esquerdo)
        glTranslatef(0.3,0.0,0.0); // Translação para a posição do cotovelo esquerdo
        glRotatef((GLfloat) left_elbow, 0.0,0.0,1.0); // Rotação do cotovelo esquerdo em torno do eixo z
        glTranslatef(0.3,0.0,0.0); // Translação para a posição do punho esquerdo
        glPushMatrix();
            glScalef(1.0,0.4,1.0); // Ajustar o tamanho do cubo (antebraço esquerdo)
            glutSolidCube(0.5); // Desenhar o cubo (antebraço esquerdo)
        glPopMatrix();
    glPopMatrix();

    // Desenhar a parte superior direita do robô (braço direito)
    glPushMatrix();
        glRotatef ((GLfloat) turn, 0.0, 1.0, 0.0); // Rotação do robô em torno do eixo y
        glTranslatef(-0.5,1.7,0.0); // Translação para a posição do ombro direito
        glRotatef((GLfloat) right_shoulder, 0.0,0.0,1.0); // Rotação do ombro direito em torno do eixo z
        glTranslatef(-0.5,0.0,0.0); // Translação para a posição do cotovelo direito
        glPushMatrix();
            glScalef(1.3,0.4,1.0); // Ajustar o tamanho do cubo (parte superior do braço direito)
            glutSolidCube(0.5); // Desenhar o cubo (parte superior do braço direito)
        glPopMatrix();

        // Desenhar a parte inferior direita do robô (antebraço direito)
        glTranslatef(-0.3,0.0,0.0); // Translação para a posição do cotovelo direito
        glRotatef((GLfloat) right_elbow, 0.0,0.0,1.0); // Rotação do cotovelo direito em torno do eixo z
        glTranslatef(-0.3,0.0,0.0); // Translação para a posição do punho direito
        glPushMatrix();
            glScalef(1.0,0.4,1.0); // Ajustar o tamanho do cubo (antebraço direito)
            glutSolidCube(0.5); // Desenhar o cubo (antebraço direito)
        glPopMatrix();
    glPopMatrix();

    // Desenhar o tronco do robô
    glPushMatrix();
        glRotatef ((GLfloat) turn, 0.0, 1.0, 0.0); // Rotação do robô em torno do eixo y
        glTranslatef (0.0, 1.0,  0.0); // Translação para a posição do tronco
        glColor3f(0.0,0.5,1.0); // Definir a cor para azul claro
        glPushMatrix();
           glScalef (1.3, 2.0, 0.5); // Ajustar o tamanho do cubo (tronco)
           glutSolidCube(1.0); // Desenhar o cubo (tronco)
        glPopMatrix();

        // Desenhar a cabeça do robô
        glTranslatef (0.0, 1.25, 0.0); // Translação para a posição da cabeça
        glColor3f(1.0,0.6,0.2); // Definir a cor para laranja
        glPushMatrix();
            glScalef (0.5, 0.5, 0.5); // Ajustar o tamanho da esfera (cabeça)
            glutSolidSphere(0.8,50,10); // Desenhar a esfera (cabeça)
        glPopMatrix();
    glPopMatrix();

    // Desenhar a perna direita do robô
    glPushMatrix();
        glRotatef ((GLfloat) (turn+180), 0.0, 1.0, 0.0); // Rotação da perna direita em torno do eixo y
        glTranslatef (0.375,0.0, 0.0); // Translação para a posição da coxa direita
        glRotatef ((GLfloat) left_shoulder, 1.0, 0.0, 0.0); // Rotação da coxa direita em torno do eixo x
        glTranslatef (0.0, -0.5, 0.0); // Translação para a posição do joelho direito
        glColor3f(0.8,1.0,0.2); // Definir a cor para verde claro
        glPushMatrix();
            glScalef (0.5, 1.0, 0.5); // Ajustar o tamanho do cubo (coxa direita)
            glutSolidCube(1.0); // Desenhar o cubo (coxa direita)
        glPopMatrix();

        // Desenhar a parte inferior da perna direita
        glTranslatef (0.0, -0.5, 0.0); // Translação para a posição da perna direita
        glRotatef ((GLfloat) left_elbow, 1.0, 0.0, 0.0); // Rotação da perna direita em torno do eixo x
        glTranslatef (0.0, -0.5, 0.0); // Translação para a posição do tornozelo direito
        glColor3f(0.5,0.1,0.8); // Definir a cor para roxo
        glPushMatrix();
            glScalef (0.5, 1.0, 0.5); // Ajustar o tamanho do cubo (perna direita)
            glutSolidCube(1.0); // Desenhar o cubo (perna direita)
        glPopMatrix();

        // Desenhar o pé direito
        glTranslatef (0.0, -0.5, -0.1); // Translação para a posição do pé direito
        glColor3f(0.5,0.2,1.0); // Definir a cor para azul escuro
        glPushMatrix();
            glScalef (0.5, 0.1, 0.7); // Ajustar o tamanho do cubo (pé direito)
            glutSolidCube(1.0); // Desenhar o cubo (pé direito)
        glPopMatrix();
    glPopMatrix();

    // Desenhar a perna esquerda do robô
    glPushMatrix();
        glRotatef ((GLfloat) (turn+180), 0.0, 1.0, 0.0); // Rotação da perna esquerda em torno do eixo y
        glTranslatef (-0.375, 0.0, 0.0); // Translação para a posição da coxa esquerda
        glRotatef ((GLfloat) right_shoulder, 1.0, 0.0, 0.0); // Rotação da coxa esquerda em torno do eixo x
        glTranslatef (0.0, -0.5, 0.0); // Translação para a posição do joelho esquerdo
        glColor3f(0.8,1.0,0.2); // Definir a cor para verde claro
        glPushMatrix();
            glScalef (0.5, 1.0, 0.5); // Ajustar o tamanho do cubo (coxa esquerda)
            glutSolidCube(1.0); // Desenhar o cubo (coxa esquerda)
        glPopMatrix();

        // Desenhar a parte inferior da perna esquerda
        glTranslatef (0.0, -0.5, 0.0); // Translação para a posição da perna esquerda
        glRotatef ((GLfloat) right_elbow, 1.0, 0.0, 0.0); // Rotação da perna esquerda em torno do eixo x
        glTranslatef (0.0, -0.5, 0.0); // Translação para a posição do tornozelo esquerdo
        glColor3f(0.5,0.1,0.8); // Definir a cor para roxo
        glPushMatrix();
            glScalef (0.5, 1.0, 0.5); // Ajustar o tamanho do cubo (perna esquerda)
            glutSolidCube(1.0); // Desenhar o cubo (perna esquerda)
        glPopMatrix();

        // Desenhar o pé esquerdo
        glTranslatef (0.0, -0.5, -0.1); // Translação para a posição do pé esquerdo
        glColor3f(0.5,0.2,1.0); // Definir a cor para azul escuro
        glPushMatrix();
            glScalef (0.5, 0.1, 0.7); // Ajustar o tamanho do cubo (pé esquerdo)
            glutSolidCube(1.0); // Desenhar o cubo (pé esquerdo)
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers(); // Trocar os buffers para exibir o desenho
}

void reshape(int w, int h){
    glViewport(0,0,(GLsizei) w, (GLsizei) h); // Definir a viewport para a janela
    glMatrixMode(GL_PROJECTION); // Mudar para a matriz de projeção
    glLoadIdentity(); // Carregar a matriz de identidade
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0,20.0); // Definir a projeção perspectiva
    glMatrixMode(GL_MODELVIEW); // Mudar para a matriz de modelview
    glLoadIdentity(); // Carregar a matriz de identidade
    glTranslatef(0.0,0.0,-5.0); // Translação para afastar o objeto da câmera
}

void keyboard(unsigned char key, int x, int y){
    // Capturar as teclas pressionadas para controlar as articulações do robô
    switch (key){
    case ';':
        if(left_shoulder != 40)
            left_shoulder = (left_shoulder+5) % 360; // Incrementar o ângulo do ombro esquerdo
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 'k':
        if(left_shoulder != -40)
            left_shoulder = (left_shoulder-5) % 360; // Decrementar o ângulo do ombro esquerdo
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 'o':
        if(left_elbow != 40)
            left_elbow = (left_elbow+5) % 360; // Incrementar o ângulo do cotovelo esquerdo
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 'l':
        if(left_elbow != -40)
            left_elbow = (left_elbow-5) % 360; // Decrementar o ângulo do cotovelo esquerdo
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 'a':
        if(right_shoulder != 40)
            right_shoulder = (right_shoulder+5) % 360; // Incrementar o ângulo do ombro direito
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 'd':
        if(right_shoulder != -40)
            right_shoulder = (right_shoulder-5) % 360; // Decrementar o ângulo do ombro direito
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 'w':
        if(right_elbow != 40)
            right_elbow = (right_elbow+5) % 360; // Incrementar o ângulo do cotovelo direito
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 's':
        if(right_elbow != -40)
            right_elbow = (right_elbow-5) % 360; // Decrementar o ângulo do cotovelo direito
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 'r':
        turn = (turn+5) % 360; // Incrementar o ângulo de rotação do robô
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 't':
        turn = (turn-5) % 360; // Decrementar o ângulo de rotação do robô
        glutPostRedisplay(); // Atualizar a janela
        break;
    case 27: // ESQ --> fecha
        exit(1);
    case 'q': // q --> fecha
        exit(1);
    default:
        break;
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv); // Inicializar o GLUT
    glutInitDisplayMode(GL_DOUBLE | GLUT_RGB); // Definir o modo de exibição (duplo buffer e cores RGB)
    glutInitWindowSize(800,600); // Definir o tamanho da janela
    glutInitWindowPosition(100,80); // Definir a posição da janela na tela
    glutCreateWindow("robot"); // Criar a janela com o título "robot"
     init(); // Inicializar os parâmetros do OpenGL
    glutDisplayFunc(display); // Registrar a função de exibição
    glutReshapeFunc(reshape); // Registrar a função de redimensionamento da janela
    glutKeyboardFunc(keyboard); // Registrar a função de captura de teclas
    glutMainLoop(); // Iniciar o loop principal do GLUT
    return 0;
}
