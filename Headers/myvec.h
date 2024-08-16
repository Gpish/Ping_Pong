#ifndef MYVEC_H
#define MYVEC_H

struct Vector{
    float x, y, z;
    Vector(float x = 0.0F, float y = 0.0F, float z = 0.0F) : x(x), y(y), z(z) {}
    Vector(const Vector &v) { x = v.x; y = v.y; z = v.z; }
    Vector& operator +(const Vector &v)
    {
        x += v.x; 
        y += v.y;
        z += v.z;
        return *this;
    }
    Vector& operator -(const Vector &v)
    {
        x -= v.x; 
        y -= v.y;
        z -= v.z;
        return *this;
    }
    Vector& operator *(const int &a)
    {
        x *= static_cast<float>(a); 
        y *= static_cast<float>(a);
        z *= static_cast<float>(a);
        return *this;
    }
};

#endif

