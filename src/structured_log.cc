#include "structured_log.h"

#include <cstddef>
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
  std::cout << "{" <<
    "  \"type\": \"total_edges\"" <<
    ", \"total\":" << total <<
    " }" << std::endl;
}

void StructuredStatusPrinter::BuildEdgeStarted(const Edge* edge, int64_t start_time_millis) {
  std::cout << "{" <<
    "  \"type\": \"build_edge_started\"" <<
    ", \"edge_id\":" << edge->id_ <<
    ", \"start_time_millis\":" << start_time_millis <<
    ", \"command\": \"" << EncodeJSONString(edge->EvaluateCommand()) << "\"" <<

    ", \"inputs\": [";
    bool is_first = true;
    for (size_t i = 0; i < edge->inputs_.size(); ++i) {
      Node * input = edge->inputs_[i];
      if (!is_first) std::cout << ",";
      is_first = false;
      const char * dep_type = edge->is_implicit(i) ? "implicit" : (edge->is_order_only(i) ? "order_only" : "explicit");
      std::cout << "{" <<
      "  \"node_id\": " << input->id() <<
      ", \"path\": \"" << input->path() << "\"" <<
      ", \"in_type\": \"" << dep_type << "\"" <<
      " }";
    }
    std::cout << "]" <<

    ", \"outputs\": [";
    is_first = true;
    for (size_t i = 0; i < edge->outputs_.size(); ++i) {
      Node * output = edge->outputs_[i];
      if (!is_first) std::cout << ",";
      is_first = false;
      const char * dep_type = edge->is_implicit_out(i) ? "implicit" : "explicit";
      std::cout << "{" <<
      "  \"node_id\": " << output->id() <<
      ", \"path\": \"" << output->path() << "\"" <<
      ", \"out_type\": \"" << dep_type << "\"" <<
      " }";
    }
    std::cout << "]" <<
    " }" << std::endl;
}

void StructuredStatusPrinter::BuildEdgeFinished(Edge* edge, int64_t end_time_millis,
                                                bool success, const std::string& output) {
  std::cout << "{" <<
    "  \"type\": \"build_edge_finished\"" <<
    ", \"edge_id\":" << edge->id_ <<
    ", \"end_time_millis\":" << end_time_millis <<
    ", \"success\":" << BoolToString(success) <<
    ", \"output\": \"" << EncodeJSONString(output) << "\"" <<
    " }" << std::endl;
}

void StructuredStatusPrinter::BuildLoadDyndeps() {
  
}

void StructuredStatusPrinter::BuildStarted() {
    std::cout << "{" <<
    "  \"type\": \"build_status\"" <<
    ", \"status\": \"running\"" <<
    " }" << std::endl;
}

void StructuredStatusPrinter::BuildFinished() {
    std::cout << "{" <<
    "  \"type\": \"build_status\"" <<
    ", \"status\": \"finished\"" <<
    " }" << std::endl;
}

void StructuredStatusPrinter::Info(const char* msg, ...) {
  
}

void StructuredStatusPrinter::Warning(const char* msg, ...) {
  
}

void StructuredStatusPrinter::Error(const char* msg, ...) {
  
}
