#ifndef __ENEMY__H__
#define __ENEMY__H__

#include <iostream>
#include <vector>
#include <memory>

template<typename EnemyKind>
struct EnemyBehaviour_t {
    void preattack() {
        //
        // Some required comprobations
        //
    };
    void postattack() {
        //
        // Some required updates
        //
    };

    void attack()
    {
        preattack();
        static_cast<EnemyKind*>(this)->attack();
        postattack();
    }

    void wander() {
        // Check position...
        static_cast<EnemyKind*>(this)->wander();
    }
};

struct Demon_t : EnemyBehaviour_t<Demon_t>{
    void attack()
    {
        std::cout << "Demon attack!" << std::endl;
    }

    void wander() {
        std::cout << "Demon wanders stomping everything as it goes..." << std::endl;
    }
};

struct Elf_t : EnemyBehaviour_t<Elf_t>{
    void attack()
    {
        std::cout << "Elf shots with its bow!" << std::endl;
    }

    void wander() {
        std::cout << "Elf start jumping on trees..." << std::endl;
    }
};

struct IEnemy_t {
    virtual void update() = 0;
    virtual ~IEnemy_t() = default;
};

template<typename EnemyKind>
struct Enemy_t : IEnemy_t{
    explicit Enemy_t() = default;

    virtual void update() override{
        behaviour.wander();    
        behaviour.attack();    
    }

    virtual ~Enemy_t() = default;

    EnemyBehaviour_t<EnemyKind> behaviour;
};


int main(int argc, char *argv[])
{

    std::vector<IEnemy_t*> v = {
        new Enemy_t<Elf_t>,
        new Enemy_t<Demon_t>
    };

    for(auto ptr : v) {
        ptr->update();
    }

    return 0;
}

#endif /* __ENEMY__H__ */
