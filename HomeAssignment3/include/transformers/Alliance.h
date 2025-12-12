#ifndef TRANSFORMERS_ALLIANCE_H_
#define TRANSFORMERS_ALLIANCE_H_

#include <string>

namespace transformers {

class Alliance {
 public:
  Alliance(const std::string& name = "Unaffiliated",
           const std::string& leader = "None",
           int member_count = 0);
  ~Alliance();
  
  const std::string& GetName() const;
  const std::string& GetLeader() const;
  int GetMemberCount() const;
  
  void SetName(const std::string& name);
  void SetLeader(const std::string& leader);
  void SetMemberCount(int member_count);
  
  std::string GetInfo() const;
  bool IsLarge() const;

 private:
  std::string name_;
  std::string leader_;
  int member_count_;
};

}

#endif