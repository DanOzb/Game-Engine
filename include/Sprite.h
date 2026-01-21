#pragma once
#include "Component.h"

  namespace engine {

  class Sprite : public Component {
  public:
      Sprite(float x, float y, float w, float h, SDL_Texture* tex);
      ~Sprite();
      void draw() const override;

  private:
      SDL_Texture* texture;
  };
  }