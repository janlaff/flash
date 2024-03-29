//#include "EntityComponentSystem.impl.h"

namespace flash {
    template<typename T>
    void EntityComponentSystem::registerComponent() {
        return m_componentManager->registerComponent<T>();
    }

    template<typename T>
    void EntityComponentSystem::addComponent(Entity entity, T component) {
        m_componentManager->addComponent<T>(entity, component);

        auto signature = m_entityManager->getSignature(entity);
        signature.set(m_componentManager->getComponentType<T>(), true);
        m_entityManager->setSignature(entity, signature);

        m_systemManager->entitySignatureChanged(entity, signature);
    }

    template<typename T>
    void EntityComponentSystem::removeComponent(Entity entity) {
        m_componentManager->removeComponent<T>(entity);

        auto signature = m_entityManager->getSignature(entity);
        signature.set(m_componentManager->getComponentType<T>(), false);
        m_entityManager->setSignature(entity, signature);

        m_systemManager->entitySignatureChanged(entity, signature);
    }

    template<typename T>
    T& EntityComponentSystem::getComponent(Entity entity) {
        return m_componentManager->getComponent<T>(entity);
    }

    template<typename T>
    ComponentType EntityComponentSystem::getComponentType() {
        return m_componentManager->getComponentType<T>();
    }

    template<typename T, typename ... Args>
    std::shared_ptr<T> EntityComponentSystem::registerSystem(Args&&... args) {
        return m_systemManager->registerSystem<T>(this, std::forward<Args>(args)...);
    }

    template<typename T>
    void EntityComponentSystem::setSystemSignature(Signature signature) {
        return m_systemManager->setSignature<T>(signature);
    }
}