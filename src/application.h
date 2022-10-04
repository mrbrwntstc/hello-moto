#include <cstdlib>

#include "motion/moto.h"

class Application
{
protected: // fields
  /** height of the application window */
  int height;

  /** width of the application window */
  int width;

public: // methods

  /**
   * Gets the title of the demo for the title bar of the window.
   * 
   * Default implementation returns a generic title.
   */
  virtual const char* get_title();

  /**
   * Sets up graphics and allows the application to acquire graphical resources.
   * Guaranteed to be called after OpenGL is set up.
   * 
   * Default implementation sets up a basic view and calls set_view to set up the camera projection.
   */
  virtual void initialize_graphics();

  /**
   * Set projection characteristics of the camera.
   * 
   * Default implementation uses a 60 degree field of view camera with a range from 1-500 units.
   */
  virtual void set_view();

  /**
   * Called before the application is destroyed.
   * Clear up can be performed here or in the application destructor.
   * 
   * Default implementation does nothing.
   */
  virtual void deinitialize();

  /**
   * Called each frame to display the current scene.
   * The common code will automatically flush the graphics pipe and swap the render buffers after calling this.
   * Because of this, glFlush does not need to be called.
   * 
   * Default implementation is to draw a diagonal line across the surface (sanity check)
   * 
   */
  virtual void display();

  /**
   * Called each frame to update the current state of the scene.
   * 
   * Default implementation requests that the display be refreshed.
   * It should probably be called from any subclass update as the last command.
   * 
   */
  virtual void update();

  /**
   * Called when a keypress is detected.
   * 
   * Default implementation does nothing.
   * 
   * @param key the ascii code of the key that has been pressed
   */
  virtual void key(unsigned char key);

  /**
   * Notifies the application that the window has changed size.
   * The new size is given.
   * 
   * Default implementation sets the internal height and width parameters and changes the gl viewport.
   * These steps are almost always needed, so it's worth calling the base class version of this method even if it's overridden
   */
  virtual void resize(int width, int height);

  /**
   * Called when GLUT detects a mouse button press
   * 
   * Default implementation does nothing
   */
  virtual void mouse(int button, int state, int x, int y);

  /**
   * Called when GLUT detects a mouse drag
   * 
   * Default implementation does nothing
   */
  virtual void mouse_drag(int x, int y);

  // helper functions that can be used by an application to render things

  /**
   * Renders the given text to the given x,y location (in screen space) on the window.
   * This is used to pass status information over to the application.
   */
  void render_text(float x, float y, const char* text, void* font=NULL);
};
