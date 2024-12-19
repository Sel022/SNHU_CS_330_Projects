///////////////////////////////////////////////////////////////////////////////
// maincode.cpp
// ============
// gets called when application is launched - initializes GLEW, GLFW
//
//  AUTHOR: Brian Battersby - SNHU Instructor / Computer Science
//	Created for CS-330-Computational Graphics and Visualization, Nov. 1st, 2023
///////////////////////////////////////////////////////////////////////////////

#include <iostream>         // error handling and output
#include <cstdlib>          // EXIT_FAILURE

#include <GL/glew.h>        // GLEW library
#include "GLFW/glfw3.h"     // GLFW library

// GLM Math Header inclusions
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "SceneManager.h"
#include "ViewManager.h"
#include "ShapeMeshes.h"
#include "ShaderManager.h"

// Namespace for declaring global variables
namespace
{
	// Macro for window title
	const char* const WINDOW_TITLE = "7-1 FinalProject and Milestones";

	// Main GLFW window
	GLFWwindow* g_Window = nullptr;

	// scene manager object for managing the 3D scene prepare and render
	SceneManager* g_SceneManager = nullptr;
	// shader manager object for dynamic interaction with the shader code
	ShaderManager* g_ShaderManager = nullptr;
	// view manager object for managing the 3D view setup and projection to 2D
	ViewManager* g_ViewManager = nullptr;
}

// Function declarations - all functions that are called manually
// need to be pre-declared at the beginning of the source code.
bool InitializeGLFW();
bool InitializeGLEW();
void processInput(GLFWwindow* window);

GLfloat tx, ty, tz;
GLfloat sx, sy, sz;
/***********************************************************
 *  main(int, char*)
 *
 *  This function gets called after the application has been
 *  launched.
 ***********************************************************/
int main(int argc, char* argv[])
{
	// if GLFW fails initialization, then terminate the application
	if (InitializeGLFW() == false)
	{
		return(EXIT_FAILURE);
	}

	// try to create a new shader manager object
	g_ShaderManager = new ShaderManager();
	// try to create a new view manager object
	g_ViewManager = new ViewManager(
		g_ShaderManager);

	// try to create the main display window
	g_Window = g_ViewManager->CreateDisplayWindow(WINDOW_TITLE);

	// if GLEW fails initialization, then terminate the application
	if (InitializeGLEW() == false)
	{
		return(EXIT_FAILURE);
	}

	// load the shader code from the external GLSL files
	g_ShaderManager->LoadShaders(
		"shaders/vertexShader.glsl",
		"shaders/fragmentShader.glsl");
	g_ShaderManager->use();

	// try to create a new scene manager object and prepare the 3D scene
	g_SceneManager = new SceneManager(g_ShaderManager);
	g_SceneManager->PrepareScene();

	std::cout << "\n*** KEY FUNCTIONS: ***\n";
	std::cout << "ESC - close the window and exit\n";
	std::cout << "W - zoom in\t" << "S - zoom out\n";
	std::cout << "A - pan left\t" << "D - pan right\n";
	std::cout << "Q - pan up\t" << "E - pan down\n";
	std::cout << "1 - front view (ortho)\n";
	std::cout << "2 - side view (ortho)\n";
	std::cout << "3 - top view (ortho)\n";
	std::cout << "P - perspective view\n";

	// loop will keep running until the application is closed 
	// or until an error has occurred
	while (!glfwWindowShouldClose(g_Window))
	{
		// Enable z-depth
		glEnable(GL_DEPTH_TEST);

		processInput(g_Window);

		// Clear the frame and z buffers
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// convert from 3D object space to 2D view
		g_ViewManager->PrepareSceneView();

		// refresh the 3D scene
		g_SceneManager->RenderScene();


		// Flips the the back buffer with the front buffer every frame.
		glfwSwapBuffers(g_Window);

		// query the latest GLFW events
		glfwPollEvents();
	}

	// clear the allocated manager objects from memory
	if (NULL != g_SceneManager)
	{
		delete g_SceneManager;
		g_SceneManager = NULL;
	}
	if (NULL != g_ViewManager)
	{
		delete g_ViewManager;
		g_ViewManager = NULL;
	}
	if (NULL != g_ShaderManager)
	{
		delete g_ShaderManager;
		g_ShaderManager = NULL;
	}

	// Terminates the program successfully
	exit(EXIT_SUCCESS);
}

void processInput(GLFWwindow* window)
{

	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
		tx += 0.05f;
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
		tx -= 0.05f;

	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		ty += 0.05f;
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		ty -= 0.05f;

	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
		tz += 0.05f;
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
		tz -= 0.05f;

	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		sx += 0.05f;
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
		sx -= 0.05f;

	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
		sy += 0.05f;
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		sy -= 0.05f;

	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
		sz += 0.05f;
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		sz -= 0.05f;

	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
	{
		std::cout << "tx = " << tx << " ty = " << ty << " tz = " << tz << std::endl;
		std::cout << "sx = " << sx << " sy = " << sy << " sz = " << sz << std::endl;
	}

}

/***********************************************************
 *	InitializeGLFW()
 *
 *  This function is used to initialize the GLFW library.
 ***********************************************************/
bool InitializeGLFW()
{
	// GLFW: initialize and configure library
	// --------------------------------------
	glfwInit();

#ifdef __APPLE__
	// set the version of OpenGL and profile to use
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
	// set the version of OpenGL and profile to use
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
	// GLFW: end -------------------------------

	return(true);
}

/***********************************************************
 *	InitializeGLEW()
 *
 *  This function is used to initialize the GLEW library.
 ***********************************************************/
bool InitializeGLEW()
{
	// GLEW: initialize
	// -----------------------------------------
	GLenum GLEWInitResult = GLEW_OK;

	// try to initialize the GLEW library
	GLEWInitResult = glewInit();
	if (GLEW_OK != GLEWInitResult)
	{
		std::cerr << glewGetErrorString(GLEWInitResult) << std::endl;
		return false;
	}
	// GLEW: end -------------------------------

	// Displays a successful OpenGL initialization message
	std::cout << "INFO: OpenGL Successfully Initialized\n";
	std::cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << "\n" << std::endl;

	return(true);
}