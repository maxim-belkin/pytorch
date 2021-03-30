#include <torch/csrc/jit/api/module.h>
#include <torch/csrc/jit/serialization/export.h>

namespace torch {
namespace jit {

void Module::save(std::ostream& out, const ExtraFilesMap& extra_files) const {
  ExportModule(
      *this,
      out,
      extra_files,
      at::optional<uint64_t>() /* bytecode_format version*/);
}

void Module::save(const std::string& filename, const ExtraFilesMap& extra_files)
    const {
  ExportModule(
      *this,
      filename,
      extra_files,
      at::optional<uint64_t>() /* bytecode_format version*/);
}

void Module::_save_for_mobile(
    std::ostream& out,
    const ExtraFilesMap& extra_files,
    at::optional<uint64_t> version,
    bool save_mobile_debug_info) const {
  ExportModule(
      *this,
      out,
      extra_files,
      version /* bytecode_format version */,
      save_mobile_debug_info);
}

void Module::_save_for_mobile(
    const std::string& filename,
    const ExtraFilesMap& extra_files,
    at::optional<uint64_t> version,
    bool save_mobile_debug_info) const {
  ExportModule(
      *this,
      filename,
      extra_files,
      version /* bytecode_format version*/,
      save_mobile_debug_info);
}

} // namespace jit
} // namespace torch
