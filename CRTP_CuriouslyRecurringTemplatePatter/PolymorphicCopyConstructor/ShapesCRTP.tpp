/******************************************************************************
* File:             main.cpp
*
* Author:           Robert Esclapez García
* Created:          03/24/20
* Description:      Testing for the record the pattern CRTP (Curiously Recurring Template Pattern)
*
* Copyright 2020 Robert Esclapez García
*
* Licensed under the "THE BEER-WARE LICENSE" (Revision 42):
* Robert Esclapez García wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer or coffee in return
*
*****************************************************************************/

#ifndef __SHAPES_CRTP_INCLUDE__
#define __SHAPES_CRTP_INCLUDE__

#include <vector>

/*
 * Base class for our experiment.
 * It contains the common interface to all the subtypes of Shape.
 * This example only contains the method Clone that returns the exact data that the current object contains.
 */
struct Shape {
    virtual Shape* Clone() = 0;
	virtual ~Shape() = default;
};

/*
 * With this struct we aim to avoid the code duplication we have seen in the previous example.
 * Thanks to the two phases the compiler makes to instanciate the templates we can build
 * our middle structure this way.
 * This way we mantain the requisities from the Shape interface, also we can take advantage of
 * the templates to build this new Clone implementation that uses the template parameter to
 * create one clone specialiced for each structure that implements the interface Shape.
 */
template<typename T>
struct IShape : Shape {	
	virtual Shape* Clone() override {
        return new T(*static_cast<T*>(this));
	}
};

/*
 * As we can see, all the code duplication has disappeared.
 */
struct Rectangle : IShape<Rectangle> {};

struct Triangle : IShape<Triangle> {};

struct Circle : IShape<Circle> {};

#endif /* ifndef __SHAPES_CRTP_INCLUDE__ */
