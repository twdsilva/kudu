// Copyright (c) 2014, Cloudera, inc.
// Confidential Cloudera Information: Covered by NDA.

#include "kudu/consensus/log_metrics.h"

#include "kudu/util/metrics.h"

METRIC_DEFINE_counter(bytes_logged, kudu::MetricUnit::kBytes,
                      "Number of bytes logged since service start");

METRIC_DEFINE_histogram(sync_latency, kudu::MetricUnit::kMicroseconds,
                        "Microseconds spent on synchronizing the log segment file",
                        60000000LU, 2);

METRIC_DEFINE_histogram(append_latency, kudu::MetricUnit::kMicroseconds,
                        "Microseconds spent on appending to the log segment file",
                        60000000LU, 2);

METRIC_DEFINE_histogram(group_commit_latency, kudu::MetricUnit::kMicroseconds,
                        "Microseconds spent on committing an entire group",
                        60000000LU, 2);

METRIC_DEFINE_histogram(roll_latency, kudu::MetricUnit::kMicroseconds,
                        "Microseconds spent on rolling over to a new log segment file",
                        60000000LU, 2);

METRIC_DEFINE_histogram(entry_batches_per_group, kudu::MetricUnit::kRequests,
                        "Number of log entry batches in a group commit group",
                        1024, 2);

namespace kudu {
namespace log {

#define MINIT(x) x(METRIC_##x.Instantiate(metric_ctx))
LogMetrics::LogMetrics(const MetricContext& metric_ctx)
    : MINIT(bytes_logged),
      MINIT(sync_latency),
      MINIT(append_latency),
      MINIT(group_commit_latency),
      MINIT(roll_latency),
      MINIT(entry_batches_per_group) {
}
#undef MINIT

} // namespace log
} // namespace kudu
