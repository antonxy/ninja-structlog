#include "structured_log.h"

#include <iostream>
#include <string>

#include "json.h"

inline const char * const BoolToString(bool b)
{
  return b ? "true" : "false";
}


StructuredStatusPrinter::StructuredStatusPrinter(const BuildConfig& config) {
  
}

void StructuredStatusPrinter::PlanHasTotalEdges(int total) {
  
}

void StructuredStatusPrinter::BuildEdgeStarted(const Edge* edge, int64_t start_time_millis) {
}

void StructuredStatusPrinter::BuildEdgeFinished(Edge* edge, int64_t end_time_millis,
                                                bool success, const std::string& output) {
  std::cout << "{" <<
    "  \"type\": \"build_edge_finished\"" <<
    ", \"edge_id\":" << edge->id_ <<
    ", \"success\":" << BoolToString(success) <<
    ", \"command\": \"" << EncodeJSONString(edge->EvaluateCommand()) << "\"" <<
    ", \"output\": \"" << EncodeJSONString(output) << "\"" <<
    " }" << std::endl;
}

void StructuredStatusPrinter::BuildLoadDyndeps() {
  
}

void StructuredStatusPrinter::BuildStarted() {
  
}

void StructuredStatusPrinter::BuildFinished() {
  
}

void StructuredStatusPrinter::Info(const char* msg, ...) {
  
}

void StructuredStatusPrinter::Warning(const char* msg, ...) {
  
}

void StructuredStatusPrinter::Error(const char* msg, ...) {
  
}
