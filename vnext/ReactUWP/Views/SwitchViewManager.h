// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <Views/ControlViewManager.h>

namespace react {
namespace uwp {

class SwitchViewManager : public ControlViewManager {
  using Super = ControlViewManager;

 public:
  SwitchViewManager(const std::shared_ptr<IReactInstance> &reactInstance);

  const char *GetName() const override;
  folly::dynamic GetNativeProps() const override;
  facebook::react::ShadowNode *createShadow() const override;
  void DispatchCommand(XamlView viewToUpdate, const std::string &commandId, const folly::dynamic &commandArgs) override;

 protected:
  bool UpdateProperty(
      ShadowNodeBase *nodeToUpdate,
      const std::string &propertyName,
      const folly::dynamic &propertyValue) override;

  XamlView CreateViewCore(int64_t tag) override;

  friend class SwitchShadowNode;
};

} // namespace uwp
} // namespace react