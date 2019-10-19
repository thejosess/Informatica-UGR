#include "motorlib/mapa.hpp"

void Mapa::colorCeldaMM(unsigned char celda) {
  switch (celda) {
    case 'P': glColor3f(0.15,0.15,0.15); break;
    case 'B': glColor3f(0.0,1.0,0.0); break;
    case 'A': glColor3f(0.0,0.0,1.0); break;
    case 'S': glColor3f(0.6,0.6,0.6); break;
    case 'M': glColor3f(0.6,0.0,0.0); break;
    case 'T': glColor3f(0.3,0.25,0.2); break;
    case 'K': glColor3f(1.0,1.0,0.0); break;
    case 'Z': glColor3f(0.0,1.0,0.3); break;
    case 'D': glColor3f(0.0,0.0,0.0); break;
    case 'X': glColor3f(1.0,0.0,1.0); break;
    default: glColor3f(1.0,1.0,1.0); break;
  }
}

void Mapa::colorCeldaOpuestoMM(unsigned char celda) {
  switch (celda) {
    case 'P': glColor3f(1,1,1); break;
    case 'B': glColor3f(0,0,0); break;
    case 'A': glColor3f(0.0,0.0,0.0); break;
    case 'S': glColor3f(0,0,0); break;
    case 'M': glColor3f(1,1,1); break;
    case 'T': glColor3f(1,1,1); break;
    case 'K': glColor3f(0,0,0); break;
    case 'Z': glColor3f(1,1,1); break;
    case 'D': glColor3f(1,1,1); break;
    case 'X': glColor3f(0,0,0); break;
    default: glColor3f(0.0,0.0,0.0); break;
  }
}


void Mapa::OrientacionEntidadMM(Orientacion orienParam) {
  switch (orienParam) {
    case norte: glRotatef(90.0,0,0,1); break;
    case este: glRotatef(0.0,0,0,1); break;
    case sur: glRotatef(270.0,0,0,1); break;
    case oeste: glRotatef(180.0,0,0,1); break;
  }
}

void Mapa::OrientacionEntidadFP(Orientacion orienParam) {
  switch (orienParam) {
    case norte: glRotatef(0.0,0,1,0); break;
    case este: glRotatef(270.0,0,1,0); break;
    case sur: glRotatef(180.0,0,1,0); break;
    case oeste: glRotatef(90.0,0,1,0); break;
  }
}

void Mapa::complementosCelda(unsigned char celda) {
  Arbol3D *arbol = new Arbol3D();

  switch (celda) {
    case 'P':
      glColor3f(0.15,0.15,0.15);
      glTranslatef(0.0, 7.5, 0.0);
      glScalef(5.0, 15.0, 5.0);
      glutSolidCube(1.0);
      break;
    case 'B':
      glScalef(5.0, 15.0, 5.0);
      arbol->draw(1);
      break;
    case 'M':
      glColor3f(0.6,0.0,0.0);
      glTranslatef(0.0, 7.5, 0.0);
      glScalef(5.0, 15.0, 5.0);
      glutSolidCube(1.0);
      break;
  }
  delete arbol;
}

void Mapa::formaEntidad(unsigned char tipoParam) {
  RevolucionObj3D * jug = new RevolucionObj3D("ply/cilindro.ply", 3);
  switch (tipoParam) {
    case 'j':
      glRotatef(90.0,1,0,0);
      glScalef(1.0, 1.0, 0.75);
      jug->setColor( _vertex3<float> (1.0,0.0,0.0));
      jug->draw(1);
      break;

    case 'l':
    case 'a':
    case 'd':
    case 'r':
      glColor3f(255.0/255.0, 159.0/255.0, 5.0/255.0);
      glutSolidCube(0.6);
      break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
      glColor3f(1.0, 5.0/255.0, 238/255.0);
      glutSolidSphere(0.5, 6, 2);
      break;
  }
}

