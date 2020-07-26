#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define PHI 3.14

//deklarasi
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
void ukuran(int, int);

//LAPANGAN
void jaringkiri(void);
void jaringkanan(void);
void papansponsor(void);
void bangku1(void);
void bangku2(void);
void lapangan(void);
void bendera(void);
void bataslapangan(void);

//BANGUNAN
void alasBangunan();
void alasLengkung();
void luar();
void luarAtas();
void atapluar();
void atapJaring();
void PintuMasuk();
void huruf();
void tiangKiri();
void tiangKanan();
void tiangBelakang();
void dalam();
void dalamAtas();
void atapdalam();
void dinding();
void bawahBangunan();

//KURSI
void kurkur();

//LAMPU
void lampu();
void lampudpn();
void lampublkg();
void lampukanan();
void lampukiri();

//z mendekati positif, jauh negatif
int is_depth; //transparan

void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah)
{
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    for (int i=0;i<=jumlah_titik;i++){
        float sudut=i*(2 * PHI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
    glVertex3f(x,-49.3,y);
    }
    glEnd();
}

void setlingkaran1(int radius, int jumlah_titik, int x_tengah, int y_tengah)
{
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    for (int i=0;i<=jumlah_titik;i++){
        float sudut=i*(PHI/jumlah_titik);
        float x=x_tengah+radius*sin(sudut);
        float y=y_tengah+radius*cos(sudut);
    glVertex3f(x,-49.3,y);
    }
    glEnd();
}

void setlingkaran2(int radius, int jumlah_titik, int x_tengah, int y_tengah)
{
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    for (int i=0;i<=jumlah_titik;i++){
        float sudut=i*(PHI/jumlah_titik);
        float x=x_tengah-radius*sin(sudut);
        float y=y_tengah-radius*cos(sudut);
    glVertex3f(x,-49.3,y);
    }
    glEnd();
}

void init(void){
    glClearColor(0.1, 0.2, 0.1, 0.0);
    glMatrixMode(GL_PROJECTION);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(2.0);
    glLineWidth(3.0f);
}

void tampil(void){
    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);


    //BANGUNAN
    alasBangunan();
    alasLengkung();
    luar();
    luarAtas();
    atapluar();
    atapJaring();
    PintuMasuk();
    huruf();
    tiangKiri();
    tiangKanan();
    tiangBelakang();
    dalam();
    dalamAtas();
    atapdalam();
    dinding();
    bawahBangunan();

    //Lapangan
    lapangan();

    //tembok batas
    bataslapangan();

    //bendera
    bendera();

    //papan sponsor
    papansponsor();

    //jaring kiri
    jaringkiri();

    //jaring kanan
    jaringkanan();

    //bangku
    bangku1();
    bangku2();


    //KURSI PENONTON
    kurkur();

    //LAMPU
    lampu();



    glutSwapBuffers();
}


//BANGUNAN
void alasBangunan(){
    glBegin(GL_QUADS); //bawah
        glColor3ub(100, 100, 100);
        glVertex3f(-530, -55.0, 400.0);
        glVertex3f(390, -55.0, 400.0);
        glVertex3f(390, -55.0, -450.0);
        glVertex3f(-530, -55.0, -450.0);
    glEnd();

    glBegin(GL_QUADS); //atas
        glVertex3f(-530, -50.0, 400.0);
        glVertex3f(390, -50.0, 400.0);
        glVertex3f(390, -50.0, -450.0);
        glVertex3f(-530, -50.0, -450.0);
    glEnd();

    glBegin(GL_QUADS); //depan
        glVertex3f(-530, -55.0, 400.0);
        glVertex3f(-530, -50.0, 400.0);
        glVertex3f(390, -50.0, 400.0);
        glVertex3f(390, -55.0, 400.0);
    glEnd();

    glBegin(GL_QUADS); //belakang
        glVertex3f(-530, -55.0, -450.0);
        glVertex3f(-530, -50.0, -450.0);
        glVertex3f(390, -50.0, -450.0);
        glVertex3f(390, -55.0, -450.0);
    glEnd();

    glBegin(GL_QUADS); //kanan
        glVertex3f(390.0, -50.0, 400.0);
        glVertex3f(390.0, -55.0, 400.0);
        glVertex3f(390.0, -55.0, -450.0);
        glVertex3f(390.0, -50.0, -450.0);
    glEnd();

    glBegin(GL_QUADS); //kiri
        glVertex3f(-530, -50.0, 400.0);
        glVertex3f(-530, -55.0, 400.0);
        glVertex3f(-530, -55.0, -450.0);
        glVertex3f(-530, -50.0, -450.0);
    glEnd();
}

void alasLengkung(){
    //ALAS LENGKUNG ABU2 MUDA
    glLineWidth(6.0f);
    glBegin(GL_POLYGON);
    glColor3ub(150, 150, 150);
        glVertex3f(-400.0, -49.99, 230.7);
        glVertex3f(267.0, -49.99, 230.7);
        glVertex3f(270.0, -49.99, 230);
        glVertex3f(275.0, -49.99, 229);
        glVertex3f(280.0, -49.99, 228);
        glVertex3f(285.0, -49.99, 227);
        glVertex3f(290.0, -49.99, 226);
        glVertex3f(295.0, -49.99, 223);
        glVertex3f(300.0, -49.99, 220);
        glVertex3f(305.0, -49.99, 217);
        glVertex3f(310.0, -49.99, 213);
        glVertex3f(315.0, -49.99, 209);
        glVertex3f(320.0, -49.99, 204);
        glVertex3f(325.0, -49.99, 198);
        glVertex3f(330.0, -49.99, 189);
        glVertex3f(333.0, -49.99, 182);
        glVertex3f(335.0, -49.99, 177);
        glVertex3f(338.0, -49.99, 168);
        glVertex3f(340.0, -49.99, 157);

        glVertex3f(340.0, -49.99, -235);
        glVertex3f(339.0, -49.99, -250);
        glVertex3f(338.0, -49.99, -260);
        glVertex3f(337.0, -49.99, -270);
        glVertex3f(333.0, -49.99, -280);
        glVertex3f(330.0, -49.99, -290);
        glVertex3f(325.0, -49.99, -300);
        glVertex3f(320.0, -49.99, -310);
        glVertex3f(315.0, -49.99, -320);
        glVertex3f(305.0, -49.99, -335);
        glVertex3f(290.0, -49.99, -345);
        glVertex3f(270.0, -49.99, -355);
        glVertex3f(260.0, -49.99, -354.9);

        glVertex3f(-400, -49.99, -354.9);
        glVertex3f(-410, -49.99, -355);
        glVertex3f(-430, -49.99, -345);
        glVertex3f(-445, -49.99, -335);
        glVertex3f(-455, -49.99, -320);
        glVertex3f(-460, -49.99, -310);
        glVertex3f(-465, -49.99, -300);
        glVertex3f(-470, -49.99, -290);
        glVertex3f(-473, -49.99, -280);
        glVertex3f(-473, -49.99, 157);

        glVertex3f(-468, -49.99, 168);
        glVertex3f(-465, -49.99, 177);
        glVertex3f(-463, -49.99, 182);
        glVertex3f(-460, -49.99, 189);
        glVertex3f(-455, -49.99, 198);
        glVertex3f(-450, -49.99, 204);
        glVertex3f(-445, -49.99, 209);
        glVertex3f(-440, -49.99, 213);
        glVertex3f(-435, -49.99, 217);
        glVertex3f(-430, -49.99, 220);
        glVertex3f(-425, -49.99, 223);
        glVertex3f(-420, -49.99, 226);
        glVertex3f(-415, -49.99, 227);
        glVertex3f(-410, -49.99, 228);
        glVertex3f(-405, -49.99, 229);
        glVertex3f(-400, -49.99, 230);
    glEnd();
}

void luar(){
    //BANGUNAN LUAR
    glColor3ub(189, 189, 189);
    glBegin(GL_QUADS);
        glVertex3f(-400.0, 39.99, 230.7);
        glVertex3f(267.0, 39.99, 230.7);
        glVertex3f(267.0, 260, 230.7);
        glVertex3f(-400.0, 260, 230.7);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(267.0, 39.99, 230.7);
        glVertex3f(270.0, 39.99, 230);
        glVertex3f(270.0, 260, 230);
        glVertex3f(267.0, 260, 230.7);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(270.0, 39.99, 230);
        glVertex3f(275.0, 39.99, 229);
        glVertex3f(275.0, 260, 229);
        glVertex3f(270.0, 260, 230);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 39.99, 229);
        glVertex3f(280.0, 39.99, 228);
        glVertex3f(280.0, 260, 228);
        glVertex3f(275.0, 260, 229);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280.0, 39.99, 228);
        glVertex3f(285.0, 39.99, 227);
        glVertex3f(285.0, 260, 227);
        glVertex3f(280.0, 260, 228);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(285.0, 39.99, 227);
        glVertex3f(290.0, 39.99, 226);
        glVertex3f(290.0, 260, 226);
        glVertex3f(285.0, 260, 227);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 39.99, 226);
        glVertex3f(295.0, 39.99, 223);
        glVertex3f(295.0, 260, 223);
        glVertex3f(290.0, 260, 226);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(295.0, 39.99, 223);
        glVertex3f(300.0, 39.99, 220);
        glVertex3f(300.0, 260, 220);
        glVertex3f(295.0, 260, 223);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300.0, 39.99, 220);
        glVertex3f(305.0, 39.99, 217);
        glVertex3f(305.0, 260, 217);
        glVertex3f(300.0, 260, 220);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 39.99, 217);
        glVertex3f(310.0, 39.99, 213);
        glVertex3f(310.0, 260, 213);
        glVertex3f(305.0, 260, 217);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310.0, 39.99, 213);
        glVertex3f(315.0, 39.99, 209);
        glVertex3f(315.0, 260, 209);
        glVertex3f(310.0, 260, 213);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 39.99, 209);
        glVertex3f(320.0, 39.99, 204);
        glVertex3f(320.0, 260, 204);
        glVertex3f(315.0, 260, 209);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 39.99, 204);
        glVertex3f(325.0, 39.99, 198);
        glVertex3f(325.0, 260, 198);
        glVertex3f(320.0, 260, 204);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.0, 39.99, 198);
        glVertex3f(330.0, 39.99, 189);
        glVertex3f(330.0, 260, 189);
        glVertex3f(325.0, 260, 198);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330.0, 39.99, 189);
        glVertex3f(333.0, 39.99, 182);
        glVertex3f(333.0, 260, 182);
        glVertex3f(330.0, 260, 189);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(333.0, 39.99, 182);
        glVertex3f(335.0, 39.99, 177);
        glVertex3f(335.0, 260, 177);
        glVertex3f(333.0, 260, 182);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(335.0, 39.99, 177);
        glVertex3f(338.0, 39.99, 168);
        glVertex3f(338.0, 260, 168);
        glVertex3f(335.0, 260, 177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(338.0, 39.99, 168);
        glVertex3f(340.5, 39.99, 97);
        glVertex3f(340.5, 260, 97);
        glVertex3f(338.0, 260, 168);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(340.5, 39.99, 97);
        glVertex3f(340.5, 39.99, -235);
        glVertex3f(340.5, 260, -235);
        glVertex3f(340.5, 260, 97);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(340.5, 39.99, -235);
        glVertex3f(339.0, 39.99, -250);
        glVertex3f(339.0, 260, -250);
        glVertex3f(340.5, 260, -235);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(339.0, 39.99, -250);
        glVertex3f(338.0, 39.99, -260);
        glVertex3f(338.0, 260, -260);
        glVertex3f(339.0, 260, -250);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(338.0, 39.99, -260);
        glVertex3f(337.0, 39.99, -270);
        glVertex3f(337.0, 260, -270);
        glVertex3f(338.0, 260, -260);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(337.0, 39.99, -270);
        glVertex3f(333.0, 39.99, -280);
        glVertex3f(333.0, 260, -280);
        glVertex3f(337.0, 260, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(333.0, 39.99, -280);
        glVertex3f(330.0, 39.99, -290);
        glVertex3f(330.0, 260, -290);
        glVertex3f(333.0, 260, -280);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330.0, 39.99, -290);
        glVertex3f(325.0, 39.99, -300);
        glVertex3f(325.0, 260, -300);
        glVertex3f(330.0, 260, -290);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.0, 39.99, -300);
        glVertex3f(320.0, 39.99, -310);
        glVertex3f(320.0, 260, -310);
        glVertex3f(325.0, 260, -300);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 39.99, -310);
        glVertex3f(315.0, 39.99, -320);
        glVertex3f(315.0, 260, -320);
        glVertex3f(320.0, 260, -310);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 39.99, -320);
        glVertex3f(305.0, 39.99, -335);
        glVertex3f(305.0, 260, -335);
        glVertex3f(315.0, 260, -320);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 39.99, -335);
        glVertex3f(290.0, 39.99, -345);
        glVertex3f(290.0, 260, -345);
        glVertex3f(305.0, 260, -335);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 39.99, -345);
        glVertex3f(250.0, 39.99, -355);
        glVertex3f(250.0, 260, -355);
        glVertex3f(290.0, 260, -345);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(250.0, 39.99, -355);
        glVertex3f(240.0, 39.99, -354.9);
        glVertex3f(240.0, 260, -354.9);
        glVertex3f(250.0, 260, -355);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(240.0, 39.99, -354.9);
        glVertex3f(-330, 39.99, -354.9);
        glVertex3f(-330, 260, -354.9);
        glVertex3f(240.0, 260, -354.9);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-330, 39.99, -354.9);
        glVertex3f(-410, 39.99, -355);
        glVertex3f(-410, 260, -355);
        glVertex3f(-330, 260, -354.9);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-410, 39.99, -355);
        glVertex3f(-430, 39.99, -345);
        glVertex3f(-430, 260, -345);
        glVertex3f(-410, 260, -355);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 39.99, -345);
        glVertex3f(-445, 39.99, -335);
        glVertex3f(-445, 260, -335);
        glVertex3f(-430, 260, -345);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 39.99, -335);
        glVertex3f(-455, 39.99, -320);
        glVertex3f(-455, 260, -320);
        glVertex3f(-445, 260, -335);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-455, 39.99, -320);
        glVertex3f(-460, 39.99, -310);
        glVertex3f(-460, 260, -310);
        glVertex3f(-455, 260, -320);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 39.99, -310);
        glVertex3f(-465, 39.99, -300);
        glVertex3f(-465, 260, -300);
        glVertex3f(-460, 260, -310);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-465, 39.99, -300);
        glVertex3f(-470.5, 39.99, -290);
        glVertex3f(-470.5, 260, -290);
        glVertex3f(-465, 260, -300);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-470.5, 39.99, -290);
        glVertex3f(-473, 39.99, -280);
        glVertex3f(-473, 260, -280);
        glVertex3f(-470.5, 260, -290);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-473, 39.99, -280);
        glVertex3f(-473, 39.99, 97);
        glVertex3f(-473, 260, 97);
        glVertex3f(-473, 260, -280);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-473, 39.99, 97);
        glVertex3f(-468, 39.99, 168);
        glVertex3f(-468, 260, 168);
        glVertex3f(-473, 260, 97);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-468, 39.99, 168);
        glVertex3f(-465, 39.99, 177);
        glVertex3f(-465, 260, 177);
        glVertex3f(-468, 260, 168);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-465, 39.99, 177);
        glVertex3f(-463, 39.99, 182);
        glVertex3f(-463, 260, 182);
        glVertex3f(-465, 260, 177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-463, 39.99, 182);
        glVertex3f(-460, 39.99, 189);
        glVertex3f(-460, 260, 189);
        glVertex3f(-463, 260, 182);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 39.99, 189);
        glVertex3f(-455, 39.99, 198);
        glVertex3f(-455, 260, 198);
        glVertex3f(-460, 260, 189);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-455, 39.99, 198);
        glVertex3f(-450, 39.99, 204);
        glVertex3f(-450, 260, 204);
        glVertex3f(-455, 260, 198);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-450, 39.99, 204);
        glVertex3f(-445, 39.99, 209);
        glVertex3f(-445, 260, 209);
        glVertex3f(-450, 260, 204);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 39.99, 209);
        glVertex3f(-440, 39.99, 213);
        glVertex3f(-440, 260, 213);
        glVertex3f(-445, 260, 209);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 39.99, 213);
        glVertex3f(-435, 39.99, 217);
        glVertex3f(-435, 260, 217);
        glVertex3f(-440, 260, 213);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 39.99, 217);
        glVertex3f(-430, 39.99, 220);
        glVertex3f(-430, 260, 220);
        glVertex3f(-435, 260, 217);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 39.99, 220);
        glVertex3f(-425, 39.99, 223);
        glVertex3f(-425, 260, 223);
        glVertex3f(-430, 260, 220);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-425, 39.99, 223);
        glVertex3f(-420, 39.99, 226);
        glVertex3f(-420, 260, 226);
        glVertex3f(-425, 260, 223);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-420, 39.99, 226);
        glVertex3f(-415, 39.99, 227);
        glVertex3f(-415, 260, 227);
        glVertex3f(-420, 260, 226);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 39.99, 227);
        glVertex3f(-410, 39.99, 228);
        glVertex3f(-410, 260, 228);
        glVertex3f(-415, 260, 227);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-410, 39.99, 228);
        glVertex3f(-405, 39.99, 229);
        glVertex3f(-405, 260, 229);
        glVertex3f(-410, 260, 228);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-405, 39.99, 229);
        glVertex3f(-400, 39.99, 230.7);
        glVertex3f(-400, 260, 230.7);
        glVertex3f(-405, 260, 229);
    glEnd();

}

void luarAtas(){
    glColor3ub(192, 192, 192);

    glBegin(GL_QUADS);
        glVertex3f(267.0, 260, 230.7);
        glVertex3f(-400.0, 260, 230.7);
        glVertex3f(-390.0, 275, 207.5);
        glVertex3f(257.0, 275, 207.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(270.0, 260, 230);
        glVertex3f(267.0, 260, 230.7);
        glVertex3f(257.0, 275, 207.5);
        glVertex3f(260.0, 275, 207);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 260, 229);
        glVertex3f(270.0, 260, 230);
        glVertex3f(257.0, 275, 207.5);
        glVertex3f(260.0, 275, 207);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 260, 229);
        glVertex3f(270.0, 260, 230);
        glVertex3f(260.0, 275, 207);
        glVertex3f(265.0, 275, 206);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 260, 229);
        glVertex3f(270.0, 260, 230);
        glVertex3f(265.0, 275, 206);
        glVertex3f(270.0, 275, 205);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 260, 229);
        glVertex3f(270.0, 260, 230);
        glVertex3f(270.0, 275, 205);
        glVertex3f(275.0, 275, 204);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280.0, 260, 228);
        glVertex3f(275.0, 260, 229);
        glVertex3f(275.0, 275, 204);
        glVertex3f(280.0, 275, 203);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(285.0, 260, 227);
        glVertex3f(280.0, 260, 228);
        glVertex3f(280.0, 275, 203);
        glVertex3f(285.0, 275, 200);
    glEnd();


    glBegin(GL_QUADS);
        glVertex3f(290.0, 260, 226);
        glVertex3f(285.0, 260, 227);
        glVertex3f(285.0, 275, 200);
        glVertex3f(290.0, 275, 195);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(295.0, 260, 223);
        glVertex3f(290.0, 260, 226);
        glVertex3f(290.0, 275, 195);
        glVertex3f(295.0, 275, 190);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300.0, 260, 220);
        glVertex3f(295.0, 260, 223);
        glVertex3f(295.0, 275, 190);
        glVertex3f(300.0, 275, 183);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 260, 217);
        glVertex3f(300.0, 260, 220);
        glVertex3f(300.0, 275, 183);
        glVertex3f(305.0, 275, 175);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310.0, 260, 213);
        glVertex3f(305.0, 260, 217);
        glVertex3f(305.0, 275, 175);
        glVertex3f(310.0, 275, 166);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 260, 209);
        glVertex3f(310.0, 260, 213);
        glVertex3f(310.0, 275, 166);
        glVertex3f(315.0, 275, 154);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 260, 204);
        glVertex3f(315.0, 260, 209);
        glVertex3f(315.0, 275, 154);
        glVertex3f(316.5, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.0, 260, 198);
        glVertex3f(320.0, 260, 204);
        glVertex3f(315.5, 275, 90);
        glVertex3f(316.5, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330.0, 260, 189);
        glVertex3f(325.0, 260, 198);
        glVertex3f(315.5, 275, 90);
        glVertex3f(316.5, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(333.0, 260, 182);
        glVertex3f(330.0, 260, 189);
        glVertex3f(315.5, 275, 90);
        glVertex3f(316.5, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(335.0, 260, 177);
        glVertex3f(333.0, 260, 182);
        glVertex3f(316.5, 275, 125);
        glVertex3f(315.5, 275, 90);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(338.0, 260, 168);
        glVertex3f(335.0, 260, 177);
        glVertex3f(316.5, 275, 125);
        glVertex3f(315.5, 275, 90);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(340.5, 260, 97);
        glVertex3f(338.0, 260, 168);
        glVertex3f(316.5, 275, 125);
        glVertex3f(315.5, 275, 90);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(340.5, 260, -235);
        glVertex3f(340.5, 260, 97);
        glVertex3f(315.5, 275, 90);
        glVertex3f(315.5, 275, -215);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(339.0, 260, -250);
        glVertex3f(340.5, 260, -235);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(338.0, 260, -260);
        glVertex3f(339.0, 260, -250);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(337.0, 260, -270);
        glVertex3f(338.0, 260, -260);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(333.0, 260, -280);
        glVertex3f(337.0, 260, -270);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330.0, 260, -290);
        glVertex3f(333.0, 260, -280);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.0, 260, -300);
        glVertex3f(330.0, 260, -290);
        glVertex3f(314, 275, -240);
        glVertex3f(312, 275, -250);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 260, -310);
        glVertex3f(325.0, 260, -300);
        glVertex3f(312, 275, -250);
        glVertex3f(310, 275, -260);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 260, -320);
        glVertex3f(320.0, 260, -310);
        glVertex3f(310, 275, -260);
        glVertex3f(308, 275, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 260, -335);
        glVertex3f(315.0, 260, -320);
        glVertex3f(308, 275, -270);
        glVertex3f(280, 275, -305);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 260, -345);
        glVertex3f(305.0, 260, -335);
        glVertex3f(280, 275, -305);
        glVertex3f(269, 275, -310);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(250.0, 260, -355);
        glVertex3f(290.0, 260, -345);
        glVertex3f(269, 275, -310);
        glVertex3f(240, 275, -319);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(240.0, 260, -354.9);
        glVertex3f(250.0, 260, -355);
        glVertex3f(240, 275, -319);
        glVertex3f(235, 275, -320.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-330, 260, -354.9);
        glVertex3f(240.0, 260, -354.9);
        glVertex3f(235, 275, -320.5);
        glVertex3f(-395, 275, -320.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-410, 260, -355);
        glVertex3f(-330, 260, -354.9);
        glVertex3f(-395, 275, -320.5);
        glVertex3f(-405, 275, -318);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 260, -345);
        glVertex3f(-410, 260, -355);
        glVertex3f(-405, 275, -318);
        glVertex3f(-415, 275, -315);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 260, -335);
        glVertex3f(-430, 260, -345);
        glVertex3f(-415, 275, -315);
        glVertex3f(-425, 275, -310);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-455, 260, -320);
        glVertex3f(-445, 260, -335);
        glVertex3f(-425, 275, -310);
        glVertex3f(-435, 275, -300);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 260, -310);
        glVertex3f(-455, 260, -320);
        glVertex3f(-435, 275, -300);
        glVertex3f(-440, 275, -295);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-465, 260, -300);
        glVertex3f(-460, 260, -310);
        glVertex3f(-440, 275, -295);
        glVertex3f(-445, 275, -280);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-470.5, 260, -290);
        glVertex3f(-465, 260, -300);
        glVertex3f(-445, 275, -280);
        glVertex3f(-446, 275, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-473, 260, -280);
        glVertex3f(-470.5, 260, -290);
        glVertex3f(-446, 275, -270);
        glVertex3f(-447, 275, -265);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-473, 260, 97);
        glVertex3f(-473, 260, -280);
        glVertex3f(-447, 275, -265);
        glVertex3f(-444, 275, 155);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-468, 260, 168);
        glVertex3f(-473, 260, 97);
        glVertex3f(-444, 275, 155);
        glVertex3f(-442, 275, 162);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-465, 260, 177);
        glVertex3f(-468, 260, 168);
        glVertex3f(-444, 275, 155);
        glVertex3f(-442, 275, 162);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-463, 260, 182);
        glVertex3f(-465, 260, 177);
        glVertex3f(-444, 275, 155);
        glVertex3f(-442, 275, 162);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 260, 189);
        glVertex3f(-463, 260, 182);
        glVertex3f(-442, 275, 162);
        glVertex3f(-440, 275, 167);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-455, 260, 198);
        glVertex3f(-460, 260, 189);
        glVertex3f(-442, 275, 162);
        glVertex3f(-440, 275, 167);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-450, 260, 204);
        glVertex3f(-455, 260, 198);
        glVertex3f(-440, 275, 167);
        glVertex3f(-435, 275, 177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 260, 209);
        glVertex3f(-450, 260, 204);
        glVertex3f(-440, 275, 167);
        glVertex3f(-435, 275, 177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 260, 213);
        glVertex3f(-445, 260, 209);
        glVertex3f(-440, 275, 167);
        glVertex3f(-435, 275, 177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 260, 217);
        glVertex3f(-440, 260, 213);
        glVertex3f(-440, 275, 167);
        glVertex3f(-435, 275, 177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 260, 220);
        glVertex3f(-435, 260, 217);
        glVertex3f(-435, 275, 177);
        glVertex3f(-430, 275, 185);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-425, 260, 223);
        glVertex3f(-430, 260, 220);
        glVertex3f(-430, 275, 185);
        glVertex3f(-418, 275, 195);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-420, 260, 226);
        glVertex3f(-425, 260, 223);
        glVertex3f(-430, 275, 185);
        glVertex3f(-418, 275, 195);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 260, 227);
        glVertex3f(-420, 260, 226);
        glVertex3f(-418, 275, 195);
        glVertex3f(-405, 275, 203);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-410, 260, 228);
        glVertex3f(-415, 260, 227);
        glVertex3f(-405, 275, 203);
        glVertex3f(-390, 275, 207.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-405, 260, 229);
        glVertex3f(-410, 260, 228);
        glVertex3f(-405, 275, 203);
        glVertex3f(-390, 275, 207.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-400, 260, 230.7);
        glVertex3f(-405, 260, 229);
        glVertex3f(-405, 275, 203);
        glVertex3f(-390, 275, 207.5);
    glEnd();

//glBegin(GL_LINE_STRIP);
//        glVertex3f(-390.0, 315, 207.5);
//        glVertex3f(257.0, 315, 207.5);
//        glVertex3f(260.0, 315, 207);
//        glVertex3f(265.0, 315, 206);
//        glVertex3f(270.0, 315, 205);
//        glVertex3f(275.0, 315, 204);
//        glVertex3f(280.0, 315, 203);
//        glVertex3f(285.0, 315, 200);
//        glVertex3f(290.0, 315, 195);
//        glVertex3f(295.0, 315, 190);
//        glVertex3f(300.0, 315, 183);
//        glVertex3f(305.0, 315, 175);
//        glVertex3f(310.0, 315, 166);
//        glVertex3f(315.0, 315, 154);
//        glVertex3f(316.5, 315, 125);
//        glVertex3f(315.5, 315, 90);
//
//        glVertex3f(315.5, 315, -215);
//        glVertex3f(314, 315, -240);
//        glVertex3f(312, 315, -250);
//        glVertex3f(310, 315, -260);
//        glVertex3f(308, 315, -270);
//        glVertex3f(300, 315, -290);
//        glVertex3f(290, 315, -300);
//        glVertex3f(280, 315, -305);
//        glVertex3f(269, 315, -310);
//        glVertex3f(240, 315, -319);
//        glVertex3f(235, 315, -320.5);
//
//        glVertex3f(-395, 315, -320.5);
//        glVertex3f(-405, 315, -318);
//        glVertex3f(-415, 315, -315);
//        glVertex3f(-425, 315, -310);
//        glVertex3f(-435, 315, -300);
//        glVertex3f(-440, 315, -295);
//        glVertex3f(-445, 315, -280);
//        glVertex3f(-446, 315, -270);
//        glVertex3f(-447, 315, -265);
//
//        glVertex3f(-444, 315, 155);
//        glVertex3f(-442, 315, 162);
//        glVertex3f(-440, 315, 167);
//        glVertex3f(-435, 315, 177);
//        glVertex3f(-430, 315, 185);
//        glVertex3f(-418, 315, 195);
//        glVertex3f(-405, 315, 203);
//        glVertex3f(-390, 315, 207.5);
//    glEnd();
}

