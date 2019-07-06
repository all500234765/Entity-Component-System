#include <Windows.h>

#include "ECS/ECS/ECS.hpp"
#include "ECS/ECS/ECSComponent.hpp"
#include "ECS/ECS/ECSSystem.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Example code
////////////////////////////////////////////////////////////////////////////////////////////////////
struct TestComponent: public ECSComponent<TestComponent> {
    float x;
    float y;
};

class TestSystem: public BaseECSSystem {
private:


public:
    TestSystem(): BaseECSSystem() {
        AddComponentType(TestComponent::_ID); // 0
    }

    void UpdateComponents(float dt, BaseECSComponent** comp) override {
        TestComponent* test = (TestComponent*)comp[0];

        test->x += dt;
        test->y += dt;
    }
};

int main() {

    ECS ecs;

    // Create component
    TestComponent testComp;
    testComp.x = 0;
    testComp.y = 0;

    // Create entitie
    EntityHandle entity = ecs.MakeEntity(testComp);

    // Create and add system
    TestSystem sys;

    ECSSystemList list;
    list.AddSystem(sys);

    // Update systems
    ecs.UpdateSystems(list, .16666);

    // Get and show data
    TestComponent* t = ecs.GetComponent<TestComponent>(entity);
    printf_s("x=%f y=%f\n", t->x, t->y);

    

    // 
    system("pause");
    return 0;
}
