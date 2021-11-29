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

		if (_firstClickRight)
		{
			glfwSetCursorPos(_camera->_window, (_camera->_width / 2), (_camera->_height / 2));
			_firstClickRight = false;
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
		_firstClickRight = true;

		if (glfwGetMouseButton(_camera->_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			glfwSetInputMode(_camera->_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
			if (_firstClickRight)
			{
				glfwSetCursorPos(_camera->_window, (_camera->_width / 2), (_camera->_height / 2));
				_firstClickRight = false;
			}

			double mouseX;
			double mouseY;
			glfwGetCursorPos(_camera->_window, &mouseX, &mouseY);

			//identifikace objektu
			GLbyte color[4];
			GLfloat depth;
			GLuint index;

			//GLint x = (GLint)x;
			//GLint y = (GLint)y;

			int newy = _camera->_height - mouseY;

			glReadPixels(mouseX, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
			glReadPixels(mouseX, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
			glReadPixels(mouseX, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

			printf("Clicked on pixel %f, %f, color %02hhx%02hhx%02hhx%02hhx, depth %f, stencil index %u\n", mouseX, mouseY, color[0], color[1], color[2], color[3], depth, index);

			ObjectManager* om = ObjectManager::getInstance();
			if ((dynamic_cast<UniversalTriangleObject*>(om->getObject(index))) && (index > 3))
			{
				om->removeObject(index);
				printf("Object %d removed\n", index);
			}


			//Mùžeme vypoèíst pozici v globálním souøadném systému.  
			glm::vec3 screenX = glm::vec3(mouseX, newy, depth);
			glm::mat4 view;
			glm::mat4 projection;
			glm::vec4 viewPort = glm::vec4(0, 0, _camera->_width, _camera->_height);
			glm::vec3 pos = glm::unProject(screenX, view, projection, viewPort);

			printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
		}
		else if (glfwGetMouseButton(_camera->_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		{
			glfwSetInputMode(_camera->_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			_firstClickRight = true;
		}
	}
}