void Mapa::drawMM1(int x, int y) {
  unsigned int colMed, filaMed;
  vector< vector< unsigned char> > mapaConPlan = (*entidades)[0]->getMapaPlan();

  colMed = (mapaCompleto.size()/2);
  filaMed = (mapaCompleto[0].size()/2);

  glLoadIdentity();
  glOrtho(-10.0,10.0,-10.0,10.0,-1.0,1.0);
  glMatrixMode(GL_MODELVIEW);

  float ratio = 1.0;
  if(mapaCompleto.size() > 15) {
    ratio = 20.0 / (float) mapaCompleto.size();
  }

  for (unsigned int i = 0; i < mapaCompleto.size(); i++) {
    for (unsigned int j = 0; j < mapaCompleto[i].size(); j++) {
        glPushMatrix();

        glTranslatef(((GLfloat) i - (GLfloat) filaMed ) * ratio, ((GLfloat) colMed - (GLfloat) j) * ratio, 0.0);
        glScalef(ratio, ratio, ratio);

        colorCeldaMM(mapaCompleto[j][i]);

        glBegin(GL_QUADS);
          glVertex3f(-0.5, -0.5, 0.0);
          glVertex3f(-0.5, 0.5, 0.0);
          glVertex3f( 0.5, 0.5, 0.0);
          glVertex3f( 0.5, -0.5, 0.0);
        glEnd();

        if (mapaConPlan[j][i]>0){
          /*glColor3f(1.0,1.0,1.0);
          glBegin(GL_QUADS);
            glVertex3f(0.0, -0.5, 0.0);
            glVertex3f(-0.5, 0.0, 0.0);
            glVertex3f( 0.0, 0.5, 0.0);
            glVertex3f( 0.5, 0.0, 0.0);
          glEnd();*/

          //glColor3f(0.0,1.0,1.0);
          colorCeldaOpuestoMM(mapaCompleto[j][i]);
          glBegin(GL_QUADS);
          glVertex3f(0.0, -0.3, 0.0);
          glVertex3f(-0.3, 0.0, 0.0);
          glVertex3f( 0.0, 0.3, 0.0);
          glVertex3f( 0.3, 0.0, 0.0);
          glEnd();
        }


        glPopMatrix();
    }
  }

  for (unsigned int i = 0; i < entidades->size(); i++) {
    if((*entidades)[i]-> getHitbox()) {
      glPushMatrix();

      glTranslatef(((GLfloat) (*entidades)[i]->getY() - (GLfloat) colMed) * ratio, ((GLfloat) filaMed - (GLfloat) (*entidades)[i]->getX()) * ratio, 0.0);

      OrientacionEntidadMM((*entidades)[i]->getOrientacion());

      glScalef(ratio, ratio, ratio);

      formaEntidad((*entidades)[i]->getSubTipoChar());

      glPopMatrix();
    }
  }

  glPushMatrix();
  glTranslatef(((GLfloat) y  - (GLfloat) colMed) * ratio, ((GLfloat) filaMed - (GLfloat) x) * ratio, 0);
  glColor3f(1.0,1.0,1.0);
  glScalef(ratio, ratio, ratio);
  glutSolidSphere(0.5, 6, 2);
  glPopMatrix();
}

