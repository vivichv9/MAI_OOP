#pragma once

#include "npc.hpp"

struct Druid : public NPC {
  Druid(int x, int y);

  virtual ~Druid() = default;

  explicit Druid(std::istream& is);

  void print() override;

  void save(std::ostream& os) override;

  bool fight(std::shared_ptr<Werewolf> other) override;

  bool fight(std::shared_ptr<Squirrel> other) override;

  bool fight(std::shared_ptr<Druid> other) override;

  bool accept(std::shared_ptr<NPC> visitor) override;

  friend std::ostream& operator<<(std::ostream& os, Druid& Squirrel);
};