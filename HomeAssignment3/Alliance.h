/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#ifndef TRANSFORMERS_ALLIANCE_H
#define TRANSFORMERS_ALLIANCE_H

#include <string>

// ассоциации
class Alliance {
 public:
  Alliance(const std::string& name, const std::string& leader);
  ~Alliance();

  std::string GetName() const;
  std::string GetLeader() const;

  // Set методы
  void SetName(const std::string& name);
  void SetLeader(const std::string& leader);

 private:
  std::string name_;
  std::string leader_;
};

#endif