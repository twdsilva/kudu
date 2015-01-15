// Copyright (c) 2013, Cloudera, inc.
// Confidential Cloudera Information: Covered by NDA.
#ifndef KUDU_CONSENSUS_LOG_METRICS_H
#define KUDU_CONSENSUS_LOG_METRICS_H

#include "kudu/gutil/macros.h"
#include "kudu/util/monotime.h"

namespace kudu {

class Counter;
class Histogram;
class MetricContext;

namespace log {

struct LogMetrics {
  explicit LogMetrics(const MetricContext& metric_ctx);

  // Global stats
  Counter* bytes_logged;

  // Per-group group commit stats
  Histogram* sync_latency;
  Histogram* append_latency;
  Histogram* group_commit_latency;
  Histogram* roll_latency;
  Histogram* entry_batches_per_group;
};

// TODO extract and generalize this for all histogram metrics
#define SCOPED_LATENCY_METRIC(_mtx, _h) \
  ScopedLatencyMetric _h##_metric(_mtx ? _mtx->_h : NULL)

} // namespace log
} // namespace kudu

#endif // KUDU_CONSENSUS_LOG_METRICS_H
