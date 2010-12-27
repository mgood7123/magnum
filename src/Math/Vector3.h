#ifndef Magnum_Math_Vector3_h
#define Magnum_Math_Vector3_h
/*
    Copyright © 2010 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

/** @file
 * @brief Class Magnum::Math::Vector3
 */

#include "Vector.h"

namespace Magnum { namespace Math {

/** @brief Vector (three-component) */
template<class T> class Vector3: public Vector<T, 3> {
    public:
        /** @brief Cross product */
        static Vector3<T> cross(const Vector3<T>& a, const Vector3<T>& b) {
            return Vector3<T>(a[1]*b[2]-a[2]*b[1],
                              a[2]*b[0]-a[0]*b[2],
                              a[0]*b[1]-a[1]*b[0]);
        }

        /** @copydoc Vector::Vector */
        inline Vector3() {}

        /** @copydoc Vector::Vector(const T*) */
        inline Vector3(const T* data): Vector<T, 3>(data) {}

        /** @copydoc Vector::Vector(const Vector&)  */
        inline Vector3(const Vector<T, 3>& other): Vector<T, 3>(other) {}

        /**
         * @brief Constructor
         * @param x     X / R value
         * @param y     Y / G value
         * @param z     Z / B value
         */
        inline Vector3(T x, T y, T z) {
            setX(x); setY(y); setZ(z);
        }

        inline T x() const { return Vector<T, 3>::at(0); } /**< @brief X component */
        inline T y() const { return Vector<T, 3>::at(1); } /**< @brief Y component */
        inline T z() const { return Vector<T, 3>::at(2); } /**< @brief Z component */

        inline void setX(T value) { set(0, value); } /**< @brief Set X component */
        inline void setY(T value) { set(1, value); } /**< @brief Set Y component */
        inline void setZ(T value) { set(2, value); } /**< @brief Set Z component */

        inline T r() const { return x(); } /**< @brief R component */
        inline T g() const { return x(); } /**< @brief G component */
        inline T b() const { return z(); } /**< @brief B component */

        inline void setR(T value) { setX(value); } /**< @brief Set R component */
        inline void setG(T value) { setY(value); } /**< @brief Set G component */
        inline void setB(T value) { setZ(value); } /**< @brief Set B component */
};

}}

#endif