void  Mapa::drawMM2(int x, int y) {
  vector< vector< unsigned char> > mapaSuperficie = (*entidades)[0]->getMapaResultado();
  vector< vector< unsigned char> > mapaEntidades = (*entidades)[0]->getMapaEntidades();
  vector< vector< unsigned char> > mapaConPlan = (*entidades)[0]->getMapaPlan();


  unsigned int colMed, filaMed;

  colMed = (mapaCompleto.size()/2);
  filaMed = (mapaCompleto[0].size()/2);

  glLoadIdentity();
  glOrtho(-10.0,10.0,-10.0,10.0,-1.0,1.0);
  glMatrixMode(GL_MODELVIEW);

   float ratio = 1.0;
   if(mapaCompleto.size() > 15) {
     ratio = 20.0 / (float) mapaCompleto.size();
   }

   for (unsigned int i = 0; i < mapaCompleto.size(); i++) {
     for (unsigned int j = 0; j < mapaCompleto[i].size(); j++) {
        glPushMatrix();

        glTranslatef(((GLfloat) i - (GLfloat) filaMed ) * ratio, ((GLfloat) colMed - (GLfloat) j) * ratio, 0.0);
        glScalef(ratio, ratio, ratio);

        colorCeldaMM(mapaSuperficie[j][i]);

        glBegin(GL_QUADS);
          glVertex3f(-0.5, -0.5, 0.0);
          glVertex3f(-0.5, 0.5, 0.0);
          glVertex3f( 0.5, 0.5, 0.0);
          glVertex3f( 0.5, -0.5, 0.0);
        glEnd();

        if (mapaConPlan[j][i]>0){
          /*glColor3f(1.0,1.0,1.0);
          glBegin(GL_QUADS);
            glVertex3f(0.0, -0.5, 0.0);
            glVertex3f(-0.5, 0.0, 0.0);
            glVertex3f( 0.0, 0.5, 0.0);
            glVertex3f( 0.5, 0.0, 0.0);
          glEnd();*/

          //glColor3f(0.0,1.0,1.0);
          colorCeldaOpuestoMM(mapaSuperficie[j][i]);
          glBegin(GL_QUADS);
          glVertex3f(0.0, -0.3, 0.0);
          glVertex3f(-0.3, 0.0, 0.0);
          glVertex3f( 0.0, 0.3, 0.0);
          glVertex3f( 0.3, 0.0, 0.0);
          glEnd();
        }

        glPopMatrix();
    }
  }

  for (unsigned int i = 0; i < entidades->size(); i++) {
    if((*entidades)[i]-> getHitbox()) {
      glPushMatrix();

      glTranslatef(((GLfloat) (*entidades)[i]->getY() - (GLfloat) colMed) * ratio, ((GLfloat) filaMed - (GLfloat) (*entidades)[i]->getX()) * ratio, 0.0);

      OrientacionEntidadMM((*entidades)[i]->getOrientacion());

      glScalef(ratio, ratio, ratio);

      formaEntidad((*entidades)[i]->getSubTipoChar());

      glPopMatrix();
    }
  }

  glPushMatrix();
  glTranslatef(((GLfloat) y  - (GLfloat) colMed) * ratio, ((GLfloat) filaMed - (GLfloat) x) * ratio, 0);
  glColor3f(1.0,0.0,0.0);
  glScalef(ratio, ratio, ratio);
  glutSolidSphere(0.5, 6, 2);
  glPopMatrix();
}

