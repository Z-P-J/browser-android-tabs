// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_ANDROID_SCOPED_SURFACE_REQUEST_CONDUIT_H_
#define GPU_IPC_COMMON_ANDROID_SCOPED_SURFACE_REQUEST_CONDUIT_H_

#include "gpu/gpu_export.h"
#include "gpu/ipc/common/android/surface_owner_android.h"

namespace base {
class UnguessableToken;
}

namespace gpu {

// Allows the forwarding of SurfaceOwners from the GPU or the browser process
// to fulfill requests registered by the ScopedSurfaceRequestManager.
class GPU_EXPORT ScopedSurfaceRequestConduit {
 public:
  static ScopedSurfaceRequestConduit* GetInstance();
  static void SetInstance(ScopedSurfaceRequestConduit* instance);

  // Sends the surface owner to the ScopedSurfaceRequestManager in the browser
  // process, to fulfill the request registered under the |request_token| key.
  virtual void ForwardSurfaceOwnerForSurfaceRequest(
      const base::UnguessableToken& request_token,
      const SurfaceOwner* surface_owner) = 0;

 protected:
  virtual ~ScopedSurfaceRequestConduit() {}
};

}  // namespace gpu

#endif  // GPU_IPC_COMMON_ANDROID_SCOPED_SURFACE_REQUEST_CONDUIT_H_
