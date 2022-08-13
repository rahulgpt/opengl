#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
  GLFWwindow *window;

  if (!glfwInit())
  {
    fprintf(stderr, "Failed to initialize GLFW\n");
    exit(EXIT_FAILURE);
  }

  window = glfwCreateWindow(800, 640, "Example", NULL, NULL);
  if (!window)
  {
    fprintf(stderr, "Failed to open GLFW window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK)
  {
    std::cout << "ERROR initializing glew" << std::endl;
  }

  std::cout << "VERSION: " << glGetString(GL_VERSION) << std::endl;

  while (!glfwWindowShouldClose(window))
  {

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Terminate GLFW
  glfwTerminate();
}