void Mapa::drawFirstPerson() {
  vector< vector< unsigned char> > mapaConPlan = (*entidades)[0]->getMapaPlan();
  unsigned int colMed, filaMed;

  colMed = (mapaCompleto.size()/2);
  filaMed = (mapaCompleto[0].size()/2);

  if(entidades->size() > 0) {
    x = (*entidades)[0]->getY() + 1;
    z = (*entidades)[0]->getX() + 1;

    switch ((*entidades)[0]->getOrientacion()) {
      case norte: angulo = 180.0; break;
      case sur: angulo = 0.0; break;
      case este: angulo = 270.0; break;
      case oeste: angulo = 90.0; break;
    }
  }

  //Camara
  gluLookAt(
            ((GLfloat) colMed - (GLfloat) x) * (5.0),
            3.5+Y2,
            ((GLfloat) filaMed - (GLfloat) z) * 5.0,
            (((GLfloat) colMed - (GLfloat) x) * (5.0)) + sin((angulo * 2.0 * M_PI)/360.0),
            3.4-Y1,
            (((GLfloat) filaMed - (GLfloat) z) * 5.0) - cos((angulo * 2.0 * M_PI)/360.0),
            0.0,
            3.3,
            0.0
          );

  int fs = x-15; if (fs<0) fs=0;
  int fi = x+15; if (fi>=mapaCompleto.size()) fi=mapaCompleto.size()-1;

  int ci = z-15; if (ci<0) ci=0;
  int cd = z+15; if (cd>=mapaCompleto.size()) cd=mapaCompleto.size()-1;

  for (unsigned int i = fs; i < fi; i++) {
    for (unsigned int j = ci; j < cd; j++) {
      //Suelo
      glPushMatrix();

      if(mapaCompleto[j][i] == 'K') {
        glTranslatef(((GLfloat) filaMed  - (GLfloat) i - 1 ) * 5.0, 0.25, ((GLfloat) colMed - (GLfloat) j  - 1) * 5.0);

        colorCeldaMM(mapaCompleto[j][i]);

        glScalef(5.0, 0.4, 5.0);
        glutSolidCube(1.0);

      }
      else if(mapaCompleto[j][i] == 'A') {
        glTranslatef(((GLfloat) filaMed  - (GLfloat) i - 1 ) * 5.0, -0.3, ((GLfloat) colMed - (GLfloat) j  - 1) * 5.0);

        colorCeldaMM(mapaCompleto[j][i]);

        glScalef(5.0, 0.4, 5.0);
        glutSolidCube(1.0);

      }
      else{
        glTranslatef(((GLfloat) filaMed  - (GLfloat) i - 1 ) * 5.0, 0.0, ((GLfloat) colMed - (GLfloat) j  - 1) * 5.0);

        colorCeldaMM(mapaCompleto[j][i]);

        glScalef(5.0, 0.4, 5.0);
        glutSolidCube(1.0);

        if (mapaConPlan[j][i]==1){
          glColor3f(1.0,0.0,0.0);
          glScalef(1.0, 1.2, 1.0);
          glutSolidSphere(0.43,50,50);
          //glutSolidCube(0.2);
        }
      }



      glPopMatrix();

      //Complementos
      glPushMatrix();
      glTranslatef(((GLfloat) filaMed  - (GLfloat) i - 1 ) * 5.0, 0.0, ((GLfloat) colMed - (GLfloat) j  - 1) * 5.0);
      complementosCelda(mapaCompleto[j][i]);
      glPopMatrix();
    }
  }

  Luz luz(GL_LIGHT0);
  luz.setPosicion(_vertex3<float>(0.0, 20.0, 0.0));
  luz.encender();
  luz.draw();

  //Dibujamos las entidades
  for (unsigned int i = 1; i < entidades->size(); i++) {
    x = (*entidades)[i]->getY() + 1;
    z = (*entidades)[i]->getX() + 1;

    glPushMatrix();
      glTranslatef(((GLfloat) colMed - (GLfloat) x) * 5.0, 0.4 ,   ((GLfloat) filaMed - (GLfloat) z) * 5.0);

      OrientacionEntidadFP((*entidades)[i]->getOrientacion());
      (*entidades)[i]->draw(1);

    glPopMatrix();
  }
}

int Mapa::casillaOcupada(unsigned int entidad) {
  int out = -1;
  unsigned int x = (*entidades)[entidad]->getX();
  unsigned int y = (*entidades)[entidad]->getY();

  switch ((*entidades)[entidad]->getOrientacion()) {
    case norte: x--; break;
    case este: y++; break;
    case sur: x++; break;
    case oeste: y--; break;
  }

  unsigned int i = 0;
  while ((i < entidades->size()) and (out == -1)) {
    if (((*entidades)[i]->getX() == x and (*entidades)[i]->getY() == y) and (entidad != i) and ((*entidades)[i]->getHitbox())) {
      out = i;
    }
    i++;
  }

  return out;
}

