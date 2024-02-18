#ifndef NINJA_STRUCTURED_LOG_H_
#define NINJA_STRUCTURED_LOG_H_

#include "status.h"

struct StructuredStatusPrinter : Status {
  explicit StructuredStatusPrinter(const BuildConfig& config);
  virtual void PlanHasTotalEdges(int total);
  virtual void BuildEdgeStarted(const Edge* edge, int64_t start_time_millis);
  virtual void BuildEdgeFinished(Edge* edge, int64_t end_time_millis,
                                 bool success, const std::string& output);
  virtual void BuildLoadDyndeps();
  virtual void BuildStarted();
  virtual void BuildFinished();

  virtual void Info(const char* msg, ...);
  virtual void Warning(const char* msg, ...);
  virtual void Error(const char* msg, ...);

  virtual ~StructuredStatusPrinter() { }
};

#endif //NINJA_STRUCTURED_LOG_H
