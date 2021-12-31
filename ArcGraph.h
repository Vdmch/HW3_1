#pragma once

#include "IGraph.h"
#include <unordered_set>

class ArcGraph : public IGraph {
public:
    ArcGraph(size_t _vertices_count);
    ArcGraph(const IGraph &graph);
    ~ArcGraph() override = default;
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> vertices;
    size_t vertices_count;
};

