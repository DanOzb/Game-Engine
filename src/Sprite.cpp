#include "Sprite.h"
#include "GameEngine.h"

  namespace engine {
  Sprite::Sprite(float x, float y, float w, float h, SDL_Texture* tex)
      : Component(x, y, w, h), texture(tex) {}
  Sprite::~Sprite() {
      if (texture) SDL_DestroyTexture(texture);
  }
  void Sprite::draw() const {
      SDL_FRect r = getRect();
      SDL_RenderTexture(eng.getRenderer(), texture, nullptr, &r);
  }
}