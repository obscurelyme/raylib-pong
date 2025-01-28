#ifndef ZERO_EDITOR_GUI_ELEMENT_H_
#define ZERO_EDITOR_GUI_ELEMENT_H_

#include <raylib.h>
#include <yoga/Yoga.h>

#include <string>
#include <vector>

#include "Editor/types.h"

namespace Zero {
  // Interface for all Editor GUI elements
  class GuiElement {
    public:
      explicit GuiElement();
      virtual ~GuiElement();

      virtual void draw();
      virtual void setWidth(float width, bool percent = false);
      virtual void setHeight(float height, bool percent = false);

      virtual float getWidth();
      virtual float getHeight();
      virtual float getTop();
      virtual float getLeft();

      virtual void addChild(GuiElement* element);
      virtual void removeChild(GuiElement* element);
      virtual void drawChildren();
      virtual void setFlexStyles(const Flex&);
      virtual void setStyles(const Styles&);
      virtual void setBorder(const Border&);
      virtual void setMargin(const Margin&);
      virtual void setPadding(const Padding&);
      virtual void setTitle(const std::string&);
      // Recalculate the size and position of this element based on the parent's calculation
      virtual void calculate();
      virtual void calculateSize();
      virtual void calculatePosition();

      YGNodeRef node{nullptr};
      std::string title{""};
      std::string id{""};
      GuiElement* parent{nullptr};
      std::vector<GuiElement*> children{};
      Vector2 calculatedSize{0, 0};
      Vector2 calculatedPosition{0, 0};
  };
}  // namespace Zero

#endif  // ZERO_EDITOR_GUI_ELEMENT_H_