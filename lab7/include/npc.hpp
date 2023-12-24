#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <shared_mutex>

// type for npcs
class NPC;
struct Werewolf;
struct Squirrel;
struct Druid;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
  Unknown,
  WerewolfType,
  SquirrelType,
  DruidType
};

struct IFightObserver {
  virtual void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) = 0;
};

class NPC {
private:
  std::mutex mtx;

  NpcType type;
  int x{0};
  int y{0};
  bool alive{true};

  std::vector<std::shared_ptr<IFightObserver>> observers;

public:
  NPC(NpcType t, int _x, int _y);

  NPC(NpcType t, std::istream& is);

  void subscribe(std::shared_ptr<IFightObserver> observer);

  void fight_notify(const std::shared_ptr<NPC> defender, bool win);

  virtual bool is_close(const std::shared_ptr<NPC>& other, size_t distance);

  virtual bool accept(std::shared_ptr<NPC> visitor) = 0;

  // visit
  virtual bool fight(std::shared_ptr<Werewolf> other) = 0;

  virtual bool fight(std::shared_ptr<Squirrel> other) = 0;

  virtual bool fight(std::shared_ptr<Druid> other) = 0;

  virtual void print() = 0;

  std::pair<int, int> position();

  NpcType get_type();

  virtual void save(std::ostream& os);

  friend std::ostream& operator<<(std::ostream& os, NPC& npc);

  void move(int shift_x, int shift_y, int max_x, int max_y);

  bool is_alive();

  void must_die();
};