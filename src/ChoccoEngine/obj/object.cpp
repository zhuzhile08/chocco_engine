#include <ChoccoEngine/object.h>

namespace chocco {
    // Consturctor
    Object::Object() {}

    Object::Object(Vector2 position, Vector2 scale, double rotation, std::string name) : position(position), scale(scale), rotation(rotation), Node(nullptr, name) { }

    // update function
    void Object::update() {
        return;
    }

    // some getters and setters
    Vector2 Object::getPosition() {
        return position;
    } 
    
    Vector2 Object::getScale() {
        return scale;
    }

    double Object::getRotation() {
        return rotation;
    }

    void Object::translate(Vector2 vel) {
        position += vel;
    } 
    
    void Object::rotate(double rot) {
        rotation += rot;
    } 
    
    void Object::resize(Vector2 newScale) {
        scale += newScale;
    }
}