void atapluar(){
    glLineWidth(4.0f);
    glColor3ub(210, 210, 210);

    glBegin(GL_QUADS);
        glVertex3f(-390.0, 275, 207.5);
        glVertex3f(257.0, 275, 207.5);
        glVertex3f(197.0, 275, 160.5);
        glVertex3f(-330.0, 275, 160.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(257.0, 275, 207.5);
        glVertex3f(260.0, 275, 207);
        glVertex3f(200.0, 275, 160);
        glVertex3f(197.0, 275, 160.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(257.0, 275, 207.5);
        glVertex3f(260.0, 275, 207);
        glVertex3f(200.0, 275, 160);
        glVertex3f(197.0, 275, 160.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(260.0, 275, 207);
        glVertex3f(265.0, 275, 206);
        glVertex3f(200.0, 275, 160);
        glVertex3f(197.0, 275, 160.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(265.0, 275, 206);
        glVertex3f(270.0, 275, 205);
        glVertex3f(205.0, 275, 159);
        glVertex3f(200.0, 275, 160);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(270.0, 275, 205);
        glVertex3f(275.0, 275, 204);
        glVertex3f(210.0, 275, 158);
        glVertex3f(205.0, 275, 159);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 275, 204);
        glVertex3f(280.0, 275, 203);
        glVertex3f(210.0, 275, 158);
        glVertex3f(205.0, 275, 159);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280.0, 275, 203);
        glVertex3f(285.0, 275, 200);
        glVertex3f(210.0, 275, 158);
        glVertex3f(205.0, 275, 159);
    glEnd();


    glBegin(GL_QUADS);
        glVertex3f(285.0, 275, 200);
        glVertex3f(290.0, 275, 195);
        glVertex3f(215.0, 275, 157);
        glVertex3f(210.0, 275, 158);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 275, 195);
        glVertex3f(295.0, 275, 190);
        glVertex3f(220.0, 275, 156);
        glVertex3f(215.0, 275, 157);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(295.0, 275, 190);
        glVertex3f(300.0, 275, 183);
        glVertex3f(230.0, 275, 149);
        glVertex3f(220.0, 275, 156);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300.0, 275, 183);
        glVertex3f(305.0, 275, 175);
        glVertex3f(238.0, 275, 140);
        glVertex3f(230.0, 275, 149);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 275, 175);
        glVertex3f(310.0, 275, 166);
        glVertex3f(242.0, 275, 132);
        glVertex3f(238.0, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310.0, 275, 166);
        glVertex3f(315.0, 275, 154);
        glVertex3f(242.0, 275, 132);
        glVertex3f(238.0, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 275, 154);
        glVertex3f(316.5, 275, 125);
        glVertex3f(242.0, 275, 132);
        glVertex3f(238.0, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(316.5, 275, 125);
        glVertex3f(315.5, 275, 90);
        glVertex3f(245.0, 275, 125);
        glVertex3f(242.0, 275, 132);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(316.5, 275, 125);
        glVertex3f(315.5, 275, 90);
        glVertex3f(245.0, 275, 125);
        glVertex3f(242.0, 275, 132);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(316.5, 275, 125);
        glVertex3f(315.5, 275, 90);
        glVertex3f(248.0, 275, 120);
        glVertex3f(245.0, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(316.5, 275, 125);
        glVertex3f(315.5, 275, 90);
        glVertex3f(250.0, 275, 106);
        glVertex3f(248.0, 275, 120);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.5, 275, 90);
        glVertex3f(315.5, 275, -215);
        glVertex3f(250.0, 275, -177);
        glVertex3f(250.0, 275, 106);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
        glVertex3f(248, 275, -200);
        glVertex3f(250.0, 275, -177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
        glVertex3f(248, 275, -200);
        glVertex3f(250.0, 275, -177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
        glVertex3f(248, 275, -200);
        glVertex3f(250.0, 275, -177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
        glVertex3f(240, 275, -230);
        glVertex3f(248, 275, -200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.5, 275, -215);
        glVertex3f(314, 275, -240);
        glVertex3f(240, 275, -230);
        glVertex3f(248, 275, -200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(314, 275, -240);
        glVertex3f(312, 275, -250);
        glVertex3f(230, 275, -250);
        glVertex3f(240, 275, -230);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(312, 275, -250);
        glVertex3f(310, 275, -260);
        glVertex3f(230, 275, -250);
        glVertex3f(240, 275, -230);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310, 275, -260);
        glVertex3f(308, 275, -270);
        glVertex3f(220, 275, -260);
        glVertex3f(230, 275, -250);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(308, 275, -270);
        glVertex3f(280, 275, -305);
        glVertex3f(220, 275, -260);
        glVertex3f(230, 275, -250);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280, 275, -305);
        glVertex3f(269, 275, -310);
        glVertex3f(210, 275, -265);
        glVertex3f(220, 275, -260);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(269, 275, -310);
        glVertex3f(240, 275, -319);
        glVertex3f(180, 275, -270);
        glVertex3f(210, 275, -265);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(240, 275, -319);
        glVertex3f(235, 275, -320.5);
        glVertex3f(180, 275, -270);
        glVertex3f(210, 275, -265);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(235, 275, -320.5);
        glVertex3f(-395, 275, -320.5);
        glVertex3f(-335, 275, -270);
        glVertex3f(180, 275, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-395, 275, -320.5);
        glVertex3f(-405, 275, -318);
        glVertex3f(-345, 275, -268);
        glVertex3f(-335, 275, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-405, 275, -318);
        glVertex3f(-415, 275, -315);
        glVertex3f(-355, 275, -265);
        glVertex3f(-345, 275, -268);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 275, -315);
        glVertex3f(-425, 275, -310);
        glVertex3f(-365, 275, -262);
        glVertex3f(-355, 275, -265);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-425, 275, -310);
        glVertex3f(-435, 275, -300);
        glVertex3f(-365, 275, -262);
        glVertex3f(-355, 275, -265);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 275, -300);
        glVertex3f(-440, 275, -295);
        glVertex3f(-375, 275, -252);
        glVertex3f(-365, 275, -262);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 275, -295);
        glVertex3f(-445, 275, -280);
        glVertex3f(-377, 275, -245);
        glVertex3f(-375, 275, -252);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 275, -280);
        glVertex3f(-446, 275, -270);
        glVertex3f(-377, 275, -245);
        glVertex3f(-375, 275, -252);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-446, 275, -270);
        glVertex3f(-447, 275, -265);
        glVertex3f(-380, 275, -222);
        glVertex3f(-377, 275, -245);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-447, 275, -265);
        glVertex3f(-444, 275, 155);
        glVertex3f(-380, 275, 115);
        glVertex3f(-380, 275, -222);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-444, 275, 155);
        glVertex3f(-442, 275, 162);
        glVertex3f(-378, 275, 125);
        glVertex3f(-380, 275, 115);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-444, 275, 155);
        glVertex3f(-442, 275, 162);
        glVertex3f(-378, 275, 125);
        glVertex3f(-380, 275, 115);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-444, 275, 155);
        glVertex3f(-442, 275, 162);
        glVertex3f(-374, 275, 132);
        glVertex3f(-378, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-442, 275, 162);
        glVertex3f(-440, 275, 167);
        glVertex3f(-374, 275, 132);
        glVertex3f(-378, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-442, 275, 162);
        glVertex3f(-440, 275, 167);
        glVertex3f(-370, 275, 140);
        glVertex3f(-374, 275, 132);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 275, 167);
        glVertex3f(-435, 275, 177);
        glVertex3f(-370, 275, 140);
        glVertex3f(-374, 275, 132);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 275, 167);
        glVertex3f(-435, 275, 177);
        glVertex3f(-370, 275, 140);
        glVertex3f(-374, 275, 132);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 275, 167);
        glVertex3f(-435, 275, 177);
        glVertex3f(-360, 275, 150);
        glVertex3f(-370, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 275, 167);
        glVertex3f(-435, 275, 177);
        glVertex3f(-360, 275, 150);
        glVertex3f(-370, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 275, 177);
        glVertex3f(-430, 275, 185);
        glVertex3f(-360, 275, 150);
        glVertex3f(-370, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 275, 185);
        glVertex3f(-418, 275, 195);
        glVertex3f(-360, 275, 150);
        glVertex3f(-370, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 275, 185);
        glVertex3f(-418, 275, 195);
        glVertex3f(-345, 275, 160);
        glVertex3f(-360, 275, 150);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-418, 275, 195);
        glVertex3f(-405, 275, 203);
        glVertex3f(-345, 275, 160);
        glVertex3f(-360, 275, 150);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-405, 275, 203);
        glVertex3f(-390, 275, 207.5);
        glVertex3f(-345, 275, 160);
        glVertex3f(-360, 275, 150);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-405, 275, 203);
        glVertex3f(-390, 275, 207.5);
        glVertex3f(-330.0, 275, 160.5);
        glVertex3f(-345, 275, 160);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-405, 275, 203);
        glVertex3f(-390, 275, 207.5);
        glVertex3f(-330.0, 275, 160.5);
        glVertex3f(-345, 275, 160);
    glEnd();


//    glBegin(GL_LINE_STRIP);
//        glVertex3f(-330.0, 315, 160.5);
//        glVertex3f(197.0, 315, 160.5);
//        glVertex3f(200.0, 315, 160);
//        glVertex3f(205.0, 315, 159);
//        glVertex3f(210.0, 315, 158);
//        glVertex3f(215.0, 315, 157);
//        glVertex3f(220.0, 315, 156);
//        glVertex3f(230.0, 315, 149);
//        glVertex3f(238.0, 315, 140);
//        glVertex3f(242.0, 315, 132);
//        glVertex3f(245.0, 315, 125);
//        glVertex3f(248.0, 315, 120);
//        glVertex3f(250.0, 315, 106);
//
//        glVertex3f(250.0, 315, -177);
//        glVertex3f(248, 315, -200);
//        glVertex3f(240, 315, -230);
//        glVertex3f(230, 315, -250);
//        glVertex3f(220, 315, -260);
//        glVertex3f(210, 315, -265);
//        glVertex3f(180, 315, -270);
//
//        glVertex3f(-335, 315, -270);
//        glVertex3f(-345, 315, -268);
//        glVertex3f(-355, 315, -265);
//        glVertex3f(-365, 315, -262);
//        glVertex3f(-375, 315, -252);
//        glVertex3f(-377, 315, -245);
//        glVertex3f(-380, 315, -222);
//
//        glVertex3f(-380, 315, 115);
//        glVertex3f(-378, 315, 125);
//        glVertex3f(-374, 315, 132);
//        glVertex3f(-370, 315, 140);
//        glVertex3f(-360, 315, 150);
//        glVertex3f(-345, 315, 160);
//        glVertex3f(-330.0, 315, 160.5);
//    glEnd();
}

void atapJaring(){
    glLineWidth(2.0f);

    //JARING 1
    glColor3ub(255, 20, 20);
    glBegin(GL_LINE_STRIP);
        glVertex3f(-320.0, 275, 150.5);
        glVertex3f(187.0, 275, 150.5);
        glVertex3f(190.0, 275, 150);
        glVertex3f(195.0, 275, 149);
        glVertex3f(200.0, 275, 148);
        glVertex3f(205.0, 275, 147);
        glVertex3f(210.0, 275, 146);
        glVertex3f(220.0, 275, 139);
        glVertex3f(228.0, 275, 130);
        glVertex3f(232.0, 275, 122);
        glVertex3f(235.0, 275, 115);
        glVertex3f(238.0, 275, 110);
        glVertex3f(240.0, 275, 96);

        glVertex3f(240.0, 275, -167);
        glVertex3f(238, 275, -190);
        glVertex3f(230, 275, -220);
        glVertex3f(220, 275, -240);
        glVertex3f(210, 275, -250);
        glVertex3f(200, 275, -255);
        glVertex3f(170, 275, -260);

        glVertex3f(-325, 275, -260);
        glVertex3f(-335, 275, -258);
        glVertex3f(-345, 275, -255);
        glVertex3f(-355, 275, -252);
        glVertex3f(-365, 275, -242);
        glVertex3f(-367, 275, -235);
        glVertex3f(-370, 275, -212);

        glVertex3f(-370, 275, 105);
        glVertex3f(-368, 275, 115);
        glVertex3f(-364, 275, 122);
        glVertex3f(-360, 275, 130);
        glVertex3f(-350, 275, 140);
        glVertex3f(-335, 275, 150);
        glVertex3f(-320.0, 275, 150.5);
    glEnd();

    //JARING 2
    glBegin(GL_LINE_STRIP);
        glVertex3f(-310.0, 275, 140.5);
        glVertex3f(177.0, 275, 140.5);
        glVertex3f(180.0, 275, 140);
        glVertex3f(185.0, 275, 139);
        glVertex3f(190.0, 275, 138);
        glVertex3f(195.0, 275, 137);
        glVertex3f(200.0, 275, 136);
        glVertex3f(210.0, 275, 129);
        glVertex3f(218.0, 275, 120);
        glVertex3f(222.0, 275, 112);
        glVertex3f(225.0, 275, 105);
        glVertex3f(228.0, 275, 100);
        glVertex3f(230.0, 275, 86);

        glVertex3f(230.0, 275, -157);
        glVertex3f(228, 275, -180);
        glVertex3f(220, 275, -210);
        glVertex3f(210, 275, -230);
        glVertex3f(200, 275, -240);
        glVertex3f(190, 275, -245);
        glVertex3f(160, 275, -250);

        glVertex3f(-315, 275, -250);
        glVertex3f(-325, 275, -248);
        glVertex3f(-335, 275, -245);
        glVertex3f(-345, 275, -242);
        glVertex3f(-355, 275, -232);
        glVertex3f(-357, 275, -225);
        glVertex3f(-360, 275, -202);

        glVertex3f(-360, 275, 95);
        glVertex3f(-358, 275, 105);
        glVertex3f(-354, 275, 112);
        glVertex3f(-350, 275, 120);
        glVertex3f(-340, 275, 130);
        glVertex3f(-325, 275, 140);
        glVertex3f(-310.0, 275, 140.5);
    glEnd();

    //JARING 3
    glBegin(GL_LINE_STRIP);
        glVertex3f(-300.0, 275, 130.5);
        glVertex3f(167.0, 275, 130.5);
        glVertex3f(170.0, 275, 130);
        glVertex3f(175.0, 275, 129);
        glVertex3f(180.0, 275, 128);
        glVertex3f(185.0, 275, 127);
        glVertex3f(190.0, 275, 126);
        glVertex3f(200.0, 275, 119);
        glVertex3f(208.0, 275, 110);
        glVertex3f(212.0, 275, 102);
        glVertex3f(215.0, 275, 95);
        glVertex3f(218.0, 275, 90);
        glVertex3f(220.0, 275, 76);

        glVertex3f(220.0, 275, -147);
        glVertex3f(218, 275, -170);
        glVertex3f(210, 275, -200);
        glVertex3f(200, 275, -220);
        glVertex3f(190, 275, -230);
        glVertex3f(180, 275, -235);
        glVertex3f(150, 275, -240);

        glVertex3f(-305, 275, -240);
        glVertex3f(-315, 275, -238);
        glVertex3f(-325, 275, -235);
        glVertex3f(-335, 275, -232);
        glVertex3f(-345, 275, -222);
        glVertex3f(-347, 275, -215);
        glVertex3f(-350, 275, -192);

        glVertex3f(-350, 275, 85);
        glVertex3f(-348, 275, 95);
        glVertex3f(-344, 275, 102);
        glVertex3f(-340, 275, 110);
        glVertex3f(-330, 275, 120);
        glVertex3f(-315, 275, 130);
        glVertex3f(-300.0, 275, 130.5);
    glEnd();

    //JARING PENDEK KIRI
    glBegin(GL_LINES);
        glVertex3f(-377, 275.1, -245);
        glVertex3f(-342, 275.1, -225);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-380, 275.1, -195);
        glVertex3f(-348, 275.1, -195);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-380, 275.1, -165);
        glVertex3f(-348, 275.1, -165);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-380, 275.1, -135);
        glVertex3f(-350, 275.1, -135);
    glEnd();

        glBegin(GL_LINES);
        glVertex3f(-380, 275.1, -105);
        glVertex3f(-350, 275.1, -105);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-380, 275.1, -75);
        glVertex3f(-350, 275.1, -75);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-380, 275.1, -45);
        glVertex3f(-350, 275.1, -45);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-380, 275.1, -15);
        glVertex3f(-350, 275.1, -15);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-380, 275.1, 15);
        glVertex3f(-350, 275.1, 15);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-380, 275.1, 45);
        glVertex3f(-350, 275.1, 45);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-380, 275.1, 75);
        glVertex3f(-350, 275.1, 75);
    glEnd();

    //JARING PENDEK KANAN
    glBegin(GL_LINES);
        glVertex3f(221, 275.1, -260);
        glVertex3f(196, 275.1, -225);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(245, 275.1, -210);
        glVertex3f(211, 275.1, -195);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(250, 275.1, -165);
        glVertex3f(218, 275.1, -165);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(250, 275.1, -135);
        glVertex3f(220, 275.1, -135);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(250, 275.1, -105);
        glVertex3f(220, 275.1, -105);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(250, 275.1, -75);
        glVertex3f(220, 275.1, -75);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(250, 275.1, -45);
        glVertex3f(220, 275.1, -45);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(250, 275.1, -15);
        glVertex3f(220, 275.1, -15);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(250, 275.1, 15);
        glVertex3f(220, 275.1, 15);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(250, 275.1, 45);
        glVertex3f(220, 275.1, 45);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(250, 275.1, 75);
        glVertex3f(220, 275.1, 75);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(249, 275.1, 115);
        glVertex3f(215, 275.1, 95);
    glEnd();


    // JARING PENDEK DEPAN
    glBegin(GL_LINES);
        glVertex3f(220, 275.1, 157);
        glVertex3f(200, 275.1, 120);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(185, 275.1, 160);
        glVertex3f(185, 275.1, 127);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(155, 275.1, 160);
        glVertex3f(155, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(125, 275.1, 160);
        glVertex3f(125, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(95, 275.1, 160);
        glVertex3f(95, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(65, 275.1, 160);
        glVertex3f(65, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(35, 275.1, 160);
        glVertex3f(35, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(5, 275.1, 160);
        glVertex3f(5, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-25, 275.1, 160);
        glVertex3f(-25, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-55, 275.1, 160);
        glVertex3f(-55, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-85, 275.1, 160);
        glVertex3f(-85, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-115, 275.1, 160);
        glVertex3f(-115, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-145, 275.1, 160);
        glVertex3f(-145, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-175, 275.1, 160);
        glVertex3f(-175, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-205, 275.1, 160);
        glVertex3f(-205, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-235, 275.1, 160);
        glVertex3f(-235, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-265, 275.1, 160);
        glVertex3f(-265, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-295, 275.1, 160);
        glVertex3f(-295, 275.1, 130);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-325, 275.1, 160);
        glVertex3f(-325, 275.1, 124);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-375, 275.1, 134);
        glVertex3f(-345, 275.1, 102);
    glEnd();

    //JARING PENDEK BELAKANG
    glBegin(GL_LINES);
        glVertex3f(185, 275.1, -235);
        glVertex3f(185, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(155, 275.1, -240);
        glVertex3f(155, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(125, 275.1, -240);
        glVertex3f(125, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(95, 275.1, -240);
        glVertex3f(95, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(65, 275.1, -240);
        glVertex3f(65, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(35, 275.1, -240);
        glVertex3f(35, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(5, 275.1, -240);
        glVertex3f(5, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-25, 275.1, -240);
        glVertex3f(-25, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-55, 275.1, -240);
        glVertex3f(-55, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-85, 275.1, -240);
        glVertex3f(-85, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-115, 275.1, -240);
        glVertex3f(-115, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-145, 275.1, -240);
        glVertex3f(-145, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-175, 275.1, -240);
        glVertex3f(-175, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-205, 275.1, -240);
        glVertex3f(-205, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-235, 275.1, -240);
        glVertex3f(-235, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-265, 275.1, -240);
        glVertex3f(-265, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-295, 275.1, -240);
        glVertex3f(-295, 275.1, -270);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-325, 275.1, -234);
        glVertex3f(-325, 275.1, -270);
    glEnd();
}

void PintuMasuk(){
        //PINTU MASUK
    glBegin(GL_QUADS);//depan
        glColor4f(0.1, 0.1, 0.2, 0.1);
        glVertex3f(-310, 150, 285.0);
        glVertex3f(-310, 33, 285.0);
        glVertex3f(170, 33, 285.0);
        glVertex3f(170, 150, 285.0);
    glEnd();

    glBegin(GL_QUADS);//depan kiri
        glVertex3f(-310, 150, 285.0);
        glVertex3f(-310, -49.99, 285.0);
        glVertex3f(-300, -49.99, 285.0);
        glVertex3f(-300, 150, 285.0);
    glEnd();

    glBegin(GL_QUADS);//depan kanan
        glVertex3f(160, 150, 285.0);
        glVertex3f(160, -49.99, 285.0);
        glVertex3f(170, -49.99, 285.0);
        glVertex3f(170, 150, 285.0);
    glEnd();

    glBegin(GL_QUADS);//belakang
        glVertex3f(-310, 150, 230.5);
        glVertex3f(-310, 33, 230.5);
        glVertex3f(170, 33, 230.5);
        glVertex3f(170, 150, 230.5);
    glEnd();

    glBegin(GL_QUADS);//belakang kiri
        glVertex3f(-310, 150, 230.5);
        glVertex3f(-310, -49.99, 230.5);
        glVertex3f(-300, -49.99, 230.5);
        glVertex3f(-300, 150, 230.5);
    glEnd();

    glBegin(GL_QUADS);//belakang kanan
        glVertex3f(160, 150, 230.5);
        glVertex3f(160, -49.99, 230.5);
        glVertex3f(170, -49.99, 230.5);
        glVertex3f(170, 150, 230.5);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-310, 150.0, 285.0);
        glVertex3f(170, 150.0, 285.0);
        glVertex3f(170, 150.0, 230.5);
        glVertex3f(-310, 150.0, 230.5);
    glEnd();

    glBegin(GL_QUADS);//kanan
        glVertex3f(170.0, 150, 285);
        glVertex3f(170.0, -49.99, 285);
        glVertex3f(170.0, -49.99, 230.5);
        glVertex3f(170.0, 150, 230.5);
    glEnd();

    glBegin(GL_QUADS);//kanan
        glVertex3f(160.0, 150, 285);
        glVertex3f(160.0, -49.99, 285);
        glVertex3f(160.0, -49.99, 230.5);
        glVertex3f(160.0, 150, 230.5);
    glEnd();

    glBegin(GL_QUADS);//kiri
        glVertex3f(-310, 150, 285);
        glVertex3f(-310, -49.99, 285);
        glVertex3f(-310, -49.99, 230.5);
        glVertex3f(-310, 150, 230.5);
    glEnd();

    glBegin(GL_QUADS);//kiri
        glVertex3f(-300, 150, 285);
        glVertex3f(-300, -49.99, 285);
        glVertex3f(-300, -49.99, 230.5);
        glVertex3f(-300, 150, 230.5);
    glEnd();
}

void huruf(){
    glLineWidth(4.5f);
    glColor3f(0.85, 0.0, 0.0);
    //HURUF S
    glBegin(GL_LINE_STRIP);
        glVertex3f(-280, 235, 232);
        glVertex3f(-295, 235, 232);
        glVertex3f(-295, 205, 232);
        glVertex3f(-280, 205, 232);
        glVertex3f(-280, 175, 232);
        glVertex3f(-295, 175, 232);
    glEnd();

    //HURUF T
    glBegin(GL_LINE_STRIP);
        glVertex3f(-250, 235, 232);
        glVertex3f(-270, 235, 232);
        glVertex3f(-260, 235, 232);
        glVertex3f(-260, 172, 232);
    glEnd();

    //HURUF A
    glBegin(GL_LINE_STRIP);
        glVertex3f(-245, 172, 232);
        glVertex3f(-235, 237, 232);
        glVertex3f(-225, 172, 232);
        glVertex3f(-230, 205, 232);
        glVertex3f(-240, 205, 232);
    glEnd();

    //HURUF D
    glBegin(GL_LINE_LOOP);
        glVertex3f(-215, 235, 232);
        glVertex3f(-204, 235, 232);
        glVertex3f(-195, 220, 232);
        glVertex3f(-195, 190, 232);
        glVertex3f(-204, 174, 232);
        glVertex3f(-215, 174, 232);
    glEnd();

    //HURUF E
    glBegin(GL_LINE_STRIP);
        glVertex3f(-165, 235, 232);
        glVertex3f(-180, 235, 232);
        glVertex3f(-180, 205, 232);
        glVertex3f(-165, 205, 232);
        glVertex3f(-180, 205, 232);
        glVertex3f(-180, 174, 232);
        glVertex3f(-165, 174, 232);
    glEnd();

    //HURUF D
    glBegin(GL_LINE_LOOP);
        glVertex3f(-125, 235, 232);
        glVertex3f(-114, 235, 232);
        glVertex3f(-105, 220, 232);
        glVertex3f(-105, 190, 232);
        glVertex3f(-114, 174, 232);
        glVertex3f(-125, 174, 232);
    glEnd();

    //HURUF U
    glBegin(GL_LINE_STRIP);
        glVertex3f(-90, 237, 232);
        glVertex3f(-90, 185, 232);
        glVertex3f(-85, 174, 232);
        glVertex3f(-80, 174, 232);
        glVertex3f(-70, 185, 232);
        glVertex3f(-70, 237, 232);
    glEnd();

    //HURUF H
    glBegin(GL_LINE_STRIP);
        glVertex3f(-30, 237, 232);
        glVertex3f(-30, 174, 232);
        glVertex3f(-30, 210, 232);
        glVertex3f(-15, 210, 232);
        glVertex3f(-15, 237, 232);
        glVertex3f(-15, 174, 232);
    glEnd();

    //HURUF A
    glBegin(GL_LINE_STRIP);
        glVertex3f(-5, 174, 232);
        glVertex3f(5, 237, 232);
        glVertex3f(15, 174, 232);
        glVertex3f(10, 205, 232);
        glVertex3f(0, 205, 232);
    glEnd();

    //HURUF I
    glBegin(GL_LINE_STRIP);
        glVertex3f(25, 237, 232);
        glVertex3f(25, 173, 232);
    glEnd();

    //HURUF N
    glBegin(GL_LINE_STRIP);
        glVertex3f(40, 173, 232);
        glVertex3f(40, 237, 232);
        glVertex3f(60, 173, 232);
        glVertex3f(60, 237, 232);
    glEnd();

    //HURUF A
    glBegin(GL_LINE_STRIP);
        glVertex3f(70, 172, 232);
        glVertex3f(80, 237, 232);
        glVertex3f(90, 172, 232);
        glVertex3f(85, 205, 232);
        glVertex3f(75, 205, 232);
    glEnd();

    //HURUF U
    glBegin(GL_LINE_STRIP);
        glVertex3f(100, 237, 232);
        glVertex3f(100, 185, 232);
        glVertex3f(107, 174, 232);
        glVertex3f(113, 174, 232);
        glVertex3f(119, 185, 232);
        glVertex3f(119, 237, 232);
    glEnd();

    //HURUF T
    glBegin(GL_LINE_STRIP);
        glVertex3f(130, 235, 232);
        glVertex3f(155, 235, 232);
        glVertex3f(142.5, 235, 232);
        glVertex3f(142.5, 172, 232);
    glEnd();
}

void tiangKiri(){
    //TIANG SAMPING KIRI
    glColor3ub(139, 1, 1);
    glBegin(GL_QUADS);
        glVertex3f(-460, 70, 97);
        glVertex3f(-460, -49.98, 77);
        glVertex3f(-470, -49.98, 77);
        glVertex3f(-470, 70, 97);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-470, 70.0, 97);
        glVertex3f(-470, -49.98, 77);
        glVertex3f(-470, -49.98, 67);
        glVertex3f(-470, 70.0, 87);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 70, 87);
        glVertex3f(-460, -49.98, 67);
        glVertex3f(-470, -49.98, 67);
        glVertex3f(-470, 70, 87);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, 30);
        glVertex3f(-460, -49.98, 72);
        glVertex3f(-470, -49.98, 72);
        glVertex3f(-470, 130, 30);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-470, 130.0, 30);
        glVertex3f(-470, -49.98, 62);
        glVertex3f(-470, -49.98, 72);
        glVertex3f(-470, 130.0, 39.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, 39.5);
        glVertex3f(-460, -49.98, 62);
        glVertex3f(-470, -49.98, 62);
        glVertex3f(-470, 130, 39.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, 34.5);
        glVertex3f(-460, -49.98, -8);
        glVertex3f(-470, -49.98, -8);
        glVertex3f(-470, 130, 34.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-470, 130.0, 24.5);
        glVertex3f(-470, -49.98, -18);
        glVertex3f(-470, -49.98, -8);
        glVertex3f(-470, 130.0, 34.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, 24.5);
        glVertex3f(-460, -49.98, -18);
        glVertex3f(-470, -49.98, -18);
        glVertex3f(-470, 130, 24.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -41);
        glVertex3f(-460, -49.98, -9);
        glVertex3f(-470, -49.98, -9);
        glVertex3f(-470, 130, -41);
    glEnd();

     glBegin(GL_POLYGON);
        glVertex3f(-470, 130.0, -51);
        glVertex3f(-470, -49.98, -19);
        glVertex3f(-470, -49.98, -9);
        glVertex3f(-470, 130.0, -41);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -51);
        glVertex3f(-460, -49.98, -19);
        glVertex3f(-470, -49.98, -19);
        glVertex3f(-470, 130, -51);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -41);
        glVertex3f(-460, -49.98, -73);
        glVertex3f(-470, -49.98, -73);
        glVertex3f(-470, 130, -41);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-470, 130.0, -51);
        glVertex3f(-470, -49.98, -83);
        glVertex3f(-470, -49.98, -73);
        glVertex3f(-470, 130.0, -41);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -51);
        glVertex3f(-460, -49.98, -83);
        glVertex3f(-470, -49.98, -83);
        glVertex3f(-470, 130, -51);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -105);
        glVertex3f(-460, -49.98, -73);
        glVertex3f(-470, -49.98, -73);
        glVertex3f(-470, 130, -105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-470, 130.0, -115);
        glVertex3f(-470, -49.98, -83);
        glVertex3f(-470, -49.98, -73);
        glVertex3f(-470, 130.0, -105);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -115);
        glVertex3f(-460, -49.98, -83);
        glVertex3f(-470, -49.98, -83);
        glVertex3f(-470, 130, -115);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -105);
        glVertex3f(-460, -49.98, -137);
        glVertex3f(-470, -49.98, -137);
        glVertex3f(-470, 130, -105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-470, 130.0, -115);
        glVertex3f(-470, -49.98, -147);
        glVertex3f(-470, -49.98, -137);
        glVertex3f(-470, 130.0, -105);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -115);
        glVertex3f(-460, -49.98, -147);
        glVertex3f(-470, -49.98, -147);
        glVertex3f(-470, 130, -115);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -169);
        glVertex3f(-460, -49.98, -137);
        glVertex3f(-470, -49.98, -137);
        glVertex3f(-470, 130, -169);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-470, 130.0, -179);
        glVertex3f(-470, -49.98, -147);
        glVertex3f(-470, -49.98, -137);
        glVertex3f(-470, 130.0, -169);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 130, -179);
        glVertex3f(-460, -49.98, -147);
        glVertex3f(-470, -49.98, -147);
        glVertex3f(-470, 130, -179);
    glEnd();


    glBegin(GL_POLYGON);
        glVertex3f(-460, 70.0, 97);
        glVertex3f(-460, -49.98, 77);
        glVertex3f(-460, -49.98, 67);
        glVertex3f(-460, 70.0, 87);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-460, 130.0, 30);
        glVertex3f(-460, -49.98, 62);
        glVertex3f(-460, -49.98, 72);
        glVertex3f(-460, 130.0, 39.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-460, 130.0, 24.5);
        glVertex3f(-460, -49.98, -18);
        glVertex3f(-460, -49.98, -8);
        glVertex3f(-460, 130.0, 34.5);
    glEnd();

     glBegin(GL_POLYGON);
        glVertex3f(-460, 130.0, -51);
        glVertex3f(-460, -49.98, -19);
        glVertex3f(-460, -49.98, -9);
        glVertex3f(-460, 130.0, -41);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-460, 130.0, -51);
        glVertex3f(-460, -49.98, -83);
        glVertex3f(-460, -49.98, -73);
        glVertex3f(-460, 130.0, -41);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-460, 130.0, -115);
        glVertex3f(-460, -49.98, -83);
        glVertex3f(-460, -49.98, -73);
        glVertex3f(-460, 130.0, -105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-460, 130.0, -115);
        glVertex3f(-460, -49.98, -147);
        glVertex3f(-460, -49.98, -137);
        glVertex3f(-460, 130.0, -105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-460, 130.0, -179);
        glVertex3f(-460, -49.98, -147);
        glVertex3f(-460, -49.98, -137);
        glVertex3f(-460, 130.0, -169);
    glEnd();
}

