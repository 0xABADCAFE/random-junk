#ifndef _AEK_VEC3_HPP_
    #define _AEK_VEC3_HPP
    #include <cmath>

/**
 * Simple three component vector with value semantics. Component values are directly accessible.
 * Artithmetic operations are realised using operators.
 */
class Vec3 {
    public:
        float32 x, y, z;

        // Constructors
        Vec3()                : x(0.0f), y(0.0f), z(0.0f) { }
        Vec3(const float32 v) : x(v), y(v), z(v) { }
        Vec3(const float32 a, const float32 b, const float32 c) : x(a), y(b), z(c) { }

        /**
         * Multiply by a scalar.
         *
         * @param const float32 f
         * @return Vec3&
         */
        Vec3& operator*=(const float32 f) {
            x *= f;
            y *= f;
            z *= f;
            return *this;
        }

        /**
         * Add a Vec3.
         *
         * @param const Vec3& v
         * @return Vec3&
         */
        Vec3& operator+=(const Vec3& v) {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        /**
         * Subtract a Vec3.
         *
         */
        Vec3& operator-=(const Vec3& v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }
} __attribute__((aligned(16)));


/**
 * Vec3 product of a Vec3 and a scalar float
 *
 * Vec3 = Vec3 * float
 */
inline Vec3 operator*(const Vec3& v, const float32 f) {
    return Vec3(
        v.x * f,
        v.y * f,
        v.z * f
    );
}

/**
 * Vec3 product of a scalar float and a Vec3
 *
 * Vec3 = float * Vec3
 */
inline Vec3 operator*(const float32 f, const Vec3& v) {
    return Vec3(
        v.x * f,
        v.y * f,
        v.z * f
    );
}

/**
 * Vec3 sum of a pair of Vec3
 *
 * Vec3 = Vec3 + Vec3
 */
inline Vec3 operator+(const Vec3& v1, const Vec3& v2) {
    return Vec3(
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z
    );
}

/**
 * Vec3 difference of a pair of Vec3
 *
 * Vec3 = Vec3 - Vec3
 */
inline Vec3 operator-(const Vec3& v1, const Vec3& v2) {
    return Vec3(
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    );
}

/**
 * Vec3 cross product of a pair of Vec3
 *
 * Vec3 = Vec3 * Vec3
 */
inline Vec3 operator*(const Vec3& v1, const Vec3& v2) {
    return Vec3(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}

/**
 * Scalar float dot product of a pair of Vec3
 *
 * float = Vec3 ^ Vec3
 */
inline float32 operator^(const Vec3& v1, const Vec3& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/**
 * Vec3 normalised unit vector of a Vec3
 *
 * Vec3 = ~Vec3
 */
inline Vec3 operator~(const Vec3& v) {
    return v * (1.0f / std::sqrt(v ^ v));
}

/**
 * Vec3 half-vector of a pair of Vec3
 *
 * Vec3 = Vec3 | Vec3
 */
inline Vec3 operator|(const Vec3& v1, const Vec3& v2) {
    return v1 + v2 * (v2 ^ v1) * -2.0f;
}


#endif
