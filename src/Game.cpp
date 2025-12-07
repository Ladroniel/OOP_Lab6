#include "../include/Game.h"
#include <iostream>
#include <fstream>

Game::Game() {
    observers.push_back(new ConsoleObserver());
    observers.push_back(new FileObserver());
}

void Game::notify(const std::string &killer, const std::string &victim) {
    for (auto o : observers) o->onKill(killer, victim);
}

void Game::addNPC() {
    std::string type, name; 
    int x, y;

    std::cout << "Тип (Orc/Bear/Squirrel): ";
    std::cin >> type;

    std::cout << "Имя: ";
    std::cin >> name;

    std::cout << "Координаты X Y: ";
    std::cin >> x >> y;

    npcs.push_back(NPC_Factory::create(type, name, x, y));
}

void Game::listNPC() {
    if (npcs.empty()) { 
        std::cout << "Пусто\n"; 
        return;
    }

    for (int i = 0; i < npcs.size(); i++) {
        std::cout << i << ") " << npcs[i]->getType()
                  << " " << npcs[i]->getName()
                  << " (" << npcs[i]->getX() << "," << npcs[i]->getY() << ")\n";
    }
}

void Game::save() {
    std::ofstream f("npc.txt");

    for (auto &n : npcs) {
        f << n->getType() << " " << n->getName() << " "
          << n->getX() << " " << n->getY() << "\n";
    }

    std::cout << "Сохранено\n";
}

void Game::load() {
    std::ifstream f("npc.txt");
    std::string type, name;
    int x, y;

    npcs.clear();

    while (f >> type >> name >> x >> y) {
        npcs.push_back(NPC_Factory::create(type, name, x, y));
    }

    std::cout << "Загружено\n";
}

void Game::fight() {
    listNPC();

    if (npcs.size() < 2) {
        std::cout << "Недостаточно NPC для боя.\n";
        return;
    }

    std::cout << "Выберите двух персонажей (индексы): ";
    int a, b;
    std::cin >> a >> b;

    if (a >= npcs.size() || b >= npcs.size() || a == b) {
        std::cout << "Ошибка выбора\n";
        return;
    }

    if (fightVisitor.fight(*npcs[a], *npcs[b])) {
        notify(npcs[a]->getName(), npcs[b]->getName());
        npcs.erase(npcs.begin() + b);
    } 
    else if (fightVisitor.fight(*npcs[b], *npcs[a])) {
        notify(npcs[b]->getName(), npcs[a]->getName());
        npcs.erase(npcs.begin() + a);
    } 
    else {
        std::cout << "Ничья. Белка замир опиумов.\n";
    }
}

void Game::runMenu() {
    while (true) {
        std::cout << "\n1) Добавить NPC\n"
                     "2) Показать список\n"
                     "3) Сохранить\n"
                     "4) Загрузить\n"
                     "5) Бой\n"
                     "0) Выход\n> ";

        int cmd;
        std::cin >> cmd;

        if (cmd == 1) addNPC();
        else if (cmd == 2) listNPC();
        else if (cmd == 3) save();
        else if (cmd == 4) load();
        else if (cmd == 5) fight();
        else if (cmd == 0) break;
        else std::cout << "Неизвестная команда\n";
    }
}
