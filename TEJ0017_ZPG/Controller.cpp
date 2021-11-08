#include "Controller.h"

Controller* Controller::_instance = nullptr;

Controller::Controller(Camera* camera)
{
	_camera = camera;
}

Controller* Controller::getInstance(Camera* camera)
{
	if (_instance == nullptr)
	{
		_instance = new Controller(camera);
	}

	return _instance;
}

void Controller::checkInputs()
{
	//Keyboard
	if (glfwGetKey(_camera->_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		_camera->_position += _speed * _camera->_orientation;
	}
	if (glfwGetKey(_camera->_window, GLFW_KEY_A) == GLFW_PRESS)
	{
		_camera->_position += _speed * -glm::normalize(glm::cross(_camera->_orientation, _camera->_up));
	}
	if (glfwGetKey(_camera->_window, GLFW_KEY_S) == GLFW_PRESS)
	{
		_camera->_position += _speed * -_camera->_orientation;
	}
	if (glfwGetKey(_camera->_window, GLFW_KEY_D) == GLFW_PRESS)
	{
		_camera->_position += _speed * glm::normalize(glm::cross(_camera->_orientation, _camera->_up));
	}
	if (glfwGetKey(_camera->_window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		_camera->_position += _speed * _camera->_up;
	}
	if (glfwGetKey(_camera->_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		_camera->_position += _speed * -_camera->_up;
	}
	if (glfwGetKey(_camera->_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		_speed = 0.4f;
	}
	else if (glfwGetKey(_camera->_window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		_speed = 0.1f;
	}

	//Mouse
	if (glfwGetMouseButton(_camera->_window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		glfwSetInputMode(_camera->_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (_firstClick)
		{
			glfwSetCursorPos(_camera->_window, (_camera->_width / 2), (_camera->_height / 2));
			_firstClick = false;
		}

		double mouseX;
		double mouseY;

		glfwGetCursorPos(_camera->_window, &mouseX, &mouseY);

		float rotX = _sensitivity * (float)(mouseY - (_camera->_height / 2)) / _camera->_height;
		float rotY = _sensitivity * (float)(mouseX - (_camera->_width / 2)) / _camera->_width;
		printf("%d %d\n", _camera->_height, _camera->_width);

		glm::vec3 newOrientation = glm::rotate(_camera->_orientation, glm::radians(-rotX), glm::normalize(glm::cross(_camera->_orientation, _camera->_up)));

		if (abs(glm::angle(newOrientation, _camera->_up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			_camera->_orientation = newOrientation;
		}

		_camera->_orientation = glm::rotate(_camera->_orientation, glm::radians(-rotY), _camera->_up);

		glfwSetCursorPos(_camera->_window, (_camera->_width / 2), (_camera->_height / 2));
	}
	else if (glfwGetMouseButton(_camera->_window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		glfwSetInputMode(_camera->_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		_firstClick = true;
	}
}
