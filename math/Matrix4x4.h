#pragma once

#include "Vector3.h"

class Matrix4x4 {
public:
    float m[4][4];

    // コンストラクタやその他のメソッドは省略

    // Vector3との掛け算
    Vector3 operator*(const Vector3& v) const {
        Vector3 result;
        result.x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0];
        result.y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1];
        result.z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2];
        float w = m[0][3] * v.x + m[1][3] * v.y + m[2][3] * v.z + m[3][3];
        if (w != 0.0f) {
            result.x /= w;
            result.y /= w;
            result.z /= w;
        }
        return result;
    }
};
