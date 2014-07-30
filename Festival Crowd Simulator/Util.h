#ifndef __Util_H_
#define __Util_H_

//includes
#include <windows.h>
#include <cassert>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// macro defines
#define RELEASE_AND_CLEAN(p) {if(p != 0) {p->Release();p=0;}}
#define DELETE_AND_CLEAN(p) {if(p != 0) {delete (p);p=0;}}
#define LOG(p) {std::cout << p;}
#define LOG_W(p) {std::wcout << p;}


//ENGINE define
#define ENGINE (Engine::GetSingleton())

#endif //__Util_H_