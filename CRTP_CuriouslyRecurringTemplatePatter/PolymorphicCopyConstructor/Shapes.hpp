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

#ifndef __SHAPES_INCLUDE__
#define __SHAPES_INCLUDE__

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
 * As we can see for each structure we have to write its own method Clone which contains the same exact code except for the type.
 * This code duplication is what we want to avoid.
 */

struct Rectangle : Shape {
    virtual Shape* Clone() override { return new Rectangle(*this); }
	int x1,y2,x3,x4;
};

struct Triangle : Shape { 
    virtual Shape* Clone() override { return new Triangle(*this); }
	int x1,x2,x3;
};

struct Circle : Shape {
    virtual Shape* Clone() override { return new Circle(*this); }
    int x1, radius;
};


#endif /* ifndef __SHAPES_INCLUDE__ */
