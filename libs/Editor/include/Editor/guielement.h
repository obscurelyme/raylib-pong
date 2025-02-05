#ifndef ZERO_EDITOR_GUI_ELEMENT_H_
#define ZERO_EDITOR_GUI_ELEMENT_H_

#include <imgui.h>
#include <raylib.h>
#include <yoga/Yoga.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "Editor/types.h"
#include "types.h"

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
      virtual void setGap(const Gap&);
      virtual void setTitle(const std::string&);
      // Recalculate the size and position of this element based on the parent's calculation
      virtual void calculate();
      virtual void calculateSize();
      virtual void calculateBorder();
      virtual void calculateMargin();
      virtual void calculatePadding();
      virtual void calculatePosition();
      virtual Vector4 calculateVec4(const float, const float, const float, const float, const float);

      // Returns true if this element is valid and can be drawn
      virtual bool isValidElement();
      // Returns true if this element's tree is valid and can be drawn
      virtual bool isValidTree();

      virtual void setId(const std::string& id) {
        this->id = id;
        profilerStringId = toProfilerFormatString();
      }

      void startProfile(const std::string&);
      void endProfile(const std::string&);
      void pauseProfile(const std::string&);
      void resumeProfile(const std::string&);

      YGNodeRef node{nullptr};
      std::string title{""};
      std::string innerText{""};
      std::string id{""};
      GuiElement* parent{nullptr};
      std::vector<GuiElement*> children{};
      Vector2 calculatedSize{0, 0};
      Vector2 calculatedPosition{0, 0};
      Vector4 border{0, 0, 0, 0};
      Vector4 margin{0, 0, 0, 0};
      Vector4 padding{0, 0, 0, 0};
      Vector2 gap{0, 0};
      Elements type{Elements::Unknown};

    protected:
      static std::unordered_map<Elements, std::string> elementTypeNames;
      std::unordered_map<Attribute, bool> requiredAttributes{};
      void debugLayout();
      std::string toProfilerFormatString() const;
      std::string profilerStringId{""};
  };
}  // namespace Zero

#endif  // ZERO_EDITOR_GUI_ELEMENT_H_