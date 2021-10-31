#include "SceneFactory.h"

Scene* SceneFactory::initFirstScene(GLFWwindow* window)
{
    Scene* scene = new FirstScene(window);
    return scene;
}

Scene* SceneFactory::initSecondScene(GLFWwindow* window)
{
    Scene* scene = new SecondScene(window);
    return scene;
}
