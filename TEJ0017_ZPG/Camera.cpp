#include "Camera.h"

Camera* Camera::_instance = nullptr;

Camera::Camera(GLFWwindow* window, glm::vec3 position)
{
	_window = window;
	_position = position;
}

Camera* Camera::getInstance(GLFWwindow* window, glm::vec3 position)
{
	if (_instance == nullptr)
	{
		_instance = new Camera(window, position);
	}

	return _instance;
}

Camera* Camera::getInstance()
{
	if (_instance != nullptr)
	{
		return _instance;
	}
}

void Camera::lookAt()
{
	glfwGetWindowSize(_window, &_width, &_height);
	glViewport(0, 0, _width, _height);

	_view = glm::lookAt(_position, _position + _orientation, _up);
	_projection = glm::perspective(glm::radians(45.0f), (float)(_width / _height), 0.1f, 100.0f);
}

glm::mat4 Camera::getView()
{
	return _view;
}

glm::mat4 Camera::getProjection()
{
	return _projection;
}

glm::vec3 Camera::getPosition()
{
	return _position;
}
