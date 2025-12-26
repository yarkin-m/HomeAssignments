/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#ifndef TRANSFORMERS_ALLIANCE_H
#define TRANSFORMERS_ALLIANCE_H

#include <string>

// assotiation
class Alliance {
 public:
  Alliance(const std::string& name, const std::string& leader);
  ~Alliance();

  std::string GetName() const;
  std::string GetLeader() const;

  // Sets
  void SetName(const std::string& name);
  void SetLeader(const std::string& leader);

 private:
  std::string name_;
  std::string leader_;
};

#endif