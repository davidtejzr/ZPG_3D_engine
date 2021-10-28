#include "Camera.h"

Camera::Camera(GLFWwindow* window, glm::vec3 position)
{
	_window = window;
	_position = position;
}

void Camera::lookAt()
{
	glfwGetWindowSize(_window, &_width, &_height);

	_view = glm::lookAt(_position, _position + _orientation, _up);
	_projection = glm::perspective(glm::radians(45.0f), (float)(_width / _height), 0.1f, 100.0f);
}

void Camera::Controller()
{
	//Keyboard
	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		_position += _speed * _orientation;
	}
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
	{
		_position += _speed * -glm::normalize(glm::cross(_orientation, _up));
	}
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
	{
		_position += _speed * -_orientation;
	}
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
	{
		_position += _speed * glm::normalize(glm::cross(_orientation, _up));
	}
	if (glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		_position += _speed * _up;
	}
	if (glfwGetKey(_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		_position += _speed * -_up;
	}
	if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		_speed = 0.4f;
	}
	else if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		_speed = 0.1f;
	}

	//Mouse
	if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (_firstClick)
		{
			glfwSetCursorPos(_window, (_width / 2), (_height / 2));
			_firstClick = false;
		}

		double mouseX;
		double mouseY;

		glfwGetCursorPos(_window, &mouseX, &mouseY);

		float rotX = _sensitivity * (float)(mouseY - (_height / 2)) / _height;
		float rotY = _sensitivity * (float)(mouseX - (_width / 2)) / _width;

		glm::vec3 newOrientation = glm::rotate(_orientation, glm::radians(-rotX), glm::normalize(glm::cross(_orientation, _up)));

		if (abs(glm::angle(newOrientation, _up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			_orientation = newOrientation;
		}

		_orientation = glm::rotate(_orientation, glm::radians(-rotY), _up);

		glfwSetCursorPos(_window, (_width / 2), (_height / 2));
	}
	else if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		_firstClick = true;
	}
}

glm::mat4 Camera::getView()
{
	return _view;
}

glm::mat4 Camera::getProjection()
{
	return _projection;
}
