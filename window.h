#pragma once
#define GL_SILENCE_DEPRECATION

// BUILT-IN
#include <vector>
#include <GLUT/glut.h>
#include <OpenGL/OpenGL.h>

// QUBIT
#include "quat.h"
#include "world.h"
#include "event.h"
#include "slerp.h"


static void reshape(int width, int height);
static void keyboard(unsigned char key, int x, int y);
static void keyboardUp(unsigned char key, int x, int y);
static void display();
static void customLoop();
static void idle();


void rotateAll(std::vector<Quat> &quats, Quat &axis, double radians);


class Window 
{
public:
    bool active;
    std::chrono::time_point<std::chrono::system_clock> m_tp1, m_tp2;
    int width;
    int height;
    double fFrameTimer = 0;
    int nFrameCount = 0;
    int nLastFPS = 0;

public:
    Window(int _width, int _height);
    void createWindow() const;
    void startMainLoop() const;
    void start() const;
    void exit() const;
    void renderFrame() const;
    void drawLine(Quat& a, Quat& b) const;
    void clearBuffer() const;
};
