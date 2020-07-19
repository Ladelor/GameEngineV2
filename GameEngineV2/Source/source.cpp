#include <iostream>
#include <glfw3.h>
#include "window.h"

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        return -1;
    }

    Window window = Window(800, 600, "Title");

    /* Loop until the user closes the window */
    while (!window.gameLoop())
    {
        //std::cout << "hi";
    }

    glfwTerminate();
    return 0;
}