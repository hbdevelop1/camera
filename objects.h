

#include "soho/Matrices.h"
#include <list>
using namespace std;


void draw_pyramid();
void small_draw_pyramid();
void draw_cube();
void blue_draw_pyramid();
void green_draw_pyramid();
void red_draw_pyramid();

void DrawGrid();
void DrawAxis();


struct Object
{
  Object(void(*d_raw)(), float _angle, Vector3 _displacement);

  void draw();
  virtual void update();

  list<Object *> children;
  void(*drawfunction)();
  Matrix4         m;
  Vector3         displacement;
  float           angle;
};

struct Pyramid: public Object
{
  Pyramid(void(*d_raw)(), float _angle, Vector3 _displacement):Object(d_raw, _angle, _displacement){}
  void update();
};

struct Cube: public Object
{
  Cube(void(*d_raw)(), float _angle, Vector3 _displacement):Object(d_raw, _angle, _displacement){}
  void update();
};

