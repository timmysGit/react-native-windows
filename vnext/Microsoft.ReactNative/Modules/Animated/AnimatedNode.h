// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include <cstdint>
#include <memory>
#include <vector>

namespace react {
namespace uwp {
class NativeAnimatedNodeManager;
class AnimatedNode {
 public:
  AnimatedNode(int64_t tag, const std::shared_ptr<NativeAnimatedNodeManager> &manager);
  int64_t Tag();
  void AddChild(int64_t animatedNode);
  void RemoveChild(int64_t animatedNode);

  virtual void Update(){};
  virtual void OnDetachedFromNode(int64_t /*animatedNodeTag*/){};
  virtual void OnAttachToNode(int64_t /*animatedNodeTag*/){};

 protected:
  AnimatedNode *GetChildNode(int64_t tag);
  const std::weak_ptr<NativeAnimatedNodeManager> m_manager;

 protected:
  std::vector<int64_t> m_children{};
  int64_t m_tag{0};
};
} // namespace uwp
} // namespace react
