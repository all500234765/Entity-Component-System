#pragma once

#include "ECSComponent.hpp"
#include <vector>

class BaseECSSystem {
private:
    std::vector<uint32> ComponentTypes;
    std::vector<uint32> ComponentFlags;

public:
    enum Flags {
        Optional = 1, 
    };

    BaseECSSystem() {};
    BaseECSSystem(const std::vector<uint32>& In): ComponentTypes(In) {};
    virtual void UpdateComponents(float dt, BaseECSComponent** comp) {};
    inline const std::vector<uint32>& GetComponentTypes() { return ComponentTypes; }
    inline const std::vector<uint32>& GetComponentFlags() { return ComponentFlags; }

    bool IsValid();

protected:
    void AddComponentType(uint32 Type, uint32 Flag=0) {
        ComponentTypes.push_back(Type);
        ComponentFlags.push_back(Flag);
    };
};

class ECSSystemList {
private:
    std::vector<BaseECSSystem*> Systems;

public:
    inline bool AddSystem(BaseECSSystem& Sys) {
        if( !Sys.IsValid() ) return false;
        Systems.push_back(&Sys);
        return true;
    }

    bool RemoveSystem(BaseECSSystem* Sys);

    inline size_t size() { return Systems.size(); }
    inline BaseECSSystem* operator[](uint32 index) {return Systems[index]; }
};