int Mapa::casillaOcupadaThrow(unsigned int entidad, int &fil, int &col) {
    int out = -4;

    unsigned int x1 = (*entidades)[entidad]->getX();
    unsigned int x2 = (*entidades)[entidad]->getX();
    unsigned int x3 = (*entidades)[entidad]->getX();

    unsigned int y1 = (*entidades)[entidad]->getY();
    unsigned int y2 = (*entidades)[entidad]->getY();
    unsigned int y3 = (*entidades)[entidad]->getY();

    switch ((*entidades)[entidad]->getOrientacion()) {
      case norte:
        x1--;
        x2-=2;
        x3-=3;
      break;

      case este:
        y1++;
        y2+=2;
        y3+=3;
      break;

      case sur:
        x1++;
        x2+=2;
        x3+=3;
      break;
      case oeste:
        y1--;
        y2-=2;
        y3-=3;
      break;
    }

    unsigned int i = 0;
    while ((i < entidades->size()) and (out == -1)) {
      if((*entidades)[i]->getX() == x1 and (*entidades)[i]->getY() == y1 and (*entidades)[i]->getHitbox() and entidad != i) {
        out = i;
      }

      if((*entidades)[i]->getX() == x2 and (*entidades)[i]->getY() == y2 and (*entidades)[i]->getHitbox() and entidad != i) {
        out = i;
      }

      if((*entidades)[i]->getX() == x3 and (*entidades)[i]->getY() == y3 and (*entidades)[i]->getHitbox() and entidad != i) {
        out = i;
      }
      i++;
    }

    if (out == -1) {
	    if (mapaCompleto[x3][y3]=='S' or mapaCompleto[x3][y3]=='T') {
	      fil = x3;
	      col = y3;
	      out = -3;
	    }
	    else if (mapaCompleto[x2][y2]=='S' or mapaCompleto[x2][y2]=='T') {
	      fil = x2;
	      col = y2;
	      out = -2;
	    }
	    else if (mapaCompleto[x1][y1]=='S' or mapaCompleto[x1][y1]=='T') {
	      fil = x1;
	      col = y1;
	      out = -1;
	    }
    }

    return out;
}

void Mapa::girarCamaraIzquierda() {
  angulo -= 90.0;
  if (angulo < 0.0) {
    angulo = 270.0;
  }
}

void Mapa::girarCamaraDerecha() {
  angulo += 90.0;
  if (angulo >= 360.0) {
    angulo = 0.0;
  }
}

unsigned char Mapa::entidadEnCelda(unsigned int x, unsigned int y) {
  unsigned char out = '_';
  bool encontrado = false;
  unsigned int aux = 0, i = 0;

  while ((i< entidades->size()) and (!encontrado)) {
    if((*entidades)[i]->getX() == x and (*entidades)[i]->getY() == y and (*entidades)[i]->getHitbox()) {
      encontrado = true;
      aux = i;
    }
    i++;
  }

  if (encontrado and (*entidades)[aux]->getHitbox()) {
    switch ((*entidades)[aux]->getSubTipo()) {
      case jugador_: out = 'j'; break;
      case aldeano: out = 'a'; break;
    }
  }

  return out;
}

