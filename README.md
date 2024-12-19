# **CS 330 - Computer Graphics and Visualization**  
**Southern New Hampshire University (SNHU)**

Welcome to the repository for the projects completed as part of the CS 330 - Computer Graphics and Visualization course at SNHU Online. This course focused on creating 3D objects and visualizations using OpenGL, GLM, and C++. Below is an overview of the project structure and features.

---

## **Project Structure**

### **Directory Breakdown:**
- **shaders/**: Contains GLSL shader files responsible for controlling the visual appearance of 3D objects.
- **Source/**: The main source files for the project, including code for scene management, camera handling, and user input processing.
- **textures/**: Includes texture files used to enhance the realism of 3D models.

---

## **Key Components**

### **SceneManager.cpp**
This file is responsible for managing the 3D scene's layout and user interactions. It handles:
- Scene initialization, including objects and shaders
- User input handling (keyboard/mouse)
- Camera and projection settings
- Rendering of 3D objects

### **ViewManager.cpp**
The ViewManager controls the camera system, including:
- Camera position and orientation
- View transformations (e.g., perspective/orthographic projections)
- Handling of dynamic camera movements and user interactions

---

## **Features Overview**

### **Project Highlights**
- **3D Objects**: The scene consists of several complex 3D models (e.g., a coffee cup, monitor, keyboard, mouse, and books). These are built from both basic geometric shapes and more intricate combinations.
- **Lighting**: The scene incorporates at least one light source to enhance the visual realism of the 3D objects.
- **Textures**: Custom-designed textures are applied to the 3D models, adding depth and realism to the scene.
- **Interactivity**: Users can interact with the objects within the scene, exploring the environment from different viewpoints.
#### **Key Functions**

The following are the key functions available for interacting with the 3D window:

- **ESC**: Close the window and exit the program.
- **W**: Zoom in.
- **S**: Zoom out.
- **A**: Pan left.
- **D**: Pan right.
- **Q**: Pan up.
- **E**: Pan down.
- **Mouse Wheel** - Change the speed of the camera.
- **1**: Switch to front view (orthographic projection).
- **2**: Switch to side view (orthographic projection).
- **3**: Switch to top view (orthographic projection).
- **P**: Switch to perspective view.

---

## **Scene Breakdown**

### **1. Overall Scene**
The scene features multiple 3D objects arranged to form a cohesive and visually engaging layout. Objects are positioned and scaled to create an immersive environment.

![Overall Scene](https://github.com/Sel022/SNHU_CS_330_Projects/blob/main/Projects/outputs/OverallScene.jpg)

### **2. Monitor**
The monitor is built from simple cubes and textured using custom designs created in Paint3D.

![Monitor](https://github.com/Sel022/SNHU_CS_330_Projects/blob/main/Projects/outputs/Monitor.jpg)

### **3. Mouse & Keyboard**
The mouse is modeled using a scaled-down sphere, while the keyboard and its individual keys are constructed using basic cubes. Textures are also created using Paint3D.

![Mouse](https://github.com/Sel022/SNHU_CS_330_Projects/blob/main/Projects/outputs/Keyboard%26Mouse.jpg)

### **4. Coffee Cup**
The coffee cup is modeled using a combination of hollow cylinders and a half-torus, showcasing the ability to combine basic shapes to form more complex objects.

![Coffee Cup](https://github.com/Sel022/SNHU_CS_330_Projects/blob/main/Projects/outputs/CoffeMug.jpg)

### **5. Pen**
The pen is constructed from a cone and an elongated cylinder, demonstrating the use of basic geometric shapes to model everyday objects.

![Pen](https://github.com/Sel022/SNHU_CS_330_Projects/blob/main/Projects/outputs/Pen.jpg)

---

## **Technical Details**

- **Programming Language**: C++ (using OpenGL for rendering)
- **Graphics Library**: OpenGL for 3D rendering
- **Shader Language**: GLSL for vertex and fragment shaders
- **Texture Design**: Custom textures created using Paint3D

---

## **Getting Started**

### **Prerequisites**

To run this project locally, ensure you have the following software installed:

- A C++ compiler (e.g., GCC or Clang)
- OpenGL 3.3 or higher
- GLFW (for window creation and input handling)

### **Building the Project**

1. **Clone the Repository**  
   Begin by cloning the repository to your local machine:
   ```bash
   git clone https://github.com/lorenarms/SNHU_CS_330_Computer_Graphics_and_Visualization.git

2. **Open the Solution**:
   - Navigate to the project directory.
   - Double-click on the `7-1_FinalProjectMilestones.sln` file to open the project in Visual Studio.

3. **Build the Solution**:
   - In Visual Studio, go to `Build` > `Build Solution`.
   - If everything is set up correctly, the solution will build without errors.

4. **Run the Project**:
   - Click on `Debug` > `Start Without Debugging` to run the project.