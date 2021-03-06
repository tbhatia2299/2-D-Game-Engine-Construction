#include <vector>
#include <SDL.h>
#include "ioMod.h"
#include "renderContext.h"
#include "clock.h"
#include "world.h"
#include "viewport.h"
#include "hud.h"

class CollisionStrategy;
class SmartSprite;
class SubjectSprite;
class ShootingSprite;

class Engine {
public:
  Engine ();
  ~Engine ();
  void play();

  Engine(const Engine&) = delete;
  Engine& operator=(const Engine&) = delete;

private:
  const RenderContext* rc;
  const IOmod& io;
  Clock& clock;

  SDL_Renderer * const renderer;
  World sky;
  World purplesky;
  World road;
  Viewport& viewport;

  ShootingSprite* player;
  std::vector<Drawable*> sprites;
  std::vector<SmartSprite*> smart;
  CollisionStrategy* strategy;
  bool collision;

  unsigned int hudTime;
  bool drawHud;
  Hud& hud;

  int currentSprite;

  bool makeVideo;

  void draw() const;
  void update(Uint32);

  void printScales() const;
  void checkForCollisions();

};