void tiangKanan(){
    //TIANG SAMPING KANAN
    glBegin(GL_QUADS);
        glVertex3f(330, 70, 97);
        glVertex3f(330, -49.98, 77);
        glVertex3f(340, -49.98, 77);
        glVertex3f(340, 70, 97);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(340, 70.0, 97);
        glVertex3f(340, -49.98, 77);
        glVertex3f(340, -49.98, 67);
        glVertex3f(340, 70.0, 87);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 70, 87);
        glVertex3f(330, -49.98, 67);
        glVertex3f(340, -49.98, 67);
        glVertex3f(340, 70, 87);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, 30);
        glVertex3f(330, -49.98, 72);
        glVertex3f(340, -49.98, 72);
        glVertex3f(340, 130, 30);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(340, 130.0, 30);
        glVertex3f(340, -49.98, 62);
        glVertex3f(340, -49.98, 72);
        glVertex3f(340, 130.0, 39.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, 39.5);
        glVertex3f(330, -49.98, 62);
        glVertex3f(340, -49.98, 62);
        glVertex3f(340, 130, 39.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, 34.5);
        glVertex3f(330, -49.98, -8);
        glVertex3f(340, -49.98, -8);
        glVertex3f(340, 130, 34.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(340, 130.0, 24.5);
        glVertex3f(340, -49.98, -18);
        glVertex3f(340, -49.98, -8);
        glVertex3f(340, 130.0, 34.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, 24.5);
        glVertex3f(330, -49.98, -18);
        glVertex3f(340, -49.98, -18);
        glVertex3f(340, 130, 24.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -41);
        glVertex3f(330, -49.98, -9);
        glVertex3f(340, -49.98, -9);
        glVertex3f(340, 130, -41);
    glEnd();

     glBegin(GL_POLYGON);
        glVertex3f(340, 130.0, -51);
        glVertex3f(340, -49.98, -19);
        glVertex3f(340, -49.98, -9);
        glVertex3f(340, 130.0, -41);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -51);
        glVertex3f(330, -49.98, -19);
        glVertex3f(340, -49.98, -19);
        glVertex3f(340, 130, -51);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -41);
        glVertex3f(330, -49.98, -73);
        glVertex3f(340, -49.98, -73);
        glVertex3f(340, 130, -41);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(340, 130.0, -51);
        glVertex3f(340, -49.98, -83);
        glVertex3f(340, -49.98, -73);
        glVertex3f(340, 130.0, -41);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -51);
        glVertex3f(330, -49.98, -83);
        glVertex3f(340, -49.98, -83);
        glVertex3f(340, 130, -51);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -105);
        glVertex3f(330, -49.98, -73);
        glVertex3f(340, -49.98, -73);
        glVertex3f(340, 130, -105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(340, 130.0, -115);
        glVertex3f(340, -49.98, -83);
        glVertex3f(340, -49.98, -73);
        glVertex3f(340, 130.0, -105);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -115);
        glVertex3f(330, -49.98, -83);
        glVertex3f(340, -49.98, -83);
        glVertex3f(340, 130, -115);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -105);
        glVertex3f(330, -49.98, -137);
        glVertex3f(340, -49.98, -137);
        glVertex3f(340, 130, -105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(340, 130.0, -115);
        glVertex3f(340, -49.98, -147);
        glVertex3f(340, -49.98, -137);
        glVertex3f(340, 130.0, -105);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -115);
        glVertex3f(330, -49.98, -147);
        glVertex3f(340, -49.98, -147);
        glVertex3f(340, 130, -115);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -169);
        glVertex3f(330, -49.98, -137);
        glVertex3f(340, -49.98, -137);
        glVertex3f(340, 130, -169);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(340, 130.0, -179);
        glVertex3f(340, -49.98, -147);
        glVertex3f(340, -49.98, -137);
        glVertex3f(340, 130.0, -169);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330, 130, -179);
        glVertex3f(330, -49.98, -147);
        glVertex3f(340, -49.98, -147);
        glVertex3f(340, 130, -179);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(330, 70.0, 97);
        glVertex3f(330, -49.98, 77);
        glVertex3f(330, -49.98, 67);
        glVertex3f(330, 70.0, 87);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(330, 130.0, 30);
        glVertex3f(330, -49.98, 62);
        glVertex3f(330, -49.98, 72);
        glVertex3f(330, 130.0, 39.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(330, 130.0, 24.5);
        glVertex3f(330, -49.98, -18);
        glVertex3f(330, -49.98, -8);
        glVertex3f(330, 130.0, 34.5);
    glEnd();

     glBegin(GL_POLYGON);
        glVertex3f(330, 130.0, -51);
        glVertex3f(330, -49.98, -19);
        glVertex3f(330, -49.98, -9);
        glVertex3f(330, 130.0, -41);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(330, 130.0, -51);
        glVertex3f(330, -49.98, -83);
        glVertex3f(330, -49.98, -73);
        glVertex3f(330, 130.0, -41);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(330, 130.0, -115);
        glVertex3f(330, -49.98, -83);
        glVertex3f(330, -49.98, -73);
        glVertex3f(330, 130.0, -105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(330, 130.0, -115);
        glVertex3f(330, -49.98, -147);
        glVertex3f(330, -49.98, -137);
        glVertex3f(330, 130.0, -105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(330, 130.0, -179);
        glVertex3f(330, -49.98, -147);
        glVertex3f(330, -49.98, -137);
        glVertex3f(330, 130.0, -169);
    glEnd();
}

void tiangBelakang(){
    //TIANG BELAKANG
    glBegin(GL_POLYGON);
        glVertex3f(190, 100.0, -354.5);
        glVertex3f(160, -49.98, -354.5);
        glVertex3f(160, -49.98, -344.5);
        glVertex3f(190, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(190, 100, -354.5);
        glVertex3f(160, -49.98, -354.5);
        glVertex3f(150, -49.98, -354.5);
        glVertex3f(180, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(180, 100.0, -354.5);
        glVertex3f(150, -49.98, -354.5);
        glVertex3f(150, -49.98, -344.5);
        glVertex3f(180, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(120, 100.0, -354.5);
        glVertex3f(160, -49.98, -354.5);
        glVertex3f(160, -49.98, -344.5);
        glVertex3f(120, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(120, 100, -354.5);
        glVertex3f(160, -49.98, -354.5);
        glVertex3f(150, -49.98, -354.5);
        glVertex3f(110, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(110, 100.0, -354.5);
        glVertex3f(150, -49.98, -354.5);
        glVertex3f(150, -49.98, -344.5);
        glVertex3f(110, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(120, 100.0, -354.5);
        glVertex3f(80, -49.98, -354.5);
        glVertex3f(80, -49.98, -344.5);
        glVertex3f(120, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(120, 100, -354.5);
        glVertex3f(80, -49.98, -354.5);
        glVertex3f(70, -49.98, -354.5);
        glVertex3f(110, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(110, 100.0, -354.5);
        glVertex3f(70, -49.98, -354.5);
        glVertex3f(70, -49.98, -344.5);
        glVertex3f(110, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(40, 100.0, -354.5);
        glVertex3f(80, -49.98, -354.5);
        glVertex3f(80, -49.98, -344.5);
        glVertex3f(40, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(40, 100, -354.5);
        glVertex3f(80, -49.98, -354.5);
        glVertex3f(70, -49.98, -354.5);
        glVertex3f(30, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(30, 100.0, -354.5);
        glVertex3f(70, -49.98, -354.5);
        glVertex3f(70, -49.98, -344.5);
        glVertex3f(30, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(40, 100.0, -354.5);
        glVertex3f(0, -49.98, -354.5);
        glVertex3f(00, -49.98, -344.5);
        glVertex3f(40, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(40, 100, -354.5);
        glVertex3f(0, -49.98, -354.5);
        glVertex3f(-10, -49.98, -354.5);
        glVertex3f(30, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(30, 100.0, -354.5);
        glVertex3f(-10, -49.98, -354.5);
        glVertex3f(-10, -49.98, -344.5);
        glVertex3f(30, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-40, 100.0, -354.5);
        glVertex3f(0, -49.98, -354.5);
        glVertex3f(0, -49.98, -344.5);
        glVertex3f(-40, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-40, 100, -354.5);
        glVertex3f(0, -49.98, -354.5);
        glVertex3f(-10, -49.98, -354.5);
        glVertex3f(-50, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-50, 100.0, -354.5);
        glVertex3f(-10, -49.98, -354.5);
        glVertex3f(-10, -49.98, -344.5);
        glVertex3f(-50, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-40, 100.0, -354.5);
        glVertex3f(-80, -49.98, -354.5);
        glVertex3f(-80, -49.98, -344.5);
        glVertex3f(-40, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-40, 100, -354.5);
        glVertex3f(-80, -49.98, -354.5);
        glVertex3f(-90, -49.98, -354.5);
        glVertex3f(-50, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-50, 100.0, -354.5);
        glVertex3f(-90, -49.98, -354.5);
        glVertex3f(-90, -49.98, -344.5);
        glVertex3f(-50, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-120, 100.0, -354.5);
        glVertex3f(-80, -49.98, -354.5);
        glVertex3f(-80, -49.98, -344.5);
        glVertex3f(-120, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-120, 100, -354.5);
        glVertex3f(-80, -49.98, -354.5);
        glVertex3f(-90, -49.98, -354.5);
        glVertex3f(-130, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-130, 100.0, -354.5);
        glVertex3f(-90, -49.98, -354.5);
        glVertex3f(-90, -49.98, -344.5);
        glVertex3f(-130, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-120, 100.0, -354.5);
        glVertex3f(-160, -49.98, -354.5);
        glVertex3f(-160, -49.98, -344.5);
        glVertex3f(-120, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-120, 100, -354.5);
        glVertex3f(-160, -49.98, -354.5);
        glVertex3f(-170, -49.98, -354.5);
        glVertex3f(-130, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-130, 100.0, -354.5);
        glVertex3f(-170, -49.98, -354.5);
        glVertex3f(-170, -49.98, -344.5);
        glVertex3f(-130, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-200, 100.0, -354.5);
        glVertex3f(-160, -49.98, -354.5);
        glVertex3f(-160, -49.98, -344.5);
        glVertex3f(-200, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-200, 100, -354.5);
        glVertex3f(-160, -49.98, -354.5);
        glVertex3f(-170, -49.98, -354.5);
        glVertex3f(-210, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-210, 100.0, -354.5);
        glVertex3f(-170, -49.98, -354.5);
        glVertex3f(-170, -49.98, -344.5);
        glVertex3f(-210, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-200, 100.0, -354.5);
        glVertex3f(-240, -49.98, -354.5);
        glVertex3f(-240, -49.98, -344.5);
        glVertex3f(-200, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-200, 100, -354.5);
        glVertex3f(-240, -49.98, -354.5);
        glVertex3f(-250, -49.98, -354.5);
        glVertex3f(-210, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-210, 100.0, -354.5);
        glVertex3f(-250, -49.98, -354.5);
        glVertex3f(-250, -49.98, -344.5);
        glVertex3f(-210, 100.0, -344.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-280, 100.0, -354.5);
        glVertex3f(-240, -49.98, -354.5);
        glVertex3f(-240, -49.98, -344.5);
        glVertex3f(-280, 100.0, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-280, 100, -354.5);
        glVertex3f(-240, -49.98, -354.5);
        glVertex3f(-250, -49.98, -354.5);
        glVertex3f(-290, 100, -354.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-290, 100.0, -354.5);
        glVertex3f(-250, -49.98, -354.5);
        glVertex3f(-250, -49.98, -344.5);
        glVertex3f(-290, 100.0, -344.5);
    glEnd();




    glBegin(GL_QUADS);
        glVertex3f(190, 100, -344.5);
        glVertex3f(160, -49.98, -344.5);
        glVertex3f(150, -49.98, -344.5);
        glVertex3f(180, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(120, 100, -344.5);
        glVertex3f(160, -49.98, -344.5);
        glVertex3f(150, -49.98, -344.5);
        glVertex3f(110, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(120, 100, -344.5);
        glVertex3f(80, -49.98, -344.5);
        glVertex3f(70, -49.98, -344.5);
        glVertex3f(110, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(40, 100, -344.5);
        glVertex3f(80, -49.98, -344.5);
        glVertex3f(70, -49.98, -344.5);
        glVertex3f(30, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(40, 100, -344.5);
        glVertex3f(0, -49.98, -344.5);
        glVertex3f(-10, -49.98, -344.5);
        glVertex3f(30, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-40, 100, -344.5);
        glVertex3f(0, -49.98, -344.5);
        glVertex3f(-10, -49.98, -344.5);
        glVertex3f(-50, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-40, 100, -344.5);
        glVertex3f(-80, -49.98, -344.5);
        glVertex3f(-90, -49.98, -344.5);
        glVertex3f(-50, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-120, 100, -344.5);
        glVertex3f(-80, -49.98, -344.5);
        glVertex3f(-90, -49.98, -344.5);
        glVertex3f(-130, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-120, 100, -344.5);
        glVertex3f(-160, -49.98, -344.5);
        glVertex3f(-170, -49.98, -344.5);
        glVertex3f(-130, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-200, 100, -344.5);
        glVertex3f(-160, -49.98, -344.5);
        glVertex3f(-170, -49.98, -344.5);
        glVertex3f(-210, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-200, 100, -344.5);
        glVertex3f(-240, -49.98, -344.5);
        glVertex3f(-250, -49.98, -344.5);
        glVertex3f(-210, 100, -344.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-280, 100, -344.5);
        glVertex3f(-240, -49.98, -344.5);
        glVertex3f(-250, -49.98, -344.5);
        glVertex3f(-290, 100, -344.5);
    glEnd();
}

void dalam(){
    //BANGUNAN DALAM MERAH
    glColor3ub(255, 20, 20);
    glBegin(GL_QUADS);
        glVertex3f(-400.0, 39.99, 227.5);
        glVertex3f(267.0, 39.99, 227.5);
        glVertex3f(267.0, 260, 227.5);
        glVertex3f(-400.0, 260, 227.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(267.0, 39.99, 227.5);
        glVertex3f(270.0, 39.99, 227);
        glVertex3f(270.0, 260, 227);
        glVertex3f(267.0, 260, 227.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(270.0, 39.99, 227);
        glVertex3f(275.0, 39.99, 226);
        glVertex3f(275.0, 260, 226);
        glVertex3f(270.0, 260, 227);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 39.99, 226);
        glVertex3f(280.0, 39.99, 225);
        glVertex3f(280.0, 260, 225);
        glVertex3f(275.0, 260, 226);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280.0, 39.99, 225);
        glVertex3f(285.0, 39.99, 224);
        glVertex3f(285.0, 260, 224);
        glVertex3f(280.0, 260, 225);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(285.0, 39.99, 224);
        glVertex3f(290.0, 39.99, 223);
        glVertex3f(290.0, 260, 223);
        glVertex3f(285.0, 260, 224);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 39.99, 223);
        glVertex3f(295.0, 39.99, 220);
        glVertex3f(295.0, 260, 220);
        glVertex3f(290.0, 260, 223);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(295.0, 39.99, 220);
        glVertex3f(300.0, 39.99, 215);
        glVertex3f(300.0, 260, 215);
        glVertex3f(295.0, 260, 220);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300.0, 39.99, 215);
        glVertex3f(305.0, 39.99, 210);
        glVertex3f(305.0, 260, 210);
        glVertex3f(300.0, 260, 215);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 39.99, 210);
        glVertex3f(310.0, 39.99, 203);
        glVertex3f(310.0, 260, 203);
        glVertex3f(305.0, 260, 210);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310.0, 39.99, 203);
        glVertex3f(315.0, 39.99, 195);
        glVertex3f(315.0, 260, 195);
        glVertex3f(310.0, 260, 203);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 39.99, 195);
        glVertex3f(320.0, 39.99, 186);
        glVertex3f(320.0, 260, 186);
        glVertex3f(315.0, 260, 195);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 39.99, 186);
        glVertex3f(325.0, 39.99, 174);
        glVertex3f(325.0, 260, 174);
        glVertex3f(320.0, 260, 186);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.0, 39.99, 174);
        glVertex3f(326.5, 39.99, 145);
        glVertex3f(326.5, 260, 145);
        glVertex3f(325.0, 260, 174);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(326.5, 39.99, 145);
        glVertex3f(325.5, 39.99, 110);
        glVertex3f(325.5, 260, 110);
        glVertex3f(326.5, 260, 145);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.5, 39.99, 110);
        glVertex3f(325.5, 39.99, -235);
        glVertex3f(325.5, 260, -235);
        glVertex3f(325.5, 260, 110);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.5, 39.99, -235);
        glVertex3f(324, 39.99, -260);
        glVertex3f(324, 260, -260);
        glVertex3f(325.5, 260, -235);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(324, 39.99, -260);
        glVertex3f(322, 39.99, -270);
        glVertex3f(322, 260, -270);
        glVertex3f(324, 260, -260);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(322, 39.99, -270);
        glVertex3f(320, 39.99, -280);
        glVertex3f(320, 260, -280);
        glVertex3f(322, 260, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320, 39.99, -280);
        glVertex3f(318, 39.99, -290);
        glVertex3f(318, 260, -290);
        glVertex3f(320, 260, -280);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(318, 39.99, -290);
        glVertex3f(310, 39.99, -310);
        glVertex3f(310, 260, -310);
        glVertex3f(318, 260, -290);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310, 39.99, -310);
        glVertex3f(300, 39.99, -320);
        glVertex3f(300, 260, -320);
        glVertex3f(310, 260, -310);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300, 39.99, -320);
        glVertex3f(290, 39.99, -325);
        glVertex3f(290, 260, -325);
        glVertex3f(300, 260, -320);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290, 39.99, -325);
        glVertex3f(279, 39.99, -330);
        glVertex3f(279, 260, -330);
        glVertex3f(290, 260, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(279, 39.99, -330);
        glVertex3f(250, 39.99, -339);
        glVertex3f(250, 260, -339);
        glVertex3f(279, 260, -330);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(250, 39.99, -339);
        glVertex3f(245, 39.99, -340.5);
        glVertex3f(245, 260, -340.5);
        glVertex3f(250, 260, -339);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(245, 39.99, -340.5);
        glVertex3f(-385, 39.99, -340.5);
        glVertex3f(-385, 260, -340.5);
        glVertex3f(245, 260, -340.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-385, 39.99, -340.5);
        glVertex3f(-415, 39.99, -338);
        glVertex3f(-415, 260, -338);
        glVertex3f(-385, 260, -340.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 39.99, -338);
        glVertex3f(-425, 39.99, -335);
        glVertex3f(-425, 260, -335);
        glVertex3f(-415, 260, -338);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-425, 39.99, -335);
        glVertex3f(-435, 39.99, -330);
        glVertex3f(-435, 260, -330);
        glVertex3f(-425, 260, -335);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 39.99, -330);
        glVertex3f(-445, 39.99, -320);
        glVertex3f(-445, 260, -320);
        glVertex3f(-435, 260, -330);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 39.99, -320);
        glVertex3f(-450, 39.99, -315);
        glVertex3f(-450, 260, -315);
        glVertex3f(-445, 260, -320);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-450, 39.99, -315);
        glVertex3f(-455, 39.99, -300);
        glVertex3f(-455, 260, -300);
        glVertex3f(-450, 260, -315);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-455, 39.99, -300);
        glVertex3f(-456, 39.99, -290);
        glVertex3f(-456, 260, -290);
        glVertex3f(-455, 260, -300);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-456, 39.99, -290);
        glVertex3f(-457, 39.99, -285);
        glVertex3f(-457, 260, -285);
        glVertex3f(-456, 260, -290);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-457, 39.99, -285);
        glVertex3f(-454, 39.99, 175);
        glVertex3f(-454, 260, 175);
        glVertex3f(-457, 260, -285);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-454, 39.99, 175);
        glVertex3f(-452, 39.99, 182);
        glVertex3f(-452, 260, 182);
        glVertex3f(-454, 260, 175);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-452, 39.99, 182);
        glVertex3f(-450, 39.99, 187);
        glVertex3f(-450, 260, 187);
        glVertex3f(-452, 260, 182);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-450, 39.99, 187);
        glVertex3f(-445, 39.99, 197);
        glVertex3f(-445, 260, 197);
        glVertex3f(-450, 260, 187);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 39.99, 197);
        glVertex3f(-440, 39.99, 205);
        glVertex3f(-440, 260, 205);
        glVertex3f(-445, 260, 197);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 39.99, 205);
        glVertex3f(-428, 39.99, 215);
        glVertex3f(-428, 260, 215);
        glVertex3f(-440, 260, 205);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-428, 39.99, 215);
        glVertex3f(-415, 39.99, 223);
        glVertex3f(-415, 260, 223);
        glVertex3f(-428, 260, 215);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 39.99, 223);
        glVertex3f(-400, 39.99, 227.5);
        glVertex3f(-400, 260, 227.5);
        glVertex3f(-415, 260, 223);
    glEnd();
}

