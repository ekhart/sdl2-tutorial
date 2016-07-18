#ifndef RES_PATH_H
#define RES_PATH_H

#include <iostream>
#include <string>
#include <SDL.h>

/*
 * Getthe resource for resources located in res/subDir
 * It's assumed the project direcotry i structed like:
 * bin/
 *  the executable
 * res/
 *  Lesson1/
 *  Lesson2/
 *
 * Path returned will be Lessons/res/subDir
 */
std::string getResourcePath(const std::string &subDir = "");

#endif