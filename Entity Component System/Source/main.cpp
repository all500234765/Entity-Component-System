#include <Windows.h>

#include "ECS\ECS.hpp"
#include "ECS\ECSComponent.hpp"
#include "ECS\ECSSystem.hpp"
////////////////////////////////////////////////////////////////////////////////////////////////////
// Example code
////////////////////////////////////////////////////////////////////////////////////////////////////
struct TestComponent: public ECSComponent<TestComponent> {
    float x;
    float y;
};

int main() {

    ECS ecs;

    // Create components
    TestComponent testComp;
    testComp.x = 0;
    testComp.y = 0;

    // Create entities
    ecs.MakeEntity(testComp);

    // Create systems


    // 
    system("pause");
    return 0;
}