void dalamAtas(){
    glLineWidth(4.0f);
    glColor3ub(255, 20, 20);

    glBegin(GL_QUADS);
        glVertex3f(267.0, 260, 227.5);
        glVertex3f(-400.0, 260, 227.5);
        glVertex3f(-390.0, 270, 207.5);
        glVertex3f(257.0, 270, 207.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(270.0, 260, 227);
        glVertex3f(267.0, 260, 227.5);
        glVertex3f(257.0, 270, 207.5);
        glVertex3f(260.0, 270, 207);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 260, 226);
        glVertex3f(270.0, 260, 227);
        glVertex3f(260.0, 270, 207);
        glVertex3f(265.0, 270, 206);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 260, 226);
        glVertex3f(270.0, 260, 227);
        glVertex3f(265.0, 270, 206);
        glVertex3f(275.0, 270, 204);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280.0, 260, 225);
        glVertex3f(275.0, 260, 226);
        glVertex3f(275.0, 270, 204);
        glVertex3f(280.0, 270, 203);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(285.0, 260, 224);
        glVertex3f(280.0, 260, 225);
        glVertex3f(280.0, 270, 203);
        glVertex3f(285.0, 270, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 260, 223);
        glVertex3f(285.0, 260, 224);
        glVertex3f(285.0, 270, 200);
        glVertex3f(290.0, 270, 195);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(295.0, 260, 220);
        glVertex3f(290.0, 260, 223);
        glVertex3f(290.0, 270, 195);
        glVertex3f(295.0, 270, 190);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300.0, 260, 215);
        glVertex3f(295.0, 260, 220);
        glVertex3f(295.0, 270, 190);
        glVertex3f(300.0, 270, 183);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 260, 210);
        glVertex3f(300.0, 260, 215);
        glVertex3f(300.0, 270, 183);
        glVertex3f(305.0, 270, 175);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310.0, 260, 203);
        glVertex3f(305.0, 260, 210);
        glVertex3f(305.0, 270, 175);
        glVertex3f(310.0, 270, 166);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 260, 195);
        glVertex3f(310.0, 260, 203);
        glVertex3f(310.0, 270, 166);
        glVertex3f(315.0, 270, 154);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 260, 186);
        glVertex3f(315.0, 260, 195);
        glVertex3f(315.0, 270, 154);
        glVertex3f(316.5, 270, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.0, 260, 174);
        glVertex3f(320.0, 260, 186);
        glVertex3f(315.0, 270, 154);
        glVertex3f(316.5, 270, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(326.5, 260, 145);
        glVertex3f(325.0, 260, 174);
        glVertex3f(315.0, 270, 154);
        glVertex3f(316.5, 270, 125);
    glEnd();


    glBegin(GL_QUADS);
        glVertex3f(325.5, 260, 110);
        glVertex3f(326.5, 260, 145);
        glVertex3f(316.5, 270, 125);
        glVertex3f(315.5, 270, 90);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.5, 260, -235);
        glVertex3f(325.5, 260, 110);
        glVertex3f(315.5, 270, 90);
        glVertex3f(315.5, 270, -215);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(324, 260, -260);
        glVertex3f(325.5, 260, -235);
        glVertex3f(315.5, 270, -215);
        glVertex3f(314, 270, -240);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(322, 260, -270);
        glVertex3f(324, 260, -260);
        glVertex3f(314, 270, -240);
        glVertex3f(312, 270, -250);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320, 260, -280);
        glVertex3f(322, 260, -270);
        glVertex3f(312, 270, -250);
        glVertex3f(310, 270, -260);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(318, 260, -290);
        glVertex3f(320, 260, -280);
        glVertex3f(310, 270, -260);
        glVertex3f(308, 270, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310, 260, -310);
        glVertex3f(318, 260, -290);
        glVertex3f(308, 270, -270);
        glVertex3f(300, 270, -290);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300, 260, -320);
        glVertex3f(310, 260, -310);
        glVertex3f(300, 270, -290);
        glVertex3f(290, 270, -300);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290, 260, -325);
        glVertex3f(300, 260, -320);
        glVertex3f(290, 270, -300);
        glVertex3f(280, 270, -305);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(279, 260, -330);
        glVertex3f(290, 260, -325);
        glVertex3f(280, 270, -305);
        glVertex3f(269, 270, -310);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(250, 260, -339);
        glVertex3f(279, 260, -330);
        glVertex3f(269, 270, -310);
        glVertex3f(240, 270, -319);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(245, 260, -340.5);
        glVertex3f(250, 260, -339);
        glVertex3f(240, 270, -319);
        glVertex3f(235, 270, -320.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-385, 260, -340.5);
        glVertex3f(245, 260, -340.5);
        glVertex3f(235, 270, -320.5);
        glVertex3f(-395, 270, -320.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 260, -338);
        glVertex3f(-385, 260, -340.5);
        glVertex3f(-395, 270, -320.5);
        glVertex3f(-405, 270, -318);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-425, 260, -335);
        glVertex3f(-415, 260, -338);
        glVertex3f(-405, 270, -318);
        glVertex3f(-415, 270, -315);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 260, -330);
        glVertex3f(-425, 260, -335);
        glVertex3f(-415, 270, -315);
        glVertex3f(-425, 270, -310);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 260, -320);
        glVertex3f(-435, 260, -330);
        glVertex3f(-425, 270, -310);
        glVertex3f(-435, 270, -300);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-450, 260, -315);
        glVertex3f(-445, 260, -320);
        glVertex3f(-435, 270, -300);
        glVertex3f(-440, 270, -295);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-455, 260, -300);
        glVertex3f(-450, 260, -315);
        glVertex3f(-440, 270, -295);
        glVertex3f(-445, 270, -280);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-456, 260, -290);
        glVertex3f(-455, 260, -300);
        glVertex3f(-445, 270, -280);
        glVertex3f(-446, 270, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-457, 260, -285);
        glVertex3f(-456, 260, -290);
        glVertex3f(-446, 270, -270);
        glVertex3f(-447, 270, -265);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-454, 260, 175);
        glVertex3f(-457, 260, -285);
        glVertex3f(-447, 270, -265);
        glVertex3f(-444, 270, 155);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-452, 260, 182);
        glVertex3f(-454, 260, 175);
        glVertex3f(-444, 270, 155);
        glVertex3f(-442, 270, 162);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-450, 260, 187);
        glVertex3f(-452, 260, 182);
        glVertex3f(-442, 270, 162);
        glVertex3f(-440, 270, 167);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 260, 197);
        glVertex3f(-450, 260, 187);
        glVertex3f(-440, 270, 167);
        glVertex3f(-435, 270, 177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 260, 205);
        glVertex3f(-445, 260, 197);
        glVertex3f(-435, 270, 177);
        glVertex3f(-430, 270, 185);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-428, 260, 215);
        glVertex3f(-440, 260, 205);
        glVertex3f(-430, 270, 185);
        glVertex3f(-418, 270, 195);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 260, 223);
        glVertex3f(-428, 260, 215);
        glVertex3f(-418, 270, 195);
        glVertex3f(-405, 270, 203);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-400, 260, 227.5);
        glVertex3f(-415, 260, 223);
        glVertex3f(-405, 270, 203);
        glVertex3f(-390, 270, 207.5);
    glEnd();


//    glBegin(GL_LINE_STRIP);
//        glVertex3f(-390.0, 310, 207.5);
//        glVertex3f(257.0, 310, 207.5);
//        glVertex3f(260.0, 310, 207);
//        glVertex3f(265.0, 310, 206);
//        glVertex3f(270.0, 310, 205);
//        glVertex3f(275.0, 310, 204);
//        glVertex3f(280.0, 310, 203);
//        glVertex3f(285.0, 310, 200);
//        glVertex3f(290.0, 310, 195);
//        glVertex3f(295.0, 310, 190);
//        glVertex3f(300.0, 310, 183);
//        glVertex3f(305.0, 310, 175);
//        glVertex3f(310.0, 310, 166);
//        glVertex3f(315.0, 310, 154);
//        glVertex3f(316.5, 310, 125);
//        glVertex3f(315.5, 310, 90);
//
//        glVertex3f(315.5, 310, -215);
//        glVertex3f(314, 310, -240);
//        glVertex3f(312, 310, -250);
//        glVertex3f(310, 310, -260);
//        glVertex3f(308, 310, -270);
//        glVertex3f(300, 310, -290);
//        glVertex3f(290, 310, -300);
//        glVertex3f(280, 310, -305);
//        glVertex3f(269, 310, -310);
//        glVertex3f(240, 310, -319);
//        glVertex3f(235, 310, -320.5);
//
//        glVertex3f(-395, 310, -320.5);
//        glVertex3f(-405, 310, -318);
//        glVertex3f(-415, 310, -315);
//        glVertex3f(-425, 310, -310);
//        glVertex3f(-435, 310, -300);
//        glVertex3f(-440, 310, -295);
//        glVertex3f(-445, 310, -280);
//        glVertex3f(-446, 310, -270);
//        glVertex3f(-447, 310, -265);
//
//        glVertex3f(-444, 310, 155);
//        glVertex3f(-442, 310, 162);
//        glVertex3f(-440, 310, 167);
//        glVertex3f(-435, 310, 177);
//        glVertex3f(-430, 310, 185);
//        glVertex3f(-418, 310, 195);
//        glVertex3f(-405, 310, 203);
//        glVertex3f(-390, 310, 207.5);
//    glEnd();
}

void atapdalam(){
    glLineWidth(4.0f);
    glColor3ub(255, 20, 20);

    glBegin(GL_QUADS);
        glVertex3f(-390.0, 270, 207.5);
        glVertex3f(257.0, 270, 207.5);
        glVertex3f(197.0, 275, 160.5);
        glVertex3f(-330.0, 275, 160.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(257.0, 270, 207.5);
        glVertex3f(260.0, 270, 207);
        glVertex3f(200.0, 275, 160);
        glVertex3f(197.0, 275, 160.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(260.0, 270, 207);
        glVertex3f(265.0, 270, 206);
        glVertex3f(205.0, 275, 159);
        glVertex3f(200.0, 275, 160);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(265.0, 270, 206);
        glVertex3f(275.0, 270, 204);
        glVertex3f(210.0, 275, 158);
        glVertex3f(205.0, 275, 159);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 270, 204);
        glVertex3f(280.0, 270, 203);
        glVertex3f(215.0, 275, 157);
        glVertex3f(210.0, 275, 158);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280.0, 270, 203);
        glVertex3f(285.0, 270, 200);
        glVertex3f(220.0, 275, 156);
        glVertex3f(215.0, 275, 157);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(285.0, 270, 200);
        glVertex3f(290.0, 270, 195);
        glVertex3f(230.0, 275, 149);
        glVertex3f(220.0, 275, 156);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 270, 195);
        glVertex3f(295.0, 270, 190);
        glVertex3f(238.0, 275, 140);
        glVertex3f(230.0, 275, 149);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(295.0, 270, 190);
        glVertex3f(300.0, 270, 183);
        glVertex3f(238.0, 275, 140);
        glVertex3f(230.0, 275, 149);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300.0, 270, 183);
        glVertex3f(305.0, 270, 175);
        glVertex3f(242.0, 275, 132);
        glVertex3f(238.0, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 270, 175);
        glVertex3f(310.0, 270, 166);
        glVertex3f(242.0, 275, 132);
        glVertex3f(238.0, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310.0, 270, 166);
        glVertex3f(315.0, 270, 154);
        glVertex3f(245.0, 275, 125);
        glVertex3f(242.0, 275, 132);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 270, 154);
        glVertex3f(316.5, 270, 125);
        glVertex3f(245.0, 275, 125);
        glVertex3f(242.0, 275, 132);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 270, 154);
        glVertex3f(316.5, 270, 125);
        glVertex3f(248.0, 275, 120);
        glVertex3f(245.0, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 270, 154);
        glVertex3f(316.5, 270, 125);
        glVertex3f(248.0, 275, 120);
        glVertex3f(245.0, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(316.5, 270, 125);
        glVertex3f(315.5, 270, 90);
        glVertex3f(250.0, 275, 106);
        glVertex3f(248.0, 275, 120);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.5, 270, 90);
        glVertex3f(315.5, 270, -215);
        glVertex3f(250.0, 275, -177);
        glVertex3f(250.0, 275, 106);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.5, 270, -215);
        glVertex3f(314, 270, -240);
        glVertex3f(248, 275, -200);
        glVertex3f(250.0, 275, -177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(314, 270, -240);
        glVertex3f(312, 270, -250);
        glVertex3f(248, 275, -200);
        glVertex3f(250.0, 275, -177);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(312, 270, -250);
        glVertex3f(310, 270, -260);
        glVertex3f(240, 275, -230);
        glVertex3f(248, 275, -200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310, 270, -260);
        glVertex3f(308, 270, -270);
        glVertex3f(240, 275, -230);
        glVertex3f(248, 275, -200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(308, 270, -270);
        glVertex3f(300, 270, -290);
        glVertex3f(230, 275, -250);
        glVertex3f(240, 275, -230);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300, 270, -290);
        glVertex3f(290, 270, -300);
        glVertex3f(230, 275, -250);
        glVertex3f(240, 275, -230);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290, 270, -300);
        glVertex3f(280, 270, -305);
        glVertex3f(220, 275, -260);
        glVertex3f(230, 275, -250);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280, 270, -305);
        glVertex3f(269, 270, -310);
        glVertex3f(220, 275, -260);
        glVertex3f(230, 275, -250);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(269, 270, -310);
        glVertex3f(240, 270, -319);
        glVertex3f(210, 275, -265);
        glVertex3f(220, 275, -260);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(240, 270, -319);
        glVertex3f(235, 270, -320.5);
        glVertex3f(180, 275, -270);
        glVertex3f(210, 275, -265);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(235, 270, -320.5);
        glVertex3f(-395, 270, -320.5);
        glVertex3f(-335, 275, -270);
        glVertex3f(180, 275, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-395, 270, -320.5);
        glVertex3f(-405, 270, -318);
        glVertex3f(-345, 275, -268);
        glVertex3f(-335, 275, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-405, 270, -318);
        glVertex3f(-415, 270, -315);
        glVertex3f(-345, 275, -268);
        glVertex3f(-335, 275, -270);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 270, -315);
        glVertex3f(-425, 270, -310);
        glVertex3f(-355, 275, -265);
        glVertex3f(-345, 275, -268);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-425, 270, -310);
        glVertex3f(-435, 270, -300);
        glVertex3f(-365, 275, -262);
        glVertex3f(-355, 275, -265);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 270, -300);
        glVertex3f(-440, 270, -295);
        glVertex3f(-365, 275, -262);
        glVertex3f(-355, 275, -265);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 270, -295);
        glVertex3f(-445, 270, -280);
        glVertex3f(-375, 275, -252);
        glVertex3f(-365, 275, -262);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 270, -280);
        glVertex3f(-446, 270, -270);
        glVertex3f(-377, 275, -245);
        glVertex3f(-375, 275, -252);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-446, 270, -270);
        glVertex3f(-447, 270, -265);
        glVertex3f(-380, 275, -222);
        glVertex3f(-377, 275, -245);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-447, 270, -265);
        glVertex3f(-444, 270, 155);
        glVertex3f(-380, 275, 115);
        glVertex3f(-380, 275, -222);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-444, 270, 155);
        glVertex3f(-442, 270, 162);
        glVertex3f(-378, 275, 125);
        glVertex3f(-380, 275, 115);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-442, 270, 162);
        glVertex3f(-440, 270, 167);
        glVertex3f(-378, 275, 125);
        glVertex3f(-380, 275, 115);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 270, 167);
        glVertex3f(-435, 270, 177);
        glVertex3f(-374, 275, 132);
        glVertex3f(-378, 275, 125);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 270, 177);
        glVertex3f(-430, 270, 185);
        glVertex3f(-370, 275, 140);
        glVertex3f(-374, 275, 132);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 270, 185);
        glVertex3f(-418, 270, 195);
        glVertex3f(-360, 275, 150);
        glVertex3f(-370, 275, 140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-418, 270, 195);
        glVertex3f(-405, 270, 203);
        glVertex3f(-345, 275, 160);
        glVertex3f(-360, 275, 150);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-405, 270, 203);
        glVertex3f(-390, 270, 207.5);
        glVertex3f(-330.0, 275, 160.5);
        glVertex3f(-345, 275, 160);
    glEnd();

//    glBegin(GL_LINE_STRIP);
//        glVertex3f(-330.0, 315, 160.5);
//        glVertex3f(197.0, 315, 160.5);
//        glVertex3f(200.0, 315, 160);
//        glVertex3f(205.0, 315, 159);
//        glVertex3f(210.0, 315, 158);
//        glVertex3f(215.0, 315, 157);
//        glVertex3f(220.0, 315, 156);
//        glVertex3f(230.0, 315, 149);
//        glVertex3f(238.0, 315, 140);
//        glVertex3f(242.0, 315, 132);
//        glVertex3f(245.0, 315, 125);
//        glVertex3f(248.0, 315, 120);
//        glVertex3f(250.0, 315, 106);
//
//        glVertex3f(250.0, 315, -177);
//        glVertex3f(248, 315, -200);
//        glVertex3f(240, 315, -230);
//        glVertex3f(230, 315, -250);
//        glVertex3f(220, 315, -260);
//        glVertex3f(210, 315, -265);
//        glVertex3f(180, 315, -270);
//
//        glVertex3f(-335, 315, -270);
//        glVertex3f(-345, 315, -268);
//        glVertex3f(-355, 315, -265);
//        glVertex3f(-365, 315, -262);
//        glVertex3f(-375, 315, -252);
//        glVertex3f(-377, 315, -245);
//        glVertex3f(-380, 315, -222);
//
//        glVertex3f(-380, 315, 115);
//        glVertex3f(-378, 315, 125);
//        glVertex3f(-374, 315, 132);
//        glVertex3f(-370, 315, 140);
//        glVertex3f(-360, 315, 150);
//        glVertex3f(-345, 315, 160);
//        glVertex3f(-330.0, 315, 160.5);
//    glEnd();

}

void dinding(){
    glLineWidth(4.0f);
    glColor3ub(255, 240, 245);

    glBegin(GL_QUADS);
        glVertex3f(-400.0, 39.99, 220.5);
        glVertex3f(267.0, 39.99, 220.5);
        glVertex3f(267.0, 230, 220.5);
        glVertex3f(-400.0, 230, 220.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(267.0, 39.99, 220.5);
        glVertex3f(270.0, 39.99, 220);
        glVertex3f(270.0, 230, 220);
        glVertex3f(267.0, 230, 220.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(270.0, 39.99, 220);
        glVertex3f(275.0, 39.99, 219);
        glVertex3f(275.0, 230, 219);
        glVertex3f(270.0, 230, 220);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 39.99, 219);
        glVertex3f(280.0, 39.99, 218);
        glVertex3f(280.0, 230, 218);
        glVertex3f(275.0, 230, 219);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280.0, 39.99, 218);
        glVertex3f(285.0, 39.99, 217);
        glVertex3f(285.0, 230, 217);
        glVertex3f(280.0, 230, 218);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(285.0, 39.99, 217);
        glVertex3f(290.0, 39.99, 216);
        glVertex3f(290.0, 230, 216);
        glVertex3f(285.0, 230, 217);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 39.99, 216);
        glVertex3f(300.0, 39.99, 209);
        glVertex3f(300.0, 230, 209);
        glVertex3f(290.0, 230, 216);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300.0, 39.99, 209);
        glVertex3f(308.0, 39.99, 200);
        glVertex3f(308.0, 230, 200);
        glVertex3f(300.0, 230, 209);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(308.0, 39.99, 200);
        glVertex3f(312.0, 39.99, 192);
        glVertex3f(312.0, 230, 192);
        glVertex3f(308.0, 230, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(312.0, 39.99, 192);
        glVertex3f(315.0, 39.99, 185);
        glVertex3f(315.0, 230, 185);
        glVertex3f(312.0, 230, 192);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 39.99, 185);
        glVertex3f(318.0, 39.99, 180);
        glVertex3f(318.0, 230, 180);
        glVertex3f(315.0, 230, 185);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(318.0, 39.99, 180);
        glVertex3f(320.0, 39.99, 166);
        glVertex3f(320.0, 230, 166);
        glVertex3f(318.0, 230, 180);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 39.99, 166);
        glVertex3f(320.0, 39.99, -237);
        glVertex3f(320.0, 230, -237);
        glVertex3f(320.0, 230, 166);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 39.99, -237);
        glVertex3f(318, 39.99, -260);
        glVertex3f(318, 230, -260);
        glVertex3f(320.0, 230, -237);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(318, 39.99, -260);
        glVertex3f(310, 39.99, -290);
        glVertex3f(310, 230, -290);
        glVertex3f(318, 230, -260);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310, 39.99, -290);
        glVertex3f(300, 39.99, -310);
        glVertex3f(300, 230, -310);
        glVertex3f(310, 230, -290);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300, 39.99, -310);
        glVertex3f(290, 39.99, -320);
        glVertex3f(290, 230, -320);
        glVertex3f(300, 230, -310);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290, 39.99, -320);
        glVertex3f(280, 39.99, -325);
        glVertex3f(280, 230, -325);
        glVertex3f(290, 230, -320);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280, 39.99, -325);
        glVertex3f(250, 39.99, -330);
        glVertex3f(250, 230, -330);
        glVertex3f(280, 230, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(250, 39.99, -330);
        glVertex3f(-385, 39.99, -330);
        glVertex3f(-385, 230, -330);
        glVertex3f(250, 230, -330);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-385, 39.99, -330);
        glVertex3f(-415, 39.99, -328);
        glVertex3f(-415, 230, -328);
        glVertex3f(-385, 230, -330);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 39.99, -328);
        glVertex3f(-425, 39.99, -325);
        glVertex3f(-425, 230, -325);
        glVertex3f(-415, 230, -328);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-425, 39.99, -325);
        glVertex3f(-435, 39.99, -322);
        glVertex3f(-435, 230, -322);
        glVertex3f(-425, 230, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 39.99, -322);
        glVertex3f(-445, 39.99, -312);
        glVertex3f(-445, 230, -312);
        glVertex3f(-435, 230, -322);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 39.99, -312);
        glVertex3f(-447, 39.99, -305);
        glVertex3f(-447, 230, -305);
        glVertex3f(-445, 230, -312);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-447, 39.99, -305);
        glVertex3f(-450, 39.99, -282);
        glVertex3f(-450, 230, -282);
        glVertex3f(-447, 230, -305);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-450, 39.99, -282);
        glVertex3f(-450, 39.99, 175);
        glVertex3f(-450, 230, 175);
        glVertex3f(-450, 230, -282);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-450, 39.99, 175);
        glVertex3f(-448, 39.99, 185);
        glVertex3f(-448, 230, 185);
        glVertex3f(-450, 230, 175);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-448, 39.99, 185);
        glVertex3f(-444, 39.99, 192);
        glVertex3f(-444, 230, 192);
        glVertex3f(-448, 230, 185);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-444, 39.99, 192);
        glVertex3f(-440, 39.99, 200);
        glVertex3f(-440, 230, 200);
        glVertex3f(-444, 230, 192);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 39.99, 200);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-430, 230, 210);
        glVertex3f(-440, 230, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-415, 39.99, 220);
        glVertex3f(-415, 230, 220);
        glVertex3f(-430, 230, 210);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 39.99, 220);
        glVertex3f(-400.0, 39.99, 220.5);
        glVertex3f(-400.0, 230, 220.5);
        glVertex3f(-415, 230, 220);
    glEnd();



//    glBegin(GL_LINE_STRIP);
//        glVertex3f(-330.0, 39.99, 160.5);
//        glVertex3f(197.0, 39.99, 160.5);
//        glVertex3f(200.0, 39.99, 160);
//        glVertex3f(205.0, 39.99, 159);
//        glVertex3f(210.0, 39.99, 158);
//        glVertex3f(215.0, 39.99, 157);
//        glVertex3f(220.0, 39.99, 156);
//        glVertex3f(230.0, 39.99, 149);
//        glVertex3f(238.0, 39.99, 140);
//        glVertex3f(242.0, 39.99, 132);
//        glVertex3f(245.0, 39.99, 125);
//        glVertex3f(248.0, 39.99, 120);
//        glVertex3f(250.0, 39.99, 106);
//
//        glVertex3f(250.0, 39.99, -177);
//        glVertex3f(248, 39.99, -200);
//        glVertex3f(240, 39.99, -230);
//        glVertex3f(230, 39.99, -250);
//        glVertex3f(220, 39.99, -260);
//        glVertex3f(210, 39.99, -265);
//        glVertex3f(180, 39.99, -270);
//
//        glVertex3f(-335, 39.99, -270);
//        glVertex3f(-345, 39.99, -268);
//        glVertex3f(-355, 39.99, -265);
//        glVertex3f(-365, 39.99, -262);
//        glVertex3f(-375, 39.99, -252);
//        glVertex3f(-377, 39.99, -245);
//        glVertex3f(-380, 39.99, -222);
//
//        glVertex3f(-380, 39.99, 115);
//        glVertex3f(-378, 39.99, 125);
//        glVertex3f(-374, 39.99, 132);
//        glVertex3f(-370, 39.99, 140);
//        glVertex3f(-360, 39.99, 150);
//        glVertex3f(-345, 39.99, 160);
//        glVertex3f(-330.0, 39.99, 160.5);
//    glEnd();
}

void bawahBangunan(){
    glColor3ub(180, 180, 180);
    glBegin(GL_QUADS);
        glVertex3f(-400.0, 39.99, 230.7);
        glVertex3f(267.0, 39.99, 230.7);
        glVertex3f(267.0, 39.99, 220.5);
        glVertex3f(-400.0, 39.99, 220.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(267.0, 39.99, 230.7);
        glVertex3f(270.0, 39.99, 230);
        glVertex3f(270.0, 39.99, 220);
        glVertex3f(267.0, 39.99, 220.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(270.0, 39.99, 230);
        glVertex3f(275.0, 39.99, 229);
        glVertex3f(275.0, 39.99, 219);
        glVertex3f(270.0, 39.99, 220);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(275.0, 39.99, 229);
        glVertex3f(280.0, 39.99, 228);
        glVertex3f(280.0, 39.99, 218);
        glVertex3f(275.0, 39.99, 219);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(280.0, 39.99, 228);
        glVertex3f(285.0, 39.99, 227);
        glVertex3f(285.0, 39.99, 217);
        glVertex3f(280.0, 39.99, 218);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(285.0, 39.99, 227);
        glVertex3f(290.0, 39.99, 226);
        glVertex3f(290.0, 39.99, 216);
        glVertex3f(285.0, 39.99, 217);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 39.99, 226);
        glVertex3f(295.0, 39.99, 223);
        glVertex3f(300.0, 39.99, 209);
        glVertex3f(290.0, 39.99, 216);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(295.0, 39.99, 223);
        glVertex3f(300.0, 39.99, 220);
        glVertex3f(308.0, 39.99, 200);
        glVertex3f(300.0, 39.99, 209);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(300.0, 39.99, 220);
        glVertex3f(305.0, 39.99, 217);
        glVertex3f(312.0, 39.99, 192);
        glVertex3f(308.0, 39.99, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 39.99, 217);
        glVertex3f(310.0, 39.99, 213);
        glVertex3f(315.0, 39.99, 185);
        glVertex3f(312.0, 39.99, 192);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(310.0, 39.99, 213);
        glVertex3f(315.0, 39.99, 209);
        glVertex3f(318.0, 39.99, 180);
        glVertex3f(315.0, 39.99, 185);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 39.99, 209);
        glVertex3f(320.0, 39.99, 204);
        glVertex3f(320.0, 39.99, 166);
        glVertex3f(318.0, 39.99, 180);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 39.99, 204);
        glVertex3f(325.0, 39.99, 198);
        glVertex3f(320.0, 39.99, 166);
        glVertex3f(318.0, 39.99, 180);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.0, 39.99, 198);
        glVertex3f(330.0, 39.99, 189);
        glVertex3f(320.0, 39.99, 166);
        glVertex3f(318.0, 39.99, 180);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330.0, 39.99, 189);
        glVertex3f(333.0, 39.99, 182);
        glVertex3f(320.0, 39.99, 166);
        glVertex3f(318.0, 39.99, 180);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(333.0, 39.99, 182);
        glVertex3f(335.0, 39.99, 177);
        glVertex3f(320.0, 39.99, 166);
        glVertex3f(318.0, 39.99, 180);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(335.0, 39.99, 177);
        glVertex3f(338.0, 39.99, 168);
        glVertex3f(320.0, 39.99, 166);
        glVertex3f(318.0, 39.99, 180);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(338.0, 39.99, 168);
        glVertex3f(340.5, 39.99, 97);
        glVertex3f(320.0, 39.99, 166);
        glVertex3f(318.0, 39.99, 180);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(340.5, 39.99, 97);
        glVertex3f(340.5, 39.99, -235);
        glVertex3f(320.0, 39.99, -237);
        glVertex3f(320.0, 39.99, 166);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(340.5, 39.99, -235);
        glVertex3f(339.0, 39.99, -250);
        glVertex3f(318, 39.99, -260);
        glVertex3f(320.0, 39.99, -237);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(339.0, 39.99, -250);
        glVertex3f(338.0, 39.99, -260);
        glVertex3f(310, 39.99, -290);
        glVertex3f(318, 39.99, -260);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(338.0, 39.99, -260);
        glVertex3f(337.0, 39.99, -270);
        glVertex3f(300, 39.99, -310);
        glVertex3f(310, 39.99, -290);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(337.0, 39.99, -270);
        glVertex3f(333.0, 39.99, -280);
        glVertex3f(290, 39.99, -320);
        glVertex3f(300, 39.99, -310);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(333.0, 39.99, -280);
        glVertex3f(330.0, 39.99, -290);
        glVertex3f(280, 39.99, -325);
        glVertex3f(290, 39.99, -320);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(330.0, 39.99, -290);
        glVertex3f(325.0, 39.99, -300);
        glVertex3f(250, 39.99, -330);
        glVertex3f(280, 39.99, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(325.0, 39.99, -300);
        glVertex3f(320.0, 39.99, -310);
        glVertex3f(250, 39.99, -330);
        glVertex3f(280, 39.99, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(320.0, 39.99, -310);
        glVertex3f(315.0, 39.99, -320);
        glVertex3f(250, 39.99, -330);
        glVertex3f(280, 39.99, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(315.0, 39.99, -320);
        glVertex3f(305.0, 39.99, -335);
        glVertex3f(250, 39.99, -330);
        glVertex3f(280, 39.99, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(305.0, 39.99, -335);
        glVertex3f(290.0, 39.99, -345);
        glVertex3f(250, 39.99, -330);
        glVertex3f(280, 39.99, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(290.0, 39.99, -345);
        glVertex3f(250.0, 39.99, -355);
        glVertex3f(250, 39.99, -330);
        glVertex3f(280, 39.99, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(250.0, 39.99, -355);
        glVertex3f(240.0, 39.99, -354.9);
        glVertex3f(250, 39.99, -330);
        glVertex3f(280, 39.99, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(240.0, 39.99, -354.9);
        glVertex3f(-330, 39.99, -354.9);
        glVertex3f(-385, 39.99, -330);
        glVertex3f(250, 39.99, -330);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-330, 39.99, -354.9);
        glVertex3f(-410, 39.99, -355);
        glVertex3f(-415, 39.99, -328);
        glVertex3f(-385, 39.99, -330);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-410, 39.99, -355);
        glVertex3f(-430, 39.99, -345);
        glVertex3f(-425, 39.99, -325);
        glVertex3f(-415, 39.99, -328);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 39.99, -345);
        glVertex3f(-445, 39.99, -335);
        glVertex3f(-435, 39.99, -322);
        glVertex3f(-425, 39.99, -325);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 39.99, -335);
        glVertex3f(-455, 39.99, -320);
        glVertex3f(-445, 39.99, -312);
        glVertex3f(-435, 39.99, -322);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-455, 39.99, -320);
        glVertex3f(-460, 39.99, -310);
        glVertex3f(-447, 39.99, -305);
        glVertex3f(-445, 39.99, -312);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 39.99, -310);
        glVertex3f(-465, 39.99, -300);
        glVertex3f(-447, 39.99, -305);
        glVertex3f(-445, 39.99, -312);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-465, 39.99, -300);
        glVertex3f(-470.5, 39.99, -290);
        glVertex3f(-447, 39.99, -305);
        glVertex3f(-445, 39.99, -312);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-470.5, 39.99, -290);
        glVertex3f(-473, 39.99, -280);
        glVertex3f(-450, 39.99, -282);
        glVertex3f(-447, 39.99, -305);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-473, 39.99, -280);
        glVertex3f(-473, 39.99, 97);
        glVertex3f(-450, 39.99, 175);
        glVertex3f(-450, 39.99, -282);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-473, 39.99, 97);
        glVertex3f(-468, 39.99, 168);
        glVertex3f(-448, 39.99, 185);
        glVertex3f(-450, 39.99, 175);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-468, 39.99, 168);
        glVertex3f(-465, 39.99, 177);
        glVertex3f(-444, 39.99, 192);
        glVertex3f(-448, 39.99, 185);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-465, 39.99, 177);
        glVertex3f(-463, 39.99, 182);
        glVertex3f(-440, 39.99, 200);
        glVertex3f(-444, 39.99, 192);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-463, 39.99, 182);
        glVertex3f(-460, 39.99, 189);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-440, 39.99, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-460, 39.99, 189);
        glVertex3f(-455, 39.99, 198);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-440, 39.99, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-455, 39.99, 198);
        glVertex3f(-450, 39.99, 204);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-440, 39.99, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-450, 39.99, 204);
        glVertex3f(-445, 39.99, 209);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-440, 39.99, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-445, 39.99, 209);
        glVertex3f(-440, 39.99, 213);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-440, 39.99, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-440, 39.99, 213);
        glVertex3f(-435, 39.99, 217);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-440, 39.99, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-435, 39.99, 217);
        glVertex3f(-430, 39.99, 220);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-440, 39.99, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-430, 39.99, 220);
        glVertex3f(-425, 39.99, 223);
        glVertex3f(-430, 39.99, 210);
        glVertex3f(-440, 39.99, 200);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-425, 39.99, 223);
        glVertex3f(-420, 39.99, 226);
        glVertex3f(-415, 39.99, 220);
        glVertex3f(-430, 39.99, 210);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-420, 39.99, 226);
        glVertex3f(-415, 39.99, 227);
        glVertex3f(-415, 39.99, 220);
        glVertex3f(-430, 39.99, 210);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-415, 39.99, 227);
        glVertex3f(-410, 39.99, 228);
        glVertex3f(-415, 39.99, 220);
        glVertex3f(-430, 39.99, 210);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-410, 39.99, 228);
        glVertex3f(-405, 39.99, 229);
        glVertex3f(-400.0, 39.99, 220.5);
        glVertex3f(-415, 39.99, 220);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-405, 39.99, 229);
        glVertex3f(-400, 39.99, 230.7);
        glVertex3f(-400.0, 39.99, 220.5);
        glVertex3f(-415, 39.99, 220);
    glEnd();
}


