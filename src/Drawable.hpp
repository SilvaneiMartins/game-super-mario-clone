/**
 * @file Drawable.hpp
 * @brief Drawable classe de declaração.
 * @version 0.1
 * @date 25/02/2024
 * @copyright copyright (c) 2024 Silvanei Martins
 *
 * @author Silvanei Martins
 */
#pragma once

class Drawable
{
    public:
        virtual ~Drawable() = default;
        virtual void draw() = 0;
};
