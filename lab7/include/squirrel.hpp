#pragma once

#include "npc.hpp"

struct Squirrel : public NPC {
  Squirrel(int x, int y);

  virtual ~Squirrel() = default;

  explicit Squirrel(std::istream& is);

  void print() override;

  void save(std::ostream& os) override;

  bool fight(std::shared_ptr<Werewolf> other) override;

  bool fight(std::shared_ptr<Squirrel> other) override;

  bool fight(std::shared_ptr<Druid> other) override;

  friend std::ostream& operator<<(std::ostream& os, Squirrel& Squirrel);

  bool accept(std::shared_ptr<NPC> visitor) override;
};