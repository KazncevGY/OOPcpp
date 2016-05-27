#include "Shape.h"
#include <stdlib.h>
#include <time.h>

#pragma once

Point * getRandomPoint(float maxX, float maxY);

Circle * getRandomCircle(float maxX, float maxY, float maxR);

Rectangle * getRandomRectangle(float maxX, float maxY);

Square * getRandomSquare(float maxX, float maxY, float maxA);

Polyline * getRandomPolyline(float maxX, float maxY, int maxNumber);