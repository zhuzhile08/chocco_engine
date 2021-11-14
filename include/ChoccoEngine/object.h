#pragma once

#include <string>

#include <ChoccoEngine/Cmath.h>

namespace chocco {
    class Object {
    protected:
        Vector2 position, scale;
        std::string name = "Object";
        Object* parent = nullptr;
        int flipped = 1;
        double rotation = 0;
    public:
        Object();
        Object(std::string name, Vector2 position, Vector2 scale, double rotation);

        std::string get_name();

        Vector2 getLocalPos();
        void translate(Vector2 vel);
        void rotate(double rot);
        void input();
        void update();
    };
}