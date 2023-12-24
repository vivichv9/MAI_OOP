#pragma once

#include "npc.hpp"

struct Werewolf : public NPC {
  Werewolf(int x, int y);

  explicit Werewolf(std::istream& is);

  virtual ~Werewolf() = default;

  void print() override;

  bool fight(std::shared_ptr<Werewolf> other) override;

  bool fight(std::shared_ptr<Squirrel> other) override;

  bool fight(std::shared_ptr<Druid> other) override;

  bool accept(std::shared_ptr<NPC> visitor) override;

  void save(std::ostream& os) override;

  friend std::ostream& operator<<(std::ostream& os, Werewolf& Werewolf);
};