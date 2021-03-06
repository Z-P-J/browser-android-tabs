// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/audio/test/mock_log.h"

namespace audio {
MockLog::MockLog() : binding_(this) {}
MockLog::~MockLog() = default;
}  // namespace audio