//LAPANGAN
void bangku1(){
    //1
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -49.0, 50.0);
        glVertex3f(110.0, -49.0, 70.0);
        glVertex3f(110.0, -39.0, 70.0);
        glVertex3f(110.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(107.0, -49.0, 50.0);
        glVertex3f(107.0, -49.0, 70.0);
        glVertex3f(107.0, -39.0, 70.0);
        glVertex3f(107.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -49.0, 70.0);
        glVertex3f(107.0, -49.0, 70.0);
        glVertex3f(107.0, -39.0, 70.0);
        glVertex3f(110.0, -39.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -49.0, 50.0);
        glVertex3f(107.0, -49.0, 50.0);
        glVertex3f(107.0, -39.0, 50.0);
        glVertex3f(110.0, -39.0, 50.0);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(75.0, -49.0, 50.0);
        glVertex3f(75.0, -49.0, 70.0);
        glVertex3f(75.0, -39.0, 70.0);
        glVertex3f(75.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(72.0, -49.0, 50.0);
        glVertex3f(72.0, -49.0, 70.0);
        glVertex3f(72.0, -39.0, 70.0);
        glVertex3f(72.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(75.0, -49.0, 70.0);
        glVertex3f(72.0, -49.0, 70.0);
        glVertex3f(72.0, -39.0, 70.0);
        glVertex3f(75.0, -39.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(75.0, -49.0, 50.0);
        glVertex3f(72.0, -49.0, 50.0);
        glVertex3f(72.0, -39.0, 50.0);
        glVertex3f(75.0, -39.0, 50.0);
    glEnd();

    //3
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(41.0, -49.0, 50.0);
        glVertex3f(41.0, -49.0, 70.0);
        glVertex3f(41.0, -39.0, 70.0);
        glVertex3f(41.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, -49.0, 50.0);
        glVertex3f(38.0, -49.0, 70.0);
        glVertex3f(38.0, -39.0, 70.0);
        glVertex3f(38.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(41.0, -49.0, 70.0);
        glVertex3f(38.0, -49.0, 70.0);
        glVertex3f(38.0, -39.0, 70.0);
        glVertex3f(41.0, -39.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(41.0, -49.0, 50.0);
        glVertex3f(38.0, -49.0, 50.0);
        glVertex3f(38.0, -39.0, 50.0);
        glVertex3f(41.0, -39.0, 50.0);
    glEnd();

    //papan duduk 1
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -39.0, 70.0);
        glVertex3f(110.0, -39.0, 50.0);
        glVertex3f(38.0, -39.0, 50.0);
        glVertex3f(38.0, -39.0, 70.0);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -41.0, 70.0);
        glVertex3f(110.0, -41.0, 50.0);
        glVertex3f(38.0, -41.0, 50.0);
        glVertex3f(38.0, -41.0, 70.0);
    glEnd();

    //kursi 1
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(108.0, -38.0, 65.0);
        glVertex3f(108.0, -38.0, 50.0);
        glVertex3f(92.0, -38.0, 50.0);
        glVertex3f(92.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(108.0, -36.0, 65.0);
        glVertex3f(108.0, -36.0, 50.0);
        glVertex3f(92.0, -36.0, 50.0);
        glVertex3f(92.0, -36.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(108.0, -36.0, 65.0);
        glVertex3f(108.0, -36.0, 50.0);
        glVertex3f(108.0, -38.0, 50.0);
        glVertex3f(108.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(92.0, -36.0, 65.0);
        glVertex3f(92.0, -36.0, 50.0);
        glVertex3f(92.0, -38.0, 50.0);
        glVertex3f(92.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(108.0, -36.0, 50.0);
        glVertex3f(108.0, -38.0, 50.0);
        glVertex3f(92.0, -38.0, 50.0);
        glVertex3f(92.0, -36.0, 50.0);
    glEnd();

    //sandaran 1
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(106.0, -14.0, 65.0);
        glVertex3f(106.0, -38.0, 65.0);
        glVertex3f(94.0, -38.0, 65.0);
        glVertex3f(94.0, -14.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(108.0, -14.0, 66.0);
        glVertex3f(108.0, -38.0, 66.0);
        glVertex3f(92.0, -38.0, 66.0);
        glVertex3f(92.0, -14.0, 66.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(108.0, -14.0, 68.0);
        glVertex3f(108.0, -38.0, 68.0);
        glVertex3f(92.0, -38.0, 68.0);
        glVertex3f(92.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(108.0, -14.0, 66.0);
        glVertex3f(108.0, -38.0, 66.0);
        glVertex3f(108.0, -38.0, 68.0);
        glVertex3f(108.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(92.0, -14.0, 66.0);
        glVertex3f(92.0, -38.0, 66.0);
        glVertex3f(92.0, -38.0, 68.0);
        glVertex3f(92.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(108.0, -14.0, 66.0);
        glVertex3f(108.0, -14.0, 68.0);
        glVertex3f(92.0, -14.0, 68.0);
        glVertex3f(92.0, -14.0, 66.0);
    glEnd();

    //sandar
    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(106.0, -9.0, 67.0);
        glVertex3f(106.0, -25.0, 67.0);
        glVertex3f(94.0, -25.0, 67.0);
        glVertex3f(94.0, -9.0, 67.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(106.0, -9.0, 67.7);
        glVertex3f(106.0, -25.0, 67.7);
        glVertex3f(94.0, -25.0, 67.7);
        glVertex3f(94.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(106.0, -9.0, 67.0);
        glVertex3f(106.0, -25.0, 67.0);
        glVertex3f(106.0, -25.0, 67.7);
        glVertex3f(106.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(94.0, -9.0, 67.0);
        glVertex3f(94.0, -25.0, 67.0);
        glVertex3f(94.0, -25.0, 67.7);
        glVertex3f(94.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(106.0, -25.0, 67.7);
        glVertex3f(106.0, -25.0, 67.0);
        glVertex3f(94.0, -25.0, 67.0);
        glVertex3f(94.0, -25.0, 67.7);
    glEnd();

    //kursi 2
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(90.0, -38.0, 65.0);
        glVertex3f(90.0, -38.0, 50.0);
        glVertex3f(74.0, -38.0, 50.0);
        glVertex3f(74.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(90.0, -36.0, 65.0);
        glVertex3f(90.0, -36.0, 50.0);
        glVertex3f(74.0, -36.0, 50.0);
        glVertex3f(74.0, -36.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(90.0, -36.0, 65.0);
        glVertex3f(90.0, -36.0, 50.0);
        glVertex3f(90.0, -38.0, 50.0);
        glVertex3f(90.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(74.0, -36.0, 65.0);
        glVertex3f(74.0, -36.0, 50.0);
        glVertex3f(74.0, -38.0, 50.0);
        glVertex3f(74.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(90.0, -36.0, 50.0);
        glVertex3f(90.0, -38.0, 50.0);
        glVertex3f(74.0, -38.0, 50.0);
        glVertex3f(74.0, -36.0, 50.0);
    glEnd();

    //sandaran 2
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(88.0, -14.0, 65.0);
        glVertex3f(88.0, -38.0, 65.0);
        glVertex3f(76.0, -38.0, 65.0);
        glVertex3f(76.0, -14.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(90.0, -14.0, 66.0);
        glVertex3f(90.0, -38.0, 66.0);
        glVertex3f(74.0, -38.0, 66.0);
        glVertex3f(74.0, -14.0, 66.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(90.0, -14.0, 68.0);
        glVertex3f(90.0, -38.0, 68.0);
        glVertex3f(74.0, -38.0, 68.0);
        glVertex3f(74.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(90.0, -14.0, 66.0);
        glVertex3f(90.0, -38.0, 66.0);
        glVertex3f(90.0, -38.0, 68.0);
        glVertex3f(90.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(74.0, -14.0, 66.0);
        glVertex3f(74.0, -38.0, 66.0);
        glVertex3f(74.0, -38.0, 68.0);
        glVertex3f(74.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(90.0, -14.0, 66.0);
        glVertex3f(90.0, -14.0, 68.0);
        glVertex3f(74.0, -14.0, 68.0);
        glVertex3f(74.0, -14.0, 66.0);
    glEnd();

    //sandar
    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(88.0, -9.0, 67.0);
        glVertex3f(88.0, -25.0, 67.0);
        glVertex3f(76.0, -25.0, 67.0);
        glVertex3f(76.0, -9.0, 67.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(88.0, -9.0, 67.7);
        glVertex3f(88.0, -25.0, 67.7);
        glVertex3f(76.0, -25.0, 67.7);
        glVertex3f(76.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(88.0, -9.0, 67.0);
        glVertex3f(88.0, -25.0, 67.0);
        glVertex3f(88.0, -25.0, 67.7);
        glVertex3f(88.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(76.0, -9.0, 67.0);
        glVertex3f(76.0, -25.0, 67.0);
        glVertex3f(76.0, -25.0, 67.7);
        glVertex3f(76.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
       glVertex3f(88.0, -25.0, 67.7);
        glVertex3f(88.0, -25.0, 67.0);
        glVertex3f(76.0, -25.0, 67.0);
        glVertex3f(76.0, -25.0, 67.7);
    glEnd();

    //kursi 3
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(72.0, -38.0, 65.0);
        glVertex3f(72.0, -38.0, 50.0);
        glVertex3f(56.0, -38.0, 50.0);
        glVertex3f(56.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(72.0, -36.0, 65.0);
        glVertex3f(72.0, -36.0, 50.0);
        glVertex3f(56.0, -36.0, 50.0);
        glVertex3f(56.0, -36.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(72.0, -36.0, 65.0);
        glVertex3f(72.0, -36.0, 50.0);
        glVertex3f(72.0, -38.0, 50.0);
        glVertex3f(72.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(56.0, -36.0, 65.0);
        glVertex3f(56.0, -36.0, 50.0);
        glVertex3f(56.0, -38.0, 50.0);
        glVertex3f(56.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(72.0, -36.0, 50.0);
        glVertex3f(72.0, -38.0, 50.0);
        glVertex3f(56.0, -38.0, 50.0);
        glVertex3f(56.0, -36.0, 50.0);
    glEnd();

    //sandaran 3
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(70.0, -14.0, 65.0);
        glVertex3f(70.0, -38.0, 65.0);
        glVertex3f(58.0, -38.0, 65.0);
        glVertex3f(58.0, -14.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(72.0, -14.0, 66.0);
        glVertex3f(72.0, -38.0, 66.0);
        glVertex3f(56.0, -38.0, 66.0);
        glVertex3f(56.0, -14.0, 66.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(72.0, -14.0, 68.0);
        glVertex3f(72.0, -38.0, 68.0);
        glVertex3f(56.0, -38.0, 68.0);
        glVertex3f(56.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(72.0, -14.0, 66.0);
        glVertex3f(72.0, -38.0, 66.0);
        glVertex3f(72.0, -38.0, 68.0);
        glVertex3f(72.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(56.0, -14.0, 66.0);
        glVertex3f(56.0, -38.0, 66.0);
        glVertex3f(56.0, -38.0, 68.0);
        glVertex3f(56.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(72.0, -14.0, 66.0);
        glVertex3f(72.0, -14.0, 68.0);
        glVertex3f(56.0, -14.0, 68.0);
        glVertex3f(56.0, -14.0, 66.0);
    glEnd();

    //sandar
    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(70.0, -9.0, 67.0);
        glVertex3f(70.0, -25.0, 67.0);
        glVertex3f(58.0, -25.0, 67.0);
        glVertex3f(58.0, -9.0, 67.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(70.0, -9.0, 67.7);
        glVertex3f(70.0, -25.0, 67.7);
        glVertex3f(58.0, -25.0, 67.7);
        glVertex3f(58.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(70.0, -9.0, 67.0);
        glVertex3f(70.0, -25.0, 67.0);
        glVertex3f(70.0, -25.0, 67.7);
        glVertex3f(70.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(58.0, -9.0, 67.0);
        glVertex3f(58.0, -25.0, 67.0);
        glVertex3f(58.0, -25.0, 67.7);
        glVertex3f(58.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(70.0, -25.0, 67.7);
        glVertex3f(70.0, -25.0, 67.0);
        glVertex3f(70.0, -25.0, 67.0);
        glVertex3f(70.0, -25.0, 67.7);
    glEnd();

    //kursi 4
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(54.0, -38.0, 65.0);
        glVertex3f(54.0, -38.0, 50.0);
        glVertex3f(38.0, -38.0, 50.0);
        glVertex3f(38.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(54.0, -36.0, 65.0);
        glVertex3f(54.0, -36.0, 50.0);
        glVertex3f(38.0, -36.0, 50.0);
        glVertex3f(38.0, -36.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(54.0, -36.0, 65.0);
        glVertex3f(54.0, -36.0, 50.0);
        glVertex3f(54.0, -38.0, 50.0);
        glVertex3f(54.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(38.0, -36.0, 65.0);
        glVertex3f(38.0, -36.0, 50.0);
        glVertex3f(38.0, -38.0, 50.0);
        glVertex3f(38.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(54.0, -36.0, 50.0);
        glVertex3f(54.0, -38.0, 50.0);
        glVertex3f(38.0, -38.0, 50.0);
        glVertex3f(38.0, -36.0, 50.0);
    glEnd();

    //sandaran 4
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(52.0, -14.0, 65.0);
        glVertex3f(52.0, -38.0, 65.0);
        glVertex3f(40.0, -38.0, 65.0);
        glVertex3f(40.0, -14.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(54.0, -14.0, 66.0);
        glVertex3f(54.0, -38.0, 66.0);
        glVertex3f(38.0, -38.0, 66.0);
        glVertex3f(38.0, -14.0, 66.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(54.0, -14.0, 68.0);
        glVertex3f(54.0, -38.0, 68.0);
        glVertex3f(38.0, -38.0, 68.0);
        glVertex3f(38.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(54.0, -14.0, 66.0);
        glVertex3f(54.0, -38.0, 66.0);
        glVertex3f(54.0, -38.0, 68.0);
        glVertex3f(54.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(38.0, -14.0, 66.0);
        glVertex3f(38.0, -38.0, 66.0);
        glVertex3f(38.0, -38.0, 68.0);
        glVertex3f(38.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(54.0, -14.0, 66.0);
        glVertex3f(54.0, -14.0, 68.0);
        glVertex3f(38.0, -14.0, 68.0);
        glVertex3f(38.0, -14.0, 66.0);
    glEnd();

    //sandar
    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(52.0, -9.0, 67.0);
        glVertex3f(52.0, -25.0, 67.0);
        glVertex3f(40.0, -25.0, 67.0);
        glVertex3f(40.0, -9.0, 67.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(52.0, -9.0, 67.7);
        glVertex3f(52.0, -25.0, 67.7);
        glVertex3f(40.0, -25.0, 67.7);
        glVertex3f(40.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(52.0, -9.0, 67.0);
        glVertex3f(52.0, -25.0, 67.0);
        glVertex3f(40.0, -25.0, 67.7);
        glVertex3f(40.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(52.0, -9.0, 67.0);
        glVertex3f(52.0, -25.0, 67.0);
        glVertex3f(52.0, -25.0, 67.7);
        glVertex3f(52.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(40.0, -25.0, 67.7);
        glVertex3f(40.0, -25.0, 67.0);
        glVertex3f(40.0, -25.0, 67.0);
        glVertex3f(40.0, -25.0, 67.7);
    glEnd();

    //tiang
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -40.0, 70.0);
        glVertex3f(108.0, -40.0, 70.0);
        glVertex3f(108.0, 5.0, 70.0);
        glVertex3f(110.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -40.0, 68.0);
        glVertex3f(108.0, -40.0, 68.0);
        glVertex3f(108.0, 5.0, 68.0);
        glVertex3f(110.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -40.0, 68.0);
        glVertex3f(110.0, -40.0, 70.0);
        glVertex3f(110.0, 5.0, 70.0);
        glVertex3f(110.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(108.0, -40.0, 68.0);
        glVertex3f(108.0, -40.0, 70.0);
        glVertex3f(108.0, 5.0, 70.0);
        glVertex3f(108.0, 5.0, 68.0);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -40.0, 52.0);
        glVertex3f(108.0, -40.0, 52.0);
        glVertex3f(108.0, 5.0, 52.0);
        glVertex3f(110.0, 5.0, 52.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -40.0, 50.0);
        glVertex3f(108.0, -40.0, 50.0);
        glVertex3f(108.0, 5.0, 50.0);
        glVertex3f(110.0, 5.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, -40.0, 50.0);
        glVertex3f(110.0, -40.0, 52.0);
        glVertex3f(110.0, 5.0, 52.0);
        glVertex3f(110.0, 5.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(108.0, -40.0, 50.0);
        glVertex3f(108.0, -40.0, 52.0);
        glVertex3f(108.0, 5.0, 52.0);
        glVertex3f(108.0, 5.0, 50.0);
    glEnd();

    //3
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(72.0, -40.0, 68.0);
        glVertex3f(76.0, -40.0, 68.0);
        glVertex3f(76.0, 5.0, 68.0);
        glVertex3f(72.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(72.0, -40.0, 70.0);
        glVertex3f(76.0, -40.0, 70.0);
        glVertex3f(76.0, 5.0, 70.0);
        glVertex3f(72.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(72.0, -40.0, 68.0);
        glVertex3f(72.0, -40.0, 70.0);
        glVertex3f(72.0, 5.0, 70.0);
        glVertex3f(72.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(76.0, -40.0, 68.0);
        glVertex3f(76.0, -40.0, 70.0);
        glVertex3f(76.0, 5.0, 70.0);
        glVertex3f(76.0, 5.0, 68.0);
    glEnd();

    //4
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, -40.0, 68.0);
        glVertex3f(40.0, -40.0, 68.0);
        glVertex3f(40.0, 5.0, 68.0);
        glVertex3f(38.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, -40.0, 70.0);
        glVertex3f(40.0, -40.0, 70.0);
        glVertex3f(40.0, 5.0, 70.0);
        glVertex3f(38.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, -40.0, 68.0);
        glVertex3f(38.0, -40.0, 70.0);
        glVertex3f(38.0, 5.0, 70.0);
        glVertex3f(38.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(40.0, -40.0, 68.0);
        glVertex3f(40.0, -40.0, 70.0);
        glVertex3f(40.0, 5.0, 70.0);
        glVertex3f(40.0, 5.0, 68.0);
    glEnd();

    //5
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, -40.0, 50.0);
        glVertex3f(40.0, -40.0, 50.0);
        glVertex3f(40.0, 5.0, 50.0);
        glVertex3f(38.0, 5.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, -40.0, 52.0);
        glVertex3f(40.0, -40.0, 52.0);
        glVertex3f(40.0, 5.0, 52.0);
        glVertex3f(38.0, 5.0, 52.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, -40.0, 50.0);
        glVertex3f(38.0, -40.0, 52.0);
        glVertex3f(38.0, 5.0, 52.0);
        glVertex3f(38.0, 5.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(40.0, -40.0, 50.0);
        glVertex3f(40.0, -40.0, 52.0);
        glVertex3f(40.0, 5.0, 52.0);
        glVertex3f(40.0, 5.0, 50.0);
    glEnd();

    //atap tempat duduk
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, 5.0, 70.0);
        glVertex3f(38.0, 5.0, 50.0);
        glVertex3f(110.0, 5.0, 50.0);
        glVertex3f(110.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, 7.0, 70.0);
        glVertex3f(38.0, 7.0, 50.0);
        glVertex3f(110.0, 7.0, 50.0);
        glVertex3f(110.0, 7.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, 5.0, 70.0);
        glVertex3f(38.0, 5.0, 50.0);
        glVertex3f(38.0, 7.0, 50.0);
        glVertex3f(38.0, 7.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(110.0, 5.0, 70.0);
        glVertex3f(110.0, 5.0, 50.0);
        glVertex3f(110.0, 7.0, 50.0);
        glVertex3f(110.0, 7.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, 5.0, 70.0);
        glVertex3f(38.0, 7.0, 70.0);
        glVertex3f(110.0, 7.0, 70.0);
        glVertex3f(110.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(38.0, 5.0, 50.0);
        glVertex3f(38.0, 7.0, 50.0);
        glVertex3f(110.0, 7.0, 50.0);
        glVertex3f(110.0, 5.0, 50.0);
    glEnd();
}

void bangku2(){
    //1
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -49.0, 50.0);
        glVertex3f(-120.0, -49.0, 70.0);
        glVertex3f(-120.0, -39.0, 70.0);
        glVertex3f(-120.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-123.0, -49.0, 50.0);
        glVertex3f(-123.0, -49.0, 70.0);
        glVertex3f(-123.0, -39.0, 70.0);
        glVertex3f(-123.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -49.0, 70.0);
        glVertex3f(-123.0, -49.0, 70.0);
        glVertex3f(-123.0, -39.0, 70.0);
        glVertex3f(-120.0, -39.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -49.0, 50.0);
        glVertex3f(-123.0, -49.0, 50.0);
        glVertex3f(-123.0, -39.0, 50.0);
        glVertex3f(-120.0, -39.0, 50.0);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-155.0, -49.0, 50.0);
        glVertex3f(-155.0, -49.0, 70.0);
        glVertex3f(-155.0, -39.0, 70.0);
        glVertex3f(-155.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-158.0, -49.0, 50.0);
        glVertex3f(-158.0, -49.0, 70.0);
        glVertex3f(-158.0, -39.0, 70.0);
        glVertex3f(-158.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-155.0, -49.0, 70.0);
        glVertex3f(-158.0, -49.0, 70.0);
        glVertex3f(-158.0, -39.0, 70.0);
        glVertex3f(-155.0, -39.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-155.0, -49.0, 50.0);
        glVertex3f(-158.0, -49.0, 50.0);
        glVertex3f(-158.0, -39.0, 50.0);
        glVertex3f(-155.0, -39.0, 50.0);
    glEnd();

    //3
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-189.0, -49.0, 50.0);
        glVertex3f(-189.0, -49.0, 70.0);
        glVertex3f(-189.0, -39.0, 70.0);
        glVertex3f(-189.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-194.0, -49.0, 50.0);
        glVertex3f(-194.0, -49.0, 70.0);
        glVertex3f(-194.0, -39.0, 70.0);
        glVertex3f(-194.0, -39.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-189.0, -49.0, 70.0);
        glVertex3f(-194.0, -49.0, 70.0);
        glVertex3f(-194.0, -39.0, 70.0);
        glVertex3f(-189.0, -39.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-189.0, -49.0, 50.0);
        glVertex3f(-194.0, -49.0, 50.0);
        glVertex3f(-194.0, -39.0, 50.0);
        glVertex3f(-189.0, -39.0, 50.0);
    glEnd();

    //papan duduk 1
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -39.0, 70.0);
        glVertex3f(-120.0, -39.0, 50.0);
        glVertex3f(-194.0, -39.0, 50.0);
        glVertex3f(-194.0, -39.0, 70.0);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -41.0, 70.0);
        glVertex3f(-120.0, -41.0, 50.0);
        glVertex3f(-194.0, -41.0, 50.0);
        glVertex3f(-194.0, -41.0, 70.0);
    glEnd();

    //kursi 1
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-122.0, -38.0, 65.0);
        glVertex3f(-122.0, -38.0, 50.0);
        glVertex3f(-138.0, -38.0, 50.0);
        glVertex3f(-138.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-122.0, -36.0, 65.0);
        glVertex3f(-122.0, -36.0, 50.0);
        glVertex3f(-138.0, -36.0, 50.0);
        glVertex3f(-138.0, -36.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-122.0, -36.0, 65.0);
        glVertex3f(-122.0, -36.0, 50.0);
        glVertex3f(-122.0, -38.0, 50.0);
        glVertex3f(-122.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-138.0, -36.0, 65.0);
        glVertex3f(-138.0, -36.0, 50.0);
        glVertex3f(-138.0, -38.0, 50.0);
        glVertex3f(-138.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-122.0, -36.0, 50.0);
        glVertex3f(-122.0, -38.0, 50.0);
        glVertex3f(-138.0, -38.0, 50.0);
        glVertex3f(-138.0, -36.0, 50.0);
    glEnd();

    //sandaran 1
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-124.0, -14.0, 65.0);
        glVertex3f(-124.0, -38.0, 65.0);
        glVertex3f(-136.0, -38.0, 65.0);
        glVertex3f(-136.0, -14.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-122.0, -14.0, 66.0);
        glVertex3f(-122.0, -38.0, 66.0);
        glVertex3f(-138.0, -38.0, 66.0);
        glVertex3f(-138.0, -14.0, 66.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-122.0, -14.0, 68.0);
        glVertex3f(-122.0, -38.0, 68.0);
        glVertex3f(-138.0, -38.0, 68.0);
        glVertex3f(-138.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-122.0, -14.0, 66.0);
        glVertex3f(-122.0, -38.0, 66.0);
        glVertex3f(-122.0, -38.0, 68.0);
        glVertex3f(-122.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-138.0, -14.0, 66.0);
        glVertex3f(-138.0, -38.0, 66.0);
        glVertex3f(-138.0, -38.0, 68.0);
        glVertex3f(-138.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-122.0, -14.0, 66.0);
        glVertex3f(-122.0, -14.0, 68.0);
        glVertex3f(-138.0, -14.0, 68.0);
        glVertex3f(-138.0, -14.0, 66.0);
    glEnd();

    //sandar
    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-124.0, -9.0, 67.0);
        glVertex3f(-124.0, -25.0, 67.0);
        glVertex3f(-136.0, -25.0, 67.0);
        glVertex3f(-136.0, -9.0, 67.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-124.0, -9.0, 67.7);
        glVertex3f(-124.0, -25.0, 67.7);
        glVertex3f(-136.0, -25.0, 67.7);
        glVertex3f(-136.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-124.0, -9.0, 67.0);
        glVertex3f(-124.0, -25.0, 67.0);
        glVertex3f(-124.0, -25.0, 67.7);
        glVertex3f(-124.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-136.0, -9.0, 67.0);
        glVertex3f(-136.0, -25.0, 67.0);
        glVertex3f(-136.0, -25.0, 67.7);
        glVertex3f(-136.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-124.0, -25.0, 67.7);
        glVertex3f(-124.0, -25.0, 67.0);
        glVertex3f(-136.0, -25.0, 67.0);
        glVertex3f(-136.0, -25.0, 67.7);
    glEnd();

    //kursi 2
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-140.0, -38.0, 65.0);
        glVertex3f(-140.0, -38.0, 50.0);
        glVertex3f(-156.0, -38.0, 50.0);
        glVertex3f(-156.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-140.0, -36.0, 65.0);
        glVertex3f(-140.0, -36.0, 50.0);
        glVertex3f(-156.0, -36.0, 50.0);
        glVertex3f(-156.0, -36.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-140.0, -36.0, 65.0);
        glVertex3f(-140.0, -36.0, 50.0);
        glVertex3f(-140.0, -38.0, 50.0);
        glVertex3f(-140.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-156.0, -36.0, 65.0);
        glVertex3f(-156.0, -36.0, 50.0);
        glVertex3f(-156.0, -38.0, 50.0);
        glVertex3f(-156.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-140.0, -36.0, 50.0);
        glVertex3f(-140.0, -38.0, 50.0);
        glVertex3f(-156.0, -38.0, 50.0);
        glVertex3f(-156.0, -36.0, 50.0);
    glEnd();

    //sandaran 2
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-142.0, -14.0, 65.0);
        glVertex3f(-142.0, -38.0, 65.0);
        glVertex3f(-154.0, -38.0, 65.0);
        glVertex3f(-154.0, -14.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-140.0, -14.0, 66.0);
        glVertex3f(-140.0, -38.0, 66.0);
        glVertex3f(-156.0, -38.0, 66.0);
        glVertex3f(-156.0, -14.0, 66.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-140.0, -14.0, 68.0);
        glVertex3f(-140.0, -38.0, 68.0);
        glVertex3f(-156.0, -38.0, 68.0);
        glVertex3f(-156.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-140.0, -14.0, 66.0);
        glVertex3f(-140.0, -38.0, 66.0);
        glVertex3f(-140.0, -38.0, 68.0);
        glVertex3f(-140.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-156.0, -14.0, 66.0);
        glVertex3f(-156.0, -38.0, 66.0);
        glVertex3f(-156.0, -38.0, 68.0);
        glVertex3f(-156.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-140.0, -14.0, 66.0);
        glVertex3f(-140.0, -14.0, 68.0);
        glVertex3f(-156.0, -14.0, 68.0);
        glVertex3f(-156.0, -14.0, 66.0);
    glEnd();

    //sandar
    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-142.0, -9.0, 67.0);
        glVertex3f(-142.0, -25.0, 67.0);
        glVertex3f(-154.0, -25.0, 67.0);
        glVertex3f(-154.0, -9.0, 67.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-142.0, -9.0, 67.7);
        glVertex3f(-142.0, -25.0, 67.7);
        glVertex3f(-154.0, -25.0, 67.7);
        glVertex3f(-154.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-142.0, -9.0, 67.0);
        glVertex3f(-142.0, -25.0, 67.0);
        glVertex3f(-142.0, -25.0, 67.7);
        glVertex3f(-142.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-154.0, -9.0, 67.0);
        glVertex3f(-154.0, -25.0, 67.0);
        glVertex3f(-154.0, -25.0, 67.7);
        glVertex3f(-154.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-142.0, -25.0, 67.7);
        glVertex3f(-142.0, -25.0, 67.0);
        glVertex3f(-154.0, -25.0, 67.0);
        glVertex3f(-154.0, -25.0, 67.7);
    glEnd();

    //kursi 3
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-158.0, -38.0, 65.0);
        glVertex3f(-158.0, -38.0, 50.0);
        glVertex3f(-174.0, -38.0, 50.0);
        glVertex3f(-174.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-158.0, -36.0, 65.0);
        glVertex3f(-158.0, -36.0, 50.0);
        glVertex3f(-174.0, -36.0, 50.0);
        glVertex3f(-174.0, -36.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-158.0, -36.0, 65.0);
        glVertex3f(-158.0, -36.0, 50.0);
        glVertex3f(-158.0, -38.0, 50.0);
        glVertex3f(-158.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-174.0, -36.0, 65.0);
        glVertex3f(-174.0, -36.0, 50.0);
        glVertex3f(-174.0, -38.0, 50.0);
        glVertex3f(-174.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-158.0, -36.0, 50.0);
        glVertex3f(-158.0, -38.0, 50.0);
        glVertex3f(-174.0, -38.0, 50.0);
        glVertex3f(-174.0, -36.0, 50.0);
    glEnd();

    //sandaran 3
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-160.0, -14.0, 65.0);
        glVertex3f(-160.0, -38.0, 65.0);
        glVertex3f(-172.0, -38.0, 65.0);
        glVertex3f(-172.0, -14.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-158.0, -14.0, 66.0);
        glVertex3f(-158.0, -38.0, 66.0);
        glVertex3f(-174.0, -38.0, 66.0);
        glVertex3f(-174.0, -14.0, 66.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-158.0, -14.0, 68.0);
        glVertex3f(-158.0, -38.0, 68.0);
        glVertex3f(-174.0, -38.0, 68.0);
        glVertex3f(-174.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-158.0, -14.0, 66.0);
        glVertex3f(-158.0, -38.0, 66.0);
        glVertex3f(-158.0, -38.0, 68.0);
        glVertex3f(-158.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-174.0, -14.0, 66.0);
        glVertex3f(-174.0, -38.0, 66.0);
        glVertex3f(-174.0, -38.0, 68.0);
        glVertex3f(-174.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-158.0, -14.0, 66.0);
        glVertex3f(-158.0, -14.0, 68.0);
        glVertex3f(-174.0, -14.0, 68.0);
        glVertex3f(-174.0, -14.0, 66.0);
    glEnd();

    //sandar
    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-160.0, -9.0, 67.0);
        glVertex3f(-160.0, -25.0, 67.0);
        glVertex3f(-172.0, -25.0, 67.0);
        glVertex3f(-172.0, -9.0, 67.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-160.0, -9.0, 67.7);
        glVertex3f(-160.0, -25.0, 67.7);
        glVertex3f(-172.0, -25.0, 67.7);
        glVertex3f(-172.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-160.0, -9.0, 67.0);
        glVertex3f(-160.0, -25.0, 67.0);
        glVertex3f(-160.0, -25.0, 67.7);
        glVertex3f(-160.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-172.0, -9.0, 67.0);
        glVertex3f(-172.0, -25.0, 67.0);
        glVertex3f(-172.0, -25.0, 67.7);
        glVertex3f(-172.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-160.0, -25.0, 67.7);
        glVertex3f(-160.0, -25.0, 67.0);
        glVertex3f(-172.0, -25.0, 67.0);
        glVertex3f(-172.0, -25.0, 67.7);
    glEnd();

    //kursi 4
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-176.0, -38.0, 65.0);
        glVertex3f(-176.0, -38.0, 50.0);
        glVertex3f(-192.0, -38.0, 50.0);
        glVertex3f(-192.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-176.0, -36.0, 65.0);
        glVertex3f(-176.0, -36.0, 50.0);
        glVertex3f(-192.0, -36.0, 50.0);
        glVertex3f(-192.0, -36.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-176.0, -36.0, 65.0);
        glVertex3f(-176.0, -36.0, 50.0);
        glVertex3f(-176.0, -38.0, 50.0);
        glVertex3f(-176.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-192.0, -36.0, 65.0);
        glVertex3f(-192.0, -36.0, 50.0);
        glVertex3f(-192.0, -38.0, 50.0);
        glVertex3f(-192.0, -38.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-176.0, -36.0, 50.0);
        glVertex3f(-176.0, -38.0, 50.0);
        glVertex3f(-192.0, -38.0, 50.0);
        glVertex3f(-192.0, -36.0, 50.0);
    glEnd();

    //sandaran 4
    glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
        glVertex3f(-178.0, -14.0, 65.0);
        glVertex3f(-178.0, -38.0, 65.0);
        glVertex3f(-190.0, -38.0, 65.0);
        glVertex3f(-190.0, -14.0, 65.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-176.0, -14.0, 66.0);
        glVertex3f(-176.0, -38.0, 66.0);
        glVertex3f(-192.0, -38.0, 66.0);
        glVertex3f(-192.0, -14.0, 66.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-176.0, -14.0, 68.0);
        glVertex3f(-176.0, -38.0, 68.0);
        glVertex3f(-192.0, -38.0, 68.0);
        glVertex3f(-192.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-176.0, -14.0, 66.0);
        glVertex3f(-176.0, -38.0, 66.0);
        glVertex3f(-176.0, -38.0, 68.0);
        glVertex3f(-176.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-192.0, -14.0, 66.0);
        glVertex3f(-192.0, -38.0, 66.0);
        glVertex3f(-192.0, -38.0, 68.0);
        glVertex3f(-192.0, -14.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205,92,92);
        glVertex3f(-176.0, -14.0, 66.0);
        glVertex3f(-176.0, -14.0, 68.0);
        glVertex3f(-192.0, -14.0, 68.0);
        glVertex3f(-192.0, -14.0, 66.0);
    glEnd();

    //sandar
    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-178.0, -9.0, 67.0);
        glVertex3f(-178.0, -25.0, 67.0);
        glVertex3f(-190.0, -25.0, 67.0);
        glVertex3f(-190.0, -9.0, 67.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-178.0, -9.0, 67.7);
        glVertex3f(-178.0, -25.0, 67.7);
        glVertex3f(-190.0, -25.0, 67.7);
        glVertex3f(-190.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-178.0, -9.0, 67.0);
        glVertex3f(-178.0, -25.0, 67.0);
        glVertex3f(-178.0, -25.0, 67.7);
        glVertex3f(-178.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
        glVertex3f(-190.0, -9.0, 67.0);
        glVertex3f(-190.0, -25.0, 67.0);
        glVertex3f(-190.0, -25.0, 67.7);
        glVertex3f(-190.0, -9.0, 67.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,128,114);
         glVertex3f(-178.0, -25.0, 67.7);
        glVertex3f(-178.0, -25.0, 67.0);
        glVertex3f(-190.0, -25.0, 67.0);
        glVertex3f(-190.0, -25.0, 67.7);
    glEnd();

    //tiang
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -40.0, 70.0);
        glVertex3f(-122.0, -40.0, 70.0);
        glVertex3f(-122.0, 5.0, 70.0);
        glVertex3f(-120.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -40.0, 68.0);
        glVertex3f(-122.0, -40.0, 68.0);
        glVertex3f(-122.0, 5.0, 68.0);
        glVertex3f(-120.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -40.0, 68.0);
        glVertex3f(-120.0, -40.0, 70.0);
        glVertex3f(-120.0, 5.0, 70.0);
        glVertex3f(-120.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-122.0, -40.0, 68.0);
        glVertex3f(-122.0, -40.0, 70.0);
        glVertex3f(-122.0, 5.0, 70.0);
        glVertex3f(-122.0, 5.0, 68.0);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -40.0, 52.0);
        glVertex3f(-122.0, -40.0, 52.0);
        glVertex3f(-122.0, 5.0, 52.0);
        glVertex3f(-120.0, 5.0, 52.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -40.0, 50.0);
        glVertex3f(-122.0, -40.0, 50.0);
        glVertex3f(-122.0, 5.0, 50.0);
        glVertex3f(-120.0, 5.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, -40.0, 50.0);
        glVertex3f(-120.0, -40.0, 52.0);
        glVertex3f(-120.0, 5.0, 52.0);
        glVertex3f(-120.0, 5.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-122.0, -40.0, 50.0);
        glVertex3f(-122.0, -40.0, 52.0);
        glVertex3f(-122.0, 5.0, 52.0);
        glVertex3f(-122.0, 5.0, 50.0);
    glEnd();

    //3
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-156.0, -40.0, 68.0);
        glVertex3f(-158.0, -40.0, 68.0);
        glVertex3f(-158.0, 5.0, 68.0);
        glVertex3f(-156.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-156.0, -40.0, 70.0);
        glVertex3f(-158.0, -40.0, 70.0);
        glVertex3f(-158.0, 5.0, 70.0);
        glVertex3f(-156.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-156.0, -40.0, 68.0);
        glVertex3f(-156.0, -40.0, 70.0);
        glVertex3f(-156.0, 5.0, 70.0);
        glVertex3f(-156.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-158.0, -40.0, 68.0);
        glVertex3f(-158.0, -40.0, 70.0);
        glVertex3f(-158.0, 5.0, 70.0);
        glVertex3f(-158.0, 5.0, 68.0);
    glEnd();

    //4
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-192.0, -40.0, 68.0);
        glVertex3f(-194.0, -40.0, 68.0);
        glVertex3f(-194.0, 5.0, 68.0);
        glVertex3f(-192.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-192.0, -40.0, 70.0);
        glVertex3f(-194.0, -40.0, 70.0);
        glVertex3f(-194.0, 5.0, 70.0);
        glVertex3f(-192.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-192.0, -40.0, 68.0);
        glVertex3f(-192.0, -40.0, 70.0);
        glVertex3f(-192.0, 5.0, 70.0);
        glVertex3f(-192.0, 5.0, 68.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-194.0, -40.0, 68.0);
        glVertex3f(-194.0, -40.0, 70.0);
        glVertex3f(-194.0, 5.0, 70.0);
        glVertex3f(-194.0, 5.0, 68.0);
    glEnd();

    //5
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-192.0, -40.0, 50.0);
        glVertex3f(-194.0, -40.0, 50.0);
        glVertex3f(-194.0, 5.0, 50.0);
        glVertex3f(-192.0, 5.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-192.0, -40.0, 52.0);
        glVertex3f(-194.0, -40.0, 52.0);
        glVertex3f(-194.0, 5.0, 52.0);
        glVertex3f(-192.0, 5.0, 52.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-192.0, -40.0, 50.0);
        glVertex3f(-192.0, -40.0, 52.0);
        glVertex3f(-192.0, 5.0, 52.0);
        glVertex3f(-192.0, 5.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-194.0, -40.0, 50.0);
        glVertex3f(-194.0, -40.0, 52.0);
        glVertex3f(-194.0, 5.0, 52.0);
        glVertex3f(-194.0, 5.0, 50.0);
    glEnd();

    //atap tempat duduk
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, 5.0, 70.0);
        glVertex3f(-120.0, 5.0, 50.0);
        glVertex3f(-194.0, 5.0, 50.0);
        glVertex3f(-194.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, 7.0, 70.0);
        glVertex3f(-120.0, 7.0, 50.0);
        glVertex3f(-194.0, 7.0, 50.0);
        glVertex3f(-194.0, 7.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, 5.0, 70.0);
        glVertex3f(-120.0, 5.0, 50.0);
        glVertex3f(-120.0, 7.0, 50.0);
        glVertex3f(-120.0, 7.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-194.0, 5.0, 70.0);
        glVertex3f(-194.0, 5.0, 50.0);
        glVertex3f(-194.0, 7.0, 50.0);
        glVertex3f(-194.0, 7.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, 5.0, 70.0);
        glVertex3f(-120.0, 7.0, 70.0);
        glVertex3f(-194.0, 7.0, 70.0);
        glVertex3f(-194.0, 5.0, 70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
        glVertex3f(-120.0, 5.0, 50.0);
        glVertex3f(-120.0, 7.0, 50.0);
        glVertex3f(-194.0, 7.0, 50.0);
        glVertex3f(-194.0, 5.0, 50.0);
    glEnd();
}

//BATAS LAPANGAN
void bataslapangan(){
    glBegin(GL_POLYGON);
    glColor3ub(75,0,130);
        glVertex3f(-320.0, -49.5, -240.0);
        glVertex3f(190.0, -49.5, -240.0);
        glVertex3f(190.0, 0.0, -240.0);
        glVertex3f(-320.0, 0.0, -240.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,0,130);
        glVertex3f(-320.0, -49.5, 110.0);
        glVertex3f(190.0, -49.5, 110.0);
        glVertex3f(190.0, 0.0, 110.0);
        glVertex3f(-320.0, 0.0, 110.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,0,130);
        glVertex3f(-320.0, -49.5, -240.0);
        glVertex3f(-320.0, -49.5, 110.0);
        glVertex3f(-320.0, 0.0, 110.0);
        glVertex3f(-320.0, 0.0, -240.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,0,130);
        glVertex3f(190.0, -49.5, -240.0);
        glVertex3f(190.0, -49.5, 110.0);
        glVertex3f(190.0, 0.0, 110.0);
        glVertex3f(190.0, 0.0, -240.0);
    glEnd();
}

//LAPANGAN
void lapangan(){
    glBegin(GL_POLYGON);
    glColor3ub(0,100,0);
        glVertex3f(-320.0, -49.5, 110.0);
        glVertex3f(190.0, -49.5, 110.0);
        glVertex3f(190.0, -49.5, -240.0);
        glVertex3f(-320.0, -49.5, -240.0);
    glEnd();

    //LAPANGAN GARIS
    glBegin(GL_POLYGON);
    glColor3ub(34,139,34);
        glVertex3f(-230.0, -49.4, 110.0);
        glVertex3f(-190.0, -49.4, 110.0);
        glVertex3f(-190.0, -49.4, -240.0);
        glVertex3f(-230.0, -49.4, -240.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34,139,34);
        glVertex3f(-160.0, -49.4, 110.0);
        glVertex3f(-120.0, -49.4, 110.0);
        glVertex3f(-120.0, -49.4, -240.0);
        glVertex3f(-160.0, -49.4, -240.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34,139,34);
        glVertex3f(-90.0, -49.4, 110.0);
        glVertex3f(-50.0, -49.4, 110.0);
        glVertex3f(-50.0, -49.4, -240.0);
        glVertex3f(-90.0, -49.4, -240.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34,139,34);
        glVertex3f(-20.0, -49.4, 110.0);
        glVertex3f(20.0, -49.4, 110.0);
        glVertex3f(20.0, -49.4, -240.0);
        glVertex3f(-20.0, -49.4, -240.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34,139,34);
        glVertex3f(60.0, -49.4, 110.0);
        glVertex3f(100.0, -49.4, 110.0);
        glVertex3f(100.0, -49.4, -240.0);
        glVertex3f(60.0, -49.4, -240.0);
    glEnd();

    //GARIS TEPI LAPANGAN
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -49.3, 30.0);
        glVertex3f(130.0, -49.3, 30.0);
        glVertex3f(130.0, -49.3, -160.0);
        glVertex3f(-260.0, -49.3, -160.0);
    glEnd();

    //TENGAH
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-60.0, -49.3, 30.0);
        glVertex3f(-60.0, -49.3, -160.0);
    glEnd();

    //lingkaran
    glColor3ub(255,255,255);
    lingkaran(15, 1000, -60, -65);

    //kiri
    glColor3ub(255,255,255);
    setlingkaran1(15, 1000, -210, -65);

    //kanan
    glColor3ub(255,255,255);
    setlingkaran2(15, 1000, 80, -65);

    // GARIS GAWANG KIRI
    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -49.3, -10.0);
        glVertex3f(-210.0, -49.3, -10.0);
        glVertex3f(-210.0, -49.3, -120.0);
        glVertex3f(-260.0, -49.3, -120.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -49.3, -30.0);
        glVertex3f(-230.0, -49.3, -30.0);
        glVertex3f(-230.0, -49.3, -100.0);
        glVertex3f(-260.0, -49.3, -100.0);
    glEnd();

    //GARIS GAWANG KANAN
    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -49.3, -10.0);
        glVertex3f(80.0, -49.3, -10.0);
        glVertex3f(80.0, -49.3, -120.0);
        glVertex3f(130.0, -49.3, -120.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -49.3, -30.0);
        glVertex3f(100.0, -49.3, -30.0);
        glVertex3f(100.0, -49.3, -100.0);
        glVertex3f(130.0, -49.3, -100.0);
    glEnd();

    //GAWANG KIRI 1
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, 10.0, -30.0);
        glVertex3f(-260.0, -49.3, -30.0);
        glVertex3f(-280.0, -49.3, -30.0);
        glVertex3f(-268.0, 10.0, -30.0);
    glEnd();

    //GAWANG KIRI 2
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, 10.0, -100.0);
        glVertex3f(-260.0, -49.3, -100.0);
        glVertex3f(-280.0, -49.3, -100.0);
        glVertex3f(-268.0, 10.0, -100.0);
    glEnd();

    //GAWANG KANAN 1
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
        glVertex3f(130.0, 10.0, -30.0);
        glVertex3f(130.0, -49.3, -30.0);
        glVertex3f(150.0, -49.3, -30.0);
        glVertex3f(138.0, 10.0, -30.0);
    glEnd();

    //GAWANG KANAN 2
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
        glVertex3f(130.0, 10.0, -100.0);
        glVertex3f(130.0, -49.3, -100.0);
        glVertex3f(150.0, -49.3, -100.0);
        glVertex3f(138.0, 10.0, -100.0);
    glEnd();
}

//JARING KIRI
void jaringkiri(){
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -30.0);
        glVertex3f(-280.0, -49.3, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-278.6, -44.6, -30.0);
        glVertex3f(-278.6, -44.6, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-277.7, -39.9, -30.0);
        glVertex3f(-277.7, -39.9, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-276.8, -35.2, -30.0);
        glVertex3f(-276.8, -35.2, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-275.8, -30.5, -30.0);
        glVertex3f(-275.8, -30.5, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-275.0, -25.8, -30.0);
        glVertex3f(-275.0, -25.8, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-274.0, -21.1, -30.0);
        glVertex3f(-274.0, -21.1, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-273.4, -16.3, -30.0);
        glVertex3f(-273.4, -16.3, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-272.1, -11.6, -30.0);
        glVertex3f(-272.1, -11.6, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-271.2, -6.9, -30.0);
        glVertex3f(-271.2, -6.9, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-270.5, -2.2, -30.0);
        glVertex3f(-270.5, -2.2, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-269.5, 2.5, -30.0);
        glVertex3f(-269.5, 2.5, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-268.5, 6.9, -30.0);
        glVertex3f(-268.5, 6.9, -100.0);
    glEnd();

    //KIRI BLKG
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-265.0, 10.0, -100.0);
        glVertex3f(-265.0, -49.3, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-270.0, 0.0, -100.0);
        glVertex3f(-270.0, -49.3, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-275.0, -25.0, -100.0);
        glVertex3f(-275.0, -49.3, -100.0);
    glEnd();

    //KIRI DPN
   glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-265.0, 10.0, -30.0);
        glVertex3f(-265.0, -49.3, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-270.0, 0.0, -30.0);
        glVertex3f(-270.0, -49.3, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-275.0, -25.0, -30.0);
        glVertex3f(-275.0, -49.3, -30.0);
    glEnd();

    //JARING KIRI LURUS
    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -35.0);
        glVertex3f(-274.0, -21.1, -35.0);
        glVertex3f(-273.4, -16.3, -35.0);
        glVertex3f(-269.5, 2.5, -35.0);
        glVertex3f(-268.5, 6.9, -35.0);
        glVertex3f(-265.0, 10.0, -35.0);
        glVertex3f(-260.0, 10.0, -35.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -40.0);
        glVertex3f(-274.0, -21.1, -40.0);
        glVertex3f(-273.4, -16.3, -40.0);
        glVertex3f(-269.5, 2.5, -40.0);
        glVertex3f(-268.5, 6.9, -40.0);
        glVertex3f(-265.0, 10.0, -40.0);
        glVertex3f(-260.0, 10.0, -40.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -45.0);
        glVertex3f(-274.0, -21.1, -45.0);
        glVertex3f(-273.4, -16.3, -45.0);
        glVertex3f(-269.5, 2.5, -45.0);
        glVertex3f(-268.5, 6.9, -45.0);
        glVertex3f(-265.0, 10.0, -45.0);
        glVertex3f(-260.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -50.0);
        glVertex3f(-274.0, -21.1, -50.0);
        glVertex3f(-273.4, -16.3, -50.0);
        glVertex3f(-269.5, 2.5, -50.0);
        glVertex3f(-268.5, 6.9, -50.0);
        glVertex3f(-265.0, 10.0, -50.0);
        glVertex3f(-260.0, 10.0, -50.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -55.0);
        glVertex3f(-274.0, -21.1, -55.0);
        glVertex3f(-273.4, -16.3, -55.0);
        glVertex3f(-269.5, 2.5, -55.0);
        glVertex3f(-268.5, 6.9, -55.0);
        glVertex3f(-265.0, 10.0, -55.0);
        glVertex3f(-260.0, 10.0, -55.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -60.0);
        glVertex3f(-274.0, -21.1, -60.0);
        glVertex3f(-273.4, -16.3, -60.0);
        glVertex3f(-269.5, 2.5, -60.0);
        glVertex3f(-268.5, 6.9, -60.0);
        glVertex3f(-265.0, 10.0, -60.0);
        glVertex3f(-260.0, 10.0, -60.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -65.0);
        glVertex3f(-274.0, -21.1, -65.0);
        glVertex3f(-273.4, -16.3, -65.0);
        glVertex3f(-269.5, 2.5, -65.0);
        glVertex3f(-268.5, 6.9, -65.0);
        glVertex3f(-265.0, 10.0, -65.0);
        glVertex3f(-260.0, 10.0, -65.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -70.0);
        glVertex3f(-274.0, -21.1, -70.0);
        glVertex3f(-273.4, -16.3, -70.0);
        glVertex3f(-269.5, 2.5, -70.0);
        glVertex3f(-268.5, 6.9, -70.0);
        glVertex3f(-265.0, 10.0, -70.0);
        glVertex3f(-260.0, 10.0, -70.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -75.0);
        glVertex3f(-274.0, -21.1, -75.0);
        glVertex3f(-273.4, -16.3, -75.0);
        glVertex3f(-269.5, 2.5, -75.0);
        glVertex3f(-268.5, 6.9, -75.0);
        glVertex3f(-265.0, 10.0, -75.0);
        glVertex3f(-260.0, 10.0, -75.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -80.0);
        glVertex3f(-274.0, -21.1, -80.0);
        glVertex3f(-273.4, -16.3, -80.0);
        glVertex3f(-269.5, 2.5, -80.0);
        glVertex3f(-268.5, 6.9, -80.0);
        glVertex3f(-265.0, 10.0, -80.0);
        glVertex3f(-260.0, 10.0, -80.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -85.0);
        glVertex3f(-274.0, -21.1, -85.0);
        glVertex3f(-273.4, -16.3, -85.0);
        glVertex3f(-269.5, 2.5, -85.0);
        glVertex3f(-268.5, 6.9, -85.0);
        glVertex3f(-265.0, 10.0, -85.0);
        glVertex3f(-260.0, 10.0, -85.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -90.0);
        glVertex3f(-274.0, -21.1, -90.0);
        glVertex3f(-273.4, -16.3, -90.0);
        glVertex3f(-269.5, 2.5, -90.0);
        glVertex3f(-268.5, 6.9, -90.0);
        glVertex3f(-265.0, 10.0, -90.0);
        glVertex3f(-260.0, 10.0, -90.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-280.0, -49.3, -95.0);
        glVertex3f(-274.0, -21.1, -95.0);
        glVertex3f(-273.4, -16.3, -95.0);
        glVertex3f(-269.5, 2.5, -95.0);
        glVertex3f(-268.5, 6.9, -95.0);
        glVertex3f(-265.0, 10.0, -95.0);
        glVertex3f(-260.0, 10.0, -95.0);
    glEnd();

    //atas
    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, 10.0, -30.0);
        glVertex3f(-260.0, 10.0, -100.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(-265.0, 10.0, -30.0);
        glVertex3f(-265.0, 10.0, -100.0);
    glEnd();

    //BLKG
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -42.0, -100.0);
        glVertex3f(-278.0, -42.0, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -34.7, -100.0);
        glVertex3f(-277.0, -34.7, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -27.4, -100.0);
        glVertex3f(-276.0, -27.4, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -20.1, -100.0);
        glVertex3f(-274.0, -20.1, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -12.8, -100.0);
        glVertex3f(-273.0, -12.8, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -5.5, -100.0);
        glVertex3f(-271.0, -5.5, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, 1.8, -100.0);
        glVertex3f(-269.0, 1.8, -100.0);
    glEnd();

    //DPN
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -42.0, -30.0);
        glVertex3f(-278.0, -42.0, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -34.7, -30.0);
        glVertex3f(-277.0, -34.7, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -27.4, -30.0);
        glVertex3f(-276.0, -27.4, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -20.1, -30.0);
        glVertex3f(-274.0, -20.1, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -12.8, -30.0);
        glVertex3f(-273.0, -12.8, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, -5.5, -30.0);
        glVertex3f(-271.0, -5.5, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-260.0, 1.8, -30.0);
        glVertex3f(-269.0, 1.8, -30.0);
    glEnd();
}

//JARING KANAN
void jaringkanan(){
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -30.0);
        glVertex3f(150.0, -49.3, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(148.6, -44.6, -30.0);
        glVertex3f(148.6, -44.6, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(147.7, -39.9, -30.0);
        glVertex3f(147.7, -39.9, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(146.8, -35.2, -30.0);
        glVertex3f(146.8, -35.2, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(145.8, -30.5, -30.0);
        glVertex3f(145.8, -30.5, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(145.0, -25.8, -30.0);
        glVertex3f(145.0, -25.8, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(144.0, -21.1, -30.0);
        glVertex3f(144.0, -21.1, -100.0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(143.4, -16.3, -30.0);
        glVertex3f(143.4, -16.3, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(142.1, -11.6, -30.0);
        glVertex3f(142.1, -11.6, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(141.2, -6.9, -30.0);
        glVertex3f(141.2, -6.9, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(140.5, -2.2, -30.0);
        glVertex3f(140.5, -2.2, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(139.5, 2.5, -30.0);
        glVertex3f(139.5, 2.5, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(138.5, 6.9, -30.0);
        glVertex3f(138.5, 6.9, -100.0);
    glEnd();

    //KANAN BLKG
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(135.0, 10.0, -100.0);
        glVertex3f(135.0, -49.3, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(140.0, 0.0, -100.0);
        glVertex3f(140.0, -49.3, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(145.0, -25.0, -100.0);
        glVertex3f(145.0, -49.3, -100.0);
    glEnd();

    //KANAN DPN
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(135.0, 10.0, -30.0);
        glVertex3f(135.0, -49.3, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(140.0, 0.0, -30.0);
        glVertex3f(140.0, -49.3, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(145.0, -25.0, -30.0);
        glVertex3f(145.0, -49.3, -30.0);
    glEnd();

    //JARING KANAN LURUS
    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -35.0);
        glVertex3f(144.0, -21.1, -35.0);
        glVertex3f(143.4, -16.3, -35.0);
        glVertex3f(139.5, 2.5, -35.0);
        glVertex3f(138.5, 6.9, -35.0);
        glVertex3f(135.0, 10.0, -35.0);
        glVertex3f(130.0, 10.0, -35.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -40.0);
        glVertex3f(144.0, -21.1, -40.0);
        glVertex3f(143.4, -16.3, -40.0);
        glVertex3f(139.5, 2.5, -40.0);
        glVertex3f(138.5, 6.9, -40.0);
        glVertex3f(135.0, 10.0, -40.0);
        glVertex3f(130.0, 10.0, -40.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -45.0);
        glVertex3f(144.0, -21.1, -45.0);
        glVertex3f(143.4, -16.3, -45.0);
        glVertex3f(139.5, 2.5, -45.0);
        glVertex3f(138.5, 6.9, -45.0);
        glVertex3f(135.0, 10.0, -45.0);
        glVertex3f(130.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -50.0);
        glVertex3f(144.0, -21.1, -50.0);
        glVertex3f(143.4, -16.3, -50.0);
        glVertex3f(139.5, 2.5, -50.0);
        glVertex3f(138.5, 6.9, -50.0);
        glVertex3f(135.0, 10.0, -50.0);
        glVertex3f(130.0, 10.0, -50.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -55.0);
        glVertex3f(144.0, -21.1, -55.0);
        glVertex3f(143.4, -16.3, -55.0);
        glVertex3f(139.5, 2.5, -55.0);
        glVertex3f(138.5, 6.9, -55.0);
        glVertex3f(135.0, 10.0, -55.0);
        glVertex3f(130.0, 10.0, -55.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -60.0);
        glVertex3f(144.0, -21.1, -60.0);
        glVertex3f(143.4, -16.3, -60.0);
        glVertex3f(139.5, 2.5, -60.0);
        glVertex3f(138.5, 6.9, -60.0);
        glVertex3f(135.0, 10.0, -60.0);
        glVertex3f(130.0, 10.0, -60.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -65.0);
        glVertex3f(144.0, -21.1, -65.0);
        glVertex3f(143.4, -16.3, -65.0);
        glVertex3f(139.5, 2.5, -65.0);
        glVertex3f(138.5, 6.9, -65.0);
        glVertex3f(135.0, 10.0, -65.0);
        glVertex3f(130.0, 10.0, -65.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -70.0);
        glVertex3f(144.0, -21.1, -70.0);
        glVertex3f(143.4, -16.3, -70.0);
        glVertex3f(139.5, 2.5, -70.0);
        glVertex3f(138.5, 6.9, -70.0);
        glVertex3f(135.0, 10.0, -70.0);
        glVertex3f(130.0, 10.0, -70.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -75.0);
        glVertex3f(144.0, -21.1, -75.0);
        glVertex3f(143.4, -16.3, -75.0);
        glVertex3f(139.5, 2.5, -75.0);
        glVertex3f(138.5, 6.9, -75.0);
        glVertex3f(135.0, 10.0, -75.0);
        glVertex3f(130.0, 10.0, -75.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -80.0);
        glVertex3f(144.0, -21.1, -80.0);
        glVertex3f(143.4, -16.3, -80.0);
        glVertex3f(139.5, 2.5, -80.0);
        glVertex3f(138.5, 6.9, -80.0);
        glVertex3f(135.0, 10.0, -80.0);
        glVertex3f(130.0, 10.0, -80.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -85.0);
        glVertex3f(144.0, -21.1, -85.0);
        glVertex3f(143.4, -16.3, -85.0);
        glVertex3f(139.5, 2.5, -85.0);
        glVertex3f(138.5, 6.9, -85.0);
        glVertex3f(135.0, 10.0, -85.0);
        glVertex3f(130.0, 10.0, -85.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -90.0);
        glVertex3f(144.0, -21.1, -90.0);
        glVertex3f(143.4, -16.3, -90.0);
        glVertex3f(139.5, 2.5, -90.0);
        glVertex3f(138.5, 6.9, -90.0);
        glVertex3f(135.0, 10.0, -90.0);
        glVertex3f(130.0, 10.0, -90.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(150.0, -49.3, -95.0);
        glVertex3f(144.0, -21.1, -95.0);
        glVertex3f(143.4, -16.3, -95.0);
        glVertex3f(139.5, 2.5, -95.0);
        glVertex3f(138.5, 6.9, -95.0);
        glVertex3f(135.0, 10.0, -95.0);
        glVertex3f(130.0, 10.0, -95.0);
    glEnd();

    //atas
    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(130.0, 10.0, -30.0);
        glVertex3f(130.0, 10.0, -100.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
        glVertex3f(135.0, 10.0, -30.0);
        glVertex3f(135.0, 10.0, -100.0);
    glEnd();

    //BLKG
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -42.0, -100.0);
        glVertex3f(148.0, -42.0, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -34.7, -100.0);
        glVertex3f(147.0, -34.7, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -27.4, -100.0);
        glVertex3f(146.0, -27.4, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -20.1, -100.0);
        glVertex3f(144.0, -20.1, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -12.8, -100.0);
        glVertex3f(143.0, -12.8, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -5.5, -100.0);
        glVertex3f(141.0, -5.5, -100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, 1.8, -100.0);
        glVertex3f(139.0, 1.8, -100.0);
    glEnd();

    //DPN
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -42.0, -30.0);
        glVertex3f(148.0, -42.0, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -34.7, -30.0);
        glVertex3f(147.0, -34.7, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -27.4, -30.0);
        glVertex3f(146.0, -27.4, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -20.1, -30.0);
        glVertex3f(144.0, -20.1, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -12.8, -30.0);
        glVertex3f(143.0, -12.8, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, -5.5, -30.0);
        glVertex3f(141.0, -5.5, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(130.0, 1.8, -30.0);
        glVertex3f(139.0, 1.8, -30.0);
    glEnd();
}

//PAPAN IKLAN SPONSOR
void papansponsor(){
    //UEFA
    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(117.0, -49.3, -180.0);
        glVertex3f(60.0, -49.3, -180.0);
        glVertex3f(60.0, -24.0, -180.0);
        glVertex3f(117.0, -24.0, -180.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(117.0, -49.3, -185.0);
        glVertex3f(60.0, -49.3, -185.0);
        glVertex3f(60.0, -24.0, -185.0);
        glVertex3f(117.0, -24.0, -185.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(60.0, -49.3, -180.0);
        glVertex3f(60.0, -49.3, -185.0);
        glVertex3f(60.0, -24.0, -185.0);
        glVertex3f(60.0, -24.0, -180.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(117.0, -49.3, -180.0);
        glVertex3f(117.0, -49.3, -185.0);
        glVertex3f(117.0, -24.0, -185.0);
        glVertex3f(117.0, -24.0, -180.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(117.0, -49.3, -180.0);
        glVertex3f(117.0, -49.3, -185.0);
        glVertex3f(60.0, -24.0, -185.0);
        glVertex3f(60.0, -24.0, -180.0);
    glEnd();

    //tulisan U
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(65.0, -38.0, -179.5);
        glVertex3f(65.0, -28.0, -179.5);
        glVertex3f(66.0, -28.0, -179.5);
        glVertex3f(66.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(66.0, -37.0, -179.5);
        glVertex3f(66.0, -38.0, -179.5);
        glVertex3f(70.0, -38.0, -179.5);
        glVertex3f(70.0, -37.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(70.0, -38.0, -179.5);
        glVertex3f(70.0, -28.0, -179.5);
        glVertex3f(71.0, -28.0, -179.5);
        glVertex3f(71.0, -38.0, -179.5);
    glEnd();

    //E
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(73.0, -38.0, -179.5);
        glVertex3f(73.0, -28.0, -179.5);
        glVertex3f(74.0, -28.0, -179.5);
        glVertex3f(74.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(74.0, -37.0, -179.5);
        glVertex3f(74.0, -38.0, -179.5);
        glVertex3f(78.0, -38.0, -179.5);
        glVertex3f(78.0, -37.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(74.0, -32.5, -179.5);
        glVertex3f(74.0, -34.0, -179.5);
        glVertex3f(78.0, -34.0, -179.5);
        glVertex3f(78.0, -32.5, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(74.0, -28.0, -179.5);
        glVertex3f(74.0, -29.0, -179.5);
        glVertex3f(78.0, -29.0, -179.5);
        glVertex3f(78.0, -28.0, -179.5);
    glEnd();

    //F
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(80.0, -38.0, -179.5);
        glVertex3f(80.0, -28.0, -179.5);
        glVertex3f(81.0, -28.0, -179.5);
        glVertex3f(81.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(81.0, -28.0, -179.5);
        glVertex3f(81.0, -29.0, -179.5);
        glVertex3f(85.0, -29.0, -179.5);
        glVertex3f(85.0, -28.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(81.0, -32.5, -179.5);
        glVertex3f(81.0, -34.0, -179.5);
        glVertex3f(85.0, -34.0, -179.5);
        glVertex3f(85.0, -32.5, -179.5);
    glEnd();

    //A
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(87.0, -38.0, -179.5);
        glVertex3f(87.0, -28.0, -179.5);
        glVertex3f(88.0, -28.0, -179.5);
        glVertex3f(88.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(87.0, -28.0, -179.5);
        glVertex3f(88.0, -30.0, -179.5);
        glVertex3f(92.0, -30.0, -179.5);
        glVertex3f(92.0, -28.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(87.0, -34.0, -179.5);
        glVertex3f(87.0, -35.0, -179.5);
        glVertex3f(92.0, -35.0, -179.5);
        glVertex3f(92.0, -34.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(92.0, -38.0, -179.5);
        glVertex3f(92.0, -28.0, -179.5);
        glVertex3f(93.0, -28.0, -179.5);
        glVertex3f(93.0, -38.0, -179.5);
    glEnd();

    //.com
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(95.0, -38.0, -179.5);
        glVertex3f(95.0, -37.0, -179.5);
        glVertex3f(96.0, -37.0, -179.5);
        glVertex3f(96.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(97.0, -38.0, -179.5);
        glVertex3f(97.0, -33.0, -179.5);
        glVertex3f(98.0, -33.0, -179.5);
        glVertex3f(98.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(98.0, -34.0, -179.5);
        glVertex3f(98.0, -33.0, -179.5);
        glVertex3f(99.0, -33.0, -179.5);
        glVertex3f(99.0, -34.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(98.0, -38.0, -179.5);
        glVertex3f(98.0, -37.0, -179.5);
        glVertex3f(99.0, -37.0, -179.5);
        glVertex3f(99.0, -38.0, -179.5);
    glEnd();

    //o
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(100.0, -38.0, -179.5);
        glVertex3f(100.0, -33.0, -179.5);
        glVertex3f(101.0, -33.0, -179.5);
        glVertex3f(101.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(101.0, -34.0, -179.5);
        glVertex3f(101.0, -33.0, -179.5);
        glVertex3f(103.0, -33.0, -179.5);
        glVertex3f(103.0, -34.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(101.0, -38.0, -179.5);
        glVertex3f(101.0, -37.0, -179.5);
        glVertex3f(103.0, -37.0, -179.5);
        glVertex3f(103.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(103.0, -38.0, -179.5);
        glVertex3f(103.0, -33.0, -179.5);
        glVertex3f(104.0, -33.0, -179.5);
        glVertex3f(104.0, -38.0, -179.5);
    glEnd();

    //m
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(105.0, -38.0, -179.5);
        glVertex3f(105.0, -33.0, -179.5);
        glVertex3f(106.0, -33.0, -179.5);
        glVertex3f(106.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(108.0, -38.0, -179.5);
        glVertex3f(108.0, -33.0, -179.5);
        glVertex3f(109.0, -33.0, -179.5);
        glVertex3f(109.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(111.0, -38.0, -179.5);
        glVertex3f(111.0, -33.0, -179.5);
        glVertex3f(112.0, -33.0, -179.5);
        glVertex3f(112.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(106.0, -34.0, -179.5);
        glVertex3f(106.0, -33.0, -179.5);
        glVertex3f(108.0, -33.0, -179.5);
        glVertex3f(108.0, -34.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(109.0, -34.0, -179.5);
        glVertex3f(109.0, -33.0, -179.5);
        glVertex3f(111.0, -33.0, -179.5);
        glVertex3f(111.0, -34.0, -179.5);
    glEnd();

    //IKLAN
    glBegin(GL_POLYGON);
    glColor3ub(0,0,139);
        glVertex3f(40.0, -49.3, -180.0);
        glVertex3f(-29.0, -49.3, -180.0);
        glVertex3f(-29.0, -25.0, -180.0);
        glVertex3f(40.0, -25.0, -180.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,139);
        glVertex3f(40.0, -49.3, -185.0);
        glVertex3f(-29.0, -49.3, -185.0);
        glVertex3f(-29.0, -25.0, -185.0);
        glVertex3f(40.0, -25.0, -185.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,139);
        glVertex3f(-29.0, -49.3, -180.0);
        glVertex3f(-29.0, -49.3, -185.0);
        glVertex3f(-29.0, -25.0, -185.0);
        glVertex3f(-29.0, -25.0, -185.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,139);
        glVertex3f(40.0, -49.3, -180.0);
        glVertex3f(40.0, -49.3, -185.0);
        glVertex3f(40.0, -25.0, -185.0);
        glVertex3f(40.0, -25.0, -180.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,139);
        glVertex3f(40.0, -25.0, -180.0);
        glVertex3f(40.0, -25.0, -185.0);
        glVertex3f(-29.0, -25.0, -185.0);
        glVertex3f(-29.0, -25.0, -180.0);
    glEnd();

    //kotak iklan 1
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
        glVertex3f(37.0, -47.0, -179.5);
        glVertex3f(30.0, -47.0, -179.5);
        glVertex3f(30.0, -40.0, -179.5);
        glVertex3f(37.0, -40.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,0);
        glVertex3f(37.0, -47.0, -179.5);
        glVertex3f(30.0, -47.0, -179.5);
        glVertex3f(30.0, -40.0, -179.5);
        glVertex3f(37.0, -40.0, -179.5);
    glEnd();

    //kotak iklan 2
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
        glVertex3f(23.0, -47.0, -179.5);
        glVertex3f(16.0, -47.0, -179.5);
        glVertex3f(16.0, -40.0, -179.5);
        glVertex3f(23.0, -40.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(255,0,0);
        glVertex3f(23.0, -47.0, -179.5);
        glVertex3f(16.0, -47.0, -179.5);
        glVertex3f(16.0, -40.0, -179.5);
        glVertex3f(23.0, -40.0, -179.5);
    glEnd();

    //kotak iklan 3
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
        glVertex3f(9.0, -47.0, -179.5);
        glVertex3f(2.0, -47.0, -179.5);
        glVertex3f(2.0, -40.0, -179.5);
        glVertex3f(9.0, -40.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,128,0);
        glVertex3f(9.0, -47.0, -179.5);
        glVertex3f(2.0, -47.0, -179.5);
        glVertex3f(2.0, -40.0, -179.5);
        glVertex3f(9.0, -40.0, -179.5);
    glEnd();

    //kotak iklan 4
    glBegin(GL_POLYGON);
    glColor3ub(135,206,235);
        glVertex3f(-5.0, -47.0, -179.5);
        glVertex3f(-12.0, -47.0, -179.5);
        glVertex3f(-12.0, -40.0, -179.5);
        glVertex3f(-5.0, -40.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(135,206,235);
        glVertex3f(-5.0, -47.0, -179.5);
        glVertex3f(-12.0, -47.0, -179.5);
        glVertex3f(-12.0, -40.0, -179.5);
        glVertex3f(-5.0, -40.0, -179.5);
    glEnd();

    //kotak iklan 5
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
        glVertex3f(-19.0, -47.0, -179.5);
        glVertex3f(-26.0, -47.0, -179.5);
        glVertex3f(-26.0, -40.0, -179.5);
        glVertex3f(-19.0, -40.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
        glVertex3f(-19.0, -47.0, -179.5);
        glVertex3f(-26.0, -47.0, -179.5);
        glVertex3f(-26.0, -40.0, -179.5);
        glVertex3f(-19.0, -40.0, -179.5);
    glEnd();

    //kotak iklan 6
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
        glVertex3f(-19.0, -37.0, -179.5);
        glVertex3f(-26.0, -37.0, -179.5);
        glVertex3f(-26.0, -30.0, -179.5);
        glVertex3f(-19.0, -30.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(255,0,0);
        glVertex3f(-19.0, -37.0, -179.5);
        glVertex3f(-26.0, -37.0, -179.5);
        glVertex3f(-26.0, -30.0, -179.5);
        glVertex3f(-19.0, -30.0, -179.5);
    glEnd();

    //kotak iklan 7
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
        glVertex3f(-5.0, -37.0, -179.5);
        glVertex3f(-12.0, -37.0, -179.5);
        glVertex3f(-12.0, -30.0, -179.5);
        glVertex3f(-5.0, -30.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,0);
        glVertex3f(-5.0, -37.0, -179.5);
        glVertex3f(-12.0, -37.0, -179.5);
        glVertex3f(-12.0, -30.0, -179.5);
        glVertex3f(-5.0, -30.0, -179.5);
    glEnd();

    //kotak iklan 8
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
        glVertex3f(9.0, -37.0, -179.5);
        glVertex3f(2.0, -37.0, -179.5);
        glVertex3f(2.0, -30.0, -179.5);
        glVertex3f(9.0, -30.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
        glVertex3f(9.0, -37.0, -179.5);
        glVertex3f(2.0, -37.0, -179.5);
        glVertex3f(2.0, -30.0, -179.5);
        glVertex3f(9.0, -30.0, -179.5);
    glEnd();

    //kotak iklan 9
    glBegin(GL_POLYGON);
    glColor3ub(135,206,235);
        glVertex3f(23.0, -37.0, -179.5);
        glVertex3f(16.0, -37.0, -179.5);
        glVertex3f(16.0, -30.0, -179.5);
        glVertex3f(23.0, -30.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(135,206,235);
        glVertex3f(23.0, -37.0, -179.5);
        glVertex3f(16.0, -37.0, -179.5);
        glVertex3f(16.0, -30.0, -179.5);
        glVertex3f(23.0, -30.0, -179.5);
    glEnd();

    //kotak iklan 10
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
        glVertex3f(37.0, -37.0, -179.5);
        glVertex3f(30.0, -37.0, -179.5);
        glVertex3f(30.0, -30.0, -179.5);
        glVertex3f(37.0, -30.0, -179.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(255,0,0);
        glVertex3f(37.0, -37.0, -179.5);
        glVertex3f(30.0, -37.0, -179.5);
        glVertex3f(30.0, -30.0, -179.5);
        glVertex3f(37.0, -30.0, -179.5);
    glEnd();

    //IKLAN 3
    //UEFA
    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(-220.0, -49.3, -180.0);
        glVertex3f(-164.0, -49.3, -180.0);
        glVertex3f(-164.0, -24.0, -180.0);
        glVertex3f(-220.0, -24.0, -180.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(-220.0, -49.3, -185.0);
        glVertex3f(-164.0, -49.3, -185.0);
        glVertex3f(-164.0, -24.0, -185.0);
        glVertex3f(-220.0, -24.0, -185.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(-164.0, -49.3, -180.0);
        glVertex3f(-164.0, -49.3, -185.0);
        glVertex3f(-164.0, -24.0, -185.0);
        glVertex3f(-164.0, -24.0, -180.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(-220.0, -49.3, -180.0);
        glVertex3f(-220.0, -49.3, -185.0);
        glVertex3f(-220.0, -24.0, -185.0);
        glVertex3f(-220.0, -24.0, -180.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
        glVertex3f(-220.0, -49.3, -180.0);
        glVertex3f(-220.0, -49.3, -185.0);
        glVertex3f(-164.0, -24.0, -185.0);
        glVertex3f(-164.0, -24.0, -180.0);
    glEnd();

    //tulisan U
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-215.0, -38.0, -179.5);
        glVertex3f(-215.0, -28.0, -179.5);
        glVertex3f(-214.0, -28.0, -179.5);
        glVertex3f(-214.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-214.0, -37.0, -179.5);
        glVertex3f(-214.0, -38.0, -179.5);
        glVertex3f(-211.0, -38.0, -179.5);
        glVertex3f(-211.0, -37.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-211.0, -38.0, -179.5);
        glVertex3f(-211.0, -28.0, -179.5);
        glVertex3f(-210.0, -28.0, -179.5);
        glVertex3f(-210.0, -38.0, -179.5);
    glEnd();

    //E
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-208.0, -38.0, -179.5);
        glVertex3f(-208.0, -28.0, -179.5);
        glVertex3f(-207.0, -28.0, -179.5);
        glVertex3f(-207.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-207.0, -37.0, -179.5);
        glVertex3f(-207.0, -38.0, -179.5);
        glVertex3f(-203.0, -38.0, -179.5);
        glVertex3f(-203.0, -37.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-207.0, -32.5, -179.5);
        glVertex3f(-207.0, -34.0, -179.5);
        glVertex3f(-203.0, -34.0, -179.5);
        glVertex3f(-203.0, -32.5, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-207.0, -28.0, -179.5);
        glVertex3f(-207.0, -29.0, -179.5);
        glVertex3f(-203.0, -29.0, -179.5);
        glVertex3f(-203.0, -28.0, -179.5);
    glEnd();

    //F
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-201.0, -38.0, -179.5);
        glVertex3f(-201.0, -28.0, -179.5);
        glVertex3f(-200.0, -28.0, -179.5);
        glVertex3f(-200.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-200.0, -28.0, -179.5);
        glVertex3f(-200.0, -29.0, -179.5);
        glVertex3f(-196.0, -29.0, -179.5);
        glVertex3f(-196.0, -28.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-200.0, -32.5, -179.5);
        glVertex3f(-200.0, -34.0, -179.5);
        glVertex3f(-196.0, -34.0, -179.5);
        glVertex3f(-196.0, -32.5, -179.5);
    glEnd();

    //A
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-194.0, -38.0, -179.5);
        glVertex3f(-194.0, -28.0, -179.5);
        glVertex3f(-193.0, -28.0, -179.5);
        glVertex3f(-193.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-193.0, -28.0, -179.5);
        glVertex3f(-193.0, -30.0, -179.5);
        glVertex3f(-189.0, -30.0, -179.5);
        glVertex3f(-189.0, -28.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-193.0, -34.0, -179.5);
        glVertex3f(-193.0, -35.0, -179.5);
        glVertex3f(-189.0, -35.0, -179.5);
        glVertex3f(-189.0, -34.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-189.0, -38.0, -179.5);
        glVertex3f(-189.0, -28.0, -179.5);
        glVertex3f(-188.0, -28.0, -179.5);
        glVertex3f(-188.0, -38.0, -179.5);
    glEnd();

    //.com
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-186.0, -38.0, -179.5);
        glVertex3f(-186.0, -37.0, -179.5);
        glVertex3f(-185.0, -37.0, -179.5);
        glVertex3f(-185.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-184.0, -38.0, -179.5);
        glVertex3f(-184.0, -33.0, -179.5);
        glVertex3f(-183.0, -33.0, -179.5);
        glVertex3f(-183.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-183.0, -34.0, -179.5);
        glVertex3f(-183.0, -33.0, -179.5);
        glVertex3f(-182.0, -33.0, -179.5);
        glVertex3f(-182.0, -34.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-183.0, -38.0, -179.5);
        glVertex3f(-183.0, -37.0, -179.5);
        glVertex3f(-182.0, -37.0, -179.5);
        glVertex3f(-182.0, -38.0, -179.5);
    glEnd();

    //o
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-181.0, -38.0, -179.5);
        glVertex3f(-181.0, -33.0, -179.5);
        glVertex3f(-180.0, -33.0, -179.5);
        glVertex3f(-180.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-180.0, -34.0, -179.5);
        glVertex3f(-180.0, -33.0, -179.5);
        glVertex3f(-178.0, -33.0, -179.5);
        glVertex3f(-178.0, -34.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-180.0, -38.0, -179.5);
        glVertex3f(-180.0, -37.0, -179.5);
        glVertex3f(-178.0, -37.0, -179.5);
        glVertex3f(-178.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-178.0, -38.0, -179.5);
        glVertex3f(-178.0, -33.0, -179.5);
        glVertex3f(-177.0, -33.0, -179.5);
        glVertex3f(-177.0, -38.0, -179.5);
    glEnd();

    //m
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-176.0, -38.0, -179.5);
        glVertex3f(-176.0, -33.0, -179.5);
        glVertex3f(-175.0, -33.0, -179.5);
        glVertex3f(-175.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-173.0, -38.0, -179.5);
        glVertex3f(-173.0, -33.0, -179.5);
        glVertex3f(-172.0, -33.0, -179.5);
        glVertex3f(-172.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-170.0, -38.0, -179.5);
        glVertex3f(-170.0, -33.0, -179.5);
        glVertex3f(-169.0, -33.0, -179.5);
        glVertex3f(-169.0, -38.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-175.0, -34.0, -179.5);
        glVertex3f(-175.0, -33.0, -179.5);
        glVertex3f(-173.0, -33.0, -179.5);
        glVertex3f(-173.0, -34.0, -179.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
        glVertex3f(-172.0, -34.0, -179.5);
        glVertex3f(-172.0, -33.0, -179.5);
        glVertex3f(-170.0, -33.0, -179.5);
        glVertex3f(-170.0, -34.0, -179.5);
    glEnd();
}

//BENDERA
void bendera(){
    //tiang bendera corner kanan 1
    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(128.0, -49.2, -160.0);
        glVertex3f(130.0, -49.2, -160.0);
        glVertex3f(130.0, -30.0, -160.0);
        glVertex3f(128.0, -30.0, -160.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(128.0, -49.2, -158.0);
        glVertex3f(130.0, -49.2, -158.0);
        glVertex3f(130.0, -30.0, -158.0);
        glVertex3f(128.0, -30.0, -158.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(128.0, -49.2, -160.0);
        glVertex3f(128.0, -49.2, -158.0);
        glVertex3f(128.0, -30.0, -158.0);
        glVertex3f(128.0, -30.0, -160.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(130.0, -49.2, -160.0);
        glVertex3f(130.0, -49.2, -158.0);
        glVertex3f(130.0, -30.0, -158.0);
        glVertex3f(130.0, -30.0, -160.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(128.0, -30.0, -160.0);
        glVertex3f(128.0, -30.0, -158.0);
        glVertex3f(130.0, -30.0, -158.0);
        glVertex3f(130.0, -30.0, -160.0);
    glEnd();

    //tiang bendera korner kanan 2
    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(128.0, -49.2, 30.0);
        glVertex3f(130.0, -49.2, 30.0);
        glVertex3f(130.0, -30.0, 30.0);
        glVertex3f(128.0, -30.0, 30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(128.0, -49.2, 28.0);
        glVertex3f(130.0, -49.2, 28.0);
        glVertex3f(130.0, -30.0, 28.0);
        glVertex3f(128.0, -30.0, 28.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(128.0, -49.2, 30.0);
        glVertex3f(128.0, -49.2, 28.0);
        glVertex3f(128.0, -30.0, 28.0);
        glVertex3f(128.0, -30.0, 30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(130.0, -49.2, 30.0);
        glVertex3f(130.0, -49.2, 28.0);
        glVertex3f(130.0, -30.0, 28.0);
        glVertex3f(130.0, -30.0, 30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(128.0, -30.0, 30.0);
        glVertex3f(128.0, -30.0, 28.0);
        glVertex3f(130.0, -30.0, 28.0);
        glVertex3f(130.0, -30.0, 30.0);
    glEnd();

    //tiang bendera corner kiri 1
    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-258.0, -49.2, 30.0);
        glVertex3f(-260.0, -49.2, 30.0);
        glVertex3f(-260.0, -30.0, 30.0);
        glVertex3f(-258.0, -30.0, 30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-258.0, -49.2, 28.0);
        glVertex3f(-260.0, -49.2, 28.0);
        glVertex3f(-260.0, -30.0, 28.0);
        glVertex3f(-258.0, -30.0, 28.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-258.0, -49.2, 30.0);
        glVertex3f(-258.0, -49.2, 28.0);
        glVertex3f(-258.0, -30.0, 28.0);
        glVertex3f(-258.0, -30.0, 30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-260.0, -49.2, 30.0);
        glVertex3f(-260.0, -49.2, 28.0);
        glVertex3f(-260.0, -30.0, 28.0);
        glVertex3f(-260.0, -30.0, 30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-258.0, -30.0, 30.0);
        glVertex3f(-258.0, -30.0, 28.0);
        glVertex3f(-260.0, -30.0, 28.0);
        glVertex3f(-260.0, -30.0, 30.0);
    glEnd();

    //tiang bendera corner kiri 2
    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-258.0, -49.2, -160.0);
        glVertex3f(-260.0, -49.2, -160.0);
        glVertex3f(-260.0, -30.0, -160.0);
        glVertex3f(-258.0, -30.0, -160.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-258.0, -49.2, -158.0);
        glVertex3f(-260.0, -49.2, -158.0);
        glVertex3f(-260.0, -30.0, -158.0);
        glVertex3f(-258.0, -30.0, -158.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-258.0, -49.2, -160.0);
        glVertex3f(-258.0, -49.2, -158.0);
        glVertex3f(-258.0, -30.0, -158.0);
        glVertex3f(-258.0, -30.0, -160.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-260.0, -49.2, -160.0);
        glVertex3f(-260.0, -49.2, -158.0);
        glVertex3f(-260.0, -30.0, -158.0);
        glVertex3f(-260.0, -30.0, -160.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,250,250);
        glVertex3f(-258.0, -30.0, -160.0);
        glVertex3f(-258.0, -30.0, -158.0);
        glVertex3f(-260.0, -30.0, -158.0);
        glVertex3f(-260.0, -30.0, -160.0);
    glEnd();

    //bendera kanan 1
    glBegin(GL_POLYGON);
    glColor3ub(255,69,0);
        glVertex3f(130.0, -30.0, -159.0);
        glVertex3f(140.0, -30.0, -159.0);
        glVertex3f(140.0, -40.0, -159.0);
        glVertex3f(130.0, -40.0, -159.0);
    glEnd();

    //bendera kanan 2
    glBegin(GL_POLYGON);
    glColor3ub(255,69,0);
        glVertex3f(130.0, -30.0, 29.0);
        glVertex3f(140.0, -30.0, 29.0);
        glVertex3f(140.0, -40.0, 29.0);
        glVertex3f(130.0, -40.0, 29.0);
    glEnd();

    //bendera kiri 1
    glBegin(GL_POLYGON);
    glColor3ub(255,69,0);
        glVertex3f(-260.0, -30.0, 29.0);
        glVertex3f(-270.0, -30.0, 29.0);
        glVertex3f(-270.0, -40.0, 29.0);
        glVertex3f(-260.0, -40.0, 29.0);
    glEnd();

    //bendera kiri 2
    glBegin(GL_POLYGON);
    glColor3ub(255,69,0);
        glVertex3f(-260.0, -30.0, -159.0);
        glVertex3f(-270.0, -30.0, -159.0);
        glVertex3f(-270.0, -40.0, -159.0);
        glVertex3f(-260.0, -40.0, -159.0);
    glEnd();
}


//KURSI
void kurkur(void)
{
//belakang bawah
    glColor3ub(172, 172, 172);
    glBegin(GL_QUADS);//bawahannya
        glVertex3f(-420.0, 0.0, -240);
        glVertex3f(190.0, 0.0, -240);
        glVertex3f(300.0, 0.0, -310);
        glVertex3f(-420.0, 0.0, -310);
    glEnd();

    glColor3ub(255, 172, 172);
    glBegin(GL_QUADS);//miring
        glVertex3f(-320.0, 0.0, -240);
        glVertex3f(190.0, 0.0, -240);
        glVertex3f(190.0, 50, -330);
        glVertex3f(-320.0, 50, -330);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);//tutup belakang
        glVertex3f(-442, -50, -320);
        glVertex3f(-442, 50, -320);
        glVertex3f(315, 50, -320);
        glVertex3f(315, -50, -320);
    glEnd();

//kursi
    //baris 1
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 10.0, -250);
        glVertex3f(170.0, 10.0, -250);
        glVertex3f(170.0, 20.0, -250);
        glVertex3f(-300.0, 20.0, -250);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 20.0, -250);
        glVertex3f(170.0, 20.0, -250);
        glVertex3f(170.0, 20, -270);
        glVertex3f(-300.0, 20, -270);
    glEnd();

    //baris 2
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 25.0, -270);
        glVertex3f(170.0, 25.0, -270);
        glVertex3f(170.0, 35.0, -270);
        glVertex3f(-300.0, 35.0, -270);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 35.0, -270);
        glVertex3f(170.0, 35.0, -270);
        glVertex3f(170.0, 35, -290);
        glVertex3f(-300.0, 35, -290);
    glEnd();

    //baris 3
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 40.0, -290);
        glVertex3f(170.0, 40.0, -290);
        glVertex3f(170.0, 50.0, -290);
        glVertex3f(-300.0, 50.0, -290);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 50.0, -290);
        glVertex3f(170.0, 50.0, -290);
        glVertex3f(170.0, 50, -310);
        glVertex3f(-300.0, 50, -310);
    glEnd();

//belakang atas
    glColor3ub(172, 172, 172);
    glBegin(GL_QUADS);//bawahannya
        glVertex3f(-320.0, 70.0, -250);
        glVertex3f(190.0, 70.0, -250);
        glVertex3f(190.0, 70.0, -340);
        glVertex3f(-320.0, 70.0, -340);
    glEnd();

    glColor3ub(255, 172, 172);
    glBegin(GL_QUADS);//miring
        glVertex3f(-320.0, 70.0, -250);
        glVertex3f(190.0, 70.0, -250);
        glVertex3f(190.0, 120, -340);
        glVertex3f(-320.0, 120, -340);
    glEnd();

//kursi
    //baris 1
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 80.0, -260);
        glVertex3f(170.0, 80.0, -260);
        glVertex3f(170.0, 90.0, -260);
        glVertex3f(-300.0, 90.0, -260);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 90.0, -260);
        glVertex3f(170.0, 90.0, -260);
        glVertex3f(170.0, 90, -290);
        glVertex3f(-300.0, 90, -290);
    glEnd();

    //baris 2
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 95.0, -290);
        glVertex3f(170.0, 95.0, -290);
        glVertex3f(170.0, 105.0, -290);
        glVertex3f(-300.0, 105.0, -290);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 105.0, -290);
        glVertex3f(170.0, 105.0, -290);
        glVertex3f(170.0, 105, -310);
        glVertex3f(-300.0, 105, -310);
    glEnd();

    //baris 3
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 110.0, -310);
        glVertex3f(170.0, 110.0, -310);
        glVertex3f(170.0, 120.0, -310);
        glVertex3f(-300.0, 120.0, -310);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 120.0, -310);
        glVertex3f(170.0, 120.0, -310);
        glVertex3f(170.0, 120, -330);
        glVertex3f(-300.0, 120, -330);
    glEnd();

//depan bawah
    glColor3ub(172, 172, 172);
    glBegin(GL_QUADS);//bawahannya
        glVertex3f(-420.0, 0.0, 110);
        glVertex3f(315.0, 0.0, 110);
        glVertex3f(315.0, 0.0, 200);
        glVertex3f(-420.0, 0.0, 200);
    glEnd();

    glColor3ub(255, 172, 172);
    glBegin(GL_QUADS);//miring
        glVertex3f(-320.0, 0.0, 110);
        glVertex3f(190.0, 0.0, 110);
        glVertex3f(190.0, 50, 200);
        glVertex3f(-320.0, 50, 200);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);//tutup
        glVertex3f(-442, -50, 200);
        glVertex3f(-442, 50, 200);
        glVertex3f(-100, 50, 200);
        glVertex3f(-100, -50, 200);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);//pintu
        glVertex3f(-100, -50, 200);
        glVertex3f(-100, 50, 200);
        glVertex3f(0, 50, 200);
        glVertex3f(0, -50, 200);
    glEnd();
    glColor3ub(172, 172, 172);
    glLineWidth(10);//garis
    glBegin(GL_LINE_STRIP);
        glVertex3f(-50, -50, 201);
        glVertex3f(-50, 50, 201);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);//tutup
        glVertex3f(315, -50, 200);
        glVertex3f(315, 50, 200);
        glVertex3f(0, 50, 200);
        glVertex3f(0, -50, 200);
    glEnd();

//kursi
    //baris 1
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 10.0, 120);
        glVertex3f(170.0, 10.0, 120);
        glVertex3f(170.0, 20.0, 120);
        glVertex3f(-300.0, 20.0, 120);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 20.0, 120);
        glVertex3f(170.0, 20.0, 120);
        glVertex3f(170.0, 20, 140);
        glVertex3f(-300.0, 20, 140);
    glEnd();

    //baris 2
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 25.0, 140);
        glVertex3f(170.0, 25.0, 140);
        glVertex3f(170.0, 35.0, 140);
        glVertex3f(-300.0, 35.0, 140);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 35.0, 140);
        glVertex3f(170.0, 35.0, 140);
        glVertex3f(170.0, 35, 160);
        glVertex3f(-300.0, 35, 160);
    glEnd();

    //baris 3
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 40.0, 160);
        glVertex3f(170.0, 40.0, 160);
        glVertex3f(170.0, 50.0, 160);
        glVertex3f(-300.0, 50.0, 160);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 50.0, 180);
        glVertex3f(170.0, 50.0, 180);
        glVertex3f(170.0, 50, 180);
        glVertex3f(-300.0, 50, 180);
    glEnd();

//depan atas
    glColor3ub(172, 172, 172);
    glBegin(GL_QUADS);//bawahannya
        glVertex3f(-320.0, 70.0, 120);
        glVertex3f(190.0, 70.0, 120);
        glVertex3f(190.0, 70.0, 200);
        glVertex3f(-320.0, 70.0, 200);
    glEnd();

    glColor3ub(255, 172, 172);
    glBegin(GL_QUADS);//miring
        glVertex3f(-320.0, 70.0, 120);
        glVertex3f(190.0, 70.0, 120);
        glVertex3f(190.0, 120, 200);
        glVertex3f(-320.0, 120, 200);
    glEnd();

//kursi
    //baris 1
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 80.0, 120);
        glVertex3f(170.0, 80.0, 120);
        glVertex3f(170.0, 90.0, 120);
        glVertex3f(-300.0, 90.0, 120);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 90.0, 120);
        glVertex3f(170.0, 90.0, 120);
        glVertex3f(170.0, 90, 140);
        glVertex3f(-300.0, 90, 140);
    glEnd();

    //baris 2
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 95.0, 140);
        glVertex3f(170.0, 95.0, 140);
        glVertex3f(170.0, 105.0, 140);
        glVertex3f(-300.0, 105.0, 140);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 105.0, 140);
        glVertex3f(170.0, 105.0, 140);
        glVertex3f(170.0, 105, 160);
        glVertex3f(-300.0, 105, 160);
    glEnd();

    //baris 3
    glBegin(GL_QUADS);//depan
        glVertex3f(-300.0, 110.0, 160);
        glVertex3f(170.0, 110.0, 160);
        glVertex3f(170.0, 120.0, 160);
        glVertex3f(-300.0, 120.0, 160);
    glEnd();
    glBegin(GL_QUADS);//atas
        glVertex3f(-300.0, 120.0, 160);
        glVertex3f(170.0, 120.0, 160);
        glVertex3f(170.0, 120, 180);
        glVertex3f(-300.0, 120, 180);
    glEnd();


//kanan bawah
    glColor3ub(172, 172, 172);
    glBegin(GL_QUADS);//bawahannya
        glVertex3f(190.0, 0.0, -335);
        glVertex3f(190.0, 0.0, 110);
        glVertex3f(300.0, 0.0, 190);
        glVertex3f(300.0, 0.0, -335);
    glEnd();

    glColor3ub(255, 172, 172);
    glBegin(GL_QUADS);//miring
        glVertex3f(190.0, 0.0, -240);
        glVertex3f(190.0, 0.0, 110);
        glVertex3f(310.0, 50.0, 110);
        glVertex3f(310.0, 50.0, -240);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);//tutup belakang
        glVertex3f(313.0, 50.0, -320.0);
        glVertex3f(313.0, -50.0, -320.0);
        glVertex3f(313.0, -50.0, 200.0);
        glVertex3f(313.0, 50.0, 200.0);
    glEnd();

//kursi
    //baris 1
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//depan
        glVertex3f(200.0, 15.0, 90.0);
        glVertex3f(200.0, 5.0, 90.0);
        glVertex3f(200.0, 5.0, -220.0);
        glVertex3f(200.0, 15.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(200, 15.0, 90.0);
        glVertex3f(220, 15.0, 90.0);
        glVertex3f(220, 15.0, -220.0);
        glVertex3f(200, 15.0, -220.0);
    glEnd();

    //baris 2
    glBegin(GL_QUADS);//depan
        glVertex3f(230.0, 30.0, 90.0);
        glVertex3f(230.0, 20.0, 90.0);
        glVertex3f(230.0, 20.0, -220.0);
        glVertex3f(230.0, 30.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(230, 30.0, 90.0);
        glVertex3f(250, 30.0, 90.0);
        glVertex3f(250, 30.0, -220.0);
        glVertex3f(230, 30.0, -220.0);
    glEnd();

    //baris 3
    glBegin(GL_QUADS);//depan
        glVertex3f(260.0, 45.0, 90.0);
        glVertex3f(260.0, 35.0, 90.0);
        glVertex3f(260.0, 35.0, -220.0);
        glVertex3f(260.0, 45.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(260, 45.0, 90.0);
        glVertex3f(280, 45.0, 90.0);
        glVertex3f(280, 45.0, -220.0);
        glVertex3f(260, 45.0, -220.0);
    glEnd();

//kanan atas
    glColor3ub(172, 172, 172);
    glBegin(GL_QUADS);//bawahannya
        glVertex3f(200.0, 70.0, -240);
        glVertex3f(200.0, 70.0, 110);
        glVertex3f(320.0, 70.0, 110);
        glVertex3f(320.0, 70.0, -240);
    glEnd();

    glColor3ub(255, 172, 172);
    glBegin(GL_QUADS);//miring
        glVertex3f(200.0, 70.0, -240);
        glVertex3f(200.0, 70.0, 110);
        glVertex3f(320.0, 120.0, 110);
        glVertex3f(320.0, 120.0, -240);
    glEnd();

//kursi
    //baris 1
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//depan
        glVertex3f(200.0, 85.0, 90.0);
        glVertex3f(200.0, 75.0, 90.0);
        glVertex3f(200.0, 75.0, -220.0);
        glVertex3f(200.0, 85.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(200, 85.0, 90.0);
        glVertex3f(220, 85.0, 90.0);
        glVertex3f(220, 85.0, -220.0);
        glVertex3f(200, 85.0, -220.0);
    glEnd();

    //baris 2
    glBegin(GL_QUADS);//depan
        glVertex3f(230.0, 100.0, 90.0);
        glVertex3f(230.0, 90.0, 90.0);
        glVertex3f(230.0, 90.0, -220.0);
        glVertex3f(230.0, 100.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(230, 100.0, 90.0);
        glVertex3f(250, 100.0, 90.0);
        glVertex3f(250, 100.0, -220.0);
        glVertex3f(230, 100.0, -220.0);
    glEnd();

    //baris 3
    glBegin(GL_QUADS);//depan
        glVertex3f(260.0, 115.0, 90.0);
        glVertex3f(260.0, 105.0, 90.0);
        glVertex3f(260.0, 105.0, -220.0);
        glVertex3f(260.0, 115.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(260, 115.0, 90.0);
        glVertex3f(280, 115.0, 90.0);
        glVertex3f(280, 115.0, -220.0);
        glVertex3f(260, 115.0, -220.0);
    glEnd();

//kiri bawah
    glColor3ub(172, 172, 172);
    glBegin(GL_QUADS);//bawahannya
        glVertex3f(-320.0, 0.0, -240);
        glVertex3f(-320.0, 0.0, 110);
        glVertex3f(-440.0, 0.0, 110);
        glVertex3f(-440.0, 0.0, -240);
    glEnd();

    glColor3ub(255, 172, 172);
    glBegin(GL_QUADS);//miring
        glVertex3f(-320.0, 0.0, -240);
        glVertex3f(-320.0, 0.0, 110);
        glVertex3f(-440.0, 50.0, 110);
        glVertex3f(-440.0, 50.0, -240);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);//tutup belakang
        glVertex3f(-440.0, 50.0, -320.0);
        glVertex3f(-440.0, -50.0, -320.0);
        glVertex3f(-440.0, -50.0, 200.0);
        glVertex3f(-440.0, 50.0, 200.0);
    glEnd();


//kursi
    //baris 1
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//depan
        glVertex3f(-330.0, 15.0, 90.0);
        glVertex3f(-330.0, 5.0, 90.0);
        glVertex3f(-330.0, 5.0, -220.0);
        glVertex3f(-330.0, 15.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-330.0, 15.0, 90.0);
        glVertex3f(-350.0, 15.0, 90.0);
        glVertex3f(-350.0, 15.0, -220.0);
        glVertex3f(-330.0, 15.0, -220.0);
    glEnd();

    //baris 2
    glBegin(GL_QUADS);//depan
        glVertex3f(-360.0, 30.0, 90.0);
        glVertex3f(-360.0, 20.0, 90.0);
        glVertex3f(-360.0, 20.0, -220.0);
        glVertex3f(-360.0, 30.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-360, 30.0, 90.0);
        glVertex3f(-380, 30.0, 90.0);
        glVertex3f(-380, 30.0, -220.0);
        glVertex3f(-360, 30.0, -220.0);
    glEnd();

    //baris 3
    glBegin(GL_QUADS);//depan
        glVertex3f(-390.0, 45.0, 90.0);
        glVertex3f(-390.0, 35.0, 90.0);
        glVertex3f(-390.0, 35.0, -220.0);
        glVertex3f(-390.0, 45.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-390, 45.0, 90.0);
        glVertex3f(-410, 45.0, 90.0);
        glVertex3f(-410, 45.0, -220.0);
        glVertex3f(-390, 45.0, -220.0);
    glEnd();

//kiri atas
    glColor3ub(172, 172, 172);
    glBegin(GL_QUADS);//bawahannya
        glVertex3f(-330.0, 70.0, -240);
        glVertex3f(-330.0, 70.0, 110);
        glVertex3f(-440.0, 70.0, 110);
        glVertex3f(-440.0, 70.0, -240);
    glEnd();

    glColor3ub(255, 172, 172);
    glBegin(GL_QUADS);//miring
        glVertex3f(-330.0, 70.0, -240);
        glVertex3f(-330.0, 70.0, 110);
        glVertex3f(-440.0, 120.0, 110);
        glVertex3f(-440.0, 120.0, -240);
    glEnd();

//kursi
    //baris 1
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//depan
        glVertex3f(-330.0, 85.0, 90.0);
        glVertex3f(-330.0, 75.0, 90.0);
        glVertex3f(-330.0, 75.0, -220.0);
        glVertex3f(-330.0, 85.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-330, 85.0, 90.0);
        glVertex3f(-350, 85.0, 90.0);
        glVertex3f(-350, 85.0, -220.0);
        glVertex3f(-330, 85.0, -220.0);
    glEnd();

    //baris 2
    glBegin(GL_QUADS);//depan
        glVertex3f(-360.0, 100.0, 90.0);
        glVertex3f(-360.0, 90.0, 90.0);
        glVertex3f(-360.0, 90.0, -220.0);
        glVertex3f(-360.0, 100.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-360, 100.0, 90.0);
        glVertex3f(-380, 100.0, 90.0);
        glVertex3f(-380, 100.0, -220.0);
        glVertex3f(-360, 100.0, -220.0);
    glEnd();

    //baris 3
    glBegin(GL_QUADS);//depan
        glVertex3f(-390.0, 115.0, 90.0);
        glVertex3f(-390.0, 105.0, 90.0);
        glVertex3f(-390.0, 105.0, -220.0);
        glVertex3f(-390.0, 115.0, -220.0);
    glEnd();

    glBegin(GL_QUADS);//atas
        glVertex3f(-390, 115.0, 90.0);
        glVertex3f(-410, 115.0, 90.0);
        glVertex3f(-410, 115.0, -220.0);
        glVertex3f(-390, 115.0, -220.0);
    glEnd();


}

void lampu(){
    lampudpn();
    lampublkg();
    lampukanan();
    lampukiri();
}

void lampudpn(void){
//LAMPU 1
    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(150.0, 240.0, -340.0);
        glVertex3f(150.0, 260.0, -340.0);
        glVertex3f(70.0, 260.0, -340.0);
        glVertex3f(70.0, 240.0, -340.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(150.0, 240.0, -337.0);
        glVertex3f(150.0, 260.0, -331.0);
        glVertex3f(70.0, 260.0, -331.0);
        glVertex3f(70.0, 240.0, -337.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(150.0, 240.0, -340.0);
        glVertex3f(150.0, 240.0, -337.0);
        glVertex3f(70.0, 240.0, -337.0);
        glVertex3f(70.0, 240.0, -340.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(150.0, 260.0, -340.0);
        glVertex3f(150.0, 260.0, -336.0);
        glVertex3f(70.0, 260.0, -336.0);
        glVertex3f(70.0, 260.0, -340.0);
    glEnd();

//LAMPU 2
    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-200.0, 240.0, -340.0);
        glVertex3f(-200.0, 260.0, -340.0);
        glVertex3f(-280.0, 260.0, -340.0);
        glVertex3f(-280.0, 240.0, -340.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-200.0, 240.0, -337.0);
        glVertex3f(-200.0, 260.0, -336.0);
        glVertex3f(-280.0, 260.0, -336.0);
        glVertex3f(-280.0, 240.0, -337.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-200.0, 240.0, -340.0);
        glVertex3f(-200.0, 240.0, -337.0);
        glVertex3f(-280.0, 240.0, -337.0);
        glVertex3f(-280.0, 240.0, -340.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-200.0, 260.0, -340.0);
        glVertex3f(-200.0, 260.0, -336.0);
        glVertex3f(-280.0, 260.0, -336.0);
        glVertex3f(-280.0, 260.0, -340.0);
    glEnd();
}

void lampublkg(void){
    //LAMPU 1
    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(150.0, 240.0, 227.0);
        glVertex3f(150.0, 260.0, 227.0);
        glVertex3f(70.0, 260.0, 227.0);
        glVertex3f(70.0, 240.0, 227.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(150.0, 240.0, 224.0);
        glVertex3f(150.0, 260.0, 218.0);
        glVertex3f(70.0, 260.0, 218.0);
        glVertex3f(70.0, 240.0, 224.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(150.0, 240.0, 227.0);
        glVertex3f(150.0, 240.0, 224.0);
        glVertex3f(70.0, 240.0, 224.0);
        glVertex3f(70.0, 240.0, 227.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(150.0, 260.0, 227.0);
        glVertex3f(150.0, 260.0, 224.0);
        glVertex3f(70.0, 260.0, 224.0);
        glVertex3f(70.0, 260.0, 227.0);
    glEnd();

//LAMPU 2
    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-200.0, 240.0, 227.0);
        glVertex3f(-200.0, 260.0, 227.0);
        glVertex3f(-280.0, 260.0, 227.0);
        glVertex3f(-280.0, 240.0, 227.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-200.0, 240.0, 224.0);
        glVertex3f(-200.0, 260.0, 218.0);
        glVertex3f(-280.0, 260.0, 218.0);
        glVertex3f(-280.0, 240.0, 224.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-200.0, 240.0, 227.0);
        glVertex3f(-200.0, 240.0, 224.0);
        glVertex3f(-280.0, 240.0, 224.0);
        glVertex3f(-280.0, 240.0, 227.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-200.0, 260.0, 227.0);
        glVertex3f(-200.0, 260.0, 218.0);
        glVertex3f(-280.0, 260.0, 218.0);
        glVertex3f(-280.0, 260.0, 227.0);
    glEnd();
}

void lampukanan(void){
    //LAMPU 1
    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(325.0, 240.0, -150.0);
        glVertex3f(325.0, 260.0, -150.0);
        glVertex3f(325.0, 260.0, 20.0);
        glVertex3f(325.0, 240.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(323.0, 240.0, -150.0);
        glVertex3f(320.0, 260.0, -150.0);
        glVertex3f(320.0, 260.0, 20.0);
        glVertex3f(323.0, 240.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(325.0, 240.0, -150.0);
        glVertex3f(323.0, 240.0, -150.0);
        glVertex3f(323.0, 240.0, 20.0);
        glVertex3f(325.0, 240.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(325.0, 260.0, -150.0);
        glVertex3f(320.0, 260.0, -150.0);
        glVertex3f(320.0, 260.0, 20.0);
        glVertex3f(325.0, 260.0, 20.0);
    glEnd();
}

void lampukiri(void){
    //LAMPU 1
    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-456.0, 240.0, -150.0);
        glVertex3f(-456.0, 260.0, -150.0);
        glVertex3f(-456.0, 260.0, 20.0);
        glVertex3f(-456.0, 240.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-454.0, 240.0, -150.0);
        glVertex3f(-451.0, 260.0, -150.0);
        glVertex3f(-451.0, 260.0, 20.0);
        glVertex3f(-454.0, 240.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-456.0, 240.0, -150.0);
        glVertex3f(-454.0, 240.0, -150.0);
        glVertex3f(-454.0, 240.0, 20.0);
        glVertex3f(-456.0, 240.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
        glVertex3f(-456.0, 260.0, -150.0);
        glVertex3f(-451.0, 260.0, -150.0);
        glVertex3f(-451.0, 260.0, 20.0);
        glVertex3f(-456.0, 260.0, 20.0);
    glEnd();
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 'w':
        case 'W':
            glTranslatef(0.0, 0.0, 3.0);
            break;
        case 'd':
        case 'D':
            glTranslatef(3.0, 0.0, 0.0);
            break;
        case 's':
        case 'S':
            glTranslatef(0.0, 0.0, -3.0);
            break;
        case 'a':
        case 'A':
            glTranslatef(-3.0, 0.0, 0.0);
            break;
        case '7'://y
            glTranslatef(0.0, 3.0, 0.0);
            break;
        case '9':
            glTranslatef(0.0, -3.0, 0.0);
            break;
        case '2'://rotasi
            glRotatef(2.0, 1.0, 0.0, 0.0);
            break;
        case '8'://berlawanan arah dengan 2
            glRotatef(-2.0, 1.0, 0.0, 0.0);
            break;
        case '6':
            glRotatef(2.0, 0.0, 1.0, 0.0);
            break;
        case '4':
            glRotatef(-2.0, 0.0, 1.0, 0.0);
            break;
        case '1':
            glRotatef(2.0, 0.0, 0.0, 1.0);
            break;
        case '3':
            glRotatef(-2.0, 0.0, 0.0, 1.0);
            break;
        case '5':
            if (is_depth){
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }else{
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }else
    mouseDown = false;
}

void mouseMotion(int x, int y){
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, lebar / tinggi, 5.0, 900.0);
    glViewport(0,0,lebar,tinggi);
    glTranslatef(0.0, -5.0, -39.0);
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(250, 30);
    glViewport(0,0,640,480);
    glutCreateWindow("STADE DU HAINAUT");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutReshapeFunc(ukuran);//atur ukuran box
    glutMainLoop();
    return 0;
}