vector <vector< unsigned char> > Mapa::vision(unsigned int Entidad) {
  unsigned int x = (*entidades)[Entidad]->getX();
  unsigned int y = (*entidades)[Entidad]->getY();
  Orientacion orient = (*entidades)[Entidad]->getOrientacion();
  bool _jugador = (*entidades)[Entidad]->getTipo() == jugador;

  vector <vector< unsigned char> > fov;
  vector< unsigned char> aux(16);
  fov.push_back(aux);
  fov.push_back(aux);
  switch (orient) {
    case norte:
    fov[0][0] = getCelda(x, y);
    fov[0][1] = getCelda(x-1, y-1);
    fov[0][2] = getCelda(x-1, y);
    fov[0][3] = getCelda(x-1, y+1);
    fov[0][4] = getCelda(x-2, y-2);
    fov[0][5] = getCelda(x-2, y-1);
    fov[0][6] = getCelda(x-2, y);
    fov[0][7] = getCelda(x-2, y+1);
    fov[0][8] = getCelda(x-2, y+2);
    fov[0][9] = getCelda(x-3, y-3);
    fov[0][10] = getCelda(x-3, y-2);
    fov[0][11] = getCelda(x-3, y-1);
    fov[0][12] = getCelda(x-3, y);
    fov[0][13] = getCelda(x-3, y+1);
    fov[0][14] = getCelda(x-3, y+2);
    fov[0][15] = getCelda(x-3, y+3);

    fov[1][0] = entidadEnCelda(x, y);
    fov[1][1] = entidadEnCelda(x-1, y-1);
    fov[1][2] = entidadEnCelda(x-1, y);
    fov[1][3] = entidadEnCelda(x-1, y+1);
    fov[1][4] = entidadEnCelda(x-2, y-2);
    fov[1][5] = entidadEnCelda(x-2, y-1);
    fov[1][6] = entidadEnCelda(x-2, y);
    fov[1][7] = entidadEnCelda(x-2, y+1);
    fov[1][8] = entidadEnCelda(x-2, y+2);
    fov[1][9] = entidadEnCelda(x-3, y-3);
    fov[1][10] = entidadEnCelda(x-3, y-2);
    fov[1][11] = entidadEnCelda(x-3, y-1);
    fov[1][12] = entidadEnCelda(x-3, y);
    fov[1][13] = entidadEnCelda(x-3, y+1);
    fov[1][14] = entidadEnCelda(x-3, y+2);
    fov[1][15] = entidadEnCelda(x-3, y+3);

    break;

    case este:
    fov[0][0] = getCelda(x, y);
    fov[0][1] = getCelda(x-1, y+1);
    fov[0][2] = getCelda(x, y+1);
    fov[0][3] = getCelda(x+1, y+1);
    fov[0][4] = getCelda(x-2, y+2);
    fov[0][5] = getCelda(x-1, y+2);
    fov[0][6] = getCelda(x, y+2);
    fov[0][7] = getCelda(x+1, y+2);
    fov[0][8] = getCelda(x+2, y+2);
    fov[0][9] = getCelda(x-3, y+3);
    fov[0][10] = getCelda(x-2, y+3);
    fov[0][11] = getCelda(x-1, y+3);
    fov[0][12] = getCelda(x, y+3);
    fov[0][13] = getCelda(x+1, y+3);
    fov[0][14] = getCelda(x+2, y+3);
    fov[0][15] = getCelda(x+3, y+3);


    fov[1][0] = entidadEnCelda(x, y);
    fov[1][1] = entidadEnCelda(x-1, y+1);
    fov[1][2] = entidadEnCelda(x, y+1);
    fov[1][3] = entidadEnCelda(x+1, y+1);
    fov[1][4] = entidadEnCelda(x-2, y+2);
    fov[1][5] = entidadEnCelda(x-1, y+2);
    fov[1][6] = entidadEnCelda(x, y+2);
    fov[1][7] = entidadEnCelda(x+1, y+2);
    fov[1][8] = entidadEnCelda(x+2, y+2);
    fov[1][9] = entidadEnCelda(x-3, y+3);
    fov[1][10] = entidadEnCelda(x-2, y+3);
    fov[1][11] = entidadEnCelda(x-1, y+3);
    fov[1][12] = entidadEnCelda(x, y+3);
    fov[1][13] = entidadEnCelda(x+1, y+3);
    fov[1][14] = entidadEnCelda(x+2, y+3);
    fov[1][15] = entidadEnCelda(x+3, y+3);

    break;

    case sur:
    fov[0][0] = getCelda(x, y);
    fov[0][1] = getCelda(x+1, y+1);
    fov[0][2] = getCelda(x+1, y);
    fov[0][3] = getCelda(x+1, y-1);
    fov[0][4] = getCelda(x+2, y+2);
    fov[0][5] = getCelda(x+2, y+1);
    fov[0][6] = getCelda(x+2, y);
    fov[0][7] = getCelda(x+2, y-1);
    fov[0][8] = getCelda(x+2, y-2);
    fov[0][9] = getCelda(x+3, y+3);
    fov[0][10] = getCelda(x+3, y+2);
    fov[0][11] = getCelda(x+3, y+1);
    fov[0][12] = getCelda(x+3, y);
    fov[0][13] = getCelda(x+3, y-1);
    fov[0][14] = getCelda(x+3, y-2);
    fov[0][15] = getCelda(x+3, y-3);

    fov[1][0] = entidadEnCelda(x, y);
    fov[1][1] = entidadEnCelda(x+1, y+1);
    fov[1][2] = entidadEnCelda(x+1, y);
    fov[1][3] = entidadEnCelda(x+1, y-1);
    fov[1][4] = entidadEnCelda(x+2, y+2);
    fov[1][5] = entidadEnCelda(x+2, y+1);
    fov[1][6] = entidadEnCelda(x+2, y);
    fov[1][7] = entidadEnCelda(x+2, y-1);
    fov[1][8] = entidadEnCelda(x+2, y-2);
    fov[1][9] = entidadEnCelda(x+3, y+3);
    fov[1][10] = entidadEnCelda(x+3, y+2);
    fov[1][11] = entidadEnCelda(x+3, y+1);
    fov[1][12] = entidadEnCelda(x+3, y);
    fov[1][13] = entidadEnCelda(x+3, y-1);
    fov[1][14] = entidadEnCelda(x+3, y-2);
    fov[1][15] = entidadEnCelda(x+3, y-3);



    break;
    case oeste:
      fov[0][0] = getCelda(x, y);
      fov[0][1] = getCelda(x+1, y-1);
      fov[0][2] = getCelda(x, y-1);
      fov[0][3] = getCelda(x-1, y-1);
      fov[0][4] = getCelda(x+2, y-2);
      fov[0][5] = getCelda(x+1, y-2);
      fov[0][6] = getCelda(x, y-2);
      fov[0][7] = getCelda(x-1, y-2);
      fov[0][8] = getCelda(x-2, y-2);
      fov[0][9] = getCelda(x+3, y-3);
      fov[0][10] = getCelda(x+2, y-3);
      fov[0][11] = getCelda(x+1, y-3);
      fov[0][12] = getCelda(x, y-3);
      fov[0][13] = getCelda(x-1, y-3);
      fov[0][14] = getCelda(x-2, y-3);
      fov[0][15] = getCelda(x-3, y-3);


      fov[1][0] = entidadEnCelda(x, y);
      fov[1][1] = entidadEnCelda(x+1, y-1);
      fov[1][2] = entidadEnCelda(x, y-1);
      fov[1][3] = entidadEnCelda(x-1, y-1);
      fov[1][4] = entidadEnCelda(x+2, y-2);
      fov[1][5] = entidadEnCelda(x+1, y-2);
      fov[1][6] = entidadEnCelda(x, y-2);
      fov[1][7] = entidadEnCelda(x-1, y-2);
      fov[1][8] = entidadEnCelda(x-2, y-2);
      fov[1][9] = entidadEnCelda(x+3, y-3);
      fov[1][10] = entidadEnCelda(x+2, y-3);
      fov[1][11] = entidadEnCelda(x+1, y-3);
      fov[1][12] = entidadEnCelda(x, y-3);
      fov[1][13] = entidadEnCelda(x-1, y-3);
      fov[1][14] = entidadEnCelda(x-2, y-3);
      fov[1][15] = entidadEnCelda(x-3, y-3);
    break;
  }

  return fov;
}
