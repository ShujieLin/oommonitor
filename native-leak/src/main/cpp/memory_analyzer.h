//
// Created by linshujie on 2024/3/19.
//

#ifndef OOM_MEMORY_ANALYZER_H
#define OOM_MEMORY_ANALYZER_H
#include <string>
#include <vector>

namespace leak_monitor {

    class MemoryAnalyzer {
    public:
        MemoryAnalyzer();
        ~MemoryAnalyzer();
        bool IsValid();
        std::vector<std::pair<uintptr_t, size_t>> CollectUnreachableMem();

    private:
        using GetUnreachableFn = std::string (*)(bool, size_t);
        GetUnreachableFn get_unreachable_fn_;
        void *handle_;
    };

} // leak_monitor

#endif //OOM_MEMORY_ANALYZER_H
